/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SEgg
*/

#include "SEgg.hpp"

SEgg::SEgg()
{
    this->createSprite();
}

SEgg::~SEgg()
{
}

void SEgg::createSprite()
{
    this->_texture.loadFromFile("gui/assets/trantorian/egg.png");
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setScale(sf::Vector2f(0.1, 0.1));
    this->_rect = sf::IntRect(0, 0, 317, 306);
    this->setSpriteRect(this->_rect);
}

void SEgg::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void SEgg::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void SEgg::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void SEgg::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void SEgg::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void SEgg::setSpriteTexture(std::shared_ptr<sf::Texture> texture)
{
    this->_sprite.setTexture(*texture);
}

void SEgg::draw(sf::RenderWindow &window, sf::View &view)
{
    std::cout << "draw egg" << std::endl;
    window.draw(this->_sprite);
}

void SEgg::eventHandler(sf::Event event, sf::RenderWindow &window)
{

}

void SEgg::update(MapT cache)
{

}
