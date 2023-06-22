/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Gui
*/

#include "Gui.hpp"

Gui::Gui(int port, std::string ip)
{
    this->_display = std::make_unique<Display>(1920, 1080);
    this->_p = std::make_unique<Parsing>();
    this->_menu = std::make_unique<Menu>();
}

Gui::~Gui()
{
}

void Gui::socketThread()
{
    int port = 4242;
    std::string ip = "";
    this->_socket = std::make_unique<Socket>(port, ip);
    this->_socket->connectToServer();
    while (this->_display->getWindow()->isOpen()) {
        this->_socket->socketSelect();
        std::string msg = this->_socket->getMessage();
        if (msg != "") {
            if (msg == "WELCOME\n")
                this->_socket->sendToServer("GRAPHIC\n");
            else if (msg.back() == '\n')
                this->_p->parse(msg);
            this->_socket->resetMessage();
        }
        if (this->_display->getMessage() != "") {
            this->_socket->sendToServer(this->_display->getMessage());
            this->_display->resetMessage();
        }
    }
}

void Gui::displayThread()
{
    while (this->_display->getWindow()->isOpen()) {
        if (_isMenu) {
            this->_menu->render(*this->_display->getWindow());
            this->_menu->update();
            this->_menu->eventHandler(*this->_display->getWindow());
        } else {
            // std::thread socketThread(&Gui::socketThread, this);
            // socketThread.join();
            this->_display->update(this->_p->getMapPtr());
            this->_display->eventHandler(this->_p->getMap());
            this->_display->render();
        }
    }
}

void Gui::loop()
{

    std::thread displayThread(&Gui::displayThread, this);

    displayThread.join();
    this->_socket->sendToServer("QUIT\n");
    this->_socket->closeSocket();
}
