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
#include "../display/Trantorians.hpp"

class IEntity {
    public:
        ~IEntity() = default;
        virtual void createSprite() = 0;
        virtual void setSpriteRect(sf::IntRect rect) = 0;
        virtual void setSpritePosition(sf::Vector2f pos) = 0;
        virtual void setSpriteScale(sf::Vector2f scale) = 0;
        virtual void setSpriteOrigin(sf::Vector2f origin) = 0;
        virtual void setSpriteRotation(float angle) = 0;
        virtual void setSpriteTexture(std::shared_ptr<sf::Texture> texture) = 0;
        virtual void draw(sf::RenderWindow &window) = 0;

    protected:
    private:
};
