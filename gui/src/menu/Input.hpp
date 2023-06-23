/*
** EPITECH PROJECT, 2023
** Input.hpp
** File description:
** Input
*/

#ifndef INPUT_HEADER_GUARD
#define INPUT_HEADER_GUARD
#include "IObject.hpp"

class Input: public IObject {
    public:
        Input(std::string texture, std::string textureHover);
        ~Input() {};
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
        std::string getText() { return _value;};
        sf::Vector2f getSpritePosition();

    protected:
    private:
        std::string _value;
        std::string _textureFile;
        std::string _textureFileHover;
        sf::Texture _texture;
        sf::Texture _textureHover;
        sf::Sprite _sprite;
        bool _isActive;
        static std::map<sf::Keyboard::Key, std::string> keys;
        sf::Font _font;
        sf::Text _text;
        bool _hover;
};

#endif /* !INPUT_HEADER_GUARD */
