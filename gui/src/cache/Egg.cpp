/*
** EPITECH PROJECT, 2022
** gui
** File description:
** egg.cpp
*/

#include "Egg.hpp"

Egg::Egg(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
}

Egg::~Egg()
{
}

void Egg::setId(int id)
{
    this->id = id;
}

int Egg::getId()
{
    return (this->id);
}

void Egg::setX(int x)
{
    this->x = x;
}

int Egg::getX()
{
    return (this->x);
}

void Egg::setY(int y)
{
    this->y = y;
}

int Egg::getY()
{
    return (this->y);
}

void Egg::setHatched()
{
    this->hatched = true;
}

bool Egg::getHatched()
{
    return (this->hatched);
}
