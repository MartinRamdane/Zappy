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
        sf::Sprite getGemSprite(std::string gemName);

    protected:
    private:
        std::map<std::string, sf::Texture> _gemsTextures;
        std::map<std::string, sf::Sprite> _gemsSprites;
};
