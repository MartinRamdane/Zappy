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
}

void SSlider::createSprite(int w_width, int w_height)
{

    this->_textures["aslider_menu"] = std::make_shared<sf::Texture>();
    this->_textures["aslider_menu"]->loadFromFile("gui/assets/slider/slider_menu.png");
    this->_sprites["aslider_menu"] = std::make_shared<sf::Sprite>();
    this->_sprites["aslider_menu"]->setTexture(*this->_textures["aslider_menu"]);
    this->_sprites["aslider_menu"]->setScale(sf::Vector2f(w_width / this->_sprites["aslider_menu"]->getGlobalBounds().width * 0.2, w_height / this->_sprites["aslider_menu"]->getGlobalBounds().height * 0.5));
    this->_sprites["aslider_menu"]->setPosition(sf::Vector2f(1500, 50));
    this->_sprites["aslider_menu"]->setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_rects["zslider_bar1"] = std::make_shared<sf::RectangleShape>();
    this->_rects["zslider_bar1"]->setSize(sf::Vector2f(10, 30));
    this->_rects["zslider_bar1"]->setPosition(sf::Vector2f(1550, 150));
    sf::Color color(105,105,105);
    color.a = this->_opacity;
    this->_rects["zslider_bar1"]->setFillColor(color);

    this->_rects["slider_slide1"] = std::make_shared<sf::RectangleShape>();
    this->_rects["slider_slide1"]->setSize(sf::Vector2f(50, 30));
    this->_rects["slider_slide1"]->setPosition(sf::Vector2f(1550, 150));
    color = sf::Color::Yellow;
    color.a = this->_opacity;
    this->_rects["slider_slide1"]->setFillColor(color);

    this->_rects["slider_back1"] = std::make_shared<sf::RectangleShape>();
    this->_rects["slider_back1"]->setSize(sf::Vector2f(200, 30));
    this->_rects["slider_back1"]->setPosition(sf::Vector2f(1550, 150));
    color = sf::Color::Black;
    color.a = this->_opacity;
    this->_rects["slider_back1"]->setFillColor(color);

    // this->_rects["zslider_bar2"] = std::make_shared<sf::RectangleShape>();
    // this->_rects["zslider_bar2"]->setSize(sf::Vector2f(10, 30));
    // this->_rects["zslider_bar2"]->setPosition(sf::Vector2f(1550, 300));
    // sf::Color colora(105,105,105);
    // color.a = this->_opacity;
    // this->_rects["zslider_bar2"]->setFillColor(colora);

    // this->_rects["slider_slide2"] = std::make_shared<sf::RectangleShape>();
    // this->_rects["slider_slide2"]->setSize(sf::Vector2f(50, 30));
    // this->_rects["slider_slide2"]->setPosition(sf::Vector2f(1550, 300));
    // color = sf::Color::Yellow;
    // color.a = this->_opacity;
    // this->_rects["slider_slide2"]->setFillColor(color);

    // this->_rects["slider_back2"] = std::make_shared<sf::RectangleShape>();
    // this->_rects["slider_back2"]->setSize(sf::Vector2f(200, 30));
    // this->_rects["slider_back2"]->setPosition(sf::Vector2f(1550, 300));
    // color = sf::Color::Black;
    // color.a = this->_opacity;
    // this->_rects["slider_back2"]->setFillColor(color);


    // this->_textures["zslider_bar1"] = std::make_shared<sf::Texture>();
    // this->_textures["zslider_bar1"]->loadFromFile("gui/assets/slider/bar_loader.png");
    // this->_sprites["zslider_bar1"] = std::make_shared<sf::Sprite>();
    // this->_sprites["zslider_bar1"]->setTexture(*this->_textures["zslider_bar1"]);
    // this->_sprites["zslider_bar1"]->setScale(sf::Vector2f(w_width / this->_sprites["zslider_bar1"]->getGlobalBounds().width * 0.005, w_height / this->_sprites["zslider_bar1"]->getGlobalBounds().height * 0.05));
    // this->_sprites["zslider_bar1"]->setPosition(sf::Vector2f(1, 150));
    // this->_sprites["zslider_bar1"]->setColor(sf::Color(255, 255, 255, this->_opacity));

    // this->_textures["slider_slide1"] = std::make_shared<sf::Texture>();
    // this->_textures["slider_slide1"]->loadFromFile("gui/assets/slider/loader.png");
    // this->_sprites["slider_slide1"] = std::make_shared<sf::Sprite>();
    // this->_sprites["slider_slide1"]->setTexture(*this->_textures["slider_slide1"]);
    // _w_height = w_width / this->_sprites["slider_slide1"]->getGlobalBounds().width;
    // _w_width = w_height / this->_sprites["slider_slide1"]->getGlobalBounds().height;
    // this->_sprites["slider_slide1"]->setScale(sf::Vector2f(w_width / this->_sprites["slider_slide1"]->getGlobalBounds().width * 0.15, w_height / this->_sprites["slider_slide1"]->getGlobalBounds().height * 0.05));
    // this->_sprites["slider_slide1"]->setPosition(sf::Vector2f(1550, 150));
    // this->_sprites["slider_slide1"]->setColor(sf::Color(255, 255, 255, this->_opacity));

    // this->_textures["slider_back1"] = std::make_shared<sf::Texture>();
    // this->_textures["slider_back1"]->loadFromFile("gui/assets/slider/back_loader.png");
    // this->_sprites["slider_back1"] = std::make_shared<sf::Sprite>();
    // this->_sprites["slider_back1"]->setTexture(*this->_textures["slider_back1"]);
    // this->_sprites["slider_back1"]->setScale(sf::Vector2f(w_width / this->_sprites["slider_back1"]->getGlobalBounds().width * 0.15, w_height / this->_sprites["slider_back1"]->getGlobalBounds().height * 0.05));
    // this->_sprites["slider_back1"]->setPosition(sf::Vector2f(1550, 150));
    // this->_sprites["slider_back1"]->setColor(sf::Color(255, 255, 255, this->_opacity));
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

    this->_rects["zslider_bar1"]->setPosition(sf::Vector2f(1550 + cache->getFrequency() / 5, 150));
    if (this->_isDragging1) {
        int x = sf::Mouse::getPosition().x;
        if (x < 1550)
            x = 1551;
        if (x > 1750)
            x = 1749;
        this->_rects["zslider_bar1"]->setPosition(sf::Vector2f(x, 150));
    }
    this->_rects["slider_slide1"]->setSize(sf::Vector2f(this->_rects["zslider_bar1"]->getPosition().x - 1550, 30));

    // this->_rects["zslider_bar2"]->setPosition(sf::Vector2f(1550 + cache->getFrequency() / 5, 150));
    // if (this->_isDragging1) {
    //     int x = sf::Mouse::getPosition().x;
    //     if (x < 1550)
    //         x = 1551;
    //     if (x > 1750)
    //         x = 1749;
    //     this->_rects["zslider_bar2"]->setPosition(sf::Vector2f(x, 150));
    // }
    // this->_rects["slider_slide2"]->setSize(sf::Vector2f(this->_rects["zslider_bar1"]->getPosition().x - 1550, 30));
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