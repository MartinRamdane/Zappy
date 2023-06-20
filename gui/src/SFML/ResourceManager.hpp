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
        sf::Sprite getGemSprite(std::string gemName);
        sf::Sprite getTileSprite(char tileType);
        int getGemsSpritesSize();
        int getTilesSpritesSize();

    protected:
    private:
        std::map<std::string, sf::Texture> _gemsTextures;
        std::map<std::string, sf::Sprite> _gemsSprites;

        std::map<char, sf::Texture> _tilesTextures;
        std::map<char, sf::Sprite> _tilesSprites;
};
