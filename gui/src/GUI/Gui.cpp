/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Gui
*/

#include "Gui.hpp"

Gui::Gui()
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
    while(this->_isMenu) {
        if (!this->_display->getWindow()->isOpen())
            return;
    }
    this->_socket = std::make_unique<Socket>(_port, _ip);
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
            if (this->_menu->update() == 1) {
                _ip = this->_menu->getIp();
                _port = this->_menu->getPort();
                std::string command = "nc -zv " + std::string(_ip) + " " + std::to_string(_port);
                int output = std::system(command.c_str());
                if (output == 0) {
                    _isMenu = false;
                } else {
                    this->_menu->setState(MenuState::GAME);
                }
                this->_display->getWindow()->clear();
            } else
                this->_menu->eventHandler(*this->_display->getWindow());
        } else {
            this->_display->update(this->_p->getMapPtr());
            this->_display->eventHandler(this->_p->getMap());
            this->_display->render();
        }
    }
}

void Gui::loop()
{

    std::thread displayThread(&Gui::displayThread, this);
    std::thread socketThread(&Gui::socketThread, this);
    socketThread.join();
    displayThread.join();
    if (this->_isMenu)
        return;
    this->_socket->sendToServer("QUIT\n");
    this->_socket->closeSocket();
}
