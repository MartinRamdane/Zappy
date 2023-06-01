/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#include "Display.hpp"

// *! IMPORTANT !*
// sf::Vector2i pixelPos = sf::Mouse::getPosition(*this->_window);
// sf::Vector2f worldPos = this->_window->mapPixelToCoords(pixelPos);
// std::cout << "Mouse x: " << worldPos.x << std::endl;
// std::cout << "Mouse y: " << worldPos.y << std::endl;

Display::Display(int w_width, int w_height) : _width(w_width), _height(w_height)
{
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w_width, w_height), "Zappy");
    this->_window->setFramerateLimit(60);
    this->_view.setSize(sf::Vector2f(w_width, w_height));
    this->createTrantorians();
    this->createMap(10, 10);
    this->_clock.restart();
}

Display::~Display()
{
}


void Display::createTrantorians()
{
    this->_trantorians.insert(std::make_pair("trantorian1", std::make_unique<STrantorian>()));
}

//*TODO: remove it later
#include <fstream>

void Display::createMap(int width, int height)
{
    std::ifstream inputFile("gui/src/SFML/map.txt");

    std::string line;
    std::vector<std::string> array;
    while (std::getline(inputFile, line)) {
        array.push_back(line);
    }

    inputFile.close();
    for (int y = 0; y < array.size(); y++) {
        for (int x = 0; x < array[y].size(); x++)
            this->_map.push_back(std::make_unique<SMap>(x, y, array[y][x] - '0'));
    }
    this->_view.setCenter(sf::Vector2f(array[0].size() * 96 / 2, array.size() * 96 / 2));
    this->_mapCenter = sf::Vector2f(array[0].size() * 96 / 2, array.size() * 96 / 2);
    this->_view.zoom(2);
}

void Display::render()
{
    this->_window->clear(sf::Color::Black);
    this->_window->setView(_view);
    for (auto &sprite : this->_map) {
       sprite->draw(*this->_window);
    }
    for (auto &sprite : this->_trantorians)
        sprite.second->draw(*this->_window);
    this->_window->display();
}

void Display::keyHandler()
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
            this->_view.zoom(2);
        }
    }
}

void Display::eventHandler()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->close();
        for (auto &sprite : this->_map)
            sprite->eventHandler(this->_event, *this->_window);
        this->keyHandler();
    }
}

void Display::update()
{
    if (this->_clock.getElapsedTime().asSeconds() > 0.6) {
        this->_clock.restart();
        for (auto &sprite : this->_map)
            sprite->update();
    }
    for (auto &sprite : this->_trantorians)
        sprite.second->update();
}

std::unique_ptr<sf::RenderWindow> &Display::getWindow()
{
    return this->_window;
}
