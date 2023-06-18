/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SInventory
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include "../cache/Stock.hpp"

class SInventory {
    public:
        SInventory(int w_width, int w_height);
        ~SInventory();
        void createSprite(int w_width, int w_height);
        void draw(sf::RenderWindow &window);
        void update(std::map<std::string, int> stock, std::string, int lvl);
        void createTexts();
        void fadeIn(bool isFading);
        void fadeOut(bool isFading);
        void setTrantorianTexture(std::shared_ptr<sf::Texture> texture);

    protected:
    private:
        sf::Font _font;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
        std::map<std::string, std::shared_ptr<sf::Sprite>> _sprites;
        std::map<std::string, std::shared_ptr<sf::Text>> _texts;
        sf::Clock _clock;
        sf::IntRect _rect;
        int _opacity = 255;
        bool _isFading = false;
        bool _isFadingOut = false;
};
