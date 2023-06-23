/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STrantorian
*/

#include "STrantorian.hpp"

STrantorian::STrantorian(Trantorian trantorian, ResourceManager *resourceManager) : _broadcast(resourceManager)
{
    this->_resourceManager = resourceManager;
    this->_textures = resourceManager->getTrantorianTextures();
    this->setSpritePosition(sf::Vector2f((-40) + (96 * (trantorian.getX())), (-90) + ((96) * (trantorian.getY()))));
    this->setOrientation(trantorian.getOrientation());
    this->setSpriteScale(sf::Vector2f(3.5, 3.5));
    this->_id = trantorian.getId();
    this->_rect = sf::IntRect(0, 0, 48, 48);
    this->setSpriteRect(this->_rect);
    if (!_incantation.openFromFile("gui/assets/sounds/cast.ogg"))
        exit(84);
}

STrantorian::~STrantorian()
{
}

void STrantorian::createSprite()
{
}

void STrantorian::update(MapT *cache)
{
    this->setSpriteRect(this->_rect);
    if (this->_animation == DEATH) {
        if (this->_rect.left >= 10 * 48) {
            cache->removeTrantorian(this->_id);
        }
        else
            this->_rect.left += 48;
    } else if (this->_animation == INCANTATION) {
        if (_incantation.getStatus() != sf::Music::Playing) {
            _incantation.setLoop(true);
            _incantation.play();
        }
        if (this->_rect.left >= 480)
            this->_rect.left = 48;
        else
            this->_rect.left += 48;
    } else if (this->_animation == EJECTION) {
        if (this->_rect.left >= 6 * 48) {
            cache->setTrantorianEjection(this->_id, false);
            this->_rect.left = 0;
        } else
            this->_rect.left += 48;
    } else {
        _incantation.stop();
        if (this->_rect.left >= 204)
            this->_rect.left = 0;
        else
            this->_rect.left += 48;
    }
    if (this->_broadcasting == false)
        this->_clockBroadcast.restart();
    if (cache->getTrantorian(this->_id).getMessage() != "") {
        this->_broadcasting = true;
        this->_broadcast.setSpritePosition(sf::Vector2f(this->_sprite.getPosition().x + 20, this->_sprite.getPosition().y - 20));
    }
    if (this->_broadcasting == true) {
        if (this->_broadcast.getSpriteRect().left >= 840) {
            this->_broadcasting = false;
            this->_broadcast.createSprite();
            cache->setTrantorianMessage(this->_id, "");
        }
        if (this->_clockBroadcast.getElapsedTime().asSeconds() >= 0.8) {
            this->_broadcast.update(cache);
            this->_clockBroadcast.restart();
        }
    }
    this->setSpriteRect(this->_rect);
}

void STrantorian::moveSprite(MapT *cache)
{
    this->setSpriteRect(this->_rect);
    Trantorian t = cache->getTrantorian(this->_id);
    int freq = cache->getFrequency();

    sf::Vector2f targetPosition = sf::Vector2f((-35) + (96 * (t.getX())), (-70) + ((96) * (t.getY())));
    sf::Vector2f currentPosition = this->_sprite.getPosition();

    float distanceThreshold = 1.0f;

    if (t.getOrientation() != 1 && currentPosition.y > targetPosition.y) {
        this->_sprite.setPosition(targetPosition);
    } else if (t.getOrientation() != 4 && currentPosition.x > targetPosition.x) {
        this->_sprite.setPosition(targetPosition);
    } else if (t.getOrientation() != 3 && currentPosition.y < targetPosition.y) {
        this->_sprite.setPosition(targetPosition);
    } else if (t.getOrientation() != 2 && currentPosition.x < targetPosition.x) {
        this->_sprite.setPosition(targetPosition);
    } else {
        sf::Vector2f distance = targetPosition - currentPosition;
        float totalDistance = std::sqrt(distance.x * distance.x + distance.y * distance.y);

        if (totalDistance > distanceThreshold) {
            this->_animation = WALKING;

            float movementSpeed = freq * 1.0f;
            sf::Vector2f direction = movementSpeed / totalDistance * distance;
            sf::Vector2f newPosition = currentPosition + direction;

            this->setSpritePosition(newPosition);
        } else {
            this->_lastAnimation = this->_animation;
            if (t.getDeath() == true) {
                this->_animation = DEATH;
            } else if (t.getCanEvolve() == true) {
                this->_animation = INCANTATION;
            } else if (t.getEjection() == true) {
                this->_animation = EJECTION;
            } else {
                this->_animation = IDLE;
            }
            if (this->_lastAnimation != this->_animation)
                this->_rect.left = 0;
            this->setSpritePosition(targetPosition);
        }
    }
    this->_level = t.getLevel();
    this->setOrientation(t.getOrientation());
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

void STrantorian::setSpriteTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprite.setTexture(*texture);
}

void STrantorian::setOrientation(int orientation)
{
    if (this->_animation == IDLE) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["up" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["right" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["down" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["left" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == WALKING) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Wup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Wright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Wdown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Wleft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == INCANTATION) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Iup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Iright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Idown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Ileft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == EJECTION) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Eup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Eright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Edown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Eleft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == DEATH) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Dup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Dright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Ddown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Dleft" + std::to_string(this->_level)]);
                break;
        }
    } else if (this->_animation == HURT) {
        switch (orientation) {
            case 1:
                this->setSpriteTexture(this->_textures["Hup" + std::to_string(this->_level)]);
                break;
            case 2:
                this->setSpriteTexture(this->_textures["Hright" + std::to_string(this->_level)]);
                break;
            case 3:
                this->setSpriteTexture(this->_textures["Hdown" + std::to_string(this->_level)]);
                break;
            case 4:
                this->setSpriteTexture(this->_textures["Hleft" + std::to_string(this->_level)]);
                break;
        }
    }
}

void STrantorian::eventHandler(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
            sf::FloatRect bounds = this->_sprite.getGlobalBounds();
            bounds.left += 10;
            bounds.top += 10;
            bounds.width -= 60;
            bounds.height -= 60;
            if (bounds.contains(worldPos)) {
                this->_isClicked = true;
            }
        }
    }
}

void STrantorian::draw(sf::RenderWindow &window, sf::View &view)
{
    this->setSpriteRect(this->_rect);
    window.draw(this->_sprite);
    if (this->_broadcasting == true)
        this->_broadcast.draw(window, view);
}

sf::Vector2f STrantorian::getSpritePosition()
{
    return this->_sprite.getPosition();
}

std::shared_ptr<sf::Texture> &STrantorian::getTexture()
{
    return this->_textures["down" + std::to_string(this->_level)];
}

sf::Vector2i STrantorian::getClicked()
{
    if (this->_isClicked == true) {
        this->_isClicked = false;
        return sf::Vector2i(this->_id, 1);
    } else {
        return sf::Vector2i(-1, -1);
    }
}
