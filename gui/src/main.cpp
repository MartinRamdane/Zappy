/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** main
*/

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include "exception.hpp"
#include "GUI/Gui.hpp"

bool isNumber(const std::string &str)
{
    return (str.find_first_not_of("0123456789") == std::string::npos);
}

void argsCheck(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
        std::cout << "\tport\tis the port number" << std::endl;
        std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
        exit(0);
    } else if (ac == 3) {
        if (strcmp(av[1], "-p") == 0 && isNumber(av[2]) == false) {
            throw gui::exception("The port must be a number");
        } else if (strcmp(av[1], "-p") != 0) {
            throw gui::exception("Invalid argument\nTry ./zappy_gui -h");
        }
    } else if (ac == 5) {
        if (strcmp(av[1], "-p") == 0 && isNumber(av[2]) == false) {
            throw gui::exception("The port must be a number");
        }
        if (strcmp(av[3], "-h") != 0) {
            throw gui::exception("Invalid argument\nTry ./zappy_gui -h");
        }
    } else {
        throw gui::exception("Invalid arguments\nTry ./zappy_gui -h");
    }
}

int main(int ac, char **av)
{
    try {
        argsCheck(ac, av);
    } catch (const gui::exception &e) {
        std::cerr << e.what() << std::endl;
        return (e.getErrorCode());
    }
    std::unique_ptr<Gui> gui;
    try {
        if (ac == 3)
            gui = std::make_unique<Gui>(atoi(av[2]), "127.0.0.1");
        else
            gui = std::make_unique<Gui>(atoi(av[2]), av[4]);
    } catch (const gui::exception &e) {
        std::cerr << e.what() << std::endl;
        return (e.getErrorCode());
    }
    gui->loop();
    return (0);
}
