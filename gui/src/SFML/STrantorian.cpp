/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STrantorian
*/

#include "STrantorian.hpp"

STrantorian::STrantorian()
{
    this->createSprite();
    this->setSpritePosition(sf::Vector2f(0, 0));
    this->setOrientation(3);
    this->setSpriteScale(sf::Vector2f(1.5, 1.5));
}

STrantorian::STrantorian(Trantorian trantorian)
{
    //TODO: create sprite with trantorian infos
    // this->createSprite();
    // this->setSpritePosition(sf::Vector2f(100, 100));
    // this->setSpriteTexture(this->_textures["down"]);
}

STrantorian::~STrantorian()
{
}

void STrantorian::createSprite()
{
    _textures["down"] = std::make_shared<sf::Texture>();
    _textures["down"]->loadFromFile("gui/assets/trantorian/trantorian_down.png");
    _textures["left"] = std::make_shared<sf::Texture>();
    _textures["left"]->loadFromFile("gui/assets/trantorian/trantorian_left.png");
    _textures["up"] = std::make_shared<sf::Texture>();
    _textures["up"]->loadFromFile("gui/assets/trantorian/trantorian_up.png");
    _textures["right"] = std::make_shared<sf::Texture>();
    _textures["right"]->loadFromFile("gui/assets/trantorian/trantorian_right.png");
}

void STrantorian::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void STrantorian::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void STrantorian::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void STrantorian::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void STrantorian::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void STrantorian::setSpriteTexture(std::shared_ptr<sf::Texture> texture)
{
    this->_sprite.setTexture(*texture);
}

void STrantorian::setOrientation(int orientation)
{
    switch (orientation) {
        case 1:
            this->setSpriteTexture(this->_textures["up"]);
            this->setSpriteRect(sf::IntRect(0, 0, 112, 105));
            break;
        case 2:
            this->setSpriteTexture(this->_textures["right"]);
            this->setSpriteRect(sf::IntRect(0, 0, 112, 105));
            break;
        case 3:
            this->setSpriteTexture(this->_textures["down"]);
            this->setSpriteRect(sf::IntRect(0, 0, 112, 105));
            break;
        case 4:
            this->setSpriteTexture(this->_textures["left"]);
            this->setSpriteRect(sf::IntRect(0, 0, 112, 105));
            break;
    }
}

void STrantorian::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}
