#pragma once
#include <SFML/Graphics.hpp>

// Game class
// controls game events and object rendering
// all methods and properties are called statically
class Game {
public:
    
    static float WIDTH;
    static float HEIGHT;
    static std::string TITLE;
    
    // define various game states
    enum GameState {
        RUNNING,
        EXITING,
        UNINITIALIZED,
        PAUSE
    };
    
    static void run(void);
    
private:
    
    static GameState _gameState;
    static sf::RenderWindow _window;
    
    static void _loop(void);
    static bool _isRunning(void);
    
};
