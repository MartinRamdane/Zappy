/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <memory>

class Display {
    public:
        Display(int width, int height);
        ~Display();
        void createWindow();
        void draw();
        std::unique_ptr<sf::RenderWindow> &getWindow();
        void eventHandler();

    protected:
    private:
        std::unique_ptr<sf::RenderWindow> _window;
        sf::Event _event;
};
