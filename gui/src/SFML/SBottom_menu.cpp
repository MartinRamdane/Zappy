/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SBottom_menu
*/

#include <iostream>
#include "SBottom_menu.hpp"

SBottom_menu::SBottom_menu(int w_width, int w_height)
{
    this->createSprite(w_width, w_height);
    this->createTexts();
}

SBottom_menu::~SBottom_menu()
{
}

void SBottom_menu::createSprite(int w_width, int w_height)
{
    this->_textures["bottom_menu"] = std::make_shared<sf::Texture>();
    this->_textures["bottom_menu"]->loadFromFile("gui/assets/bottom_menu/HUD_Box.png");
    this->_sprites["bottom_menu"] = std::make_shared<sf::Sprite>();
    this->_sprites["bottom_menu"]->setTexture(*this->_textures["bottom_menu"]);
    this->_sprites["bottom_menu"]->setPosition(sf::Vector2f(w_width / 2, w_height - this->_sprites["bottom_menu"]->getGlobalBounds().height / 2));
    this->_sprites["bottom_menu"]->setOrigin(sf::Vector2f(this->_sprites["bottom_menu"]->getGlobalBounds().width / 2, this->_sprites["bottom_menu"]->getGlobalBounds().height / 2));
    this->_sprites["bottom_menu"]->setScale(sf::Vector2f(w_width / this->_sprites["bottom_menu"]->getGlobalBounds().width, w_height / this->_sprites["bottom_menu"]->getGlobalBounds().height * 0.2));

    this->_textures["food"] = std::make_shared<sf::Texture>();
    this->_textures["food"]->loadFromFile("gui/assets/gems/food.png");
    this->_sprites["food"] = std::make_shared<sf::Sprite>();
    this->_sprites["food"]->setTexture(*this->_textures["food"]);
    this->_sprites["food"]->setTextureRect(sf::IntRect(0, 0, 317, 306));
    this->_sprites["food"]->setScale(sf::Vector2f(w_width / this->_sprites["bottom_menu"]->getGlobalBounds().width, w_height / this->_sprites["bottom_menu"]->getGlobalBounds().height));
    this->_sprites["food"]->setOrigin(sf::Vector2f(this->_sprites["food"]->getGlobalBounds().width / 2, this->_sprites["food"]->getGlobalBounds().height / 2));

    this->_textures["linemate"] = std::make_shared<sf::Texture>();
    this->_textures["linemate"]->loadFromFile("gui/assets/gems/linemate.png");
    this->_sprites["linemate"] = std::make_shared<sf::Sprite>();
    this->_sprites["linemate"]->setTexture(*this->_textures["linemate"]);
    this->_sprites["linemate"]->setTextureRect(sf::IntRect(0, 0, 317, 306));
    this->_sprites["linemate"]->setScale(sf::Vector2f(w_width / this->_sprites["bottom_menu"]->getGlobalBounds().width, w_height / this->_sprites["bottom_menu"]->getGlobalBounds().height));
    this->_sprites["linemate"]->setOrigin(sf::Vector2f(this->_sprites["linemate"]->getGlobalBounds().width / 2, this->_sprites["linemate"]->getGlobalBounds().height / 2));

    this->_textures["deraumere"] = std::make_shared<sf::Texture>();
    this->_textures["deraumere"]->loadFromFile("gui/assets/gems/deraumere.png");
    this->_sprites["deraumere"] = std::make_shared<sf::Sprite>();
    this->_sprites["deraumere"]->setTexture(*this->_textures["deraumere"]);
    this->_sprites["deraumere"]->setTextureRect(sf::IntRect(0, 0, 317, 306));
    this->_sprites["deraumere"]->setOrigin(sf::Vector2f(this->_sprites["deraumere"]->getGlobalBounds().width / 2, this->_sprites["deraumere"]->getGlobalBounds().height / 2));

    this->_textures["sibur"] = std::make_shared<sf::Texture>();
    this->_textures["sibur"]->loadFromFile("gui/assets/gems/sibur.png");
    this->_sprites["sibur"] = std::make_shared<sf::Sprite>();
    this->_sprites["sibur"]->setTexture(*this->_textures["sibur"]);
    this->_sprites["sibur"]->setTextureRect(sf::IntRect(0, 0, 317, 306));
    this->_sprites["sibur"]->setOrigin(sf::Vector2f(this->_sprites["sibur"]->getGlobalBounds().width / 2, this->_sprites["sibur"]->getGlobalBounds().height / 2));

    this->_textures["mendiane"] = std::make_shared<sf::Texture>();
    this->_textures["mendiane"]->loadFromFile("gui/assets/gems/mendiane.png");
    this->_sprites["mendiane"] = std::make_shared<sf::Sprite>();
    this->_sprites["mendiane"]->setTexture(*this->_textures["mendiane"]);
    this->_sprites["mendiane"]->setTextureRect(sf::IntRect(0, 0, 317, 306));
    this->_sprites["mendiane"]->setOrigin(sf::Vector2f(this->_sprites["mendiane"]->getGlobalBounds().width / 2, this->_sprites["mendiane"]->getGlobalBounds().height / 2));

    this->_textures["phiras"] = std::make_shared<sf::Texture>();
    this->_textures["phiras"]->loadFromFile("gui/assets/gems/phiras.png");
    this->_sprites["phiras"] = std::make_shared<sf::Sprite>();
    this->_sprites["phiras"]->setTexture(*this->_textures["phiras"]);
    this->_sprites["phiras"]->setTextureRect(sf::IntRect(0, 0, 317, 306));
    this->_sprites["phiras"]->setOrigin(sf::Vector2f(this->_sprites["phiras"]->getGlobalBounds().width / 2, this->_sprites["phiras"]->getGlobalBounds().height / 2));

    this->_textures["thystame"] = std::make_shared<sf::Texture>();
    this->_textures["thystame"]->loadFromFile("gui/assets/gems/thystame.png");
    this->_sprites["thystame"] = std::make_shared<sf::Sprite>();
    this->_sprites["thystame"]->setTexture(*this->_textures["thystame"]);
    this->_sprites["thystame"]->setTextureRect(sf::IntRect(0, 0, 317, 306));
    this->_sprites["thystame"]->setOrigin(sf::Vector2f(this->_sprites["thystame"]->getGlobalBounds().width / 2, this->_sprites["thystame"]->getGlobalBounds().height / 2));

    float distance = this->_sprites["bottom_menu"]->getGlobalBounds().width / this->_sprites.size() - 1;

    auto it = this->_sprites.begin();
    it++;

    for (int i = 0; it != this->_sprites.end(); it++, i++) {
        std::cout << it->first << std::endl;
        float scale = distance / it->second->getGlobalBounds().width;
        it->second->setScale(sf::Vector2f(scale * 0.5, scale * 0.5));
        it->second->setPosition(sf::Vector2f(this->_sprites["bottom_menu"]->getPosition().x - this->_sprites["bottom_menu"]->getGlobalBounds().width / 2 + 140 + (i * distance), this->_sprites["bottom_menu"]->getPosition().y - this->_sprites["bottom_menu"]->getGlobalBounds().height / 2 + 100));
    }
}


void SBottom_menu::createTexts()
{
    this->_font.loadFromFile("gui/assets/fonts/EightBitDragon-anqx.ttf");
    this->_texts["food"] = std::make_shared<sf::Text>();
    this->_texts["food"]->setFont(this->_font);
    this->_texts["food"]->setString("0");
    this->_texts["food"]->setCharacterSize(20);
    this->_texts["food"]->setFillColor(sf::Color::White);

    this->_texts["linemate"] = std::make_shared<sf::Text>();
    this->_texts["linemate"]->setFont(this->_font);
    this->_texts["linemate"]->setString("0");
    this->_texts["linemate"]->setCharacterSize(20);
    this->_texts["linemate"]->setFillColor(sf::Color::White);

    this->_texts["deraumere"] = std::make_shared<sf::Text>();
    this->_texts["deraumere"]->setFont(this->_font);
    this->_texts["deraumere"]->setString("0");
    this->_texts["deraumere"]->setCharacterSize(20);
    this->_texts["deraumere"]->setFillColor(sf::Color::White);

    this->_texts["sibur"] = std::make_shared<sf::Text>();
    this->_texts["sibur"]->setFont(this->_font);
    this->_texts["sibur"]->setString("0");
    this->_texts["sibur"]->setCharacterSize(20);
    this->_texts["sibur"]->setFillColor(sf::Color::White);

    this->_texts["mendiane"] = std::make_shared<sf::Text>();
    this->_texts["mendiane"]->setFont(this->_font);
    this->_texts["mendiane"]->setString("0");
    this->_texts["mendiane"]->setCharacterSize(20);
    this->_texts["mendiane"]->setFillColor(sf::Color::White);

    this->_texts["phiras"] = std::make_shared<sf::Text>();
    this->_texts["phiras"]->setFont(this->_font);
    this->_texts["phiras"]->setString("0");
    this->_texts["phiras"]->setCharacterSize(20);
    this->_texts["phiras"]->setFillColor(sf::Color::White);

    this->_texts["thystame"] = std::make_shared<sf::Text>();
    this->_texts["thystame"]->setFont(this->_font);
    this->_texts["thystame"]->setString("0");
    this->_texts["thystame"]->setCharacterSize(20);
    this->_texts["thystame"]->setFillColor(sf::Color::White);

    float distance = this->_sprites["bottom_menu"]->getGlobalBounds().width / this->_texts.size() - 1;

    auto it = this->_texts.begin();
    it++;
    for (int i = 0; it != this->_texts.end(); it++, i++) {
        it->second->setPosition(sf::Vector2f(this->_sprites["bottom_menu"]->getPosition().x - this->_sprites["bottom_menu"]->getGlobalBounds().width / 2 + 140 + (i * distance), this->_sprites["bottom_menu"]->getPosition().y - this->_sprites["bottom_menu"]->getGlobalBounds().height / 2 + 100));
    }
}

void SBottom_menu::draw(sf::RenderWindow &window)
{
    for (auto &sprite : this->_sprites)
        window.draw(*sprite.second);

    for (auto &text : this->_texts)
        window.draw(*text.second);
}

void SBottom_menu::update(std::map<std::string, int> stock)
{
    this->_texts["food"]->setString(std::to_string(stock["food"]));
    this->_texts["linemate"]->setString(std::to_string(stock["linemate"]));
    this->_texts["deraumere"]->setString(std::to_string(stock["deraumere"]));
    this->_texts["sibur"]->setString(std::to_string(stock["sibur"]));
    this->_texts["mendiane"]->setString(std::to_string(stock["mendiane"]));
    this->_texts["phiras"]->setString(std::to_string(stock["phiras"]));
    this->_texts["thystame"]->setString(std::to_string(stock["thystame"]));
}
