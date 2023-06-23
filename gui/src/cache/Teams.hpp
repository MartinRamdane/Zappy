/*
** EPITECH PROJECT, 2022
** gui
** File description:
** Teams.hpp
*/

#pragma once

#include <string>

class Teams
{
    private:
        std::string name;
        int nb_eggs;
    public:
        Teams(std::string name, int nb_eggs);
        Teams();
        ~Teams();
        void setName(std::string name);
        void setNbSlot(int nb_eggs);
        std::string getName();
        int getNbSlot();
};