/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STile
*/

#include "STile.hpp"

STile::STile(int x, int y, int type) : _x(x), _y(y), _type(type)
{
    // this->createOcean();
    this->createSprite();
    this->_rect = sf::IntRect(0, 0, 32, 32);
    this->setSpriteRect(this->_rect);
}

STile::~STile()
{
}

// void STile::createOcean()
// {
//     this->_oceanTexture.loadFromFile("gui/assets/map/ocean.png");
//     this->_oceanTile.setTexture(this->_oceanTexture);
//     this->_oceanTile.setScale(sf::Vector2f(3, 3));
//     this->_oceanTile.setPosition(sf::Vector2f(-100, -100));
// }

void STile::createSprite()
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

void STile::setSpriteRect(sf::IntRect rect)
{
    this->_sprite.setTextureRect(rect);
}

void STile::setSpritePosition(sf::Vector2f pos)
{
    this->_sprite.setPosition(pos);
}

void STile::setSpriteScale(sf::Vector2f scale)
{
    this->_sprite.setScale(scale);
}

void STile::setSpriteOrigin(sf::Vector2f origin)
{
    this->_sprite.setOrigin(origin);
}

void STile::setSpriteRotation(float angle)
{
    this->_sprite.setRotation(angle);
}

void STile::setSpriteTexture(std::shared_ptr<sf::Texture> texture)
{
    this->_sprite.setTexture(*texture);
}

void STile::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(this->_sprite);
    if (this->_gems.size() > 0) {
        for (auto &gem : this->_gems) {
            gem->draw(window, view);
        }
    }
}

void STile::eventHandler(sf::Event event, sf::RenderWindow &window)
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
    if (event.type == sf::Event::MouseButtonPressed) {
        if (this->_type == 9) {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
            if (this->_sprite.getGlobalBounds().contains(sf::Vector2f(worldPos.x, worldPos.y))) {
                this->_isClicked = true;
            }
        }
    }
}

void STile::createGem(std::string name, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        std::unique_ptr<SGem> gem;
        sf::Vector2f position(this->_sprite.getGlobalBounds().left + 10 + (rand() % 55), this->_sprite.getGlobalBounds().top + 10 + (rand() % 53));

        if (name == "linemate") {
            gem = std::make_unique<SGem>(LINEMATE);
        } else if (name == "deraumere") {
            gem = std::make_unique<SGem>(DERAUMERE);
        } else if (name == "sibur") {
            gem = std::make_unique<SGem>(SIBUR);
        } else if (name == "mendiane") {
            gem = std::make_unique<SGem>(MENDIANE);
        } else if (name == "phiras") {
            gem = std::make_unique<SGem>(PHIRAS);
        } else if (name == "thystame") {
            gem = std::make_unique<SGem>(THYSTAME);
        }

        if (gem) {
            gem->setSpritePosition(position);
            this->_gems.push_back(std::move(gem));
        }
    }

}

sf::Vector2i STile::getClicked()
{
    if (this->_isClicked) {
        this->_isClicked = false;
        return sf::Vector2i(this->_x, this->_y);
    } else {
        return sf::Vector2i(-1, -1);
    }
}

void STile::update(MapT cache)
{
    if (this->_type == 9) {
        int totalGems = cache.getTile(this->_x, this->_y).getNbrTotalGems();
        std::map<std::string, int> stocks = cache.getTile(this->_x, this->_y).getStocks();
        if (this->_gems.size() != totalGems) {
            this->_gems.clear();
            for (auto &gem : stocks) {
                createGem(gem.first, gem.second);
            }
        }
    }
    if (this->_type == 10) {
        this->_rect.left += 32;
        if (this->_rect.left >= 96)
            this->_rect.left = 0;
        this->setSpriteRect(this->_rect);
    }
    if (this->_gems.size() > 0) {
        for (auto &gem : this->_gems) {
            gem->update(cache);
        }
    }
}
