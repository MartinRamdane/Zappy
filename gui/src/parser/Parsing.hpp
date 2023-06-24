/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Parsing.hpp
*/

#pragma once

#include "../cache/Map.hpp"
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include "../SFML/Display.hpp"

class Parsing
{
    private:
        MapT mapt;
        sf::Music death; // Si gabriel vois ca j avais pas le choix ^^ DO BRASSIIIIIILLLL
        sf::Music push;

    public:
        void msz(std::string arg);
        void bct(std::string arg);
        void tna(std::string arg);
        void pnw(std::string arg);
        void ppo(std::string arg);
        void plv(std::string arg);
        void pin(std::string arg);
        void pex(std::string arg);
        void pbc(std::string arg);
        void pic(std::string arg);
        void pie(std::string arg);
        void pfk(std::string arg);
        void pdr(std::string arg);
        void pgt(std::string arg);
        void pdi(std::string arg);
        void enw(std::string arg);
        void ebo(std::string arg);
        void edi(std::string arg);
        void sgt(std::string arg);
        void sst(std::string arg);
        void seg(std::string arg);
        void smg(std::string arg);
        void suc(std::string arg);
        void sbp(std::string arg);
        void eht(std::string arg);
        Parsing();
        ~Parsing();
        void parse(std::string str);
        MapT getMap();
        MapT *getMapPtr();
};

