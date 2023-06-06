from enum import Enum

class Type(Enum):
    INVENTORY = 1
    LOOK = 2
    ELEVATION = 3
    LEVELUPDATING = 4
    MESSAGE = 5
    OTHER = 6
    DEAD = 7

def getTypeOfReponse(receive) -> Type:
    if receive == "dead":
        return Type.DEAD
    if receive == "Elevation underway":
        return Type.ELEVATION
    if "Current level: " in receive:
        return Type.LEVELUPDATING
    if "message" in receive:
        return Type.MESSAGE
    if receive[0] == '[':
        if any(char.isdigit() for char in receive):
            return Type.INVENTORY
        else:
            return Type.LOOK
    return Type.OTHER

def getNearestObject(name, objects):
    indexes = []
    for i, sous_liste in enumerate(objects):
        if name in sous_liste:
            indexes.append(i)
    if not indexes:
        return None
    return min(indexes)

def getNearestNumberInList(number, liste):
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

def getPathtoObject(case):
    centers = [0, 2, 6, 12, 20, 30, 42, 56]
    path = []
    if case in centers:
        index = centers.index(case)
        for i in range(index):
            path.append("Forward\n")
        return path
    nearestNumber = getNearestNumberInList(case, centers)
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