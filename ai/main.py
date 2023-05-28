#!/usr/bin/env python3

import sys

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

if __name__ == '__main__':
    main()
