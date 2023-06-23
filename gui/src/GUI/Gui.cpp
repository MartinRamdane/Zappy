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
    this->p = Parsing();
}

Gui::~Gui()
{
}

void Gui::loop()
{
    while (1) {
        this->_socket.socketSelect();
        std::string msg = this->_socket.getMessage();
        if (msg != "") {
            if (msg == "WELCOME\n")
                _socket.sendToServer("GRAPHIC\n");
            else if (msg.back() == '\n') {
                p.parse(msg);
            }
            this->_socket.resetMessage();
        }
    }
}
