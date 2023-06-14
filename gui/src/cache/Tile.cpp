/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Tile
*/

#include "Tile.hpp"

Tile::Tile(/* args */)
{
}

Tile::Tile(Stock stock)
{
    this->stock = stock;
}

Tile::~Tile()
{
}

void Tile::setStock(Stock stock)
{
    this->stock = stock;
}

Stock Tile::getStock()
{
    return (this->stock);
}

void Tile::setLvlEvo(int lvl)
{
    this->lvl = lvl;
}

int Tile::getLvlEvo()
{
    return (this->lvl);
}

void Tile::setPlayers(std::vector<int> players)
{
    this->players = players;
}

std::vector<int> Tile::getPlayers()
{
    return (this->players);
}

int Tile::getNbrTotalGems()
{
    int nbr = 0;

    nbr += stock.linemate;
    nbr += stock.deraumere;
    nbr += stock.sibur;
    nbr += stock.mendiane;
    nbr += stock.phiras;
    nbr += stock.thystame;
    nbr += stock.food;
    return (nbr);
}

std::map<std::string, int> Tile::getStocks()
{
    std::map<std::string, int> stocks;

    if (this->stock.food != 0) {
        stocks["food"] = this->stock.food;
    }
    if (this->stock.linemate != 0) {
        stocks["linemate"] = this->stock.linemate;
    }
    if (this->stock.deraumere != 0) {
        stocks["deraumere"] = this->stock.deraumere;
    }
    if (this->stock.sibur != 0) {
        stocks["sibur"] = this->stock.sibur;
    }
    if (this->stock.mendiane != 0) {
        stocks["mendiane"] = this->stock.mendiane;
    }
    if (this->stock.phiras != 0) {
        stocks["phiras"] = this->stock.phiras;
    }
    if (this->stock.thystame != 0) {
        stocks["thystame"] = this->stock.thystame;
    }
    return (stocks);
}