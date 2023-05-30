
class Ai:
    def __init__(self, teamName):
        self.teamName = teamName
        self.mapSize = (0, 0)
        self.avaibleSlots = 0

    def setMapSize(self, arr):
        tmp = arr.split(' ')
        self.mapSize = (int(tmp[0]), int(tmp[1]))

    def setAvaibleSlots(self, slots):
        self.avaibleSlots = slots
