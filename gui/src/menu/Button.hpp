/*
** EPITECH PROJECT, 2023
** Button.hpp
** File description:
** Button
*/

#ifndef BUTTON_HEADER_GUARD
    #define BUTTON_HEADER_GUARD
#include <string>
#include "IEntity.hpp"
#include "Menu.hpp"

class Button : public IEntity {
    public:
        Button(std::string name, std::string idleTexture, std::string hoverTexture);
        ~Button();
        void createSprite(std::string idlePath, std::string hoverPath);
        void setSpriteRect(sf::IntRect rect);
        void setSpritePosition(sf::Vector2f pos);
        void setSpriteScale(sf::Vector2f scale);
        void setSpriteOrigin(sf::Vector2f origin);
        void setSpriteRotation(float angle);
        void setSpriteTexture(std::shared_ptr<sf::Texture> &texture);
        void draw(sf::RenderWindow &window, sf::View &view);
        void eventHandler(sf::Event event, sf::RenderWindow &window);
        void update();
        sf::Vector2i getClicked(){return sf::Vector2i(0, 0);};
        void moveSprite(){};
        sf::Vector2f getSpritePosition(){return this->_sprite.getPosition();};
        void setHover(bool state);
        bool getIsHovered() {return this->_isHovered;};
        std::string getButtonName() {return this->_name;};
        void onClick(Menu::MenuState _state);

    protected:
    private:
        std::string _name;
        bool _isHovered;
        sf::Sprite _sprite;
        sf::Texture _idleTexture;
        sf::Texture _hoverTexture;
        sf::IntRect _rect;
        Menu* _menu;

};

#endif /* !BUTTON_HEADER_GUARD */
