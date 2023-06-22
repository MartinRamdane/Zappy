/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    this->_currentState = MAIN;
    this->_previousState = MAIN;
    setMainEntities();
}

Menu::~Menu()
{
}

void Menu::setMainEntities()
{
    this->_entities["A_background"] = std::make_unique<Image>("gui/assets/menu/menu_background.png");
    this->_entities["A_background"]->setSpritePosition(sf::Vector2f(0, 0));
    this->_entities["B_logo"] = std::make_unique<Image>("gui/assets/menu/main_logo.png");
    this->_entities["B_logo"]->setSpritePosition(sf::Vector2f(668, 69));
    this->_entities["B_credits"] = std::make_unique<Image>("gui/assets/menu/credits.png");
    this->_entities["B_credits"]->setSpritePosition(sf::Vector2f(784, 999));
    this->_entities["C_playButton"] = std::make_unique<Button>("gui/assets/menu/play_button_idle.png", "gui/assets/menu/play_button_hover.png");
    this->_entities["C_playButton"]->setSpritePosition(sf::Vector2f(730, 422));
    this->_entities["C_exitButton"] = std::make_unique<Button>("gui/assets/menu/exit_button_idle.png", "gui/assets/menu/exit_button_hover.png");
    this->_entities["C_exitButton"]->setSpritePosition(sf::Vector2f(730, 699));
    this->_entities["C_settingsButton"] = std::make_unique<Button>("gui/assets/menu/help_button_idle.png", "gui/assets/menu/help_button_hover.png");
    this->_entities["C_settingsButton"]->setSpritePosition(sf::Vector2f(1737, 897));
}

void Menu::setState(MenuState state)
{
    _previousState = _currentState;
    _currentState = state;
}

int Menu::render(sf::RenderWindow &window)
{
    // render all entities
    for (auto &i: this->_entities) {
        i.second->draw(window);
    }
    window.display();
}

int Menu::eventHandler(sf::RenderWindow &window)
{
    while (window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            window.close();
            return 84;
        }
        for (auto &entity: this->_entities) {
            entity.second->eventHandler(_event, window);
        }
    }
}
