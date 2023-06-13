from MyClient import Client
from Level import Level
from Utilities import *
import sys

class Ai:
    def __init__(self, teamName, machine, port, filename):
        self.teamName = teamName
        self.machine = machine
        self.port = port
        self.seachFood = False
        self.path = []
        self.level = 1
        self.client = None
        self.tiles = {0: ["Look\n"], 1: ["Forward\n"], 2: ["Forward\n", "Left\n", "Forward\n"], 3: ["Left\n", "Forward\n"], 4: ["Left\n", "Forward\n", "Left\n", "Forward\n"], 5: ["Left\n", "Left\n", "Forward\n"], 6: ["Left\n", "Left\n", "Forward\n", "Left\n", "Forward\n"], 7: ["Right\n", "Forward\n"], 8: ["Forward\n", "Right\n", "Forward\n"]}
        self.sourceFile = open(filename + '.log', 'w')
        self.debug = filename
        self.inventory = {}
        self.canFork = False
        self.objectsAround = []
        self.levelManager = Level()
        self.nbFork = 0
        self.lookInventoryFood = 0
        self.haveBroadcast = False
        self.waitingForReponse = False
        self.count = 0
        self.nbMatesAvailable = 1
        self.nbMatesAvailableForIncantation = 1
        self.canIncantation = False
        self.toJoin = False
        self.prepareIncantation = False
        self.direction = ""
        self.skipSend = False
        self.countLook = 0
        self.tosendJoin = False
        self.haveStones = False
        self.message = ""
        self.askForLevel = False
        self.lastReceive = ""
        self.elevationInProgress = False

    def joinGame(self):
        self.client = Client(self.machine, self.port)
        self.client.connect()
        receive = self.client.receive_message()
        if receive == "WELCOME\n":
            self.client.send_message(self.teamName + "\n")
        receive = self.client.receive_message()
        print("Receive: ", receive, file = self.sourceFile)

    def communication(self):
        print("LEVEL: ", self.level, file = self.sourceFile)
        receive = ""
        print ("lookInventoryFood = ", self.lookInventoryFood, file = self.sourceFile)
        print ("searchFood = ", self.seachFood, file = self.sourceFile)
        print ("PATH before send: ", self.path, file = self.sourceFile)
        self.canFork = False
        if not self.skipSend and not self.elevationInProgress:
            print("HERE", file = self.sourceFile)
            self.message = "Take food\n"
            if self.lookInventoryFood >= 8 and not self.prepareIncantation and not self.toJoin:
                self.message = "Inventory\n"
                self.lookInventoryFood = 0
            elif self.seachFood and not self.path and not self.prepareIncantation:
                print("SEARCH FOOD", file = self.sourceFile)
                self.message = "Look\n"
            elif self.path:
                self.message = self.path.pop(0)
            print("Send to " + self.teamName + ": " + self.message, file = self.sourceFile)
            if "I'm coming to join you for level " in decrypt(self.message, ord(self.teamName[0])):
                self.tosendJoin = True
            elif "I have all stones for level " in decrypt(self.message, ord(self.teamName[0])):
                self.haveStones = True
            elif "Is anyone is level" in decrypt(self.message, ord(self.teamName[0])) or "Yes I'm level" in decrypt(self.message, ord(self.teamName[0])):
                self.askForLevel = True
            self.client.send_message(self.message)
        receive = self.client.receive_message()
        print("Receive: ", receive, file = self.sourceFile)
        if receive[-1] != '\n':
            receive += self.client.receive_message()
        tmp = receive.split('\n')
        i = 0
        for item in tmp:
            if item != "":
                self.parseReponse(item)
                self.lastReceive = item
                i += 1
        if i > 1:
            print("Skip send Here", self.skipSend, file = self.sourceFile)
            self.skipSend = False
        print("Skip send la",self.skipSend, file = self.sourceFile)
        self.lookInventoryFood += 1
        if self.haveBroadcast:
            self.count += 1
        return self.canFork

    def getObjectsAround(self, receive):
        data_string = receive.replace("[", "").replace("]", "")
        data_list = data_string.split(",")
        result_list = []
        for item in data_list:
            inner_list = [i.strip() for i in item.split()]
            if inner_list:
                result_list.append(inner_list)
            else:
                result_list.append([])
        self.objectsAround = result_list

    def getFood(self):
        nearestFood = getNearestObject("food", self.objectsAround)
        if nearestFood is None:
            self.path.append("Forward\n")
            return
        self.path += getPathtoObject(nearestFood)
        self.path.append("Take food\n")
        self.seachFood = False

    def getInventory(self, receive):
        data_string = receive.replace("[", "").replace("]", "").replace(",", "")
        data_list = data_string.split()
        data_dict = {}
        for i in range(0, len(data_list), 2):
            key = data_list[i]
            value = int(data_list[i+1])
            data_dict[key] = value
        self.inventory = data_dict
        if self.inventory["food"] < 13 and not "Incantation\n" in self.path:
            self.seachFood = True

    def look(self, receive):
        print("PATH IN LOOK: ", self.path, file = self.sourceFile)
        self.getObjectsAround(receive)
        if self.count >= 10:
            self.count = 0
            self.waitingForReponse = False
            if self.nbMatesAvailable >= self.levelManager.matesNeeded[self.level + 1]:
                self.canIncantation = True
                self.nbMatesAvailable = 1
        if self.path and self.path[-1] == "Incantation\n":
            if not self.levelManager.checkTileForIncanation(self.objectsAround[0], self.level + 1):
                print("INCANTATION FAILED", file = self.sourceFile)
                if self.level == 1 and checkNbElemInList(self.objectsAround[0], "player") > 1:
                    self.path = ["Eject\n", "Incantation\n"]
                else:
                    self.path = []
        if self.seachFood:
            self.getFood()
        else:
            self.makeIncantation()()

    def elevation(self, receive):
        self.elevationInProgress = True
        print("ELEVATION", file = self.sourceFile)
        if self.lastReceive != "Elevation underway":
            self.skipSend = True

    def levelUpdating(self, receive):
        print("LEVEL UPDATING from " + self.debug + " to LEVEL " + str(self.level + 1))
        self.level = int(receive[15])
        print("Level: " + str(self.level), file = self.sourceFile)
        self.nbFork = 0
        self.path = []
        self.haveBroadcast = False
        self.waitingForReponse = False
        self.count = 0
        self.canIncantation = False
        self.toJoin = False
        self.prepareIncantation = False
        self.direction = ""
        self.countLook = 0
        self.seachFood = True
        self.nbMatesAvailable = 1
        self.tosendJoin = False
        self.haveStones = False
        self.nbMatesAvailableForIncantation = 1
        self.askForLevel = False
        self.elevationInProgress = False

    def goToDir(self, tile):
        val = self.tiles[tile]
        for item in val:
            self.path.append(item)
        print("PATH TO DIR: ", self.path, file = self.sourceFile)

    def ReceiveMessage(self, receive):
        self.skipSend = True
        print("MESSAGE RECU", file = self.sourceFile)
        tmpList = receive.split(",")
        print(tmpList[1], file = self.sourceFile)
        decrypted = decrypt(tmpList[1], ord(self.teamName[0]))
        self.count = 0
        mess = tmpList[0].split(" ")
        print("DECRYPT:" + decrypted, file = self.sourceFile)
        if "Is anyone is level" in decrypted:
            print("MESSAGE DECRYPTED", file = self.sourceFile)
            code = decrypted.split(" ")
            wantedLevel = int(code[5])
            if self.level == wantedLevel:
                self.count = 0
                if not self.askForLevel and not ("Broadcast " + encrypt("Yes I'm level " + str(self.level), ord(self.teamName[0])) + "\n") in self.path:
                    encode = encrypt("Yes I'm level " + str(self.level), ord(self.teamName[0]))
                    self.path.insert(0, "Broadcast " + encode + "\n")
                self.nbMatesAvailable += 1
                if self.nbMatesAvailable >= self.levelManager.matesNeeded[self.level + 1]:
                    self.canIncantation = True
                    self.nbMatesAvailable = 1
                    self.waitingForReponse = False
        if "Yes I'm level" in decrypted:
            print("MESSAGE DECRYPTED", file = self.sourceFile)
            code = decrypted.split(" ")
            wantedLevel = int(code[4])
            if self.level == wantedLevel:
                self.count = 0
                self.nbMatesAvailable += 1
            if self.nbMatesAvailable >= self.levelManager.matesNeeded[self.level + 1]:
                self.canIncantation = True
                self.nbMatesAvailable = 1
                self.waitingForReponse = False
        if "I have all stones for level" in decrypted:
            tmp = decrypted.split(" ")
            wantedLevel = int(tmp[7])
            if wantedLevel == self.level + 1 and not self.prepareIncantation:
                if self.message == ("I have all stones for level " + str(self.level + 1) + "\n"):
                    self.haveStones = False
                self.path = []
                if (not self.toJoin or ("I'm coming to join you for level " + str(self.level + 1) + "\n") in self.path) and not self.tosendJoin and not self.haveStones:
                    self.path.append("Broadcast " + encrypt("I'm coming to join you for level " + str(self.level + 1), ord(self.teamName[0])) + "\n")
                    self.path.append("Inventory\n")
        if "Join me for level" in decrypted:
            tmp = decrypted.split(" ")
            wantedLevel = int(tmp[5])
            if wantedLevel == self.level + 1:
                self.direction = mess[1]
                self.prepareIncantation = False
                self.waitingForReponse = False
                self.canIncantation = True
                self.path = []
                self.goToDir(int(self.direction))
                self.path.append("Look\n")
                self.toJoin = True
                self.haveBroadcast = True
        if "I'm coming to join you for level" in decrypted:
            tmp = decrypted.split(" ")
            print("CICIICIC", file = self.sourceFile)
            wantedLevel = int(tmp[8])
            print("LEVEL wanted: " + str(wantedLevel), file = self.sourceFile)
            if wantedLevel == self.level + 1:
                self.nbMatesAvailableForIncantation += 1
                print("NB MATES: " + str(self.nbMatesAvailableForIncantation), file = self.sourceFile)
                print("NB MATES NEEDED: " + str(self.levelManager.matesNeeded[self.level + 1]), file = self.sourceFile)
                if self.nbMatesAvailableForIncantation >= self.levelManager.matesNeeded[self.level + 1]:
                    print("LALALAL", file = self.sourceFile)
                    self.path = ["Broadcast " + encrypt("Join me for level " + str(self.level + 1), ord(self.teamName[0])) + "\n"]
                    self.prepareIncantation = True
                    self.seachFood = False
                    self.waitingForReponse = False
                    self.canIncantation = True
        print("SKip send: " + str(self.skipSend), file = self.sourceFile)

    def other(self, receive):
        if self.message == "Fork\n" and receive == "ok":
            self.canFork = True
        if not self.path:
            print("PATH IS EMPTY", file = self.sourceFile)
            self.path = ["Look\n"]

    def dead(self, receive):
        print("Team " + self.debug + " level " + str(self.level) + " is dead")
        sys.exit(0)

    def getCommand(self,case):
        switch = {
            Type.INVENTORY: self.getInventory,
            Type.LOOK: self.look,
            Type.ELEVATION: self.elevation,
            Type.LEVELUPDATING: self.levelUpdating,
            Type.MESSAGE: self.ReceiveMessage,
            Type.OTHER: self.other,
            Type.DEAD: self.dead
        }
        return switch.get(case, lambda: "Invalid type")

    def parseReponse(self, receive):
        self.skipSend = False
        print("Receive to " + self.teamName + ": " + receive, file = self.sourceFile)
        reponseType = getTypeOfReponse(receive)
        if self.elevationInProgress and reponseType != Type.LEVELUPDATING and reponseType != Type.DEAD:
            return
        self.getCommand(reponseType)(receive)

    def makeIncantationLevel2(self):
        nearestIncantation = getNearestObject("linemate", self.objectsAround)
        if nearestIncantation is None:
            self.path.append("Forward\n")
            return
        self.path += getPathtoObject(nearestIncantation)
        self.path.append("Look\n")
        self.path.append("Incantation\n")

    def makeIncantationLevel3(self):
        print("INCANTE 3", file = self.sourceFile)
        if not self.haveBroadcast and not self.waitingForReponse:
            print("LA 1", file = self.sourceFile)
            self.path.append("Broadcast " + encrypt("Is anyone is level " + str(self.level) + " ?", ord(self.teamName[0])) + "\n")
            self.haveBroadcast = True
            self.waitingForReponse = True
        elif not self.canIncantation and not self.waitingForReponse:
            print("LA 2",  file = self.sourceFile)
            if self.nbFork < 1 and self.nbMatesAvailable < self.levelManager.matesNeeded[self.level + 1]:
                self.path.append("Fork\n")
                self.nbFork += 1
                print("FORK from " + self.debug + ", I'm level " + str(self.level))
            self.haveBroadcast = False
            self.waitingForReponse = False
        elif not self.waitingForReponse:
            print("HE CAN INCANT NOW", file = self.sourceFile)
            if self.toJoin:
                print("TO JOIN HERE", file = self.sourceFile)
                if self.levelManager.checkTileForIncanation(self.objectsAround[0], self.level + 1):
                    self.path = ["Incantation\n"]
                    return
                return
            if self.prepareIncantation:
                # remove unnecessary stones from the tile an set stone needed for incantation from the inventory to the tile
                print("Team " + self.teamName + " is preparing incantation", file = self.sourceFile)
                if self.levelManager.checkTileForIncanation(self.objectsAround[0], self.level + 1):
                    self.path = ["Incantation\n"]
                    return
                needed = self.levelManager.getDictfromLevel(self.level + 1)
                items = listToDict(self.objectsAround[0])
                for tmp in needed:
                    if tmp in items:
                        if items[tmp] < needed[tmp]:
                            for i in range(needed[tmp] - items[tmp]):
                                self.path.append("Set " + tmp + "\n")
                    else:
                        for i in range(needed[tmp]):
                            self.path.append("Set " + tmp + "\n")
                self.path.append("Look\n")
                self.seachFood = False
                if self.countLook >= 6:
                    self.path.insert(0, "Broadcast " + encrypt("Join me for level " + str(self.level + 1), ord(self.teamName[0])) + "\n")
                    self.countLook = 0
                else:
                    self.countLook += 1
                return
            val = self.levelManager.checkIfCanLevelUp(self.inventory, self.level + 1)
            if ("Broadcast " + encrypt("I'm coming to join you for level " + str(self.level + 1), ord(self.teamName[0])) + "\n") in self.path:
                return
            if val == True and not self.tosendJoin:
                print("HE BROADCAST", file = self.sourceFile)
                self.path = ["Look\n"]
                self.path.insert(0, "Broadcast " + encrypt("I have all stones for level " + str(self.level + 1), ord(self.teamName[0])) + "\n")
                return
            stonesNeeded = self.levelManager.getLevel[self.level + 1]
            take = False
            print("PATH la: ", self.path, file = self.sourceFile)
            self.path = []
            for stone in stonesNeeded:
                if stone in self.inventory and self.inventory[stone] >= checkNbElemInList(stonesNeeded, stone):
                    continue
                print("Objects: ", self.objectsAround, file = self.sourceFile)
                ifStone = getNearestObject(stone, self.objectsAround)
                print("Stone " + stone + " needed", file = self.sourceFile)
                if ifStone != None:
                    print("Stone " + stone + " found around", file = self.sourceFile)
                    self.path += getPathtoObject(ifStone)
                    self.path.append("Take " + stone + "\n")
                    take = True
                    break
            if not take:
                print("HEREEEEEEEE", file = self.sourceFile)
                self.path.append("Forward\n")
            else:
                self.path.append("Inventory\n")
            print("PATH la: ", self.path, file = self.sourceFile)

    def makeIncantationLevel4(self):
        pass

    def makeIncantationLevel5(self):
        pass

    def makeIncantationLevel6(self):
        pass

    def makeIncantationLevel7(self):
        pass

    def makeIncantationLevel8(self):
        pass

    def makeIncantation(self):
        switch = {
            2: self.makeIncantationLevel2,
            3: self.makeIncantationLevel3,
            4: self.makeIncantationLevel3,
            5: self.makeIncantationLevel3,
            6: self.makeIncantationLevel3,
            7: self.makeIncantationLevel3,
            8: self.makeIncantationLevel3
        }
        return switch.get(self.level + 1, lambda: "Invalid level")
