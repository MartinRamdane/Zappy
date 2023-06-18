/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Trantorians
*/

#pragma once

#include "Stock.hpp"
#include "Teams.hpp"
#include <map>
#include <string>

class Trantorian
{
    private:
        Stock stock;
        int id;
        int orientation;
        int lvl;
        bool canEvolve;
        int x;
        int y;
        std::string team;
        std::string message;
        bool ejecting = false;
        bool death = false;

    public:
        Trantorian();
        Trantorian(Stock stock, int id, int orientation, int lvl, bool canEvolve, int x, int y, std::string team);
        ~Trantorian();
        void setStock(Stock stock);
        void setId(int id);
        void setOrientation(int orientation);
        void setLvl(int lvl);
        void setCanEvolve(bool canEvolve);
        void setX(int x);
        void setY(int y);
        void setTeam(std::string team);
        void setMessage(std::string message);
        Stock getStock();
        int getId();
        int getOrientation();
        int getLvl();
        bool getCanEvolve();
        int getX();
        int getY();
        std::string getTeam();
        std::string getMessage();
        int getLevel();
        void setEjection(bool ejecting);
        bool getEjection();
        void setDeath();
        bool getDeath();
        std::map<std::string, int> getStocks();
};
