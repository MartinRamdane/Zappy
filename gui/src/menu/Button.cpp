/*
** EPITECH PROJECT, 2023
** AButton.cpp
** File description:
** AButton
*/

#include "Button.hpp"

Button::Button(std::string name, std::string idleTexture, std::string hoverTexture)
{
    _name = name;
    _isHovered = false;
    this->createSprite(idleTexture, hoverTexture);
}

Button::~Button()
{
}

void Button::setHover(bool state)
{
    _isHovered = state;
}

void Button::createSprite(std::string idlePath, std::string hoverPath)
{
    this->_idleTexture.loadFromFile(idlePath);
    this->_hoverTexture.loadFromFile(hoverPath);
    this->_sprite.setTexture(this->_idleTexture);
    this->_sprite.setScale(sf::Vector2f(1.3, 1.3));
    this->_rect = sf::IntRect(0, 0, 40, 39);
    this->setSpriteRect(this->_rect);
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

void Button::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}

void Button::eventHandler(sf::Event event, sf::RenderWindow &window)
{
}

void Button::update()
{
    if (_isHovered) {
        this->_sprite.setTexture(this->_hoverTexture);
    } else {
        this->_sprite.setTexture(this->_idleTexture);
    }
}

void Button::onClick(Menu::MenuState state)
{
    if (_menu) {
        _menu->setState(state);
    }
}
