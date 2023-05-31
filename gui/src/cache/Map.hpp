/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#pragma once

#include "Tile.hpp"
#include "Teams.hpp"
#include "Trantorians.hpp"
#include <tuple>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class MapT
{
    private:
        int x;
        int y;
        std::map<std::tuple<double, double>, Tile> tile;
        std::vector<Teams> teams;
        std::vector<Trantorian> trantorians;
    public:
        MapT();
        ~MapT();
        void setX(int x);
        void setY(int y);
        void setTile(std::tuple<double, double> pos, Tile tile);
        int getX();
        int getY();
        Tile getTile(int x, int y);
        void addTeam(Teams team);
        void addTrantorian(Trantorian trantorian);
        void removeTrantorian(int id);
        void setTrantorianPos(int id, int x, int y, char orientation);
        void setTrantorianLvl(int id, int lvl);
        void setTrantorianStock(int id, int x, int y, Stock stock);
        void setTrantorianMessage(int id, std::string message);
        std::vector<Teams> getTeams();
        std::vector<Trantorian> getTrantorians();
};