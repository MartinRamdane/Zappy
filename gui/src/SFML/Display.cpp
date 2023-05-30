/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#include "Display.hpp"

Display::Display(int width, int height)
{
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), "Zappy");
}

Display::~Display()
{
}

void Display::draw()
{
    this->_window->clear(sf::Color::Black);
    this->_window->display();
}

void Display::eventHandler()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->close();
    }
}

std::unique_ptr<sf::RenderWindow> &Display::getWindow()
{
    return this->_window;
}
