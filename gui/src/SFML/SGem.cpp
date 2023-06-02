/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SGem
*/

#include "SGem.hpp"

SGem::SGem(enum GemType type) : _type(type)
{
    this->createSprite();
}

SGem::~SGem()
{
}


void SGem::createSprite()
{
    switch (this->_type)
    {
        case LINEMATE:
            this->_texture.loadFromFile("gui/assets/gems/linemate.png");
            break;
        case DERAUMERE:
            this->_texture.loadFromFile("gui/assets/gems/deraumere.png");
            break;
        case SIBUR:
            this->_texture.loadFromFile("gui/assets/gems/sibur.png");
            break;
        case MENDIANE:
            this->_texture.loadFromFile("gui/assets/gems/mendiane.png");
            break;
        case PHIRAS:
            this->_texture.loadFromFile("gui/assets/gems/phiras.png");
            break;
        case THYSTAME:
            this->_texture.loadFromFile("gui/assets/gems/thystame.png");
            break;
        default:
            break;
    }
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setScale(sf::Vector2f(0.5, 0.5));
    this->_rect = sf::IntRect(0, 0, 53, 50);
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

void SGem::setSpriteTexture(std::shared_ptr<sf::Texture> texture)
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

void SGem::update(MapT cache)
{
    this->_rect.left += 53;
    if (this->_rect.left >= 53 * 6)
        this->_rect.left = 0;
    std::cout << this->_rect.left << std::endl;
    this->setSpriteRect(this->_rect);
}
