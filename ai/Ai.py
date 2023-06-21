from MyClient import Client
from Level import Level
from Utilities import *
import sys

class Ai:
    def __init__(self, teamName, machine, port):
        self.teamName = teamName
        self.machine = machine
        self.port = port
        self.seachFood = False
        self.path = []
        self.level = 1
        self.client = None
        self.tiles = {0: ["Look\n"], 1: ["Forward\n"], 2: ["Forward\n", "Left\n", "Forward\n"], 3: ["Left\n", "Forward\n"], 4: ["Left\n", "Forward\n", "Left\n", "Forward\n"], 5: ["Left\n", "Left\n", "Forward\n"], 6: ["Left\n", "Left\n", "Forward\n", "Left\n", "Forward\n"], 7: ["Right\n", "Forward\n"], 8: ["Forward\n", "Right\n", "Forward\n"]}
        self.inventory = {}
        self.canFork = False
        self.objectsAround = []
        self.levelManager = Level()
        self.nbFork = 0
        self.lookInventoryFood = 7
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
        self.takeFood = False

    def joinGame(self):
        self.client = Client(self.machine, self.port)
        self.client.connect()
        receive = self.client.receive_message()
        if receive == "WELCOME\n":
            self.client.send_message(self.teamName + "\n")
        receive = self.client.receive_message()

    def communication(self):
        receive = ""
        self.canFork = False
        if not self.skipSend and not self.elevationInProgress:
            self.message = "Take food\n"
            if not self.inventory:
                self.message = "Inventory\n"
            elif self.inventory["food"] < 25 and self.level == 1 and not self.seachFood and not self.takeFood:
                self.path = []
                self.message = "Inventory\n"
            elif self.lookInventoryFood >= 8 and not self.prepareIncantation and not self.toJoin:
                self.message = "Inventory\n"
                self.lookInventoryFood = 0
            elif self.seachFood and not self.path and not self.prepareIncantation:
                self.message = "Look\n"
            elif self.path:
                self.message = self.path.pop(0)
            if "I'm coming to join you for level " in decrypt(self.message, ord(self.teamName[0])):
                self.tosendJoin = True
            elif "I have all stones for level " in decrypt(self.message, ord(self.teamName[0])):
                self.haveStones = True
            elif "Is anyone is level" in decrypt(self.message, ord(self.teamName[0])) or "Yes I'm level" in decrypt(self.message, ord(self.teamName[0])):
                self.askForLevel = True
            self.client.send_message(self.message)
        receive = self.client.receive_message()
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
            self.skipSend = False
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
        self.takeFood = True
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
        if self.level == 1 and self.inventory["food"] < 25:
            self.seachFood = True
        if self.inventory["food"] < 25 and not "Incantation\n" in self.path:
            self.seachFood = True

    def look(self, receive):
        self.getObjectsAround(receive)
        if self.count >= 14:
            self.count = 0
            self.waitingForReponse = False
            if self.nbMatesAvailable >= self.levelManager.matesNeeded[self.level + 1]:
                self.canIncantation = True
                self.nbMatesAvailable = 1
        if self.path and self.path[-1] == "Incantation\n":
            if not self.levelManager.checkTileForIncanation(self.objectsAround[0], self.level + 1):
                if self.level == 1 and checkNbElemInList(self.objectsAround[0], "player") > 1:
                    self.path = ["Eject\n", "Incantation\n"]
                else:
                    self.path = []
        if self.seachFood:
            self.getFood()
        else:
            self.takeFood = False
            self.makeIncantation()()

    def elevation(self, receive):
        self.elevationInProgress = True
        if self.lastReceive != "Elevation underway":
            self.skipSend = True

    def levelUpdating(self, receive):
        self.level = int(receive[15])
        self.nbFork = 0
        self.path = []
        self.haveBroadcast = False
        self.waitingForReponse = False
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

    def ReceiveMessage(self, receive):
        self.skipSend = True
        tmpList = receive.split(",")
        decrypted = decrypt(tmpList[1], ord(self.teamName[0]))
        self.count = 0
        mess = tmpList[0].split(" ")
        if "Is anyone is level" in decrypted:
            code = decrypted.split(" ")
            wantedLevel = int(code[5])
            if self.level == wantedLevel:
                self.count = 0
                if not self.askForLevel and not ("Broadcast " + encrypt("Yes I'm level " + str(self.level), ord(self.teamName[0])) + "\n") in self.path:
                    encode = encrypt("Yes I'm level " + str(self.level), ord(self.teamName[0]))
                    self.path.insert(0, "Broadcast " + encode + "\n")
                    self.askForLevel = True
                    self.haveBroadcast = True
                    self.waitingForReponse = True
                self.nbMatesAvailable += 1
                if self.nbMatesAvailable >= self.levelManager.matesNeeded[self.level + 1]:
                    self.canIncantation = True
                    self.nbMatesAvailable = 1
                    self.waitingForReponse = False
        if "Yes I'm level" in decrypted:
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
                self.path = []
                food = int(tmp[9])
                if (not self.toJoin or ("I'm coming to join you for level " + str(self.level + 1) + "\n") in self.path) and not self.tosendJoin:
                    tmp = False
                    if self.haveStones:
                        if food > self.inventory["food"]:
                            tmp = True
                    else:
                        tmp = True
                    if tmp:
                        self.path.append("Broadcast " + encrypt("I'm coming to join you for level " + str(self.level + 1), ord(self.teamName[0])) + "\n")
                        self.path.append("Inventory\n")
        if "Join me for level" in decrypted:
            tmp = decrypted.split(" ")
            wantedLevel = int(tmp[5])
            if wantedLevel == self.level + 1:
                self.count = 0
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
            wantedLevel = int(tmp[8])
            if wantedLevel == self.level + 1:
                self.nbMatesAvailableForIncantation += 1
                if self.nbMatesAvailableForIncantation >= self.levelManager.matesNeeded[self.level + 1] and self.haveStones and not self.tosendJoin:
                    self.path = ["Broadcast " + encrypt("Join me for level " + str(self.level + 1), ord(self.teamName[0])) + "\n"]
                    self.prepareIncantation = True
                    self.seachFood = False
                    self.waitingForReponse = False
                    self.canIncantation = True

    def other(self, receive):
        if self.elevationInProgress and "ko" in receive:
            self.path = []
            self.path.append("Look\n")
            self.elevationInProgress = False
            self.skipSend = False
        if self.message == "Fork\n" and receive == "ok":
            self.canFork = True
        if not self.path:
            self.path = ["Look\n"]

    def dead(self, receive):
        sys.exit(0)

    def connected(self, receive):
        if int(receive) > 0:
            self.canFork = True
        elif self.nbFork < 1:
            self.path.append("Fork\n")
        self.nbFork += 1
        self.askForLevel = False

    def eject(self, receive):
        self.path = []
        self.elevationInProgress = False
        self.skipSend = False

    def getCommand(self,case):
        switch = {
            Type.INVENTORY: self.getInventory,
            Type.LOOK: self.look,
            Type.ELEVATION: self.elevation,
            Type.LEVELUPDATING: self.levelUpdating,
            Type.MESSAGE: self.ReceiveMessage,
            Type.OTHER: self.other,
            Type.DEAD: self.dead,
            Type.CONNECTED: self.connected,
            Type.EJECT: self.eject
        }
        return switch.get(case, lambda: "Invalid type")

    def parseReponse(self, receive):
        self.skipSend = False
        reponseType = getTypeOfReponse(receive)
        if (self.elevationInProgress and reponseType != Type.LEVELUPDATING and reponseType != Type.DEAD and reponseType != Type.ELEVATION and reponseType != Type.OTHER):
            return
        self.getCommand(reponseType)(receive)

    def makeIncantationLevel2(self):
        nearestIncantation = getNearestObject("linemate", self.objectsAround)
        if nearestIncantation is None:
            self.path.append("Forward\n")
            return
        self.path += getPathtoObject(nearestIncantation)
        if "Forward\n" in self.path:
            self.path.append("Look\n")
        self.path.append("Incantation\n")

    def makeIncantationOtherLevels(self):
        if not self.haveBroadcast and not self.waitingForReponse:
            self.path.append("Broadcast " + encrypt("Is anyone is level " + str(self.level) + " ?", ord(self.teamName[0])) + "\n")
            self.haveBroadcast = True
            self.waitingForReponse = True
        elif not self.canIncantation and not self.waitingForReponse:
            if self.nbFork < 1 and self.nbMatesAvailable < self.levelManager.matesNeeded[self.level + 1]:
                self.path.append("Connect_nbr\n")
            self.haveBroadcast = False
            self.waitingForReponse = False
        elif not self.waitingForReponse:
            if self.toJoin:
                if self.levelManager.checkTileForIncanation(self.objectsAround[0], self.level + 1):
                    self.path = ["Incantation\n"]
                    return
                if self.count >= 12:
                    self.count = 0
                    self.haveBroadcast = False
                    self.waitingForReponse = False
                    self.canIncantation = False
                    self.toJoin = False
                    self.prepareIncantation = False
                    self.nbMatesAvailable = 1
                    self.tosendJoin = False
                    self.haveStones = False
                    self.nbMatesAvailableForIncantation = 1
                    self.askForLevel = False
                return
            if self.prepareIncantation:
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
                self.path = ["Look\n"]
                self.path.insert(0, "Broadcast " + encrypt("I have all stones for level " + str(self.level + 1) + " food " + str(self.inventory["food"]), ord(self.teamName[0])) + "\n")
                return
            stonesNeeded = self.levelManager.getLevel[self.level + 1]
            take = False
            if ("Broadcast " + encrypt(("Yes I'm level " + str(self.level) + "\n"), ord(self.teamName[0]))) in self.path:
                self.path = [encrypt("Yes I'm level " + str(self.level), ord(self.teamName[0])) + "\n"]
            else:
                self.path = []
            for stone in stonesNeeded:
                if stone in self.inventory and self.inventory[stone] >= checkNbElemInList(stonesNeeded, stone):
                    continue
                ifStone = getNearestObject(stone, self.objectsAround)
                if ifStone != None:
                    self.path += getPathtoObject(ifStone)
                    self.path.append("Take " + stone + "\n")
                    take = True
                    break
            if not take:
                self.path.append("Forward\n")
            else:
                self.path.append("Inventory\n")

    def makeIncantation(self):
        if self.level + 1 == 2:
            return self.makeIncantationLevel2
        else:
            return self.makeIncantationOtherLevels
