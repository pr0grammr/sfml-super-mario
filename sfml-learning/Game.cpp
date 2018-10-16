#include "Game.hpp"

void Game::run() {
    if (_gameState != UNINITIALIZED) {
        return;
    }
    
    _window.create(sf::VideoMode(width, height), title);
    _gameState = RUNNING;
    
    while (_isRunning()) {
        _loop();
    }
    
    _window.close();
}

void Game::_loop() {
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

