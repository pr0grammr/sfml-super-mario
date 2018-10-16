#include "Game.hpp"

void Game::run() {
    if (_gameState != UNINITIALIZED) {
        return;
    }
    
    _window.create(sf::VideoMode(WIDTH, HEIGHT), TITLE);
    _gameState = RUNNING;
    
    while (_isRunning()) {
        _loop();
    }
    
    _window.close();
}

void Game::_loop() {
    sf::Event e;
    while (_window.pollEvent(e)) {
        if (e.type == sf::Event::EventType::Closed) {
            _gameState = EXITING;
        }
    }
}

bool Game::_isRunning() {
    if (_gameState != EXITING) {
        return true;
    }
    
    return false;
}

Game::GameState Game::_gameState = UNINITIALIZED;
sf::RenderWindow Game::_window;

// set default values
float Game::WIDTH = 640;
float Game::HEIGHT = 480;
std::string Game::TITLE = "SFML - Demo";

