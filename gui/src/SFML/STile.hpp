/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STile
*/

#pragma once

#include "IEntity.hpp"
#include "SGem.hpp"
#include "SEgg.hpp"
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

class STile : public IEntity {

    public:
        STile(int x, int y, int type, ResourceManager *_resourceManager);
        ~STile();
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
        void createGem(std::string type, int quantity);
        sf::Vector2i getClicked();
        void createEgg(int id, bool isHatched);
        void removeEgg();
        void moveSprite(MapT *cache){};
        sf::Vector2f getSpritePosition(){return sf::Vector2f(0, 0);};

    protected:
    private:
        sf::Sprite _sprite;
        sf::IntRect _rect;
        sf::Texture _oceanTexture;
        sf::Sprite _oceanTile;
        std::vector<SGem> _gems;
        std::vector<SEgg> _eggs;
        int _x;
        int _y;
        char _type;
        bool _isClicked = false;
        ResourceManager *_resourceManager;
};
