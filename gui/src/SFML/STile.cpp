/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** STile
*/

#include "STile.hpp"

STile::STile(int x, int y, int type, std::shared_ptr<sf::Texture> &tilesTextures, ResourceManager *_resourceManager) : _x(x), _y(y), _type(type)
{
    this->_texture = tilesTextures;
    this->createSprite();
    this->_rect = sf::IntRect(0, 0, 32, 32);
    this->setSpriteRect(this->_rect);
    this->_resourceManager = _resourceManager;
}

STile::~STile()
{
    this->_gems.clear();
    this->_eggs.clear();
}

void STile::createSprite()
{
    this->_sprite.setTexture(*this->_texture);
    this->_sprite.setPosition(sf::Vector2f(this->_x * 96, this->_y * 96));
    this->_sprite.setScale(sf::Vector2f(3, 3));
    this->_sprite.setColor(sf::Color(255, 255, 255, 255));
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

void STile::setSpriteTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprite.setTexture(*texture);
}

void STile::draw(sf::RenderWindow &window, sf::View &view)
{
    std::vector<std::pair<int, IEntity*>> sortedGems;
    std::vector<std::pair<int, IEntity*>> sortedEggs;

    if (this->_gems.size() > 0) {
        for (auto &gem : this->_gems) {
            SGem tmp = dynamic_cast<SGem&>(gem);
            if (tmp.getType() != FOOD)
                sortedGems.push_back(std::make_pair(gem.getSpritePosition().y, &gem));
        }
        std::sort(sortedGems.begin(), sortedGems.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
    }
    if (this->_eggs.size() > 0) {
        for (auto &egg : this->_eggs) {
            sortedEggs.push_back(std::make_pair(egg->getSpritePosition().y, egg.get()));
        }
        std::sort(sortedEggs.begin(), sortedEggs.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
    }


    int drawed_food = 0;
    window.draw(this->_sprite);
    if (this->_gems.size() > 0) {
        for (auto &gem : this->_gems) {
            SGem tmp = dynamic_cast<SGem&>(gem);
            if (tmp.getType() == FOOD) {
                if (drawed_food < 2) {
                    gem.draw(window, view);
                    drawed_food++;
                }
            }
        }

        for (auto &gem : sortedGems) {
            gem.second->draw(window, view);
        }
    }
    if (this->_eggs.size() > 0) {
        for (auto &egg : sortedEggs) {
            egg.second->draw(window, view);
        }
    }
}

void STile::eventHandler(sf::Event event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::MouseMoved) {
        if (this->_type == 'g' || this->_type == 'h' || this->_type == 'i' || this->_type == 'j' || this->_type == 'k' || this->_type == 'l' || this->_type == 'm' || this->_type == 'n' || this->_type == 'o') {
            sf::Vector2i pixelPos = sf::Vector2i(event.mouseMove.x, event.mouseMove.y);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
            if (this->_sprite.getGlobalBounds().contains(sf::Vector2f(worldPos.x, worldPos.y))) {
                this->_sprite.setColor(sf::Color(255, 255, 255, 128));
            } else {
                this->_sprite.setColor(sf::Color(255, 255, 255, 255));
            }
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (this->_type == 'g' || this->_type == 'h' || this->_type == 'i' || this->_type == 'j' || this->_type == 'k' || this->_type == 'l' || this->_type == 'm' || this->_type == 'n' || this->_type == 'o') {
            sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
            if (this->_sprite.getGlobalBounds().contains(sf::Vector2f(worldPos.x, worldPos.y))) {
                this->_isClicked = true;
            }
        }
    }
}

//weak ptr

void STile::createGem(std::string name, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        SGem *gem = nullptr;
        sf::Vector2f position(this->_sprite.getGlobalBounds().left + 10 + (rand() % 55), this->_sprite.getGlobalBounds().top + 10 + (rand() % 53));

        if (name == "linemate") {
            gem = new SGem(this->_resourceManager->getGemSprite("linemate"), LINEMATE);
        } else if (name == "deraumere") {
            gem = new SGem(this->_resourceManager->getGemSprite("deraumere"), DERAUMERE);
        } else if (name == "sibur") {
            gem = new SGem(this->_resourceManager->getGemSprite("sibur"), SIBUR);
        } else if (name == "mendiane") {
            gem = new SGem(this->_resourceManager->getGemSprite("mendiane"), MENDIANE);
        } else if (name == "phiras") {
            gem = new SGem(this->_resourceManager->getGemSprite("phiras"), PHIRAS);
        } else if (name == "thystame") {
            gem = new SGem(this->_resourceManager->getGemSprite("thystame"), THYSTAME);
        } else if (name == "food") {
            gem = new SGem(this->_resourceManager->getGemSprite("food"), FOOD);
        }
        if (gem) {
            gem->setSpritePosition(position);
            this->_gems.push_back(*gem);
        }
    }

}


void STile::createEgg(int id, bool isHatched)
{
    std::unique_ptr<SEgg> egg;
    sf::Vector2f position(this->_sprite.getGlobalBounds().left + 10 + (rand() % 55), this->_sprite.getGlobalBounds().top + 10 + (rand() % 53));

    egg = std::make_unique<SEgg>();

    if (egg) {
        egg->setSpritePosition(position);
        egg->setId(id);
        if (isHatched)
            egg->setSpriteRect(sf::IntRect(160, 0, 160, 160));
        this->_eggs.push_back(std::move(egg));
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

void STile::update(MapT *cache)
{
    if (this->_type == 'g' || this->_type == 'h' || this->_type == 'i' || this->_type == 'j' || this->_type == 'k' || this->_type == 'l' || this->_type == 'm' || this->_type == 'n' || this->_type == 'o') {
        int totalGems = cache->getTile(this->_x, this->_y).getNbrTotalGems();
        std::map<std::string, int> stocks = cache->getTile(this->_x, this->_y).getStocks();
        if (this->_gems.size() != totalGems) {
            this->_gems.clear();
            for (auto &gem : stocks) {
                createGem(gem.first, gem.second);
            }
        }
        std::vector<Egg> eggs = cache->getEggs();
        if (this->_eggs.size() != cache->getEggsFromPos(this->_x, this->_y)) {
            this->_eggs.clear();
            for (auto &egg : eggs) {
                if (egg.getX() == this->_x && egg.getY() == this->_y) {
                    createEgg(egg.getId(), egg.getHatched());
                }
            }
        }
    }
    if (this->_gems.size() > 0) {
        for (auto &gem : this->_gems) {
            gem.update(cache);
        }
    }
    if (this->_eggs.size() > 0) {
        for (auto &egg : this->_eggs) {
            egg->update(cache);
        }
    }
}

void STile::removeEgg()
{
    this->_eggs.erase(this->_eggs.begin());
}
