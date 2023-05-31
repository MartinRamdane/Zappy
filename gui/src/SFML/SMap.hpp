/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SMap
*/

#pragma once

#include "IEntity.hpp"

class SMap : public IEntity {

    public:
        SMap(int x, int y, int type);
        ~SMap();
        void createSprite();
        void setSpriteRect(sf::IntRect rect);
        void setSpritePosition(sf::Vector2f pos);
        void setSpriteScale(sf::Vector2f scale);
        void setSpriteOrigin(sf::Vector2f origin);
        void setSpriteRotation(float angle);
        void setSpriteTexture(std::shared_ptr<sf::Texture> texture);
        void draw(sf::RenderWindow &window);
        void eventHandler(sf::Event event, sf::RenderWindow &window);

    protected:
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        int _x;
        int _y;
        int _type;
};
