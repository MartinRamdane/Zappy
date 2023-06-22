/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** ResourceManager
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <iostream>
#include <string>

class ResourceManager {
    public:
        ResourceManager();
        ~ResourceManager();
        void loadGemsTextures();
        void createGemsSprites();
        void loadTilesTextures();
        void createTilesSprites();
        void loadBroadcastTexture();
        void createBroadcastSprite();
        void loadTrantoriansTexture();
        void createEggSprite();
        void loadEggTexture();
        sf::Sprite getGemSprite(std::string gemName);
        sf::Sprite getTileSprite(char tileType);
        sf::Sprite getBroadcastSprite();
        sf::Sprite getEggSprite();
        std::map<std::string, std::shared_ptr<sf::Texture>> getTrantorianTextures();
        int getGemsSpritesSize();
        int getTilesSpritesSize();

    protected:
    private:
        std::map<std::string, sf::Texture> _gemsTextures;
        std::map<std::string, sf::Sprite> _gemsSprites;
        sf::Sprite _broadcastSprite;
        sf::Sprite _eggSprite;

        std::map<char, sf::Texture> _tilesTextures;
        std::map<char, sf::Sprite> _tilesSprites;
        sf::Texture _broadcastTexture;
        std::map<std::string, std::shared_ptr<sf::Texture>> _trantorianTextures;
        sf::Texture _eggTexture;
};
