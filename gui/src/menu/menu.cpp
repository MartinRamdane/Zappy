/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** menu.cpp
*/

#include "menu.hpp"

Menu::Menu(sf::RenderWindow &window)
{
    _window = std::make_unique<sf::RenderWindow>(window);
}

Menu::~Menu()
{
}

void Menu::loop()
{
    while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window->close();
        }
        _window->clear(sf::Color::Black);
        _window->display();
    }
}