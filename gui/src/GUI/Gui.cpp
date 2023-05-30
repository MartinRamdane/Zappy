/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Gui
*/

#include "Gui.hpp"

Gui::Gui(int port, std::string ip) : _socket(port, ip)
{
    this->_socket.connectToServer();
}

Gui::~Gui()
{
}

void Gui::loop()
{
    while (1) {
        this->_socket.socketSelect();
        if (this->_socket.getMessage() != "") {
            //TODO: parse message
            this->_socket.resetMessage();
        }
    }
}
