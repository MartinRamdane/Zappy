/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SMap
*/

#include "SMap.hpp"

SMap::SMap(int x, int y, int type) : _x(x), _y(y), _type(type)
{
    this->createOcean();
    this->createSprite();
    this->_rect = sf::IntRect(0, 0, 32, 32);
    this->setSpriteRect(this->_rect);
}

SMap::~SMap()
{
}

void SMap::createOcean()
{
    this->_oceanTexture.loadFromFile("gui/assets/map/ocean.png");
    this->_oceanTile.setTexture(this->_oceanTexture);
    this->_oceanTile.setScale(sf::Vector2f(3, 3));
    this->_oceanTile.setPosition(sf::Vector2f(-100, -100));
}

void SMap::createSprite()
{
    switch(this->_type) {
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

void SMap::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}

void SMap::eventHandler(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseMoved) {
        if (this->_type == 9) {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
            if (this->_sprite.getGlobalBounds().contains(sf::Vector2f(worldPos.x, worldPos.y))) {
                this->_sprite.setColor(sf::Color(255, 255, 255, 128));
            } else {
                this->_sprite.setColor(sf::Color(255, 255, 255, 255));
            }
        }
    }
}

void SMap::update()
{
    if (this->_type == 10) {
        this->_rect.left += 32;
        if (this->_rect.left >= 96)
            this->_rect.left = 0;
        std::cout << "update" << std::endl;
        std::cout << this->_rect.left << std::endl;
        this->setSpriteRect(this->_rect);
    }
}
