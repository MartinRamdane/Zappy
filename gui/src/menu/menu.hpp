/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** menu.hpp
*/

#pragma once

#include <iostream>
#include "Gui.hpp"

class Menu
{
private:
    std::unique_ptr<sf::RenderWindow> _window;
public:
    Menu(sf::RenderWindow &window);
    ~Menu();
    void loop();
};


