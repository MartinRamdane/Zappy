/*
** EPITECH PROJECT, 2023
** Menu.hpp
** File description:
** Menu
*/

#ifndef MENU_HEADER_GUARD
    #define MENU_HEADER_GUARD
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>
#include <map>
#include "IEntity.hpp"

class Menu {
    public:
        enum MenuState {
            MAIN,
            HELP,
            PLAY
        };
        Menu();
        ~Menu();
        void setState(MenuState state);

    protected:
    private:
        MenuState _currentState;
        MenuState _previousState;
        std::map<std::string, std::unique_ptr<IEntity>> _entities;
        std::unique_ptr<sf::RenderWindow> _window;
};

#endif /* !MENU_HEADER_GUARD */
