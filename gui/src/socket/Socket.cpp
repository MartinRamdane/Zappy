/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Socket
*/

#include "Socket.hpp"

Socket::Socket(int port, std::string _ip)
{
    this->setPort(port);
    this->setMachine(_ip);
    this->createSocket();
    this->defineAddress();
}

Socket::~Socket()
{
    this->closeSocket();
}

void Socket::createSocket()
{
    int addrlen = sizeof(this->_address);
    this->_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (this->_socket == -1)
        throw gui::exception("Socket creation failed");
}

void Socket::defineAddress()
{
    this->_address.sin_family = AF_INET;
    this->_address.sin_port = htons(this->getPort());
    this->_address.sin_addr.s_addr = inet_addr(this->getMachine().c_str());
    if(this->_address.sin_addr.s_addr == INADDR_NONE)
        throw gui::exception("Invalid address");
}

void Socket::connectToServer()
{
    if (connect(this->_socket, (struct sockaddr *)&this->_address, sizeof(this->_address)) < 0) {
        this->_connected = false;
    } else {
        this->_connected = true;
    }
}

void Socket::sendToServer(std::string message)
{
    if (send(this->_socket, message.c_str(), message.length(), 0) < 0)
        throw gui::exception("Send failed");
}

std::string Socket::receiveFromServer()
{
    char buffer[2] = {0};
    std::string message = "";

    if (recv(this->_socket, buffer, 1, 0) < 0)
        throw gui::exception("Read failed");
    message = std::string(buffer);
    return message;
}

void Socket::socketSelect()
{
    FD_ZERO(&this->_readfds);
    FD_SET(this->_socket, &this->_readfds);
    this->_tv.tv_sec = 0;
    this->_tv.tv_usec = 10;
    if (select(this->_socket + 1, &this->_readfds, NULL, NULL, &this->_tv) < 0)
        throw gui::exception("Select failed");
    if (FD_ISSET(this->_socket, &this->_readfds)) {
        this->_message.append(this->receiveFromServer());
    }
}

void Socket::closeSocket()
{
    close(this->_socket);
}

void Socket::setMachine(std::string machine)
{
    this->_machine = machine;
}

void Socket::setPort(int port)
{
    this->_port = port;
}

std::string Socket::getMachine() const
{
    return this->_machine;
}

int Socket::getPort() const
{
    return this->_port;
}

std::string Socket::getMessage() const
{
    if (this->_message.empty())
        return "";
    else if (this->_message.back() != '\n')
        return "";
    else {
        return this->_message;
    }
}

void Socket::resetMessage()
{
    this->_message.clear();
}
