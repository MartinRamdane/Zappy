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
            gui = std::make_unique<Gui>();
        else
            gui = std::make_unique<Gui>();
    } catch (const gui::exception &e) {
        std::cerr << e.what() << std::endl;
        return (e.getErrorCode());
    }
    gui->loop();
    return (0);
}
