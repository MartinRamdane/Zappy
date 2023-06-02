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
#include "IEntity.hpp"
#include "STrantorian.hpp"
#include "STile.hpp"
#include "../cache/Map.hpp"

class Display {
    public:
        Display(int width, int height);
        ~Display();
        void render();
        std::unique_ptr<sf::RenderWindow> &getWindow();
        void eventHandler();
        void createMap(int width, int height);
        void createTrantorians();
        void update(MapT cache);
        void keyHandler();

    protected:
    private:
        std::unique_ptr<sf::RenderWindow> _window;
        sf::Event _event;
        std::map<std::string, std::unique_ptr<IEntity>> _trantorians;
        std::vector<std::unique_ptr<IEntity>> _map;
        sf::View _view;
        sf::Clock _clock;
        sf::Time _time;
        int _width;
        int _height;
        sf::Vector2f _mapCenter;
        bool _mapCreated = false;
};
