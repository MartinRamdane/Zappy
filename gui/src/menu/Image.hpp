/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Image
*/

#ifndef IMAGE_HEADER_GUARD
#define IMAGE_HEADER_GUARD

#include "IObject.hpp"
#include <string>

class Image: public IObject {
    public:
        Image(std::string targetTexture);
        ~Image() {};
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
        sf::Vector2i getClicked();
        void moveSprite();
        sf::Vector2f getSpritePosition();

    protected:
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;
};

#endif //IMAGE_HEADER_GUARD
