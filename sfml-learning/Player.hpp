// Player class
// defines player animations and behavior
#pragma once

#include "Animation.hpp"

class Player {
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~Player();
    
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void setPosition(int x, int y);
    sf::Vector2f getPosition();
    
private:
    sf::RectangleShape _body;
    Animation _animation;
    unsigned int _row;
    float _speed;
    bool _faceRight;
};
