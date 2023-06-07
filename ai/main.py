#!/usr/bin/env python3

import sys
from Ai import Ai
import os
import multiprocessing
import random
import string

def print_help():
    print('USAGE: ./zappy_ai -p port -n name -h machine')
    print('\tport is the port number')
    print('\tname is the name of the team')
    print('\tmachine is the name of the machine; localhost by default')

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
    ai = Ai(name, machine, port, name)
    ai.joinGame()
    while True:
        canFork = ai.communication()
        if canFork:
            # FORK HERE
            p = multiprocessing.Process(target=ai_computation, args=("toto", machine, port, "toto"))
            p.start()
        canFork = False

def get_random_string(length):
    # choose from all lowercase letter
    letters = string.ascii_lowercase
    result_str = ''.join(random.choice(letters) for i in range(length))
    print("Random string of length", length, "is:", result_str)
    return result_str

def ai_computation(name, machine, port, teamName):
    # Code pour le traitement de l'IA forkée
    ai = Ai(name, machine, port, teamName)
    ai.joinGame()
    a = 0
    while True:
        canFork = ai.communication()
        if canFork:
            # FORK HERE
            tmp:str = "toto"
            p = multiprocessing.Process(target=ai_computation, args=(tmp, machine, port, tmp + str(a)))
            p.start()
            a += 1
        canFork = False


if __name__ == '__main__':
    main()
