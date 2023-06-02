/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Gui
*/

#pragma once

#include <iostream>
#include <string>
#include "../SFML/Display.hpp"
#include "../socket/Socket.hpp"
#include "../parser/Parsing.hpp"
#include "../cache/Map.hpp"

class Gui {
    public:
        Gui(int port, std::string ip);
        ~Gui();
        void loop();

    protected:
    private:
        Socket _socket;
        std::string _message;
        Display _display;
        Parsing _p;
};
