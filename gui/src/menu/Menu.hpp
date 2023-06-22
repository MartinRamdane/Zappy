/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Menu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <map>
#include "IObject.hpp"
#include "Image.hpp"
#include "Button.hpp"

class Menu {
    public:
        enum MenuState {
            MAIN,
            SETTINGS,
            GAME,
            EXIT
        };
        Menu();
        ~Menu();
        int render(sf::RenderWindow &window);
        void setState(MenuState state);
        void setMainEntities();
        void setSettingsEntities();
        void setGameEntities();
        void setExitEntities();
        int eventHandler(sf::RenderWindow &window);

    protected:
    private:
        MenuState _currentState;
        MenuState _previousState;
        std::map<std::string , std::unique_ptr<IObject>> _entities;
        sf::Event _event;
};
