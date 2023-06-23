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
        Socket(int port, std::string _ip);
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
        void resetMessage();
        bool getConnected() const{ return _connected;};
        void initialize(int port, std::string _ip);

    protected:
    private:
        int _socket;
        int _port;
        std::string _machine;
        struct sockaddr_in _address;
        fd_set _readfds;
        std::string _message;
        struct timeval _tv;
        bool _connected = false;
};
