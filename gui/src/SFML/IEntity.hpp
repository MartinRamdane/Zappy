/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** IEntity
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "../cache/Map.hpp"

class IEntity {
    public:
        virtual ~IEntity() = default;
        virtual void createSprite() = 0;
        virtual void setSpriteRect(sf::IntRect rect) = 0;
        virtual void setSpritePosition(sf::Vector2f pos) = 0;
        virtual void setSpriteScale(sf::Vector2f scale) = 0;
        virtual void setSpriteOrigin(sf::Vector2f origin) = 0;
        virtual void setSpriteRotation(float angle) = 0;
        virtual void setSpriteTexture(std::shared_ptr<sf::Texture> &texture) = 0;
        virtual void draw(sf::RenderWindow &window, sf::View &view) = 0;
        virtual void eventHandler(sf::Event event, sf::RenderWindow &window) = 0;
        virtual void update(MapT *cache) = 0;
        virtual sf::Vector2i getClicked() = 0;
        virtual void moveSprite(MapT *cache) = 0;
        virtual sf::Vector2f getSpritePosition() = 0;

    protected:
        enum GemType {
            LINEMATE,
            DERAUMERE,
            SIBUR,
            MENDIANE,
            PHIRAS,
            THYSTAME,
            FOOD
        };

        enum EggMode {
            HATCHING,
            HATCHED
        };
    private:
};
