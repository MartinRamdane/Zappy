from MyClient import Client
import sys

class Ai:
    def __init__(self, teamName, machine, port):
        print("LALALALALALLALOALAO " + teamName)
        self.teamName = teamName
        self.mapSize = (0, 0)
        self.avaibleSlots = 0
        self.machine = machine
        self.port = port
        self.seachFood = False
        self.path = []
        self.level = 1
        self.client = None
        self.lookInventoryFood = 0
        self.message = "Look\n"
        self.receive = ""
        self.canFork = False
        self.haveBroadcast = False
        self.waitingForReponse = False
        self.canIncantation = False
        self.nbMatesAvailable = 1
        self.count = 0
        self.sourceFile = open(self.teamName + '.log', 'w')
        self.nbFork = 0
        self.skipSend = False

    def joinGame(self):
        self.client = Client(self.machine, self.port)
        self.client.connect()
        receive = self.client.receive_message()
        if receive == "WELCOME\n":
            self.client.send_message(self.teamName + "\n")
        receive = self.client.receive_message()
        arr = receive.split('\n')
        self.setAvaibleSlots(int(arr[0]))
        self.setMapSize(arr[1])

    def communication(self):
        print("Self level = ", self.level, file = self.sourceFile)
        self.canFork = False
        if not self.skipSend:
            if self.path:
                self.message = self.path.pop(0)
            elif self.seachFood and not self.path:
                self.message = "Look\n"
            elif self.lookInventoryFood >= 3 and not self.path:
                self.message = "Inventory\n"
                self.lookInventoryFood = 0
            print("Send to " + self.teamName + ": " + self.message, file = self.sourceFile)
            self.client.send_message(self.message)
        self.receive = self.client.receive_message()
        if self.message == "Incantation\n" and self.receive != "ko\n":
            print("Receive: ", self.receive, file = self.sourceFile)
            if "dead" in self.receive:
                sys.exit()
            self.receive += self.client.receive_message()
        tmp = self.receive.split('\n')
        for item in tmp:
            if item != "":
                self.receive = item
                self.parseCommands(self.message, item)
        if not self.path:
            self.lookInventoryFood += 1
        if not "message" in self.receive:
            self.message = "Look\n"
        return self.canFork

    def setMapSize(self, arr):
        tmp = arr.split(' ')
        self.mapSize = (int(tmp[0]), int(tmp[1]))

    def setAvaibleSlots(self, slots):
        self.avaibleSlots = slots

    def getInventory(self, response):
        data_string = response.replace("[", "").replace("]", "").replace(",", "")
        data_list = data_string.split()
        data_dict = {}
        for i in range(0, len(data_list), 2):
            key = data_list[i]
            value = int(data_list[i+1])
            data_dict[key] = value
        return data_dict

    def getObjectsAround(self, response):
        data_string = response.replace("[", "").replace("]", "")
        data_list = data_string.split(",")
        result_list = []
        for item in data_list:
            inner_list = [i.strip() for i in item.split()]
            if inner_list:
                result_list.append(inner_list)
            else:
                result_list.append([])
        return result_list

    def encrypt(self, message, key):
        encrypted_message = ""
        for char in message:
            if char.isalpha():
                if char.isupper():
                    encrypted_char = chr((ord(char) - 65 + key) % 26 + 65)
                else:
                    encrypted_char = chr((ord(char) - 97 + key) % 26 + 97)
                encrypted_message += encrypted_char
            else:
                encrypted_message += char
        return encrypted_message

    def decrypt(self, message, key):
        decrypted_message = ""
        for char in message:
            if char.isalpha():
                if char.isupper():
                    decrypted_char = chr((ord(char) - 65 - key) % 26 + 65)
                else:
                    decrypted_char = chr((ord(char) - 97 - key) % 26 + 97)
                decrypted_message += decrypted_char
            else:
                decrypted_message += char
        return decrypted_message

    def parseResponse(self, receive):
        print("MESSAGE RECU", file = self.sourceFile)
        tmpList = receive.split(",")
        print(tmpList[1], file = self.sourceFile)
        decrypted = self.decrypt(tmpList[1], ord(self.teamName[0]))
        self.count = 0
        print("DECRYPT:" + decrypted, file = self.sourceFile)
        if "Is anyone is level" in decrypted:
            print("MESSAGE DECRYPTED", file = self.sourceFile)
            code = decrypted.split(" ")
            wantedLevel = int(code[5])
            if self.level == wantedLevel:
                encode = self.encrypt("Yes I'm level " + str(self.level), ord(self.teamName[0]))
                self.path.append("Broadcast " + encode + "\n")
                self.nbMatesAvailable += 1
                return True
        return False

    def getNbMatesNeeded(self, level):
        if level == 1:
            return 1
        elif level == 2:
            return 2
        elif level == 3:
            return 2
        elif level == 4:
            return 4
        elif level == 5:
            return 4
        elif level == 6:
            return 6
        elif level == 7:
            return 6

    def parseCommands(self, message, receive):
        print("Mess: " + self.message + " Receive to " + self.teamName + ": " + receive, file = self.sourceFile)
        self.skipSend = False
        if "message" in self.receive:
            self.skipSend = not self.parseResponse(self.receive)
        if message == "Look\n" and self.count >= 3:
            self.count = 0
            self.waitingForReponse = False
            if self.nbMatesAvailable >= self.getNbMatesNeeded(self.level):
                self.canIncantation = True
                self.nbMatesAvailable = 1
        elif message == "Inventory\n" and receive != "ko":
            inventory = self.getInventory(receive)
            if inventory["food"] < 5:
                self.seachFood = True
        elif message == "Look\n" and self.path and self.path[-1] == "Incantation\n":
            if not self.checkTileForIncantation(self.getObjectsAround(receive)[0], self.level):
                self.path = []
        if message == "Look\n" and receive != "ko":
            getobjects = self.getObjectsAround(receive)
            if self.haveBroadcast:
                self.count += 1
            if self.seachFood:
                self.getFood(getobjects)
            elif not self.waitingForReponse:
                self.makeIncantation(getobjects)
        elif message == "dead\n":
            sys.exit()
        elif "Current level: " in receive:
            print("HEREE", file = self.sourceFile)
            self.level = int(receive[15])
            print("Level: " + str(self.level), file = self.sourceFile)
            self.haveBroadcast = False
            self.nbFork = 0
        elif message == "Fork\n" and receive == "ok":
            print("FORK OK", file = self.sourceFile)
            self.nbFork += 1
            self.canFork = True

    def getNearestObject(self, name, objects):
        indexes = []
        for i, sous_liste in enumerate(objects):
            if name in sous_liste:
                indexes.append(i)
        if not indexes:
            return None
        return min(indexes)

    def getNearestNumberInList(self, number, liste):
        nearest = None
        difference_minimale = float('inf')
        for i in liste:
            difference = abs(i - number)
            if difference < difference_minimale:
                nearest = i
                difference_minimale = difference
            elif difference == difference_minimale and i > nearest:
                nearest = i
        return nearest

    def getPathtoObject(self, case):
        centers = [0, 2, 6, 12, 20, 30, 42, 56]
        path = []
        if case in centers:
            index = centers.index(case)
            for i in range(index):
                path.append("Forward\n")
            return path
        nearestNumber = self.getNearestNumberInList(case, centers)
        index = centers.index(nearestNumber)
        for i in range(index):
            path.append("Forward\n")
        if case > nearestNumber:
            path.append("Right\n")
        else:
            path.append("Left\n")
        for i in range(abs(case - nearestNumber)):
            path.append("Forward\n")
        return path

    def checkTileForIncantation(self, tile, level):
        if level == 1:
            if len(tile) == 2 and "player" in tile and "linemate" in tile:
                return True
        return False

    def getFood(self, objects):
        nearestFood = self.getNearestObject("food", objects)
        if nearestFood is None:
            self.path = ["Forward\n"]
            return
        self.path = self.getPathtoObject(nearestFood)
        self.path.append("Take " + "food" + "\n")
        self.seachFood = False

    def makeIncantation(self, objects):
        if self.level == 1:
            nearestIncantation = self.getNearestObject("linemate", objects)
            if nearestIncantation is None:
                self.path = ["Forward\n"]
                return
            self.path = self.getPathtoObject(nearestIncantation)
            nbLinemate = 0
            for item in objects[nearestIncantation]:
                if item == "linemate":
                    if nbLinemate >= 1:
                        self.path.append("Take " + item + "\n")
                    nbLinemate += 1
                elif item != "player" and item != "linemate":
                    self.path.append("Take " + item + "\n")
            # self.path.append("Look\n")
            self.path.append("Incantation\n")
        elif self.level == 2:
            if not self.haveBroadcast and not self.waitingForReponse and not self.canIncantation:
                self.path = ["Broadcast " + self.encrypt("Is anyone is level 2 ?", ord(self.teamName[0])) + "\n"]
                self.haveBroadcast = True
                self.waitingForReponse = True
            elif not self.canIncantation and not self.waitingForReponse:
                if self.nbFork < 1:
                    self.path = ["Fork\n"]
                self.haveBroadcast = False
                self.waitingForReponse = False
            else:
                print("HE CAN INCANT NOW", file = self.sourceFile)