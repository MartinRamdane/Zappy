/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SSide_menu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include "../cache/Stock.hpp"

class SSide_menu {
    public:
        SSide_menu(int w_width, int w_height);
        ~SSide_menu();
        void createSprite(int w_width, int w_height);
        void draw(sf::RenderWindow &window);
        void update(std::map<std::string, int> stock);
        void createTexts();
        void fadeIn(bool isFading);
        void fadeOut(bool isFading);

    protected:
    private:
        sf::Font _font;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _sprites;
        std::map<std::string, sf::Text> _texts;
        sf::Clock _clock;
        int _opacity = 0;
        bool _isFading = false;
        bool _isFadingOut = false;
};
