#!/usr/bin/env python3

import sys
from MyClient import Client
from Ai import Ai


def print_help():
    print('USAGE: ./zappy_ai -p port -n name -h machine')
    print('\tport is the port number')
    print('\tname is the name of the team')
    print('\tmachine is the name of the machine; localhost by default')

def mainloop(machine, port, name):
    client = Client(machine, port)
    client.connect()
    ai = Ai(name)
    message = client.receive_message()
    if message == "WELCOME\n":
        client.send_message(name + "\n")
    message = client.receive_message()
    arr = message.split('\n')
    ai.setAvaibleSlots(int(arr[0]))
    ai.setMapSize(arr[1])
    print("Name: " + ai.teamName)
    print("Slots: " + str(ai.avaibleSlots))
    print("Map size: " + str(ai.mapSize))
    while True:
        message = client.receive_message()

def main():
    if len(sys.argv) == 2 and sys.argv[1] == '-help':
        print_help()
        sys.exit(0)
    if len(sys.argv) != 7:
        print_help()
        sys.exit(84)
    if sys.argv[1] != '-p' or sys.argv[3] != '-n' or sys.argv[5] != '-h':
        print_help()
        sys.exit(84)
    port = int(sys.argv[2])
    name = sys.argv[4]
    machine = sys.argv[6]
    mainloop(machine, port, name)

if __name__ == '__main__':
    main()
