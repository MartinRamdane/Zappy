/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Button
*/

#ifndef BUTTON_HEADER_GUARD
#define BUTTON_HEADER_GUARD

#include "IObject.hpp"
#include <string>

class Button: public IObject {
    public:
        Button(std::string textureFile, std::string textureFileHover, MenuState state, bool hover = false);
        ~Button() {};
        void createSprite();
        void setSpriteRect(sf::IntRect rect);
        void setSpritePosition(sf::Vector2f pos);
        void setSpriteScale(sf::Vector2f scale);
        void setSpriteOrigin(sf::Vector2f origin);
        void setSpriteRotation(float angle);
        void setSpriteTexture(std::shared_ptr<sf::Texture> &texture);
        void draw(sf::RenderWindow &window);
        void eventHandler(sf::Event event, sf::RenderWindow &window, MenuState &state);
        void update();
        sf::Vector2f getSpritePosition();

    private:
        std::string _textureFile;
        std::string _textureFileHover;
        sf::Sprite _sprite;
        sf::Texture _texture;
        sf::Texture _textureHover;
        bool _hover;
        MenuState _state;
};

#endif //BUTTON_HEADER_GUARD
