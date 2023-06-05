/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SBottom_menu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include "../cache/Stock.hpp"

class SBottom_menu {
    public:
        SBottom_menu(int w_width, int w_height);
        ~SBottom_menu();
        void createSprite(int w_width, int w_height);
        void draw(sf::RenderWindow &window);
        void update(std::map<std::string, int> stock);
        void createTexts();

    protected:
    private:
        sf::Font _font;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
        std::map<std::string, std::shared_ptr<sf::Sprite>> _sprites;
        std::map<std::string, std::shared_ptr<sf::Text>> _texts;
};
