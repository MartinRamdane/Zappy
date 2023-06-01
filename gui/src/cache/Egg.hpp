/*
** EPITECH PROJECT, 2022
** gui
** File description:
** egg.hpp
*/

#pragma once

class Egg
{
    private:
        int id;
        int x;
        int y;
    public:
        Egg(int id, int x, int y);
        ~Egg();
        void setId(int id);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        int getId();
};

