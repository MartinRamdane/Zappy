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
        sf::Sprite getGemSprite(std::string gemName);
        sf::Sprite getTileSprite(char tileType);
        sf::Sprite getBroadcastSprite();
        int getGemsSpritesSize();
        int getTilesSpritesSize();

    protected:
    private:
        std::map<std::string, sf::Texture> _gemsTextures;
        std::map<std::string, sf::Sprite> _gemsSprites;
        sf::Sprite _broadcastSprite;

        std::map<char, sf::Texture> _tilesTextures;
        std::map<char, sf::Sprite> _tilesSprites;
        sf::Texture _broadcastTexture;
};
