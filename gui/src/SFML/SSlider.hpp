/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SSlider.hpp
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include "../cache/Stock.hpp"
#include "../cache/Map.hpp"

class SSlider
{
    public:
        SSlider(int w_width, int w_height);
        ~SSlider();
        void createSprite(int w_width, int w_height);
        void draw(sf::RenderWindow &window);
        void update(MapT *cache);
        void fadeIn(bool isFading);
        void fadeOut(bool isFading);
        std::map<std::string, std::shared_ptr<sf::RectangleShape>> getRect();
        void setRect(std::string S, std::shared_ptr<sf::RectangleShape> r);
        bool getIsDragging1();
        void setIsDragging1(bool drag);
    private:
        sf::Font _font;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
        std::map<std::string, std::shared_ptr<sf::Sprite>> _sprites;
        std::map<std::string, std::shared_ptr<sf::RectangleShape>> _rects;
        std::map<std::string, std::shared_ptr<sf::Text>> _texts;

        sf::Clock _clock;
        bool _isDragging1 = false;
        int _opacity = 0;
        bool _isFading = false;
        bool _isFadingOut = false;
        float _w_width;
        float _w_height;
};

