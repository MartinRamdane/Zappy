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
    this->loadTilesTextures();
    this->createTilesSprites();
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

void ResourceManager::loadTilesTextures()
{
    this->_tilesTextures['g'] = sf::Texture();
    this->_tilesTextures['g'].loadFromFile("gui/assets/map/grass.png");
    this->_tilesTextures['h'] = sf::Texture();
    this->_tilesTextures['h'].loadFromFile("gui/assets/map/grass_left_top.png");
    this->_tilesTextures['i'] = sf::Texture();
    this->_tilesTextures['i'].loadFromFile("gui/assets/map/grass_right_top.png");
    this->_tilesTextures['j'] = sf::Texture();
    this->_tilesTextures['j'].loadFromFile("gui/assets/map/grass_left_down.png");
    this->_tilesTextures['k'] = sf::Texture();
    this->_tilesTextures['k'].loadFromFile("gui/assets/map/grass_right_down.png");
    this->_tilesTextures['l'] = sf::Texture();
    this->_tilesTextures['l'].loadFromFile("gui/assets/map/grass_middle_top.png");
    this->_tilesTextures['m'] = sf::Texture();
    this->_tilesTextures['m'].loadFromFile("gui/assets/map/grass_middle_left.png");
    this->_tilesTextures['n'] = sf::Texture();
    this->_tilesTextures['n'].loadFromFile("gui/assets/map/grass_middle_right.png");
    this->_tilesTextures['o'] = sf::Texture();
    this->_tilesTextures['o'].loadFromFile("gui/assets/map/grass_middle_down.png");
    this->_tilesTextures['p'] = sf::Texture();
    this->_tilesTextures['p'].loadFromFile("gui/assets/map/ocean_terrain_left_middle.png");
    this->_tilesTextures['q'] = sf::Texture();
    this->_tilesTextures['q'].loadFromFile("gui/assets/map/ocean_terrain_top_middle.png");
    this->_tilesTextures['w'] = sf::Texture();
    this->_tilesTextures['w'].loadFromFile("gui/assets/map/ocean_terrain_top_left.png");
    this->_tilesTextures['x'] = sf::Texture();
    this->_tilesTextures['x'].loadFromFile("gui/assets/map/ocean_terrain_top_right.png");
    this->_tilesTextures['z'] = sf::Texture();
    this->_tilesTextures['z'].loadFromFile("gui/assets/map/ocean_terrain_right_middle.png");
    this->_tilesTextures['a'] = sf::Texture();
    this->_tilesTextures['a'].loadFromFile("gui/assets/map/ocean_terrain_bottom_middle.png");
    this->_tilesTextures['s'] = sf::Texture();
    this->_tilesTextures['s'].loadFromFile("gui/assets/map/ocean_terrain_bottom_left.png");
    this->_tilesTextures['d'] = sf::Texture();
    this->_tilesTextures['d'].loadFromFile("gui/assets/map/ocean_terrain_bottom_right.png");
    this->_tilesTextures['r'] = sf::Texture();
    this->_tilesTextures['r'].loadFromFile("gui/assets/map/ocean.png");
}

void ResourceManager::createTilesSprites()
{
    this->_tilesSprites['g'] = sf::Sprite();
    this->_tilesSprites['g'].setTexture(this->_tilesTextures['g']);
    this->_tilesSprites['h'] = sf::Sprite();
    this->_tilesSprites['h'].setTexture(this->_tilesTextures['h']);
    this->_tilesSprites['i'] = sf::Sprite();
    this->_tilesSprites['i'].setTexture(this->_tilesTextures['i']);
    this->_tilesSprites['j'] = sf::Sprite();
    this->_tilesSprites['j'].setTexture(this->_tilesTextures['j']);
    this->_tilesSprites['k'] = sf::Sprite();
    this->_tilesSprites['k'].setTexture(this->_tilesTextures['k']);
    this->_tilesSprites['l'] = sf::Sprite();
    this->_tilesSprites['l'].setTexture(this->_tilesTextures['l']);
    this->_tilesSprites['m'] = sf::Sprite();
    this->_tilesSprites['m'].setTexture(this->_tilesTextures['m']);
    this->_tilesSprites['n'] = sf::Sprite();
    this->_tilesSprites['n'].setTexture(this->_tilesTextures['n']);
    this->_tilesSprites['o'] = sf::Sprite();
    this->_tilesSprites['o'].setTexture(this->_tilesTextures['o']);
    this->_tilesSprites['p'] = sf::Sprite();
    this->_tilesSprites['p'].setTexture(this->_tilesTextures['p']);
    this->_tilesSprites['q'] = sf::Sprite();
    this->_tilesSprites['q'].setTexture(this->_tilesTextures['q']);
    this->_tilesSprites['w'] = sf::Sprite();
    this->_tilesSprites['w'].setTexture(this->_tilesTextures['w']);
    this->_tilesSprites['x'] = sf::Sprite();
    this->_tilesSprites['x'].setTexture(this->_tilesTextures['x']);
    this->_tilesSprites['z'] = sf::Sprite();
    this->_tilesSprites['z'].setTexture(this->_tilesTextures['z']);
    this->_tilesSprites['a'] = sf::Sprite();
    this->_tilesSprites['a'].setTexture(this->_tilesTextures['a']);
    this->_tilesSprites['s'] = sf::Sprite();
    this->_tilesSprites['s'].setTexture(this->_tilesTextures['s']);
    this->_tilesSprites['d'] = sf::Sprite();
    this->_tilesSprites['d'].setTexture(this->_tilesTextures['d']);
    this->_tilesSprites['r'] = sf::Sprite();
    this->_tilesSprites['r'].setTexture(this->_tilesTextures['r']);
}

sf::Sprite ResourceManager::getGemSprite(std::string gemName)
{
    return (this->_gemsSprites[gemName]);
}

int ResourceManager::getGemsSpritesSize()
{
    return (this->_gemsSprites.size());
}


sf::Sprite ResourceManager::getTileSprite(char tileType)
{
    return (this->_tilesSprites[tileType]);
}

int ResourceManager::getTilesSpritesSize()
{
    return (this->_tilesSprites.size());
}
