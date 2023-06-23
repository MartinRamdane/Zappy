/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SEgg
*/

#include "SEgg.hpp"


SEgg::SEgg(ResourceManager *resourceManager)
{
    this->_resourceManager = resourceManager;
    this->_sprite = this->_resourceManager->getEggSprite();
    this->createSprite();
}

SEgg::~SEgg()
{
}

void SEgg::createSprite()
{
    this->_sprite.setScale(sf::Vector2f(1.3, 1.3));
    this->_rect = sf::IntRect(0, 0, 40, 39);
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

void SEgg::setSpriteTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprite.setTexture(*texture);
}

void SEgg::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}

void SEgg::eventHandler(sf::Event event, sf::RenderWindow &window)
{
}

void SEgg::update(MapT *cache)
{
    std::vector<Egg> eggs = cache->getEggs();
    for (auto &egg : eggs) {
        if (egg.getId() == this->_id) {
            if (egg.getHatched() == true && this->_mode == EggMode::HATCHING) {
                if (this->_rect.left < 120) {
                    this->_rect.left += 40;
                } else if (this->_rect.left == 120 && this->_rect.top < 39 * 3) {
                    this->_rect.left = 0;
                    this->_rect.top += 39;
                } else if (this->_rect.left == 120 && this->_rect.top == 39 * 3) {
                    this->_rect.left = 120;
                    this->_rect.top = 39 * 3;
                    this->_mode = EggMode::HATCHED;
                }
            }
        }
    }
    this->setSpriteRect(this->_rect);
}

void SEgg::setId(int id)
{
    this->_id = id;
}
