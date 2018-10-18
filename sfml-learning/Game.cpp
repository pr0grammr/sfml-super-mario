#include "Game.hpp"
#include "ResourcePath.hpp"

void Game::run() {
    if (_gameState != UNINITIALIZED) {
        return;
    }
    
    _window.create(sf::VideoMode(width, height), title);
    _gameState = RUNNING;
    
    _deltaTime = 0.0f;
    
    sf::Texture playerTexture;
    playerTexture.loadFromFile(resourcePath() + "supermario.png");
    Player player(&playerTexture, sf::Vector2u(3, 1), 0.1f, 120.0f);
    player.setPosition(0, height - 48);
    
    while (_isRunning()) {
        _loop(player);
    }
    
    _window.close();
}

void Game::_loop(Player& player) {
    
    _deltaTime = _timer.restart().asSeconds();
    
    // player current position
    sf::Vector2f pos = player.getPosition();
    
    sf::Event e;
    
    // waiting for user action
    while (_window.pollEvent(e)) {
        if (e.type == sf::Event::EventType::Closed) {
            _gameState = EXITING;
        }
    }
    
    _window.clear();
    
    // handling objects from object manager
    for(auto& platform : _gameObjectManager.getObjects()) {
        platform.second.draw(_window);
    }
    
    if (pos.x >= 0 && pos.x <= width) {
        player.update(_deltaTime);
    }
    
    player.draw(_window);
    
    _window.display();
}

bool Game::_isRunning() {
    if (_gameState != EXITING) {
        return true;
    }
    
    return false;
}

GameObjectManager Game::getManager() {
    return _gameObjectManager;
}

Game::GameState Game::_gameState = UNINITIALIZED;
sf::RenderWindow Game::_window;

// set default values
float Game::width = 640;
float Game::height = 480;
std::string Game::title = "SFML - Demo";
sf::Clock Game::_timer;
float Game::_deltaTime;

