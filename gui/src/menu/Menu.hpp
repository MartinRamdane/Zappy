/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
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
#include <map>
#include "Image.hpp"
#include "Button.hpp"
#include "Input.hpp"

class IObject;

class Menu {
    public:
        Menu();
        ~Menu();
        int render(sf::RenderWindow &window);
        void setState(MenuState state);
        void setMainEntities();
        void setSettingsEntities();
        void setGameEntities();
        void setExitEntities();
        int update();
        void eventHandler(sf::RenderWindow &window);
        void clear();
        std::string getIp() { return _ip; };
        int getPort() { return _port; };

    protected:
    private:
        sf::Font _font;
        MenuState _currentState;
        MenuState _previousState;
        std::map<std::string, std::unique_ptr<IObject>> _entities;
        sf::Event _event;
        std::string _ip;
        int _port;
};

#endif // MENU_HEADER_GUARD
