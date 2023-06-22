/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Button
*/

#include "Button.hpp"

Button::Button(std::string textureFile, std::string textureFileHover, bool hover): _textureFile(textureFile), _textureFileHover(textureFileHover), _hover(hover)
{
    createSprite();
}

void Button::createSprite()
{
    _texture.loadFromFile(_textureFile);
    _textureHover.loadFromFile(_textureFileHover);
    if (_hover)
        _sprite.setTexture(_texture);
    else
        _sprite.setTexture(_textureHover);
    // _sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
}

void Button::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void Button::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void Button::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void Button::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void Button::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void Button::setSpriteTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprite.setTexture(*texture);
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(this->_sprite);
}

void Button::eventHandler(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
    if (_sprite.getGlobalBounds().contains(mousePos)) {
        _sprite.setTexture(_textureHover);
    } else {
        _sprite.setTexture(_texture);
    }
}

void Button::update()
{
    ;
    
}

sf::Vector2f Button::getSpritePosition()
{
    return _sprite.getPosition();
}