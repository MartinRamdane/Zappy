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

    this->_sprites["bar"] = sf::Sprite();
    this->_textures["bar"] = sf::Texture();
    this->_textures["bar"].loadFromFile("gui/assets/slider/bar.png");
    this->_sprites["bar"].setTexture(this->_textures["bar"]);
    this->_sprites["bar"].setScale(sf::Vector2f(0.31, 0.3));
    this->_sprites["bar"].setPosition(sf::Vector2f(this->_texts["frequency"].getPosition().x, this->_texts["frequency"].getPosition().y + 70));
    this->_sprites["bar"].setColor(sf::Color(255, 255, 255, this->_opacity));

    this->_sprites["slider"] = sf::Sprite();
    this->_textures["slider"] = sf::Texture();
    this->_textures["slider"].loadFromFile("gui/assets/slider/slider.png");
    this->_sprites["slider"].setTexture(this->_textures["slider"]);
    this->_sprites["slider"].setScale(sf::Vector2f(0.3, 0.3));
    this->_sprites["slider"].setPosition(sf::Vector2f(this->_sprites["bar"].getPosition().x + 10, this->_sprites["bar"].getPosition().y + 8));
    this->_sprites["slider"].setColor(sf::Color(255, 255, 255, this->_opacity));
    this->_sprites["slider"].setOrigin(sf::Vector2f(this->_sprites["slider"].getGlobalBounds().width / 2, this->_sprites["slider"].getGlobalBounds().height / 2));

    this->_texts["zoom"] = sf::Text();
    this->_texts["zoom"].setFont(this->_font);
    this->_texts["zoom"].setString("Zoom :");
    this->_texts["zoom"].setCharacterSize(40);
    this->_texts["zoom"].setFillColor(sf::Color(13, 144, 104, this->_opacity));
    this->_texts["zoom"].setPosition(this->_sprites["aslider_menu"].getPosition().x + this->_textures["aslider_menu"].getSize().x + 20, this->_sprites["bar"].getPosition().y + 60);

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

    // if (this->_isDragging1) {
    //     // int frequency = this->_sprites["slider"].getPosition().x * 1000 / (((800 * 0.3)) - 37);
    //     int frequency = (this->_sprites["slider"].getPosition().x - this->_sprites["bar"].getPosition().x) * 1000 / ((800 * 0.3) - 37);
    //     std::cout << "Frequency: " << frequency << std::endl;
    //     cache->setFrequency(frequency);
    // }
    // if (!this->_isDragging1) {
    //     auto pos = this->_sprites["slider"].getPosition();
    //     pos.x = (this->_sprites["bar"].getPosition().x) + 10 + ((cache->getFrequency() * (((800 * 0.3)) - 37)) / 1000);
    //     this->_sprites["slider"].setPosition(pos);
    // }
    if (!this->_isDragging1) {
        auto pos = this->_sprites["slider"].getPosition();
        pos.x = (this->_sprites["bar"].getPosition().x) + 10 + (cache->getFrequency() / 5);
        this->_sprites["slider"].setPosition(pos);
    }
    if (this->_isDragging1) {
        int frequency = (this->_sprites["slider"].getPosition().x - this->_sprites["bar"].getPosition().x - 10) * 5;
        if (frequency <= 5)
            frequency = 2;
        if (frequency >= 995)
            frequency = 1000;
        cache->setFrequency(frequency);
    }
    this->_texts["frequencyV"].setString(std::to_string(cache->getFrequency()));
    if (cache->getFrequency() <= 5)
        this->_texts["frequencyV"].setString("2");
    if (cache->getFrequency() >= 995)
        this->_texts["frequencyV"].setString("1000");
}

void SSlider::eventHandler(sf::Event event, sf::RenderWindow &window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    if (this->_sprites["slider"].getGlobalBounds().contains(mousePosF)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                this->_isDragging1 = true;
            }
        }
    }

    if (event.type == sf::Event::MouseButtonReleased) 
        this->_isDragging1 = false;
    
    if (this->_isDragging1) {
        sf::Vector2f pos = this->_sprites["slider"].getPosition();
        if (mousePosF.x < (this->_sprites["bar"].getPosition().x + 10)) {
            pos.x = this->_sprites["bar"].getPosition().x + 10;
            this->_sprites["slider"].setPosition(pos);
        } else if (mousePosF.x > (this->_sprites["bar"].getPosition().x + 210)) {
            pos.x = this->_sprites["bar"].getPosition().x + 210;
            this->_sprites["slider"].setPosition(pos);
        } else {
            pos.x = mousePosF.x;
            this->_sprites["slider"].setPosition(pos);
        }
        // if (mousePosF.x < (this->_sprites["bar"].getPosition().x + 9)) {
        //     pos.x = this->_sprites["bar"].getPosition().x + 9;
        //     this->_sprites["slider"].setPosition(pos);
        // } else if (mousePosF.x > (this->_sprites["bar"].getPosition().x + (792 * 0.3) - 37)) {
        //     pos.x = this->_sprites["bar"].getPosition().x + (792 * 0.3) - 37;
        //     this->_sprites["slider"].setPosition(pos);
        // } else {
        //     pos.x = mousePosF.x;
        //     this->_sprites["slider"].setPosition(pos);
        // }
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
