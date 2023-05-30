/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Socket
*/

#pragma once

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../exception.hpp"

class Socket {
    public:
        Socket(int socket, std::string ip);
        ~Socket();
        void createSocket();
        void closeSocket();
        void setPort(int port);
        void setMachine(std::string machine);
        void defineAddress();
        int getPort() const;
        std::string getMachine() const;
        void connectToServer();
        void sendToServer(std::string message);
        std::string receiveFromServer();
        void socketSelect();
        std::string getMessage() const;

    protected:
    private:
        int _socket;
        int _port;
        std::string _machine;
        struct sockaddr_in _address;
        fd_set _readfds;
        struct timeval _tv;
        std::string _message;
};
