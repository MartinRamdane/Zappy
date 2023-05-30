/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#pragma once

#include "Tile.hpp"
#include <tuple>
#include <map>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Display
{
    public:
        Display();
        ~Display();
    private:
        std::map<std::tuple<double, double>, Tile> tile;
};