// Animation class
// animates a game object
#pragma once
#include <SFML/Graphics.hpp>

class Animation {
public:
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Animation();
    
    sf::IntRect uvrect;
    
    void update(int row, float deltaTime, bool faceRight, bool jump, bool defaultV);
    
private:
    sf::Vector2u _imageCount;
    sf::Vector2u _currentImage;
    
    float _totalTime;
    float _switchTime;
};
