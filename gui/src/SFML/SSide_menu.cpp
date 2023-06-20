/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SSide_menu
*/

#include <iostream>
#include "SSide_menu.hpp"

SSide_menu::SSide_menu(int w_width, int w_height)
{
    this->createSprite(w_width, w_height);
    this->createTexts();
}

SSide_menu::~SSide_menu()
{
    this->_sprites.clear();
    this->_textures.clear();
    this->_texts.clear();
}

void SSide_menu::createSprite(int w_width, int w_height)
{
    this->_textures["bottom_menu"] = sf::Texture();
    this->_textures["bottom_menu"].loadFromFile("gui/assets/bottom_menu/HUD_Box.png");
    this->_sprites["bottom_menu"] = sf::Sprite();
    this->_sprites["bottom_menu"].setTexture(this->_textures["bottom_menu"]);
    this->_sprites["bottom_menu"].setScale(sf::Vector2f(w_width / this->_sprites["bottom_menu"].getGlobalBounds().width * 0.3, w_height / this->_sprites["bottom_menu"].getGlobalBounds().height * 0.7));
    this->_sprites["bottom_menu"].setPosition(sf::Vector2f(0, 0));
    this->_sprites["bottom_menu"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_textures["food"] = sf::Texture();
    this->_textures["food"].loadFromFile("gui/assets/gems/food.png");
    this->_sprites["food"] = sf::Sprite();
    this->_sprites["food"].setTexture(this->_textures["food"]);
    this->_sprites["food"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["food"].setOrigin(sf::Vector2f(this->_sprites["food"].getGlobalBounds().width / 2, this->_sprites["food"].getGlobalBounds().height / 2));
    this->_sprites["food"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_textures["linemate"] = sf::Texture();
    this->_textures["linemate"].loadFromFile("gui/assets/gems/linemate.png");
    this->_sprites["linemate"] = sf::Sprite();
    this->_sprites["linemate"].setTexture(this->_textures["linemate"]);
    this->_sprites["linemate"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["linemate"].setOrigin(sf::Vector2f(this->_sprites["linemate"].getGlobalBounds().width / 2, this->_sprites["linemate"].getGlobalBounds().height / 2));
    this->_sprites["linemate"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_textures["deraumere"] = sf::Texture();
    this->_textures["deraumere"].loadFromFile("gui/assets/gems/deraumere.png");
    this->_sprites["deraumere"] = sf::Sprite();
    this->_sprites["deraumere"].setTexture(this->_textures["deraumere"]);
    this->_sprites["deraumere"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["deraumere"].setOrigin(sf::Vector2f(this->_sprites["deraumere"].getGlobalBounds().width / 2, this->_sprites["deraumere"].getGlobalBounds().height / 2));
    this->_sprites["deraumere"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_textures["sibur"] = sf::Texture();
    this->_textures["sibur"].loadFromFile("gui/assets/gems/sibur.png");
    this->_sprites["sibur"] = sf::Sprite();
    this->_sprites["sibur"].setTexture(this->_textures["sibur"]);
    this->_sprites["sibur"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["sibur"].setOrigin(sf::Vector2f(this->_sprites["sibur"].getGlobalBounds().width / 2, this->_sprites["sibur"].getGlobalBounds().height / 2));
    this->_sprites["sibur"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_textures["mendiane"] = sf::Texture();
    this->_textures["mendiane"].loadFromFile("gui/assets/gems/mendiane.png");
    this->_sprites["mendiane"] = sf::Sprite();
    this->_sprites["mendiane"].setTexture(this->_textures["mendiane"]);
    this->_sprites["mendiane"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["mendiane"].setOrigin(sf::Vector2f(this->_sprites["mendiane"].getGlobalBounds().width / 2, this->_sprites["mendiane"].getGlobalBounds().height / 2));
    this->_sprites["mendiane"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_textures["phiras"] = sf::Texture();
    this->_textures["phiras"].loadFromFile("gui/assets/gems/phiras.png");
    this->_sprites["phiras"] = sf::Sprite();
    this->_sprites["phiras"].setTexture(this->_textures["phiras"]);
    this->_sprites["phiras"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["phiras"].setOrigin(sf::Vector2f(this->_sprites["phiras"].getGlobalBounds().width / 2, this->_sprites["phiras"].getGlobalBounds().height / 2));
    this->_sprites["phiras"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_textures["thystame"] = sf::Texture();
    this->_textures["thystame"].loadFromFile("gui/assets/gems/thystame.png");
    this->_sprites["thystame"] = sf::Sprite();
    this->_sprites["thystame"].setTexture(this->_textures["thystame"]);
    this->_sprites["thystame"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["thystame"].setOrigin(sf::Vector2f(this->_sprites["thystame"].getGlobalBounds().width / 2, this->_sprites["thystame"].getGlobalBounds().height / 2));
    this->_sprites["thystame"].setColor(sf::Color(255, 255, 255, this->_opacity));

    float distance = this->_sprites["bottom_menu"].getGlobalBounds().height / this->_sprites.size();
    float scale;

    this->_sprites["food"].setPosition(sf::Vector2f(this->_sprites["bottom_menu"].getPosition().x + this->_sprites["bottom_menu"].getGlobalBounds().width / 4, this->_sprites["bottom_menu"].getPosition().y - this->_sprites["bottom_menu"].getGlobalBounds().height / 4 + (distance * 3.6)));
    scale = distance / this->_sprites["food"].getGlobalBounds().height;
    this->_sprites["food"].setScale(sf::Vector2f(scale * 0.5, scale * 0.5));

    this->_sprites["linemate"].setPosition(sf::Vector2f(this->_sprites["bottom_menu"].getPosition().x + this->_sprites["bottom_menu"].getGlobalBounds().width / 4, this->_sprites["food"].getPosition().y + (distance * 0.85)));
    scale = distance / this->_sprites["linemate"].getGlobalBounds().height;
    this->_sprites["linemate"].setScale(sf::Vector2f(scale * 0.5, scale * 0.5));

    this->_sprites["deraumere"].setPosition(sf::Vector2f(this->_sprites["bottom_menu"].getPosition().x + this->_sprites["bottom_menu"].getGlobalBounds().width / 4, this->_sprites["linemate"].getPosition().y + (distance * 0.85)));
    scale = distance / this->_sprites["deraumere"].getGlobalBounds().height;
    this->_sprites["deraumere"].setScale(sf::Vector2f(scale * 0.5, scale * 0.5));

    this->_sprites["sibur"].setPosition(sf::Vector2f(this->_sprites["bottom_menu"].getPosition().x + this->_sprites["bottom_menu"].getGlobalBounds().width / 4, this->_sprites["deraumere"].getPosition().y + (distance * 0.85)));
    scale = distance / this->_sprites["sibur"].getGlobalBounds().height;
    this->_sprites["sibur"].setScale(sf::Vector2f(scale * 0.5, scale * 0.5));

    this->_sprites["mendiane"].setPosition(sf::Vector2f(this->_sprites["bottom_menu"].getPosition().x + this->_sprites["bottom_menu"].getGlobalBounds().width / 4, this->_sprites["sibur"].getPosition().y + (distance * 0.85)));
    scale = distance / this->_sprites["mendiane"].getGlobalBounds().height;
    this->_sprites["mendiane"].setScale(sf::Vector2f(scale * 0.5, scale * 0.5));

    this->_sprites["phiras"].setPosition(sf::Vector2f(this->_sprites["bottom_menu"].getPosition().x + this->_sprites["bottom_menu"].getGlobalBounds().width / 4, this->_sprites["mendiane"].getPosition().y + (distance * 0.85)));
    scale = distance / this->_sprites["phiras"].getGlobalBounds().height;
    this->_sprites["phiras"].setScale(sf::Vector2f(scale * 0.5, scale * 0.5));

    this->_sprites["thystame"].setPosition(sf::Vector2f(this->_sprites["bottom_menu"].getPosition().x + this->_sprites["bottom_menu"].getGlobalBounds().width / 4, this->_sprites["phiras"].getPosition().y + (distance * 0.85)));
    scale = distance / this->_sprites["thystame"].getGlobalBounds().height;
    this->_sprites["thystame"].setScale(sf::Vector2f(scale * 0.5, scale * 0.5));
}


void SSide_menu::createTexts()
{
    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    this->_texts["food"] = sf::Text();
    this->_texts["food"].setFont(this->_font);
    this->_texts["food"].setString("0");
    this->_texts["food"].setCharacterSize(40);
    this->_texts["food"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["foodName"] = sf::Text();
    this->_texts["foodName"].setFont(this->_font);
    this->_texts["foodName"].setString("Food");
    this->_texts["foodName"].setCharacterSize(40);
    this->_texts["foodName"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["linemate"] = sf::Text();
    this->_texts["linemate"].setFont(this->_font);
    this->_texts["linemate"].setString("0");
    this->_texts["linemate"].setCharacterSize(40);
    this->_texts["linemate"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["linemateName"] = sf::Text();
    this->_texts["linemateName"].setFont(this->_font);
    this->_texts["linemateName"].setString("Linemate");
    this->_texts["linemateName"].setCharacterSize(35);
    this->_texts["linemateName"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["deraumere"] = sf::Text();
    this->_texts["deraumere"].setFont(this->_font);
    this->_texts["deraumere"].setString("0");
    this->_texts["deraumere"].setCharacterSize(40);
    this->_texts["deraumere"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["deraumereName"] = sf::Text();
    this->_texts["deraumereName"].setFont(this->_font);
    this->_texts["deraumereName"].setString("Deraumere");
    this->_texts["deraumereName"].setCharacterSize(35);
    this->_texts["deraumereName"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["sibur"] = sf::Text();
    this->_texts["sibur"].setFont(this->_font);
    this->_texts["sibur"].setString("0");
    this->_texts["sibur"].setCharacterSize(40);
    this->_texts["sibur"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["siburName"] = sf::Text();
    this->_texts["siburName"].setFont(this->_font);
    this->_texts["siburName"].setString("Sibur");
    this->_texts["siburName"].setCharacterSize(35);
    this->_texts["siburName"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["mendiane"] = sf::Text();
    this->_texts["mendiane"].setFont(this->_font);
    this->_texts["mendiane"].setString("0");
    this->_texts["mendiane"].setCharacterSize(40);
    this->_texts["mendiane"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["mendianeName"] = sf::Text();
    this->_texts["mendianeName"].setFont(this->_font);
    this->_texts["mendianeName"].setString("Mendiane");
    this->_texts["mendianeName"].setCharacterSize(35);
    this->_texts["mendianeName"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["phiras"] = sf::Text();
    this->_texts["phiras"].setFont(this->_font);
    this->_texts["phiras"].setString("0");
    this->_texts["phiras"].setCharacterSize(40);
    this->_texts["phiras"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["phirasName"] = sf::Text();
    this->_texts["phirasName"].setFont(this->_font);
    this->_texts["phirasName"].setString("Phiras");
    this->_texts["phirasName"].setCharacterSize(35);
    this->_texts["phirasName"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["thystame"] = sf::Text();
    this->_texts["thystame"].setFont(this->_font);
    this->_texts["thystame"].setString("0");
    this->_texts["thystame"].setCharacterSize(40);
    this->_texts["thystame"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    this->_texts["thystameName"] = sf::Text();
    this->_texts["thystameName"].setFont(this->_font);
    this->_texts["thystameName"].setString("Thystame");
    this->_texts["thystameName"].setCharacterSize(70);
    this->_texts["thystameName"].setFillColor(sf::Color(13, 144, 104, this->_opacity));

    float scale;

    this->_texts["foodName"].setPosition(sf::Vector2f(this->_sprites["food"].getPosition().x + this->_sprites["food"].getGlobalBounds().width, this->_sprites["food"].getPosition().y - this->_sprites["food"].getGlobalBounds().height / 2));
    scale = this->_sprites["food"].getGlobalBounds().height / this->_texts["foodName"].getGlobalBounds().height * 0.4;
    this->_texts["foodName"].setScale(sf::Vector2f(scale, scale));

    this->_texts["linemateName"].setPosition(sf::Vector2f(this->_sprites["linemate"].getPosition().x + this->_sprites["linemate"].getGlobalBounds().width, this->_sprites["linemate"].getPosition().y - this->_sprites["linemate"].getGlobalBounds().height / 2));
    scale = this->_sprites["linemate"].getGlobalBounds().height / this->_texts["linemateName"].getGlobalBounds().height * 0.4;
    this->_texts["linemateName"].setScale(sf::Vector2f(scale, scale));

    this->_texts["deraumereName"].setPosition(sf::Vector2f(this->_sprites["deraumere"].getPosition().x + this->_sprites["deraumere"].getGlobalBounds().width, this->_sprites["deraumere"].getPosition().y - this->_sprites["deraumere"].getGlobalBounds().height / 2));
    scale = this->_sprites["deraumere"].getGlobalBounds().height / this->_texts["deraumereName"].getGlobalBounds().height * 0.4;
    this->_texts["deraumereName"].setScale(sf::Vector2f(scale, scale));

    this->_texts["siburName"].setPosition(sf::Vector2f(this->_sprites["sibur"].getPosition().x + this->_sprites["sibur"].getGlobalBounds().width, this->_sprites["sibur"].getPosition().y - this->_sprites["sibur"].getGlobalBounds().height / 2));
    scale = this->_sprites["sibur"].getGlobalBounds().height / this->_texts["siburName"].getGlobalBounds().height * 0.4;
    this->_texts["siburName"].setScale(sf::Vector2f(scale, scale));

    this->_texts["mendianeName"].setPosition(sf::Vector2f(this->_sprites["mendiane"].getPosition().x + this->_sprites["mendiane"].getGlobalBounds().width, this->_sprites["mendiane"].getPosition().y - this->_sprites["mendiane"].getGlobalBounds().height / 2));
    scale = this->_sprites["mendiane"].getGlobalBounds().height / this->_texts["mendianeName"].getGlobalBounds().height * 0.4;
    this->_texts["mendianeName"].setScale(sf::Vector2f(scale, scale));

    this->_texts["phirasName"].setPosition(sf::Vector2f(this->_sprites["phiras"].getPosition().x + this->_sprites["phiras"].getGlobalBounds().width, this->_sprites["phiras"].getPosition().y - this->_sprites["phiras"].getGlobalBounds().height / 2));
    scale = this->_sprites["phiras"].getGlobalBounds().height / this->_texts["phirasName"].getGlobalBounds().height * 0.4;
    this->_texts["phirasName"].setScale(sf::Vector2f(scale, scale));

    this->_texts["thystameName"].setPosition(sf::Vector2f(this->_sprites["thystame"].getPosition().x + this->_sprites["thystame"].getGlobalBounds().width, this->_sprites["thystame"].getPosition().y - this->_sprites["thystame"].getGlobalBounds().height / 2));
    scale = this->_sprites["thystame"].getGlobalBounds().height / this->_texts["thystameName"].getGlobalBounds().height * 0.55;
    this->_texts["thystameName"].setScale(sf::Vector2f(scale, scale));

    this->_texts["food"].setPosition(sf::Vector2f(this->_texts["foodName"].getPosition().x + this->_texts["foodName"].getGlobalBounds().width * 1.3, this->_texts["foodName"].getPosition().y - this->_texts["foodName"].getGlobalBounds().height / 2 * 0.2));
    scale = this->_sprites["food"].getGlobalBounds().height / this->_texts["food"].getGlobalBounds().height * 0.4;
    this->_texts["food"].setScale(sf::Vector2f(scale, scale));

    this->_texts["linemate"].setPosition(sf::Vector2f(this->_texts["linemateName"].getPosition().x + this->_texts["linemateName"].getGlobalBounds().width * 1.3, this->_texts["linemateName"].getPosition().y - this->_texts["linemateName"].getGlobalBounds().height / 2 * 0.2));
    scale = this->_sprites["linemate"].getGlobalBounds().height / this->_texts["linemate"].getGlobalBounds().height * 0.4;
    this->_texts["linemate"].setScale(sf::Vector2f(scale, scale));

    this->_texts["deraumere"].setPosition(sf::Vector2f(this->_texts["deraumereName"].getPosition().x + this->_texts["deraumereName"].getGlobalBounds().width * 1.1, this->_texts["deraumereName"].getPosition().y - this->_texts["deraumereName"].getGlobalBounds().height / 2 * 0.2));
    scale = this->_sprites["deraumere"].getGlobalBounds().height / this->_texts["deraumere"].getGlobalBounds().height * 0.4;
    this->_texts["deraumere"].setScale(sf::Vector2f(scale, scale));

    this->_texts["sibur"].setPosition(sf::Vector2f(this->_texts["siburName"].getPosition().x + this->_texts["siburName"].getGlobalBounds().width * 1.3, this->_texts["siburName"].getPosition().y - this->_texts["siburName"].getGlobalBounds().height / 2 * 0.2));
    scale = this->_sprites["sibur"].getGlobalBounds().height / this->_texts["sibur"].getGlobalBounds().height * 0.4;
    this->_texts["sibur"].setScale(sf::Vector2f(scale, scale));

    this->_texts["mendiane"].setPosition(sf::Vector2f(this->_texts["mendianeName"].getPosition().x + this->_texts["mendianeName"].getGlobalBounds().width * 1.3, this->_texts["mendianeName"].getPosition().y - this->_texts["mendianeName"].getGlobalBounds().height / 2 * 0.2));
    scale = this->_sprites["mendiane"].getGlobalBounds().height / this->_texts["mendiane"].getGlobalBounds().height * 0.4;
    this->_texts["mendiane"].setScale(sf::Vector2f(scale, scale));

    this->_texts["phiras"].setPosition(sf::Vector2f(this->_texts["phirasName"].getPosition().x + this->_texts["phirasName"].getGlobalBounds().width * 1.3, this->_texts["phirasName"].getPosition().y - this->_texts["phirasName"].getGlobalBounds().height / 2 * 0.2));
    scale = this->_sprites["phiras"].getGlobalBounds().height / this->_texts["phiras"].getGlobalBounds().height * 0.4;
    this->_texts["phiras"].setScale(sf::Vector2f(scale, scale));

    this->_texts["thystame"].setPosition(sf::Vector2f(this->_texts["thystameName"].getPosition().x + this->_texts["thystameName"].getGlobalBounds().width * 1.3, this->_texts["thystameName"].getPosition().y - this->_texts["thystameName"].getGlobalBounds().height / 2 * 0.2));
    scale = this->_sprites["thystame"].getGlobalBounds().height / this->_texts["thystame"].getGlobalBounds().height * 0.4;
    this->_texts["thystame"].setScale(sf::Vector2f(scale, scale));
}

void SSide_menu::draw(sf::RenderWindow &window)
{
    for (auto &sprite : this->_sprites)
        window.draw(sprite.second);

    for (auto &text : this->_texts)
        window.draw(text.second);
}

void SSide_menu::update(std::map<std::string, int> stock)
{
    if (this->_clock.getElapsedTime().asSeconds() >= 0.01) {
        if (this->_opacity < 255 && this->_isFading)
            this->_opacity += 15;
        if (this->_opacity > 0 && this->_isFadingOut)
            this->_opacity -= 15;
        for (auto &sprite : this->_sprites)
            sprite.second.setColor(sf::Color(255, 255, 255, this->_opacity));
        for (auto &text : this->_texts)
            text.second.setFillColor(sf::Color(13, 144, 104, this->_opacity));
        this->_clock.restart();
    }

    this->_texts["food"].setString(std::to_string(stock["food"]) + "x");
    this->_texts["linemate"].setString(std::to_string(stock["linemate"]) + "x");
    this->_texts["deraumere"].setString(std::to_string(stock["deraumere"]) + "x");
    this->_texts["sibur"].setString(std::to_string(stock["sibur"]) + "x");
    this->_texts["mendiane"].setString(std::to_string(stock["mendiane"]) + "x");
    this->_texts["phiras"].setString(std::to_string(stock["phiras"]) + "x");
    this->_texts["thystame"].setString(std::to_string(stock["thystame"]) + "x");
}

void SSide_menu::fadeIn(bool isFading)
{
    this->_isFading = isFading;
}

void SSide_menu::fadeOut(bool isFading)
{
    this->_isFadingOut = isFading;
}
