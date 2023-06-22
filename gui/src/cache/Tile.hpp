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
#include <vector>
#include <map>

class Tile
{
    private:
        Stock stock;
        int lvl;
        std::vector<int> players;
    public:
        Tile();
        Tile(Stock stock);
        ~Tile();
        void setStock(Stock stock);
        void setLvlEvo(int lvl);
        void setPlayers(std::vector<int> players);
        Stock getStock();
        int getLvlEvo();
        std::map<std::string, int> getStocks();
        std::vector<int> getPlayers();
        int getNbrTotalGems();
};
