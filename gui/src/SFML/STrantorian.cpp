/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STrantorian
*/

#include "STrantorian.hpp"

// STrantorian::STrantorian()
// {
//     this->createSprite();
//     this->setSpritePosition(sf::Vector2f(0, 0));
//     this->setOrientation(3);
//     this->setSpriteScale(sf::Vector2f(1.5, 1.5));
// }

STrantorian::STrantorian(Trantorian trantorian)
{
    this->createSprite();
    std::cout << "creer Tranto x: " << trantorian.getX() << " y: " << trantorian.getY() << std::endl;
    this->setSpritePosition(sf::Vector2f((-40) + (96 * (trantorian.getX())), (-90) + ((96) * (trantorian.getY()))));
    this->setOrientation(trantorian.getOrientation());
    this->setSpriteScale(sf::Vector2f(3.5, 3.5));
    id = trantorian.getId();
    this->_rect = sf::IntRect(0, 0, 48, 48);
}

STrantorian::~STrantorian()
{
}

void STrantorian::createSprite()
{
    _textures["down"] = std::make_shared<sf::Texture>();
    _textures["down"]->loadFromFile("gui/assets/trantorian/TrantorianUpIdle.png");
    _textures["left"] = std::make_shared<sf::Texture>();
    _textures["left"]->loadFromFile("gui/assets/trantorian/TrantorianLeftIdle.png");
    _textures["up"] = std::make_shared<sf::Texture>();
    _textures["up"]->loadFromFile("gui/assets/trantorian/TrantorianDownIdle.png");
    _textures["right"] = std::make_shared<sf::Texture>();
    _textures["right"]->loadFromFile("gui/assets/trantorian/TrantorianRightIdle.png");

    _textures["Wdown"] = std::make_shared<sf::Texture>();
    _textures["Wdown"]->loadFromFile("gui/assets/trantorian/TrantorianUpRun.png");
    _textures["Wleft"] = std::make_shared<sf::Texture>();
    _textures["Wleft"]->loadFromFile("gui/assets/trantorian/TrantorianLeftRun.png");
    _textures["Wup"] = std::make_shared<sf::Texture>();
    _textures["Wup"]->loadFromFile("gui/assets/trantorian/TrantorianDownRun.png");
    _textures["Wright"] = std::make_shared<sf::Texture>();
    _textures["Wright"]->loadFromFile("gui/assets/trantorian/TrantorianRightRun.png");
}

//! implement tp, if origentation is not the same of direction, TP

void STrantorian::update(MapT cache)
{
    Trantorian t = cache.getTrantorian(id);
    int freq = cache.getFrequency();

    sf::Vector2f targetPosition = sf::Vector2f((-35) + (96 * (t.getX())), (-70) + ((96) * (t.getY())));
    sf::Vector2f currentPosition = this->_sprite.getPosition();
    float movementMultiplier = 8.0f;
    sf::Vector2f movementPerFrame = (targetPosition - currentPosition) * (movementMultiplier / freq);

    if (currentPosition != targetPosition) {
        this->_animation = WALKING;
        this->setSpritePosition(currentPosition + movementPerFrame);
    } else {
        this->_animation = IDLE;
    }

    this->setOrientation(t.getOrientation());

    if (this->_rect.left >= 204)
        this->_rect.left = 0;
    else
        this->_rect.left += 48;

    this->setSpriteRect(this->_rect);
}


void STrantorian::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void STrantorian::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void STrantorian::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void STrantorian::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void STrantorian::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void STrantorian::setSpriteTexture(std::shared_ptr<sf::Texture> texture)
{
    this->_sprite.setTexture(*texture);
}

void STrantorian::setOrientation(int orientation)
{
    if (this->_animation == IDLE) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["up"]);
                this->setSpriteRect(sf::IntRect(0, 0, 48, 48));
                break;
            case 2:
                this->setSpriteTexture(this->_textures["right"]);
                this->setSpriteRect(sf::IntRect(0, 0, 48, 48));
                break;
            case 3:
                this->setSpriteTexture(this->_textures["down"]);
                this->setSpriteRect(sf::IntRect(0, 0, 48, 48));
                break;
            case 4:
                this->setSpriteTexture(this->_textures["left"]);
                this->setSpriteRect(sf::IntRect(0, 0, 48, 48));
                break;
        }
    } else if (this->_animation == WALKING) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Wup"]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Wright"]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Wdown"]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Wleft"]);
                break;
        }
    }
}

void STrantorian::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
}


