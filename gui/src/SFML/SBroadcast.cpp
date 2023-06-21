/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SBroadcast
*/

#include "SBroadcast.hpp"

SBroadcast::SBroadcast(ResourceManager *resourceManager)
{
    this->_resourceManager = resourceManager;
    this->_sprite = this->_resourceManager->getBroadcastSprite();
    this->createSprite();
}

SBroadcast::~SBroadcast()
{
}

void SBroadcast::createSprite()
{
    this->_sprite.setScale(sf::Vector2f(0.4, 0.4));
    this->_rect = sf::IntRect(0, 0, 280, 150);
    this->setSpriteRect(this->_rect);
}

void SBroadcast::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void SBroadcast::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void SBroadcast::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void SBroadcast::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void SBroadcast::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void SBroadcast::setSpriteTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprite.setTexture(*texture);
}

void SBroadcast::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}

void SBroadcast::eventHandler(sf::Event event, sf::RenderWindow &window)
{
}

void SBroadcast::update(MapT *cache)
{
    if (this->_rect.left >= 840)
        this->_rect.left = 280;
    else
        this->_rect.left += 280;
    this->setSpriteRect(this->_rect);
}
