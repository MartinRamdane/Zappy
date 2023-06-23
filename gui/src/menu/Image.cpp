/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Image
*/

#include "Image.hpp"

Image::Image(std::string targetTexture)
{
    _texture.loadFromFile(targetTexture);
    createSprite();
}

void Image::createSprite()
{
    _sprite.setTexture(_texture);
    // _sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
}

void Image::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void Image::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void Image::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void Image::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void Image::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void Image::setSpriteTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprite.setTexture(*texture);
}

void Image::draw(sf::RenderWindow &window)
{
    window.draw(this->_sprite);
}

void Image::eventHandler(sf::Event event, sf::RenderWindow &window, MenuState &state)
{
    return;
}

void Image::update()
{
    ;
}

sf::Vector2f Image::getSpritePosition()
{
    return _sprite.getPosition();
}