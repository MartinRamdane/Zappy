/*
** EPITECH PROJECT, 2023
** B-YEP-400-MAR-4-1-zappy-martin.ramdane
** File description:
** Display
*/

#include "Display.hpp"

Display::Display(int w_width, int w_height) : _width(w_width), _height(w_height)
{
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(w_width, w_height), "Zappy", sf::Style::Titlebar | sf::Style::Close);
    this->_window->setFramerateLimit(60);
    this->_window->setActive(false);
    this->_view.setSize(sf::Vector2f(w_width, w_height));
    this->_resourceManager = new ResourceManager();
    this->_bottomMenu = std::make_unique<SSide_menu>(w_width, w_height);
    this->_inventory = std::make_unique<SInventory>(w_width, w_height, this->_resourceManager);
    this->_slider = std::make_unique<SSlider>(w_width, w_height, 1);
    this->_winnerBackground.setSize(sf::Vector2f(w_width, w_height));
    this->_winnerBackground.setFillColor(sf::Color(0, 0, 0, 200));
    this->_clock_map.restart();
    this->_clock_trantorian.restart();
    if (!music.openFromFile("gui/assets/sounds/main_theme.ogg"))
        exit(84);
    this->_font.loadFromFile("gui/assets/fonts/fibberish.ttf");
    music.setVolume(50);
    music.setLoop(true);
    music.play();
    this->_winnerSprite = sf::Sprite();
    this->_winnerTexture = sf::Texture();
    this->_winnerTexture.loadFromFile("gui/assets/Confetti.png");
    this->_winnerSprite.setTexture(this->_winnerTexture);
    this->_winnerRectangle = sf::IntRect(0, 0, 512, 512);
    this->_winnerSprite.setTextureRect(this->_winnerRectangle);
    this->_winnerSprite.setScale(sf::Vector2f(4, 4));
    this->_winnerSprite.setPosition(sf::Vector2f(this->_width / 2 - this->_winnerSprite.getGlobalBounds().width / 2, this->_height - this->_winnerSprite.getGlobalBounds().height / 2 - 100));
}

Display::~Display()
{
    delete this->_resourceManager;
}

void Display::createMap(int width, int height)
{
    int waterWidth = 0;
    int waterHeight = 0;
    if (width == 10) {
        waterWidth = 6 * width;
    }
    if (height == 10) {
        waterHeight = 6 * height;
    }
    if (width > 10 && width < 20) {
        waterWidth = 4 * width;
    }
    if (height > 10 && height < 20) {
        waterHeight = 4 * height;
    }
    if (width >= 20) {
        waterWidth = width / 2;
    }
    if (height >= 20) {
        waterHeight = height / 2;
    }


    std::vector<std::string> array(height + 2 * waterHeight);

    for (int i = 0; i < height + 2 * waterHeight; i++) {
        array[i] = std::string(width + 2 * waterWidth, 'r');
    }

    for (int i = waterHeight; i < height + waterHeight; i++) {
        for (int j = waterWidth; j < width + waterWidth; j++) {
            if (i == waterHeight && j == waterWidth) {
                array[i][j] = 'h';
            } else if (i == waterHeight && j == width + waterWidth - 1) {
                array[i][j] = 'i';
            } else if (i == height + waterHeight - 1 && j == waterWidth) {
                array[i][j] = 'j';
            } else if (i == height + waterHeight - 1 && j == width + waterWidth - 1) {
                array[i][j] = 'k';
            } else if (i == waterHeight) {
                array[i][j] = 'l';
            } else if (j == waterWidth) {
                array[i][j] = 'm';
            } else if (j == width + waterWidth - 1) {
                array[i][j] = 'n';
            } else if (i == height + waterHeight - 1) {
                array[i][j] = 'o';
            } else {
                array[i][j] = 'g';
            }
        }
    }
    array.push_back("");

    array[waterHeight - 1][waterWidth - 1] = 'w';
    for (int i = waterWidth; i < width + waterWidth; i++) {
        array[waterHeight - 1][i] = 'q';
        array[height + waterHeight][i] = 'a';
    }

    for (int i = waterHeight; i < height + waterHeight; i++) {
        array[i][waterWidth - 1] = 'p';
        array[i][width + waterWidth] = 'z';
    }
    array[waterHeight - 1][width + waterWidth] = 'x';
    array[height + waterHeight][waterWidth - 1] = 's';
    array[height + waterHeight][width + waterWidth] = 'd';

    for (int y = 0; y < height + 2 * waterHeight; y++) {
        for (int x = 0; x < width + 2 * waterWidth; x++)
           this->_map.push_back(std::make_unique<STile>(x - waterWidth, y - waterHeight, array[y][x], this->_resourceManager));
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
    std::vector<std::pair<int, IEntity *>> sortedTrantorians;
    if (this->_trantorians.size() > 0) {
        for (auto &sprite : this->_trantorians)
            sortedTrantorians.push_back(std::make_pair(sprite.second->getSpritePosition().y, sprite.second.get()));
        std::sort(sortedTrantorians.begin(), sortedTrantorians.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
    }
    this->_window->clear(sf::Color::Black);
    for (auto &sprite : this->_ocean)
        sprite->draw(*this->_window, this->_view);
    for (auto &sprite : this->_map)
       sprite->draw(*this->_window, this->_view);
    if (this->_trantorians.size() > 0) {
        for (auto &sprite : sortedTrantorians)
            sprite.second->draw(*this->_window, this->_view);
    }
    if (this->_zoom < this->_slider->getZoom()) {
        this->_view.zoom(0.9);
        this->_zoom = this->_slider->getZoom();
    } else if (this->_zoom > this->_slider->getZoom()) {
        this->_view.zoom(1.1);
        this->_zoom = this->_slider->getZoom();
    }
    this->_window->setView(this->_bottomMenuView);
    if (this->_click_pos.x != -1 && this->_click_pos.y != -1)
        this->_bottomMenu->draw(*this->_window);
    if (this->_trantorian_clicked.x != -1 && this->_trantorian_clicked.y != -1)
        this->_inventory->draw(*this->_window);
    this->_slider->draw(*this->_window);
    if (this->_winner != "") {
        this->_window->draw(this->_winnerBackground);
        this->_window->draw(this->_winnerSprite);
        this->_window->draw(this->_winnerText);
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
        } else if (this->_event.key.code == sf::Keyboard::W) {
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
            this->_bottomMenu->fadeIn(false);
            this->_bottomMenu->fadeOut(true);
        } else if (this->_event.key.code == sf::Keyboard::P) {
            if (this->_slider->getOpacity() == 0) {
                this->_slider->fadeOut(false);
                this->_slider->fadeIn(true);
            } else if (this->_slider->getOpacity() == 255) {
                this->_slider->fadeOut(true);
                this->_slider->fadeIn(false);
            }
        } else if (this->_event.key.code == sf::Keyboard::I) {
            this->_inventory->fadeIn(false);
            this->_inventory->fadeOut(true);
        } else if (this->_event.key.code == sf::Keyboard::C) {
            this->_message = "sst " + std::to_string(cache.getFrequency() - 1) + "\n";
        } else if (this->_event.key.code == sf::Keyboard::V) {
            this->_message = "sst " + std::to_string(cache.getFrequency() + 1) + "\n";
        }
    }
}

void Display::clickHandler(MapT cache)
{
    bool clicked = false;
    this->_slider->eventHandler(this->_event, *this->_window);

    if (this->_zoom == this->_slider->getZoom()) {
        for (auto &sprite : this->_trantorians) {
            sf::Vector2i click = sprite.second->getClicked();
            if (click.x  != -1 && click.y != -1) {
                clicked = true;
                this->_trantorian_clicked = click;
                this->_inventory->fadeOut(false);
                this->_inventory->fadeIn(true);
                this->_message = "pin " + std::to_string(click.x) + "\n";
            }
        }
        int opacity = this->_inventory->getOpacity();
        this->_inventory->eventHandler(this->_event, *this->_window);
        for (auto &sprite : this->_map) {
            sf::Vector2i click = sprite->getClicked();
            if (click.x != -1 && click.y != -1 && clicked == false && (opacity == 0 || this->_inventory->isFadingOut() == false)) {
                this->_click_pos = click;
                this->_bottomMenu->fadeOut(false);
                this->_bottomMenu->fadeIn(true);
            }
        }
    }
}

void Display::eventHandler(MapT cache)
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->close();
        if (cache.getWinner() != "") {
            this->_inventory->fadeIn(false);
            this->_inventory->fadeOut(true);
            this->_bottomMenu->fadeIn(false);
            this->_bottomMenu->fadeOut(true);
            this->_slider->fadeIn(false);
            this->_slider->fadeOut(true);
            return;
        }
        this->clickHandler(cache);
        if (this->_zoom == this->_slider->getZoom()) {
            if (this->_trantorians.size() > 0) {
                for (auto &sprite : this->_trantorians)
                    sprite.second->eventHandler(this->_event, *this->_window);
            }
            for (auto &sprite : this->_map)
                sprite->eventHandler(this->_event, *this->_window);
        }
        this->keyHandler(cache);
    }
}

void Display::update(MapT *cache)
{
    const sf::Time targetFrameTime = sf::seconds(1.0f / cache->getFrequency());
    if (this->_mapCreated == false && cache->getX() != 0 && cache->getY() != 0) {
        this->createMap(cache->getX(), cache->getY());
        this->createViews(cache->getX(), cache->getY());
        this->_mapCreated = true;
    }
    if (this->_trantorians.size() > 0) {
        for (auto &sprite : this->_trantorians)
            sprite.second->moveSprite(cache);
        if (this->_clock_trantorian.getElapsedTime() > targetFrameTime) {
            this->_clock_trantorian.restart();
            for (auto &sprite : this->_trantorians)
                sprite.second->update(cache);
        }
    }
    if (this->_clock_map.getElapsedTime() > targetFrameTime) {
        this->_clock_map.restart();
        for (auto &sprite : this->_map)
            sprite->update(cache);
    }
    if (this->_trantorians.size() != cache->getTrantorians().size()) {
        this->_trantorians.clear();
        for (auto &trantor : cache->getTrantorians())
            this->_trantorians[trantor.getId()] = std::make_unique<STrantorian>(trantor, this->_resourceManager);
    }
    if (this->_click_pos.x != -1 && this->_click_pos.y != -1)
        this->_bottomMenu->update(cache->getTile(this->_click_pos.x, this->_click_pos.y).getStocks());
    bool notFound = true;
    if (this->_trantorians.size() > 0) {
        for (auto &sprite : this->_trantorians) {
            if (sprite.first == this->_trantorian_clicked.x) {
                notFound = false;
                STrantorian *trantorian = dynamic_cast<STrantorian *>(this->_trantorians[this->_trantorian_clicked.x].get());
                this->_inventory->setTrantorianTexture(trantorian->getTexture());
                this->_inventory->update(cache->getTrantorian(this->_trantorian_clicked.x).getStocks(), cache->getTrantorian(this->_trantorian_clicked.x).getTeam(), cache->getTrantorian(this->_trantorian_clicked.x).getLvl());
            }
        }
    }
    if (notFound == true) {
        this->_trantorian_clicked = sf::Vector2i(-1, -1);
    }
    this->_slider->update(cache);
    if (this->_inventory->getOpacity() == 0) {
        this->_trantorian_clicked = sf::Vector2i(-1, -1);
    }

    if (cache->getWinner() != "") {
        this->_winner = cache->getWinner();
        this->_winnerText.setFont(this->_font);
        this->_winnerText.setCharacterSize(100);
        this->_winnerText.setFillColor(sf::Color::White);
        this->_winnerText.setString(cache->getWinner() + " won the game !");
        this->_winnerText.setPosition(sf::Vector2f(this->_width / 2 - this->_winnerText.getGlobalBounds().width / 2, this->_height / 2 - 100));
    }

    if (this->_winner != "" && this->_clock_confetti.getElapsedTime().asSeconds() > 0.05) {
        if (this->_winnerRectangle.left >= 3584 && this->_winnerRectangle.top <= 4096) {
            this->_winnerRectangle.left = 512;
            this->_winnerRectangle.top += 512;
        } else {
            this->_winnerRectangle.left += 512;
        }
        this->_winnerSprite.setTextureRect(this->_winnerRectangle);
        this->_clock_confetti.restart();
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
