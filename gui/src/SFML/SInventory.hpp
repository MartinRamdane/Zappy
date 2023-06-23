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
#include "ResourceManager.hpp"

class SInventory {
    public:
        SInventory(int w_width, int w_height, ResourceManager *_resourceManager);
        ~SInventory();
        void createSprite(int w_width, int w_height);
        void draw(sf::RenderWindow &window);
        void update(std::map<std::string, int> stock, std::string, int lvl);
        void createTexts();
        void fadeIn(bool isFading);
        void fadeOut(bool isFading);
        void setTrantorianTexture(std::shared_ptr<sf::Texture> &texture);
        void eventHandler(sf::Event event, sf::RenderWindow &window);
        bool isFading(){return _isFading;};
        bool isFadingOut(){return _isFadingOut;};
        int getOpacity(){return _opacity;};

    protected:
    private:
        sf::Font _font;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _sprites;
        std::map<std::string, sf::Text> _texts;
        sf::RectangleShape _background;
        sf::Clock _clock;
        sf::IntRect _rect;
        int _opacity = 0;
        bool _isFading = false;
        bool _isFadingOut = false;
        ResourceManager *_resourceManager;
};
