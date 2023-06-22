#!/usr/bin/env python3

import sys
from Ai import Ai
import os
import multiprocessing
import random

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
    ai = Ai(name, machine, port)
    ai.joinGame()
    while True:
        canFork = ai.communication()
        if canFork:
            p = multiprocessing.Process(target=ai_computation, args=(name, machine, port))
            p.start()
        canFork = False

def ai_computation(name, machine, port):
    ai = Ai(name, machine, port)
    ai.joinGame()
    while True:
        canFork = ai.communication()
        if canFork:
            p = multiprocessing.Process(target=ai_computation, args=(name, machine, port))
            p.start()
        canFork = False


if __name__ == '__main__':
    main()
