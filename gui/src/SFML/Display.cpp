/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#include "Display.hpp"

Display::Display(int w_width, int w_height) : _width(w_width), _height(w_height)
{
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w_width, w_height), "Zappy");
    this->_window->setFramerateLimit(60);
    this->_window->setActive(false);
    this->_view.setSize(sf::Vector2f(w_width, w_height));
    this->_bottomMenu = std::make_unique<SBottom_menu>(w_width, w_height);
    this->_clock_map.restart();
    this->_clock_trantorian.restart();
}

Display::~Display()
{
}

// void Display::createTrantorians()
// {
//     this->_trantorians.insert(std::make_pair("trantorian1", std::make_unique<STrantorian>()));
// }

void Display::createMap(int width, int height)
{
    width += 2; height += 2;
    std::vector<std::string> array(height);
    for (int i = 0; i < height; i++) {
        array[i] = std::string(width, '9');
        for (int j = 0; j < width; j++) {
            if (i == 0 && j == 0) {
                array[i][j] = '1';
            } else if (i == 0 && j == width - 1) {
                array[i][j] = '3';
            } else if (i == 0 && j != 0) {
                array[i][j] = '2';
            } else if (i == height - 1 && j == 0) {
                array[i][j] = '7';
            } else if (i == height - 1 && j == width - 1) {
                array[i][j] = '5';
            } else if (i == height - 1 && j != 0) {
                array[i][j] = '6';
            } else if (i != 0 && j == 0) {
                array[i][j] = '8';
            } else if (i != 0 && j == width - 1) {
                array[i][j] = '4';
            }
        }
    }
    array.push_back("");

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++)
            this->_map.push_back(std::make_unique<STile>(x - 1, y - 1, array[y][x] - '0'));
    }
}

void Display::createViews(int map_width, int map_height)
{
    this->_view.setSize(sf::Vector2f(this->_width, this->_height));
    this->_view.setCenter(sf::Vector2f(map_width * 96 / 2, map_height * 96 / 2));
    this->_mapCenter = sf::Vector2f(map_width * 96 / 2, map_height * 96 / 2);

    this->_bottomMenuView.setSize(sf::Vector2f(this->_width, this->_height));
    this->_bottomMenuView.setCenter(sf::Vector2f(this->_width / 2, this->_height / 2));
}

void Display::render()
{
    this->_window->clear(sf::Color::Black);
    for (auto &sprite : this->_map)
       sprite->draw(*this->_window, this->_view);
    for (auto &sprite : this->_trantorians)
        sprite.second->draw(*this->_window, this->_view);
    this->_window->setView(this->_bottomMenuView);
    if (this->_ShowBottomMenu == true) {
        this->_bottomMenu->draw(*this->_window);
    }
    this->_window->display();
    this->_window->setView(this->_view);
}

void Display::keyHandler(MapT cache)
{
    if (this->_event.type == sf::Event::KeyPressed) {
        if (this->_event.key.code == sf::Keyboard::Escape)
            this->_window->close();
        else if (this->_event.key.code == sf::Keyboard::Up) {
            this->_view.move(0, -10);
        } else if (this->_event.key.code == sf::Keyboard::Down) {
            this->_view.move(0, 10);
        } else if (this->_event.key.code == sf::Keyboard::Left) {
            this->_view.move(-10, 0);
        } else if (this->_event.key.code == sf::Keyboard::Right) {
            this->_view.move(10, 0);
        } else if (this->_event.key.code == sf::Keyboard::Z) {
            this->_view.zoom(0.9);
        } else if (this->_event.key.code == sf::Keyboard::X) {
            this->_view.zoom(1.1);
        } else if (this->_event.key.code == sf::Keyboard::R) {
            this->_view.rotate(1);
        } else if (this->_event.key.code == sf::Keyboard::T) {
            this->_view.rotate(-1);
        } else if (this->_event.key.code == sf::Keyboard::Space) {
            this->_view.reset(sf::FloatRect(0, 0, this->_width, this->_height));
            this->_view.setCenter(this->_mapCenter);
        } else if (this->_event.key.code == sf::Keyboard::B) {
            this->_ShowBottomMenu = !this->_ShowBottomMenu;
        } else if (this->_event.key.code == sf::Keyboard::C) {
            this->_message = "sst " + std::to_string(cache.getFrequency() - 10) + "\n";
        } else if (this->_event.key.code == sf::Keyboard::V) {
            this->_message = "sst " + std::to_string(cache.getFrequency() + 10) + "\n";
        }
    }
}

void Display::clickHandler(MapT cache)
{
    if (this->_event.type == sf::Event::MouseButtonPressed) {
        if (this->_event.mouseButton.button == sf::Mouse::Left) {
            for (auto &sprite : this->_map) {
                this->_click_pos = sprite->getClicked();
                if (this->_click_pos.x != -1 && this->_click_pos.y != -1) {
                    this->_ShowBottomMenu = true;
                    this->_bottomMenu->update(cache.getTile(this->_click_pos.x, this->_click_pos.y).getStocks());
                }
            }
        }
    }
}

void Display::eventHandler(MapT cache)
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->close();
        for (auto &sprite : this->_map)
            sprite->eventHandler(this->_event, *this->_window);
        this->keyHandler(cache);
        this->clickHandler(cache);
    }
}

//TODO: use the time unit to determine the speed of the animation
void Display::update(MapT cache)
{
    const sf::Time targetFrameTime = sf::seconds(1.0f / cache.getFrequency());
    if (this->_mapCreated == false && cache.getX() != 0 && cache.getY() != 0) {
        this->createMap(cache.getX(), cache.getY());
        this->createViews(cache.getX(), cache.getY());
        this->_mapCreated = true;
    }
    if (this->_clock_map.getElapsedTime() > targetFrameTime) {
        this->_clock_map.restart();
        for (auto &sprite : this->_map)
            sprite->update(cache);
    }
    if (this->_trantorians.size() != cache.getTrantorians().size()) {
        this->_trantorians.clear();
        for (auto &trantor : cache.getTrantorians()) {
            this->_trantorians[trantor.getId()] = std::make_unique<STrantorian>(trantor);
        }
    }
    if (this->_trantorians.size() > 0) {
        if (this->_clock_trantorian.getElapsedTime() > targetFrameTime) {
            this->_clock_trantorian.restart();
            for (auto &sprite : this->_trantorians)
                sprite.second->update(cache);
        }
    }
}

std::unique_ptr<sf::RenderWindow> &Display::getWindow()
{
    return this->_window;
}

void Display::resetMessage()
{
    this->_message.clear();
}

std::string Display::getMessage()
{
    if (this->_message == "")
        return "";
    return this->_message;
}
