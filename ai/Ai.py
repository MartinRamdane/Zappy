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
        self.tiles = {0: [], 1: ["Forward\n"], 2: ["Forward\n", "Left\n", "Forward\n"], 3: ["Left\n", "Forward\n"], 4: ["Left\n", "Forward\n", "Left\n", "Forward\n"], 5: ["Left\n", "Left\n", "Forward\n"], 6: ["Left\n", "Left\n", "Forward\n", "Left\n", "Forward\n"], 7: ["Right\n", "Forward\n"], 8: ["Forward\n", "Right\n", "Forward\n"]}
        self.sourceFile = open(self.teamName + '.log', 'w')
        self.inventory = {}
        self.canFork = False
        self.objectsAround = []
        self.levelManager = Level()
        self.nbFork = 0
        self.lookInventoryFood = 0

    def joinGame(self):
        self.client = Client(self.machine, self.port)
        self.client.connect()
        receive = self.client.receive_message()
        if receive == "WELCOME\n":
            self.client.send_message(self.teamName + "\n")
        receive = self.client.receive_message()

    def communication(self):
        message = "Take food\n"
        receive = ""
        print ("lookInventoryFood = ", self.lookInventoryFood, file = self.sourceFile)
        print ("searchFood = ", self.seachFood, file = self.sourceFile)
        print ("PATH before send: ", self.path, file = self.sourceFile)
        self.canFork = False
        if self.lookInventoryFood >= 4:
            message = "Inventory\n"
            self.lookInventoryFood = 0
        elif self.seachFood:
            message = "Look\n"
        elif self.path:
            message = self.path.pop(0)
        print("Send to " + self.teamName + ": " + message, file = self.sourceFile)
        self.client.send_message(message)
        receive = self.client.receive_message()
        print("Receive: ", receive, file = self.sourceFile)
        tmp = receive.split('\n')
        for item in tmp:
            if item != "":
                self.parseReponse(item)
        self.lookInventoryFood += 1
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
        if self.inventory["food"] < 5:
            self.seachFood = True

    def look(self, receive):
        self.getObjectsAround(receive)
        if self.path and self.path[-1] == "Incantation\n":
            if not self.levelManager.checkTileForIncanation(self.objectsAround[0], self.level + 1):
                self.path = []
        if self.seachFood:
            self.getFood()
        elif not self.path:
            self.makeIncantation()()

    def elevation(self, receive):
        pass

    def levelUpdating(self, receive):
        self.level = int(receive[15])
        print("Level: " + str(self.level), file = self.sourceFile)
        self.nbFork = 0
        self.path = []
        print ("LEVEL 2 DONE", file = self.sourceFile)
        sys.exit(0)

    def ReceiveMessage(self, receive):
        pass

    def other(self, receive):
        if not self.path:
            self.path = ["Look\n"]

    def dead(self, receive):
        print("Team " + self.teamName + " is dead")
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
        print("Receive to " + self.teamName + ": " + receive, file = self.sourceFile)
        reponseType = getTypeOfReponse(receive)
        self.getCommand(reponseType)(receive)

    def makeIncantationLevel2(self):
        nearestIncantation = getNearestObject("linemate", self.objectsAround)
        if nearestIncantation is None:
            self.path.append("Forward\n")
            return
        self.path += getPathtoObject(nearestIncantation)
        nbLinemate = 0
        for item in self.objectsAround[nearestIncantation]:
            if item == "linemate":
                if nbLinemate >= 1:
                    self.path.append("Take " + item + "\n")
                nbLinemate += 1
            elif item != "player" and item != "linemate":
                self.path.append("Take " + item + "\n")
        self.path.append("Look\n")
        self.path.append("Incantation\n")

    def makeIncantationLevel3(self):
        pass

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
            4: self.makeIncantationLevel4,
            5: self.makeIncantationLevel5,
            6: self.makeIncantationLevel6,
            7: self.makeIncantationLevel7,
            8: self.makeIncantationLevel8
        }
        return switch.get(self.level + 1, lambda: "Invalid level")
