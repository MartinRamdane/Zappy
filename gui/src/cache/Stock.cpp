/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** stock
*/

#include "Stock.hpp"

Stock::Stock(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
{
    this->food = food;
    this->linemate = linemate;
    this->deraumere = deraumere;
    this->sibur = sibur;
    this->mendiane = mendiane;
    this->phiras = phiras;
    this->thystame = thystame;
}

Stock::Stock(/* args */)
{
}

Stock::~Stock()
{
}

int Stock::getTotalGem()
{
    return (this->linemate + this->deraumere + this->sibur + this->mendiane + this->phiras + this->thystame);
}
