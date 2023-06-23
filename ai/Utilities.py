from enum import Enum

class Type(Enum):
    INVENTORY = 1
    LOOK = 2
    ELEVATION = 3
    LEVELUPDATING = 4
    MESSAGE = 5
    OTHER = 6
    DEAD = 7
    CONNECTED = 8
    EJECT = 9

class Message(Enum):
    LEVELASKED = 1
    LEVELANSWER = 2
    ALLSTONES = 3
    JOINME = 4
    COMINGJOIN = 5

def getTypeOfMessage(message, key) -> Message:
    tmpList = message.split(",")
    decrypted = decrypt(tmpList[1], key)
    if "Is anyone is level" in decrypted:
        return Message.LEVELASKED
    if "Yes I'm level" in decrypted:
        return Message.LEVELANSWER
    if "I have all stones for level" in decrypted:
        return Message.ALLSTONES
    if "Join me for level" in decrypted:
        return Message.JOINME
    if "I'm coming to join you for level" in decrypted:
        return Message.COMINGJOIN
    return None

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
    if receive.isdigit():
        return Type.CONNECTED
    if "eject" in receive:
        return Type.EJECT
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

def checkNbElemInList(liste, elem):
    nb = 0
    for item in liste:
        if item == elem:
            nb += 1
    return nb

def encrypt(message, key):
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

def decrypt(message, key):
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

def listToDict(liste):
    dico = {}
    for item in liste:
        if item in dico:
            dico[item] += 1
        else:
            dico[item] = 1
    return dico