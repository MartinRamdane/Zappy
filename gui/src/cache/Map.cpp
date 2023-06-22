/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#include "Map.hpp"

MapT::MapT()
{
}

MapT::~MapT()
{
}

void MapT::setX(int x)
{
    this->x = x;
}

void MapT::setY(int y)
{
    this->y = y;
}

void MapT::setTile(std::tuple<double, double> pos, Tile tile)
{
    this->tile[pos] = tile;
}

int MapT::getX()
{
    return (this->x);
}

int MapT::getY()
{
    return (this->y);
}

Tile MapT::getTile(int x, int y)
{
    return (this->tile[std::make_tuple(x, y)]);
}

void MapT::addTeam(Teams team)
{
    this->teams.push_back(team);
}

void MapT::addTrantorian(Trantorian trantorian)
{
    this->trantorians.push_back(trantorian);
}

std::vector<Teams> MapT::getTeams()
{
    return (this->teams);
}

std::vector<Trantorian> MapT::getTrantorians()
{
    return (this->trantorians);
}

void MapT::setTrantorianPos(int id, int x, int y, int orientation)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians[i].setX(x);
            this->trantorians[i].setY(y);
            this->trantorians[i].setOrientation(orientation);
        }
    }
}

void MapT::setTrantorianLvl(int id, int lvl)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians[i].setLvl(lvl);
            this->trantorians[i].setCanEvolve(false);
        }
    }
}

void MapT::setTrantorianStock(int id, int x, int y, Stock stock)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians[i].setX(x);
            this->trantorians[i].setY(y);
            this->trantorians[i].setStock(stock);
        }
    }
}

void MapT::removeTrantorian(int id)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians.erase(this->trantorians.begin() + i);
        }
    }
}

void MapT::setTrantorianMessage(int id, std::string message)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians[i].setMessage(message);
        }
    }
}

Trantorian MapT::getTrantorian(int id)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            return (this->trantorians[i]);
        }
    }
    return Trantorian();
}

void MapT::addEgg(Egg egg)
{
    this->eggs.push_back(egg);
}

void MapT::removeEgg(int e)
{
    for (int i = 0; i < this->eggs.size(); i++) {
        if (this->eggs[i].getId() == e) {
            this->eggs.erase(this->eggs.begin() + i);
        }
    }
}

void MapT::setHasHatched(int id)
{
    for (int i = 0; i < this->eggs.size(); i++) {
        if (this->eggs[i].getId() == id) {
            this->eggs[i].setHatched();
        }
    }
}

std::vector<Egg> MapT::getEggs()
{
    return (this->eggs);
}

void MapT::removeTeam(std::string team)
{
    for (int i = 0; i < this->teams.size(); i++) {
        if (this->teams[i].getName() == team) {
            this->teams.erase(this->teams.begin() + i);
        }
    }
}

void MapT::setFrequency(int frequency)
{
    this->frequency = frequency;
}

int MapT::getFrequency()
{
    return (this->frequency);
}

int MapT::getEggsFromPos(int x, int y)
{
    int num = 0;
    for (int i = 0; i < this->eggs.size(); i++) {
        if (this->eggs[i].getX() == x && this->eggs[i].getY() == y) {
            num++;
        }
    }
    return (num);
}

void MapT::setTrantorianCanEvolve(int id, bool canEvolve)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians[i].setCanEvolve(canEvolve);
        }
    }
}

void MapT::setTrantorianEjection(int id, bool ejecting)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians[i].setEjection(ejecting);
        }
    }
}

void MapT::setTrantorianDeath(int id)
{
    for (int i = 0; i < this->trantorians.size(); i++) {
        if (this->trantorians[i].getId() == id) {
            this->trantorians[i].setDeath();
        }
    }
}
