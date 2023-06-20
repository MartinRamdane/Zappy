/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SInventory
*/

#include <iostream>
#include "SInventory.hpp"

SInventory::SInventory(int w_width, int w_height, ResourceManager *_resourceManager)
{
    this->_resourceManager = _resourceManager;
    this->createSprite(w_width, w_height);
    this->createTexts();
}

SInventory::~SInventory()
{
}

void SInventory::createSprite(int w_width, int w_height)
{
    this->_textures["inventory"] = sf::Texture();
    this->_textures["inventory"].loadFromFile("gui/assets/inventory/inventory.png");
    this->_sprites["inventory"] = sf::Sprite();
    this->_sprites["inventory"].setTexture(this->_textures["inventory"]);
    this->_sprites["inventory"].setScale(1.5, 1.5);
    this->_sprites["inventory"].setPosition(w_width - this->_sprites["inventory"].getGlobalBounds().width - 20, 40);

    this->_textures["display"] = sf::Texture();
    this->_textures["display"].loadFromFile("gui/assets/inventory/player_display.png");
    this->_sprites["display"] = sf::Sprite();
    this->_sprites["display"].setTexture(this->_textures["display"]);
    this->_sprites["display"].setScale(1.5, 1.5);
    this->_sprites["display"].setPosition(this->_sprites["inventory"].getPosition().x - this->_sprites["display"].getGlobalBounds().width, this->_sprites["inventory"].getPosition().y + 6);

    this->_textures["trantorian"] = sf::Texture();
    this->_sprites["trantorian"] = sf::Sprite();
    this->_sprites["trantorian"].setTextureRect(sf::IntRect(0, 0, 48, 48));
    this->_sprites["trantorian"].setColor(sf::Color(255, 255, 255, this->_opacity));
    this->_sprites["trantorian"].setScale(6, 6);
    this->_rect = sf::IntRect(0, 0, 48, 48);
    this->_sprites["trantorian"].setPosition(this->_sprites["display"].getPosition().x + 30, this->_sprites["display"].getPosition().y + 20);

    this->_textures["food"] = sf::Texture();
    this->_textures["food"].loadFromFile("gui/assets/gems/food.png");
    this->_sprites["food"] = sf::Sprite();
    this->_sprites["food"].setTexture(this->_textures["food"]);
    this->_sprites["food"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["food"].setPosition(this->_sprites["inventory"].getPosition().x + 35, this->_sprites["inventory"].getPosition().y + 50);
    this->_sprites["food"].setScale(3.5, 3.5);

    this->_textures["linemate"] = sf::Texture();
    this->_textures["linemate"].loadFromFile("gui/assets/gems/linemate.png");
    this->_sprites["linemate"] = sf::Sprite();
    this->_sprites["linemate"].setTexture(this->_textures["linemate"]);
    this->_sprites["linemate"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["linemate"].setPosition(this->_sprites["food"].getPosition().x + 93, this->_sprites["inventory"].getPosition().y + 50);
    this->_sprites["linemate"].setScale(3.5, 3.5);

    this->_textures["deraumere"] = sf::Texture();
    this->_textures["deraumere"].loadFromFile("gui/assets/gems/deraumere.png");
    this->_sprites["deraumere"] = sf::Sprite();
    this->_sprites["deraumere"].setTexture(this->_textures["deraumere"]);
    this->_sprites["deraumere"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["deraumere"].setPosition(this->_sprites["linemate"].getPosition().x + 90, this->_sprites["inventory"].getPosition().y + 50);
    this->_sprites["deraumere"].setScale(3.5, 3.5);

    this->_textures["sibur"] = sf::Texture();
    this->_textures["sibur"].loadFromFile("gui/assets/gems/sibur.png");
    this->_sprites["sibur"] = sf::Sprite();
    this->_sprites["sibur"].setTexture(this->_textures["sibur"]);
    this->_sprites["sibur"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["sibur"].setPosition(this->_sprites["deraumere"].getPosition().x + 89, this->_sprites["inventory"].getPosition().y + 50);
    this->_sprites["sibur"].setScale(3.5, 3.5);

    this->_textures["mendiane"] = sf::Texture();
    this->_textures["mendiane"].loadFromFile("gui/assets/gems/mendiane.png");
    this->_sprites["mendiane"] = sf::Sprite();
    this->_sprites["mendiane"].setTexture(this->_textures["mendiane"]);
    this->_sprites["mendiane"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["mendiane"].setPosition(this->_sprites["sibur"].getPosition().x + 93, this->_sprites["inventory"].getPosition().y + 50);
    this->_sprites["mendiane"].setScale(3.5, 3.5);

    this->_textures["phiras"] = sf::Texture();
    this->_textures["phiras"].loadFromFile("gui/assets/gems/phiras.png");
    this->_sprites["phiras"] = sf::Sprite();
    this->_sprites["phiras"].setTexture(this->_textures["phiras"]);
    this->_sprites["phiras"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["phiras"].setPosition(this->_sprites["inventory"].getPosition().x + 490, this->_sprites["inventory"].getPosition().y + 50);
    this->_sprites["phiras"].setScale(3.5, 3.5);

    this->_textures["thystame"] = sf::Texture();
    this->_textures["thystame"].loadFromFile("gui/assets/gems/thystame.png");
    this->_sprites["thystame"] = sf::Sprite();
    this->_sprites["thystame"].setTexture(this->_textures["thystame"]);
    this->_sprites["thystame"].setTextureRect(sf::IntRect(0, 0, 16, 16));
    this->_sprites["thystame"].setPosition(this->_sprites["inventory"].getPosition().x + 35, this->_sprites["inventory"].getPosition().y + 135);
    this->_sprites["thystame"].setScale(3.5, 3.5);

    this->_textures["close"] = sf::Texture();
    this->_textures["close"].loadFromFile("gui/assets/close.png");
    this->_sprites["close"] = sf::Sprite();
    this->_sprites["close"].setTexture(this->_textures["close"]);
    this->_sprites["close"].setTextureRect(sf::IntRect(0, 0, 200, 200));
    this->_sprites["close"].setPosition(this->_sprites["display"].getPosition().x, this->_sprites["display"].getPosition().y);
    this->_sprites["close"].setScale(0.25, 0.25);

    this->_background.setSize(sf::Vector2f(180, 50));
    this->_background.setFillColor(sf::Color(0, 0, 0, 0));
    this->_background.setPosition(this->_sprites["close"].getPosition().x + 10, this->_sprites["close"].getPosition().y + 10);

    for (auto &sprite : this->_sprites)
        sprite.second.setColor(sf::Color(255, 255, 255, this->_opacity));
}


void SInventory::createTexts()
{
    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    this->_texts["food"] = sf::Text();
    this->_texts["food"].setFont(this->_font);
    this->_texts["food"].setString("0x");
    this->_texts["food"].setCharacterSize(30);
    this->_texts["food"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["food"].setPosition(this->_sprites["food"].getPosition().x + 33, this->_sprites["food"].getPosition().y + 25);

    this->_texts["foodName"] = sf::Text();
    this->_texts["foodName"].setFont(this->_font);
    this->_texts["foodName"].setString("Food");
    this->_texts["foodName"].setCharacterSize(35);
    this->_texts["foodName"].setFillColor(sf::Color(255, 255, 255, 0));
    this->_texts["foodName"].setPosition(this->_sprites["food"].getPosition().x + 35, this->_sprites["food"].getPosition().y + 55);

    this->_texts["linemate"] = sf::Text();
    this->_texts["linemate"].setFont(this->_font);
    this->_texts["linemate"].setString("0x");
    this->_texts["linemate"].setCharacterSize(30);
    this->_texts["linemate"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["linemate"].setPosition(this->_sprites["linemate"].getPosition().x + 33, this->_sprites["linemate"].getPosition().y + 25);

    this->_texts["linemateName"] = sf::Text();
    this->_texts["linemateName"].setFont(this->_font);
    this->_texts["linemateName"].setString("Linemate");
    this->_texts["linemateName"].setCharacterSize(35);
    this->_texts["linemateName"].setFillColor(sf::Color(255, 255, 255, 0));
    this->_texts["linemateName"].setPosition(this->_sprites["linemate"].getPosition().x + 35, this->_sprites["linemate"].getPosition().y + 55);

    this->_texts["deraumere"] = sf::Text();
    this->_texts["deraumere"].setFont(this->_font);
    this->_texts["deraumere"].setString("0x");
    this->_texts["deraumere"].setCharacterSize(30);
    this->_texts["deraumere"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["deraumere"].setPosition(this->_sprites["deraumere"].getPosition().x + 33, this->_sprites["deraumere"].getPosition().y + 25);

    this->_texts["deraumereName"] = sf::Text();
    this->_texts["deraumereName"].setFont(this->_font);
    this->_texts["deraumereName"].setString("Deraumere");
    this->_texts["deraumereName"].setCharacterSize(35);
    this->_texts["deraumereName"].setFillColor(sf::Color(255, 255, 255, 0));
    this->_texts["deraumereName"].setPosition(this->_sprites["deraumere"].getPosition().x + 35, this->_sprites["deraumere"].getPosition().y + 55);

    this->_texts["sibur"] = sf::Text();
    this->_texts["sibur"].setFont(this->_font);
    this->_texts["sibur"].setString("0x");
    this->_texts["sibur"].setCharacterSize(30);
    this->_texts["sibur"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["sibur"].setPosition(this->_sprites["sibur"].getPosition().x + 33, this->_sprites["sibur"].getPosition().y + 25);

    this->_texts["siburName"] = sf::Text();
    this->_texts["siburName"].setFont(this->_font);
    this->_texts["siburName"].setString("Sibur");
    this->_texts["siburName"].setCharacterSize(35);
    this->_texts["siburName"].setFillColor(sf::Color(255, 255, 255, 0));
    this->_texts["siburName"].setPosition(this->_sprites["sibur"].getPosition().x + 35, this->_sprites["sibur"].getPosition().y + 55);

    this->_texts["mendiane"] = sf::Text();
    this->_texts["mendiane"].setFont(this->_font);
    this->_texts["mendiane"].setString("0x");
    this->_texts["mendiane"].setCharacterSize(30);
    this->_texts["mendiane"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["mendiane"].setPosition(this->_sprites["mendiane"].getPosition().x + 33, this->_sprites["mendiane"].getPosition().y + 25);

    this->_texts["mendianeName"] = sf::Text();
    this->_texts["mendianeName"].setFont(this->_font);
    this->_texts["mendianeName"].setString("Mendiane");
    this->_texts["mendianeName"].setCharacterSize(35);
    this->_texts["mendianeName"].setFillColor(sf::Color(255, 255, 255, 0));
    this->_texts["mendianeName"].setPosition(this->_sprites["mendiane"].getPosition().x + 35, this->_sprites["mendiane"].getPosition().y + 55);

    this->_texts["phiras"] = sf::Text();
    this->_texts["phiras"].setFont(this->_font);
    this->_texts["phiras"].setString("0x");
    this->_texts["phiras"].setCharacterSize(30);
    this->_texts["phiras"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["phiras"].setPosition(this->_sprites["phiras"].getPosition().x + 33, this->_sprites["phiras"].getPosition().y + 25);

    this->_texts["phirasName"] = sf::Text();
    this->_texts["phirasName"].setFont(this->_font);
    this->_texts["phirasName"].setString("Phiras");
    this->_texts["phirasName"].setCharacterSize(35);
    this->_texts["phirasName"].setFillColor(sf::Color(255, 255, 255, 0));
    this->_texts["phirasName"].setPosition(this->_sprites["phiras"].getPosition().x + 35, this->_sprites["phiras"].getPosition().y + 55);

    this->_texts["thystame"] = sf::Text();
    this->_texts["thystame"].setFont(this->_font);
    this->_texts["thystame"].setString("0x");
    this->_texts["thystame"].setCharacterSize(30);
    this->_texts["thystame"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["thystame"].setPosition(this->_sprites["thystame"].getPosition().x + 33, this->_sprites["thystame"].getPosition().y + 25);

    this->_texts["thystameName"] = sf::Text();
    this->_texts["thystameName"].setFont(this->_font);
    this->_texts["thystameName"].setString("Thystame");
    this->_texts["thystameName"].setCharacterSize(35);
    this->_texts["thystameName"].setFillColor(sf::Color(255, 255, 255, 0));
    this->_texts["thystameName"].setPosition(this->_sprites["thystame"].getPosition().x + 35, this->_sprites["thystame"].getPosition().y + 55);

    this->_texts["team"] = sf::Text();
    this->_texts["team"].setFont(this->_font);
    this->_texts["team"].setString("Team");
    this->_texts["team"].setCharacterSize(40);
    this->_texts["team"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["team"].setPosition(this->_sprites["trantorian"].getPosition().x + 35, this->_sprites["trantorian"].getPosition().y + 240);

    this->_texts["lvl"] = sf::Text();
    this->_texts["lvl"].setFont(this->_font);
    this->_texts["lvl"].setString("Lvl");
    this->_texts["lvl"].setCharacterSize(40);
    this->_texts["lvl"].setFillColor(sf::Color(255, 255, 255, this->_opacity));
    this->_texts["lvl"].setPosition(this->_sprites["trantorian"].getPosition().x + 35, this->_sprites["trantorian"].getPosition().y + 300);
}

void SInventory::draw(sf::RenderWindow &window)
{
    for (auto &sprite : this->_sprites) {
        if (sprite.first == "food" || sprite.first == "deraumere" || sprite.first == "close")
            continue;
        window.draw(sprite.second);
    }

    window.draw(this->_sprites["food"]);
    window.draw(this->_sprites["deraumere"]);
    window.draw(this->_sprites["close"]);

    window.draw(this->_background);
    for (auto &text : this->_texts) {
        window.draw(text.second);
    }
}

void SInventory::update(std::map<std::string, int> stock, std::string team, int lvl)
{
    this->_texts["food"].setString(std::to_string(stock["food"]) + "x");
    this->_texts["linemate"].setString(std::to_string(stock["linemate"]) + "x");
    this->_texts["deraumere"].setString(std::to_string(stock["deraumere"]) + "x");
    this->_texts["sibur"].setString(std::to_string(stock["sibur"]) + "x");
    this->_texts["mendiane"].setString(std::to_string(stock["mendiane"]) + "x");
    this->_texts["phiras"].setString(std::to_string(stock["phiras"]) + "x");
    this->_texts["thystame"].setString(std::to_string(stock["thystame"]) + "x");
    this->_texts["team"].setString(std::string("Team: ") + team);
    this->_texts["lvl"].setString(std::string("Lvl: ") + std::to_string(lvl));


    if (this->_isFading) {
        if (this->_opacity < 255)
            this->_opacity += 15;
        else {
            this->_isFading = false;
            this->_isFadingOut = false;
        }
        for (auto &text : this->_texts) {
            if (text.first.find("Name") != std::string::npos)
                continue;
            text.second.setFillColor(sf::Color(255, 255, 255, this->_opacity));
        }
        for (auto &sprite : this->_sprites)
            sprite.second.setColor(sf::Color(255, 255, 255, this->_opacity));
    } else if (this->_isFadingOut) {
        if (this->_opacity > 0)
            this->_opacity -= 15;
        else {
            this->_isFadingOut = false;
            this->_isFading = false;
        }
        for (auto &text : this->_texts) {
            if (text.first.find("Name") != std::string::npos)
                continue;
            text.second.setFillColor(sf::Color(255, 255, 255, this->_opacity));
        }
        for (auto &sprite : this->_sprites)
            sprite.second.setColor(sf::Color(255, 255, 255, this->_opacity));
    }

    if (this->_clock.getElapsedTime().asSeconds() > 0.1) {
        if (this->_rect.left >= 204)
            this->_rect.left = 48;
        else
            this->_rect.left += 48;
        this->_sprites["trantorian"].setTextureRect(this->_rect);
        this->_clock.restart();
    }
}

void SInventory::eventHandler(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    for (auto &sprite : this->_sprites) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (sprite.second.getGlobalBounds().contains(mousePosF)) {
                    if (sprite.first == "close") {
                        this->_isFadingOut = true;
                    }
                }
            }
        }
        if (sprite.second.getGlobalBounds().contains(mousePosF)) {
            if(sprite.first == "inventory" || sprite.first == "display" || sprite.first == "trantorian" || sprite.first == "close") {
                continue;
            } else {
                this->_texts[sprite.first + "Name"].setFillColor(sf::Color(255, 255, 255, 255));
                this->_background.setSize(sf::Vector2f(this->_texts[sprite.first + "Name"].getGlobalBounds().width + 10, 35));
                this->_background.setFillColor(sf::Color(0, 0, 0, 190));
                this->_background.setPosition(this->_texts[sprite.first + "Name"].getPosition().x - 5, this->_texts[sprite.first + "Name"].getPosition().y + 10);
                break;
            }
        } else {
            if (sprite.first == "inventory" || sprite.first == "display" || sprite.first == "trantorian" || sprite.first == "close") {
                continue;
            } else {
                this->_texts[sprite.first + "Name"].setFillColor(sf::Color(255, 255, 255, 0));
                this->_background.setFillColor(sf::Color(0, 0, 0, 0));
            }
        }
    }
}

void SInventory::fadeIn(bool isFading)
{
    this->_isFading = isFading;
}

void SInventory::fadeOut(bool isFading)
{
    this->_isFadingOut = isFading;
}

void SInventory::setTrantorianTexture(std::shared_ptr<sf::Texture> &texture)
{
    this->_sprites["trantorian"].setTexture(*texture);
}
