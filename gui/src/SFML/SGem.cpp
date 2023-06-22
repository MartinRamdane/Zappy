/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SGem
*/

#include "SGem.hpp"

SGem::SGem(sf::Sprite sprite, GemType type) : _type(type)
{
    this->_sprite = sprite;
    this->createSprite();
}

SGem::~SGem()
{
}

void SGem::createSprite()
{
    this->_sprite.setScale(sf::Vector2f(2, 2));
    this->_rect = sf::IntRect(0, 0, 16, 16);
    this->setSpriteRect(this->_rect);
}

void SGem::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void SGem::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void SGem::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void SGem::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void SGem::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void SGem::setSpriteTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprite.setTexture(*texture);
}

void SGem::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}

void SGem::eventHandler(sf::Event event, sf::RenderWindow &window)
{

}

void SGem::update(MapT *cache)
{
    if (this->_type == FOOD)
        return;
    this->_rect.left += 16;
    if (this->_rect.left >= 16 * 4)
        this->_rect.left = 0;
    this->setSpriteRect(this->_rect);
}
