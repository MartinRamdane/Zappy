/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Trantorians
*/

#pragma once

#include "Stock.hpp"

class Trantorian
{
    private:
        Stock stock;
        int id;
        char orientation;
        int lvl;
        int nb_egg;
        int x;
        int y;

    public:
        Trantorian();
        ~Trantorian();
};
