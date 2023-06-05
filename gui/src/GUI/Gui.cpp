/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Gui
*/

#include "Gui.hpp"

Gui::Gui(int port, std::string ip) : _socket(port, ip), _display(1920, 1080), _p()
{
    this->_socket.connectToServer();
}

Gui::~Gui()
{
}

void Gui::socketThread()
{
    while (this->_display.getWindow()->isOpen()) {
        this->_socket.socketSelect();
        std::string msg = this->_socket.getMessage();
        // for (int i = 0; _p.getMap().getTrantorians().size() != i; i++) {
        //     std::string send = "ppo " + std::to_string(_p.getMap().getTrantorians()[i].getId()) + "\n";
        //     this->_socket.sendToServer(send.c_str());
        // }
        if (msg != "") {
            if (msg == "WELCOME\n")
                this->_socket.sendToServer("GRAPHIC\n");
            else if (msg.back() == '\n')
                this->_p.parse(msg);
            this->_socket.resetMessage();
        }
    }
}

void Gui::displayThread()
{
    while (this->_display.getWindow()->isOpen()) {
        this->_display.eventHandler(this->_p.getMap());
        this->_display.update(this->_p.getMap());
        this->_display.render();
    }
}

void Gui::loop()
{
    std::thread socketThread(&Gui::socketThread, this);
    std::thread displayThread(&Gui::displayThread, this);

    socketThread.join();
    displayThread.join();
    this->_socket.sendToServer("QUIT\n");
    this->_socket.closeSocket();
}
