/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Gui
*/

#pragma once

#include <iostream>
#include <string>
#include "../menu/Menu.hpp"
#include "../SFML/Display.hpp"
#include "../socket/Socket.hpp"
#include "../parser/Parsing.hpp"
#include "../cache/Map.hpp"
#include <thread>

class Gui {
    public:
        Gui();
        ~Gui();
        void loop();
        void socketThread();
        void displayThread();

    protected:
    private:
        std::unique_ptr<Socket> _socket = nullptr;
        std::string _message;
        std::unique_ptr<Display> _display = nullptr;
        std::unique_ptr<Parsing> _p = nullptr;
        bool _isMenu = true;
        std::unique_ptr<Menu> _menu = nullptr;
        std::string _ip;
        int _port;
};
