/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STrantorian
*/

#pragma once

#include "IEntity.hpp"

class STrantorian : public IEntity {
    public:
        STrantorian(Trantorian trantorian);
        STrantorian();
        ~STrantorian();
        void createSprite();
        void setSpriteRect(sf::IntRect rect);
        void setSpritePosition(sf::Vector2f pos);
        void setSpriteScale(sf::Vector2f scale);
        void setSpriteOrigin(sf::Vector2f origin);
        void setSpriteRotation(float angle);
        void setSpriteTexture(std::shared_ptr<sf::Texture> texture);
        void draw(sf::RenderWindow &window);
        void setOrientation(int orientation);
        void eventHandler(sf::Event event, sf::RenderWindow &window){};
        void update(){};

    protected:
    private:
        sf::Sprite _sprite;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
};
