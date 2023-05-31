/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Gui
*/

#include "Gui.hpp"

Gui::Gui(int port, std::string ip) : _socket(port, ip), _display(1920, 1080)
{
    this->_socket.connectToServer();
}

Gui::~Gui()
{
}

void Gui::loop()
{
    while (this->_display.getWindow()->isOpen()) {
        this->_socket.socketSelect();
        if (this->_socket.getMessage() != "") {
            //TODO: parse message
            this->_socket.resetMessage();
        }
        this->_display.eventHandler();
        this->_display.render();
    }
}
