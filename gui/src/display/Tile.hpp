/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Tile
*/

#pragma once

#include "Stock.hpp"

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Tile
{
    public:
        Tile();
        ~Tile();
    private:
        Stock stock;
};

