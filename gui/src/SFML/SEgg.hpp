/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SEgg
*/

#pragma once

#include "IEntity.hpp"
#include "../cache/Egg.hpp"
#include "ResourceManager.hpp"

class SEgg : public IEntity {
    public:
        SEgg(ResourceManager *resourceManager);
        ~SEgg();
        void createSprite();
        void setSpriteRect(sf::IntRect rect);
        void setSpritePosition(sf::Vector2f pos);
        void setSpriteScale(sf::Vector2f scale);
        void setSpriteOrigin(sf::Vector2f origin);
        void setSpriteRotation(float angle);
        void setSpriteTexture(std::shared_ptr<sf::Texture> &texture);
        void draw(sf::RenderWindow &window, sf::View &view);
        void eventHandler(sf::Event event, sf::RenderWindow &window);
        void update(MapT *cache);
        sf::Vector2i getClicked(){return sf::Vector2i(0, 0);};
        void moveSprite(MapT *cache){};
        void setId(int id);
        sf::Vector2f getSpritePosition(){return this->_sprite.getPosition();};


    protected:
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::IntRect _rect;
        enum EggMode _mode;
        int _id;
        ResourceManager *_resourceManager;
};
