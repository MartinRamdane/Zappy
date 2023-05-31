from MyClient import Client
import sys

class Ai:
    def __init__(self, teamName, machine, port):
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

    def comunication(self):
        if self.path:
            self.message = self.path.pop(0)
        elif self.seachFood and not self.path:
            self.message = "Look\n"
        elif self.lookInventoryFood >= 3 and not self.path:
            self.message = "Inventory\n"
            self.lookInventoryFood = 0
        print("Send: " + self.message)
        self.client.send_message(self.message)
        self.receive = self.client.receive_message()
        self.parseCommands(self.message, self.receive)
        if not self.path:
            self.lookInventoryFood += 1
        self.message = "Look\n"

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

    def parseCommands(self, message, receive):
        print("Receive: " + receive)
        if message == "Inventory\n" and receive != "ko\n":
            inventory = self.getInventory(receive)
            if inventory["food"] < 5:
                self.seachFood = True
        elif message == "Look\n" and receive != "ko\n":
            getobjects = self.getObjectsAround(receive)
            if self.seachFood:
                nearestFood = self.getNearestObject("food", getobjects)
                if nearestFood is None:
                    self.path = ["Forward\n"]
                    return
                self.path = self.getPathtoObject(nearestFood, "food")
                self.seachFood = False
        elif message == "dead\n":
            sys.exit()

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

    def getPathtoObject(self, case, item):
        centers = [0, 2, 6, 12, 20, 30, 42, 56]
        path = []
        if case in centers:
            index = centers.index(case)
            for i in range(index):
                path.append("Forward\n")
            path.append("Take " + item + "\n")
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
        path.append("Take " + item + "\n")
        return path

    # def checkTileForIncantation(self, tile, level):
    #     match level:
    #         case 1:
    #             if len(tile) == 2 and "player" in tile and "linemate" in tile:
    #                 return True
    #         case _:
    #             return False
    #     return False
