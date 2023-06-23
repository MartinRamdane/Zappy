/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu()
{
    this->_currentState = MenuState::MAIN;
    this->_previousState = MenuState::MAIN;
    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    this->_entities["A_background"] = std::make_unique<Image>("gui/assets/menu/menu_background.png");
    this->_entities["A_background"]->setSpritePosition(sf::Vector2f(0, 0));
    this->_entities["B_logo"] = std::make_unique<Image>("gui/assets/menu/main_logo.png");
    this->_entities["B_logo"]->setSpritePosition(sf::Vector2f(668, 100));
    this->_entities["B_credits"] = std::make_unique<Image>("gui/assets/menu/credits.png");
    this->_entities["B_credits"]->setSpritePosition(sf::Vector2f(784, 950));
    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    setMainEntities();
}

Menu::~Menu()
{
}

void Menu::clear()
{
    if (this->_previousState == GAME) {
        this->_entities.erase("C_backButton");
        this->_entities.erase("C_backgroundPaper");
        this->_entities.erase("C_playButton");
        this->_entities.erase("C_connectText");
        this->_entities.erase("C_ipText");
        this->_entities.erase("C_portText");
        this->_entities.erase("C_input1");
        this->_entities.erase("C_input2");
    }
    if (this->_previousState == SETTINGS) {
        this->_entities.erase("C_backgroundPaper");
        this->_entities.erase("C_content");
        this->_entities.erase("C_exitButton");
    }
    if (this->_previousState == MAIN) {
        this->_entities.erase("C_playButton");
        this->_entities.erase("C_exitButton");
        this->_entities.erase("C_settingsButton");
    }
}

void Menu::setMainEntities()
{
    this->_entities["C_playButton"] = std::make_unique<Button>("gui/assets/menu/play_button_idle.png", "gui/assets/menu/play_button_hover.png", MenuState::GAME);
    this->_entities["C_playButton"]->setSpritePosition(sf::Vector2f(730, 422));
    this->_entities["C_exitButton"] = std::make_unique<Button>("gui/assets/menu/exit_button_idle.png", "gui/assets/menu/exit_button_hover.png", MenuState::EXIT);
    this->_entities["C_exitButton"]->setSpritePosition(sf::Vector2f(730, 679));
    this->_entities["C_settingsButton"] = std::make_unique<Button>("gui/assets/menu/help_button_idle.png", "gui/assets/menu/help_button_hover.png", MenuState::SETTINGS);
    this->_entities["C_settingsButton"]->setSpritePosition(sf::Vector2f(1737, 840));
}

void Menu::setGameEntities()
{
    this->_entities["C_backButton"] = std::make_unique<Button>("gui/assets/menu/return_button_idle.png", "gui/assets/menu/return_button_hover.png", MenuState::MAIN);
    this->_entities["C_backButton"]->setSpritePosition(sf::Vector2f(50, 50));
    this->_entities["C_backgroundPaper"] = std::make_unique<Image>("gui/assets/menu/background_paper.png");
    this->_entities["C_backgroundPaper"]->setSpritePosition(sf::Vector2f(304, 204));
    this->_entities["C_playButton"] = std::make_unique<Button>("gui/assets/menu/play_button_idle.png", "gui/assets/menu/play_button_hover.png", MenuState::INGAME);
    this->_entities["C_playButton"]->setSpritePosition(sf::Vector2f(720, 746));
    this->_entities["C_connectText"] = std::make_unique<Image>("gui/assets/menu/connection_title.png");
    this->_entities["C_connectText"]->setSpritePosition(sf::Vector2f(686, 436));
    this->_entities["C_ipText"] = std::make_unique<Image>("gui/assets/menu/ip_text.png");
    this->_entities["C_ipText"]->setSpritePosition(sf::Vector2f(597, 550));
    this->_entities["C_portText"] = std::make_unique<Image>("gui/assets/menu/port_text.png");
    this->_entities["C_portText"]->setSpritePosition(sf::Vector2f(1037, 550));
    this->_entities["C_input1"] = std::make_unique<Input>("gui/assets/menu/input_background.png", "gui/assets/menu/input_background_hover.png");
    this->_entities["C_input1"]->setSpritePosition(sf::Vector2f(597, 580));
    this->_entities["C_input2"] = std::make_unique<Input>("gui/assets/menu/input_background.png", "gui/assets/menu/input_background_hover.png");
    this->_entities["C_input2"]->setSpritePosition(sf::Vector2f(1037, 580));
}

void Menu::setSettingsEntities()
{
    this->_entities["C_backgroundPaper"] = std::make_unique<Image>("gui/assets/menu/background_paper.png");
    this->_entities["C_backgroundPaper"]->setSpritePosition(sf::Vector2f(304, 204));
    this->_entities["C_content"] = std::make_unique<Image>("gui/assets/menu/help_section.png");
    this->_entities["C_content"]->setSpritePosition(sf::Vector2f(604, 454));
    this->_entities["C_exitButton"] = std::make_unique<Button>("gui/assets/menu/return_button_idle.png", "gui/assets/menu/return_button_hover.png", MenuState::MAIN);
    this->_entities["C_exitButton"]->setSpritePosition(sf::Vector2f(50, 50));
}

void Menu::setState(MenuState state)
{
    _previousState = _currentState;
    _currentState = state;
}

int Menu::update()
{
    if (_currentState != _previousState) {
        if (_currentState == GAME) {
            clear();
            setGameEntities();
        } else if (_currentState == SETTINGS) {
            clear();
            setSettingsEntities();
        } else if (_currentState == MAIN) {
            clear();
            setMainEntities();
        } else if (_currentState == INGAME) {
            // _music.stop();
            Input *ipInput = dynamic_cast<Input *>((this->_entities["C_input1"]).get());
            Input *portInput = dynamic_cast<Input *>((this->_entities["C_input2"]).get());
            _ip = ipInput->getText();
            _port = atoi(portInput->getText().c_str());
            std::cout << "IP: " << _ip << std::endl;
            std::cout << "Port: " << _port << std::endl;
            return 1;
        }
        _previousState = _currentState;
    }
    return 0;
}

int Menu::render(sf::RenderWindow &window)
{
    // render all entities
    for (auto &i: this->_entities) {
        i.second->draw(window);
    }
    window.display();
    return 0;
}

void Menu::eventHandler(sf::RenderWindow &window)
{
    while (window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            window.close();
            return;
        }
        if (this->_currentState == MenuState::EXIT) {
            window.close();
            return;
        }
        for (auto &entity: this->_entities) {
            entity.second->eventHandler(_event, window, _currentState);
        }
    }
}
