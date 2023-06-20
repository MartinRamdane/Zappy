/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** ResourceManager
*/

#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
    this->loadGemsTextures();
    this->createGemsSprites();
    std::cout << this->_gemsSprites.size() << std::endl;
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::loadGemsTextures()
{
    this->_gemsTextures["linemate"] = sf::Texture();
    this->_gemsTextures["linemate"].loadFromFile("gui/assets/gems/linemate.png");
    this->_gemsTextures["deraumere"] = sf::Texture();
    this->_gemsTextures["deraumere"].loadFromFile("gui/assets/gems/deraumere.png");
    this->_gemsTextures["sibur"] = sf::Texture();
    this->_gemsTextures["sibur"].loadFromFile("gui/assets/gems/sibur.png");
    this->_gemsTextures["mendiane"] = sf::Texture();
    this->_gemsTextures["mendiane"].loadFromFile("gui/assets/gems/mendiane.png");
    this->_gemsTextures["phiras"] = sf::Texture();
    this->_gemsTextures["phiras"].loadFromFile("gui/assets/gems/phiras.png");
    this->_gemsTextures["thystame"] = sf::Texture();
    this->_gemsTextures["thystame"].loadFromFile("gui/assets/gems/thystame.png");
    this->_gemsTextures["food"] = sf::Texture();
    this->_gemsTextures["food"].loadFromFile("gui/assets/gems/food.png");
}

void ResourceManager::createGemsSprites()
{
    this->_gemsSprites["linemate"] = sf::Sprite();
    this->_gemsSprites["linemate"].setTexture(this->_gemsTextures["linemate"]);
    this->_gemsSprites["deraumere"] = sf::Sprite();
    this->_gemsSprites["deraumere"].setTexture(this->_gemsTextures["deraumere"]);
    this->_gemsSprites["sibur"] = sf::Sprite();
    this->_gemsSprites["sibur"].setTexture(this->_gemsTextures["sibur"]);
    this->_gemsSprites["mendiane"] = sf::Sprite();
    this->_gemsSprites["mendiane"].setTexture(this->_gemsTextures["mendiane"]);
    this->_gemsSprites["phiras"] = sf::Sprite();
    this->_gemsSprites["phiras"].setTexture(this->_gemsTextures["phiras"]);
    this->_gemsSprites["thystame"] = sf::Sprite();
    this->_gemsSprites["thystame"].setTexture(this->_gemsTextures["thystame"]);
    this->_gemsSprites["food"] = sf::Sprite();
    this->_gemsSprites["food"].setTexture(this->_gemsTextures["food"]);
}


sf::Sprite ResourceManager::getGemSprite(std::string gemName)
{
    std::cout << this->_gemsSprites.size() << std::endl;
    return (this->_gemsSprites[gemName]);
}
