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