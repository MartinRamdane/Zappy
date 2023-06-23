
class Level():
    def __init__(self):
        self.getLevel = {1: [],
                    2: ["linemate"],
                    3: ["linemate", "deraumere", "sibur"],
                    4: ["linemate", "linemate", "phiras", "phiras", "sibur"],
                    5: ["linemate", "deraumere", "sibur", "sibur", "phiras"],
                    6: ["linemate", "deraumere", "deraumere", "sibur", "mendiane", "mendiane", "mendiane"],
                    7: ["linemate", "deraumere", "deraumere", "sibur", "sibur", "sibur", "phiras"],
                    8: ["linemate", "linemate", "deraumere", "deraumere", "sibur", "sibur", "mendiane", "mendiane",  "phiras",  "phiras", "thystame"]}
        self.matesNeeded = {1: 1, 2: 1, 3: 2, 4: 2, 5: 4, 6: 4, 7: 6, 8: 6}

    def checkIfCanLevelUp(self, inventory, level):
        tohave = {}
        for i in self.getLevel[level]:
            if i in tohave:
                tohave[i] += 1
            else:
                tohave[i] = 1
        for i in tohave:
            if i not in inventory or inventory[i] < tohave[i]:
                return False
        return True

    def getNbElemOnTile(self, tile, elem):
        nb = 0
        for i in tile:
            if i == elem:
                nb += 1
        return nb

    def getNbElemForLevel(self, level, item):
        nb = 0
        for i in self.getLevel[level]:
            if i == item:
                nb += 1
        return nb


    def checkTileForIncanation(self, tile, level):
        nbPlayersOnTile = self.getNbElemOnTile(tile, "player")
        if nbPlayersOnTile < self.matesNeeded[level]:
            return False
        for i in self.getLevel[level]:
            nbElemForLevel = self.getNbElemForLevel(level, i)
            if self.getNbElemOnTile(tile, i) < nbElemForLevel:
                return False
        return True

    def getDictfromLevel(self, level):
        tohave = {}
        for i in self.getLevel[level]:
            if i in tohave:
                tohave[i] += 1
            else:
                tohave[i] = 1
        return tohave