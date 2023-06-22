/*
** EPITECH PROJECT, 2022
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** SSlider.cpp
*/

#include "SSlider.hpp"

SSlider::SSlider(int w_width, int w_height, int zoom) : _w_width(w_width), _w_height(w_height), _zoom(static_cast<float>(zoom))
{
    this->createSprite(w_width, w_height, zoom);
}

SSlider::~SSlider()
{
    this->_rects.clear();
    this->_sprites.clear();
    this->_textures.clear();
    this->_texts.clear();
}

void SSlider::createSprite(int w_width, int w_height, int zoom)
{
    this->_textures["aslider_menu"] = sf::Texture();
    this->_textures["aslider_menu"].loadFromFile("gui/assets/bottom_menu/bottom_menu.png");
    this->_sprites["aslider_menu"] = sf::Sprite();
    this->_sprites["aslider_menu"].setTexture(this->_textures["aslider_menu"]);
    this->_sprites["aslider_menu"].setScale(sf::Vector2f(w_width / this->_sprites["aslider_menu"].getGlobalBounds().width * 0.3, w_height / this->_sprites["aslider_menu"].getGlobalBounds().height * 0.4));
    this->_sprites["aslider_menu"].setPosition(sf::Vector2f(w_width - this->_sprites["aslider_menu"].getGlobalBounds().width, w_height - this->_sprites["aslider_menu"].getGlobalBounds().height));
    this->_sprites["aslider_menu"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    this->_texts["frequency"] = sf::Text();
    this->_texts["frequency"].setFont(this->_font);
    this->_texts["frequency"].setString("Frequency :");
    this->_texts["frequency"].setCharacterSize(40);
    this->_texts["frequency"].setFillColor(sf::Color(13, 144, 104, this->_opacity));
    this->_texts["frequency"].setPosition(sf::Vector2f(this->_sprites["aslider_menu"].getPosition().x + 165, this->_sprites["aslider_menu"].getPosition().y + 90));

    this->_texts["frequencyV"] = sf::Text();
    this->_texts["frequencyV"].setFont(this->_font);
    this->_texts["frequencyV"].setString("0");
    this->_texts["frequencyV"].setCharacterSize(40);
    this->_texts["frequencyV"].setFillColor(sf::Color(13, 144, 104, this->_opacity));
    this->_texts["frequencyV"].setPosition(sf::Vector2f(this->_texts["frequency"].getPosition().x + 200, this->_texts["frequency"].getPosition().y));

    this->_rects["slider_slide1"] = sf::RectangleShape();
    this->_rects["slider_slide1"].setSize(sf::Vector2f(50, 30));
    this->_rects["slider_slide1"].setPosition(sf::Vector2f(this->_texts["frequency"].getPosition().x, this->_texts["frequency"].getPosition().y + 70));
    sf::Color c(13, 144, 104);
    c.a = this->_opacity;
    this->_rects["slider_slide1"].setFillColor(c);

    this->_rects["zslider_bar1"] = sf::RectangleShape();
    this->_rects["zslider_bar1"].setSize(sf::Vector2f(10, 30));
    this->_rects["zslider_bar1"].setPosition(sf::Vector2f(this->_rects["slider_slide1"].getPosition().x + this->_rects["slider_slide1"].getSize().x, this->_rects["slider_slide1"].getPosition().y));
    sf::Color color(105,105,105);
    color.a = this->_opacity;
    this->_rects["zslider_bar1"].setFillColor(color);

    this->_rects["slider_back1"] = sf::RectangleShape();
    this->_rects["slider_back1"].setSize(sf::Vector2f(200, 30));
    this->_rects["slider_back1"].setPosition(sf::Vector2f(this->_rects["slider_slide1"].getPosition().x, this->_rects["slider_slide1"].getPosition().y));
    color = sf::Color::Black;
    color.a = this->_opacity;
    this->_rects["slider_back1"].setFillColor(color);

    this->_texts["zoom"] = sf::Text();
    this->_texts["zoom"].setFont(this->_font);
    this->_texts["zoom"].setString("Zoom :");
    this->_texts["zoom"].setCharacterSize(40);
    this->_texts["zoom"].setFillColor(sf::Color(13, 144, 104, this->_opacity));
    this->_texts["zoom"].setPosition(this->_sprites["aslider_menu"].getPosition().x + this->_textures["aslider_menu"].getSize().x + 20, this->_rects["slider_back1"].getPosition().y + 60);

    this->_sprites["button_minus"] = sf::Sprite();
    this->_textures["button_minus"] = sf::Texture();
    this->_textures["button_minus_hover"] = sf::Texture();
    this->_textures["button_minus"].loadFromFile("gui/assets/zoom/button_minus.png");
    this->_textures["button_minus_hover"].loadFromFile("gui/assets/zoom/button_minus_hover.png");
    this->_sprites["button_minus"].setTexture(this->_textures["button_minus"]);
    this->_sprites["button_minus"].setScale(sf::Vector2f(0.7, 0.7));
    this->_sprites["button_minus"].setPosition(sf::Vector2f(this->_texts["zoom"].getPosition().x - 40, this->_texts["zoom"].getPosition().y + 70));
    this->_sprites["button_minus"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_sprites["button_plus"] = sf::Sprite();
    this->_textures["button_plus"] = sf::Texture();
    this->_textures["button_plus_hover"] = sf::Texture();
    this->_textures["button_plus"].loadFromFile("gui/assets/zoom/button_plus.png");
    this->_textures["button_plus_hover"].loadFromFile("gui/assets/zoom/button_plus_hover.png");
    this->_sprites["button_plus"].setTexture(this->_textures["button_plus"]);
    this->_sprites["button_plus"].setScale(sf::Vector2f(0.7, 0.7));
    this->_sprites["button_plus"].setPosition(sf::Vector2f(this->_texts["zoom"].getPosition().x + 100, this->_texts["zoom"].getPosition().y + 70));
    this->_sprites["button_plus"].setColor(sf::Color(255, 255, 255, this->_opacity));
}

void SSlider::draw(sf::RenderWindow &window)
{
    for (auto &sprite : this->_sprites)
        window.draw(sprite.second);
    for (auto &text : this->_texts)
        window.draw(text.second);
    for (auto &rect : this->_rects)
        window.draw(rect.second);
}

void SSlider::update(MapT *cache)
{
    if (this->_clock.getElapsedTime().asSeconds() >= 0.01) {
        if (this->_opacity < 255 && this->_isFading) {
            this->_opacity += 15;
            for (auto &rect : this->_rects) {
                sf::Color color = rect.second.getFillColor();
                color.a = this->_opacity;
                rect.second.setFillColor(color);
            }
            for (auto &sprite : this->_sprites)
                sprite.second.setColor(sf::Color(255, 255, 255, this->_opacity));
            for (auto &text : this->_texts)
                text.second.setFillColor(sf::Color(13, 144, 104, this->_opacity));
        }
        if (this->_opacity > 0 && this->_isFadingOut) {
            for (auto &rect : this->_rects) {
                sf::Color color = rect.second.getFillColor();
                color.a = this->_opacity;
                rect.second.setFillColor(color);
            }
            for (auto &sprite : this->_sprites)
                sprite.second.setColor(sf::Color(255, 255, 255, this->_opacity));
            for (auto &text : this->_texts)
                text.second.setFillColor(sf::Color(13, 144, 104, this->_opacity));
            this->_opacity -= 15;
            if (this->_opacity == 0) {
                for (auto &sprite : this->_sprites)
                    sprite.second.setColor(sf::Color(255, 255, 255, 0));
                for (auto &text : this->_texts)
                    text.second.setFillColor(sf::Color(13, 144, 104, 0));
                for (auto &rect : this->_rects) {
                    sf::Color color = rect.second.getFillColor();
                    color.a = 0;
                    rect.second.setFillColor(color);
                }
            }
        }
        this->_clock.restart();
    }

    this->_texts["frequencyV"].setString(std::to_string(cache->getFrequency()));
    if (cache->getFrequency() == 5)
        this->_texts["frequencyV"].setString("2");
    if (cache->getFrequency() == 995)
        this->_texts["frequencyV"].setString("1000");
    // this->_rects["zslider_bar1"].setPosition(sf::Vector2f(1550 + cache.getFrequency() / 5, 940));
    // if (this->_isDragging1) {
    //     int x = sf::Mouse::getPosition().x;
    //     if (x < 1550)
    //         x = 1551;
    //     if (x > 1750)
    //         x = 1749;
    //     this->_rects["zslider_bar1"].setPosition(sf::Vector2f(x, 940));
    // }
    // this->_rects["slider_slide1"].setSize(sf::Vector2f(this->_rects["zslider_bar1"].getPosition().x - 1550, 30));
}

void SSlider::eventHandler(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (this->_rects["slider_bar1"].getLocalBounds().contains(mousePosF)) {
                std::cout << "slider_pressed" << std::endl;
                this->_isDragging1 = true;
            }
        }
    }
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            int freq = this->_rects["slider_slide1"].getPosition().x * 5;
            // this->_message = "sst " + std::to_string(freq) + "\n";
            this->_isDragging1 = false;
            std::cout << "slider_released" << std::endl;
        }
    }

    if (this->_sprites["button_minus"].getGlobalBounds().contains(mousePosF)) {
        this->_sprites["button_minus"].setTexture(this->_textures["button_minus_hover"]);
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                this->_zoom -= 0.1;
            }
        }
    } else {
        this->_sprites["button_minus"].setTexture(this->_textures["button_minus"]);
    }

    if (this->_sprites["button_plus"].getGlobalBounds().contains(mousePosF)) {
        this->_sprites["button_plus"].setTexture(this->_textures["button_plus_hover"]);
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                this->_zoom += 0.1;
            }
        }
    } else {
        this->_sprites["button_plus"].setTexture(this->_textures["button_plus"]);
    }
    this->_texts["zoom_value"].setString(std::to_string(this->_zoom));
}

void SSlider::fadeIn(bool isFading)
{
    this->_isFading = isFading;
}

void SSlider::fadeOut(bool isFading)
{
    this->_isFadingOut = isFading;
}

std::map<std::string, sf::RectangleShape> SSlider::getRect()
{
    return (this->_rects);
}

void SSlider::setRect(std::string s, sf::RectangleShape r)
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