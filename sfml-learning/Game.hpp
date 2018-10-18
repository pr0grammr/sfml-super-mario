#pragma once

#include <SFML/Graphics.hpp>
#include "GameObjectManager.hpp"
#include "Player.hpp"

// Game class
// controls game events and object rendering
// all methods and properties are called statically
class Game {
public:
    
    static float width;
    static float height;
    static std::string title;
    
    // define various game states
    enum GameState {
        RUNNING,
        EXITING,
        UNINITIALIZED,
        PAUSE
    };
    
    static void run(void);
    static GameObjectManager getManager();
    static void setPlayer(Player& player);
    
private:
    
    static GameState _gameState;
    static sf::RenderWindow _window;
    static GameObjectManager _gameObjectManager;
    
    static void _loop(Player& player);
    static bool _isRunning(void);
    
    static sf::Clock _timer;
    static float _deltaTime;
    
};
