/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STrantorian
*/

#pragma once

#include "IEntity.hpp"
#include "ResourceManager.hpp"
#include "SBroadcast.hpp"
#include <cmath>

class STrantorian : public IEntity {
    public:
        STrantorian(Trantorian trantorian, ResourceManager *resourceManager);
        ~STrantorian();
        void createSprite();
        void setSpriteRect(sf::IntRect rect);
        void setSpritePosition(sf::Vector2f pos);
        void setSpriteScale(sf::Vector2f scale);
        void setSpriteOrigin(sf::Vector2f origin);
        void setSpriteRotation(float angle);
        void setSpriteTexture(std::shared_ptr<sf::Texture> &texture);
        void draw(sf::RenderWindow &window, sf::View &view);
        void setOrientation(int orientation);
        void eventHandler(sf::Event event, sf::RenderWindow &window);
        void update(MapT *cache);
        sf::Vector2i getClicked();
        void moveSprite(MapT *cache);
        sf::Vector2f getSpritePosition();
        std::shared_ptr<sf::Texture> &getTexture();

    protected:
    private:
        enum Animation {
            IDLE,
            WALKING,
            EJECTION,
            INCANTATION,
            HURT,
            DEATH,
        };
        int _id;
        sf::Music _incantation;
        sf::Sprite _sprite;
        std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
        sf::IntRect _rect;
        Animation _animation = IDLE;
        Animation _lastAnimation = IDLE;
        int _level = 1;
        bool _isClicked = false;
        SBroadcast _broadcast;
        ResourceManager *_resourceManager;
        bool _broadcasting = false;
        sf::Clock _clockBroadcast;
};
