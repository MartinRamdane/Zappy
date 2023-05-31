/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SMap
*/

#include "SMap.hpp"

SMap::SMap(int x, int y, int type) : _x(x), _y(y), _type(type)
{
    this->createSprite();
}

SMap::~SMap()
{
}

void SMap::createSprite()
{
    switch(this->_type) {
        case 0:
            this->_texture.loadFromFile("gui/assets/map/ocean.png");
            break;
        case 1:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_top_left.png");
            break;
        case 2:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_top_middle.png");
            break;
        case 3:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_top_right.png");
            break;
        case 4:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_right_middle.png");
            break;
        case 5:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_bottom_right.png");
            break;
        case 6:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_bottom_middle.png");
            break;
        case 7:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_bottom_left.png");
            break;
        case 8:
            this->_texture.loadFromFile("gui/assets/map/ocean_terrain_left_middle.png");
            break;
        case 9:
            this->_texture.loadFromFile("gui/assets/map/grass.png");
            break;
        default:
            break;
    }
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setPosition(sf::Vector2f(this->_x * 96, this->_y * 96));
    this->_sprite.setScale(sf::Vector2f(3, 3));
}

void SMap::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void SMap::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void SMap::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void SMap::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void SMap::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void SMap::setSpriteTexture(std::shared_ptr<sf::Texture> texture)
{
    this->_sprite.setTexture(*texture);
}

void SMap::draw(sf::RenderWindow &window)
{
    window.draw(this->_sprite);
}
