/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SSlider.cpp
*/

#include "SSlider.hpp"

SSlider::SSlider(int w_width, int w_height)
{
    this->createSprite(w_width, w_height);
    // this->createTexts();
}

SSlider::~SSlider()
{
    for (auto &sprite : this->_sprites)
        sprite.second.reset();
    for (auto &text : this->_texts)
        text.second.reset();
    for (auto &rect : this->_rects)
        rect.second.reset();
    for (auto &texture : this->_textures)
        texture.second.reset();
}

void SSlider::createSprite(int w_width, int w_height)
{

    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    this->_texts["frequency"] = std::make_shared<sf::Text>();
    this->_texts["frequency"]->setFont(this->_font);
    this->_texts["frequency"]->setString("frequency :");
    this->_texts["frequency"]->setCharacterSize(40);
    this->_texts["frequency"]->setFillColor(sf::Color(13, 144, 104, this->_opacity));
    this->_texts["frequency"]->setPosition(sf::Vector2f(1560, 880));

    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    this->_texts["frequencyV"] = std::make_shared<sf::Text>();
    this->_texts["frequencyV"]->setFont(this->_font);
    this->_texts["frequencyV"]->setString("0");
    this->_texts["frequencyV"]->setCharacterSize(40);
    this->_texts["frequencyV"]->setFillColor(sf::Color(13, 144, 104, this->_opacity));
    this->_texts["frequencyV"]->setPosition(sf::Vector2f(1750, 880));

    this->_textures["aslider_menu"] = std::make_shared<sf::Texture>();
    this->_textures["aslider_menu"]->loadFromFile("gui/assets/bottom_menu/bottom_menu.png");
    this->_sprites["aslider_menu"] = std::make_shared<sf::Sprite>();
    this->_sprites["aslider_menu"]->setTexture(*this->_textures["aslider_menu"]);
    this->_sprites["aslider_menu"]->setScale(sf::Vector2f(w_width / this->_sprites["aslider_menu"]->getGlobalBounds().width * 0.25, w_height / this->_sprites["aslider_menu"]->getGlobalBounds().height * 0.25));
    this->_sprites["aslider_menu"]->setPosition(sf::Vector2f(1450, 800));
    this->_sprites["aslider_menu"]->setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_rects["zslider_bar1"] = std::make_shared<sf::RectangleShape>();
    this->_rects["zslider_bar1"]->setSize(sf::Vector2f(10, 30));
    this->_rects["zslider_bar1"]->setPosition(sf::Vector2f(1550, 940));
    sf::Color color(105,105,105);
    color.a = this->_opacity;
    this->_rects["zslider_bar1"]->setFillColor(color);

    this->_rects["slider_slide1"] = std::make_shared<sf::RectangleShape>();
    this->_rects["slider_slide1"]->setSize(sf::Vector2f(50, 30));
    this->_rects["slider_slide1"]->setPosition(sf::Vector2f(1550, 940));
    sf::Color c(13, 144, 104);
    c.a = this->_opacity;
    this->_rects["slider_slide1"]->setFillColor(c);

    this->_rects["slider_back1"] = std::make_shared<sf::RectangleShape>();
    this->_rects["slider_back1"]->setSize(sf::Vector2f(200, 30));
    this->_rects["slider_back1"]->setPosition(sf::Vector2f(1550, 940));
    color = sf::Color::Black;
    color.a = this->_opacity;
    this->_rects["slider_back1"]->setFillColor(color);
}

void SSlider::draw(sf::RenderWindow &window)
{
    for (auto &sprite : this->_sprites)
        window.draw(*sprite.second);
    for (auto &text : this->_texts)
        window.draw(*text.second);
    for (auto &rect : this->_rects)
        window.draw(*rect.second);
}

void SSlider::update(MapT *cache)
{
    if (this->_clock.getElapsedTime().asSeconds() >= 0.01) {
        if (this->_opacity < 255 && this->_isFading) {
            this->_opacity = 255;
            for (auto &rect : this->_rects) {
                sf::Color color = rect.second->getFillColor();
                color.a = this->_opacity;
                rect.second->setFillColor(color);
            }
            for (auto &sprite : this->_sprites)
                sprite.second->setColor(sf::Color(255, 255, 255, this->_opacity));
            for (auto &text : this->_texts)
                text.second->setFillColor(sf::Color(13, 144, 104, this->_opacity));
        }
        if (this->_opacity > 0 && this->_isFadingOut) {
            for (auto &rect : this->_rects) {
                sf::Color color = rect.second->getFillColor();
                color.a = this->_opacity;
                rect.second->setFillColor(color);
            }
            for (auto &sprite : this->_sprites)
                sprite.second->setColor(sf::Color(255, 255, 255, this->_opacity));
            for (auto &text : this->_texts)
                text.second->setFillColor(sf::Color(13, 144, 104, this->_opacity));
            this->_opacity -= 15;
            if (this->_opacity == 0) {
                for (auto &sprite : this->_sprites)
                    sprite.second->setColor(sf::Color(255, 255, 255, 0));
                for (auto &text : this->_texts)
                    text.second->setFillColor(sf::Color(13, 144, 104, 0));
                for (auto &rect : this->_rects) {
                    sf::Color color = rect.second->getFillColor();
                    color.a = 0;
                    rect.second->setFillColor(color);
                }
            }
        }
        this->_clock.restart();
    }

    this->_texts["frequencyV"]->setString(std::to_string(cache->getFrequency()));
    if (cache->getFrequency() == 5)
        this->_texts["frequencyV"]->setString("2");
    if (cache->getFrequency() == 995)
        this->_texts["frequencyV"]->setString("1000");
    this->_rects["zslider_bar1"]->setPosition(sf::Vector2f(1550 + cache->getFrequency() / 5, 940));
    if (this->_isDragging1) {
        int x = sf::Mouse::getPosition().x;
        if (x < 1550)
            x = 1551;
        if (x > 1750)
            x = 1749;
        this->_rects["zslider_bar1"]->setPosition(sf::Vector2f(x, 940));
    }
    this->_rects["slider_slide1"]->setSize(sf::Vector2f(this->_rects["zslider_bar1"]->getPosition().x - 1550, 30));
}

void SSlider::fadeIn(bool isFading)
{
    this->_isFading = isFading;
}

void SSlider::fadeOut(bool isFading)
{
    this->_isFadingOut = isFading;
}

std::map<std::string, std::shared_ptr<sf::RectangleShape>> SSlider::getRect()
{
    return (this->_rects);
}

void SSlider::setRect(std::string s, std::shared_ptr<sf::RectangleShape> r)
{
    this->_rects[s] = r;
}

bool SSlider::getIsDragging1()
{
    return (this->_isDragging1);
}

void SSlider::setIsDragging1(bool drag)
{
    this->_isDragging1 = drag;
}

// bool SSlider::getIsDragging2()
// {
//     return (this->_isDragging2);
// }

// void SSlider::setIsDragging2(bool drag)
// {
//     this->_isDragging2 = drag;
// }