/*
** EPITECH PROJECT, 2022
** gui
** File description:
** Teams.cpp
*/

#include "Teams.hpp"

Teams::Teams(std::string name, int nb_eggs)
{
    this->name = name;
    this->nb_eggs = nb_eggs;
}

Teams::Teams()
{
    this->name = "";
    this->nb_eggs = 0;
}

Teams::~Teams()
{
}

void Teams::setName(std::string name)
{
    this->name = name;
}

void Teams::setNbSlot(int nb_slot)
{
    this->nb_eggs = nb_slot;
}

std::string Teams::getName()
{
    return (this->name);
}

int Teams::getNbSlot()
{
    return (this->nb_eggs);
}
