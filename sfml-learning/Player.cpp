#include "Player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
    _animation(texture, imageCount, switchTime)
{
    this->_speed = speed;
    this->_row = 0;
    this->_faceRight = true;
    
    this->_body.setSize(sf::Vector2f(16, 32));
    this->_body.setTexture(texture);
}

Player::~Player() {}

void Player::setPosition(int x, int y) {
    this->_body.setPosition(x, y);
}

sf::Vector2f Player::getPosition() {
    this->_body.getPosition();
}

void Player::update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);
    
    // check if animation should start
    bool animate = false;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        animate = true;
        movement.x -= this->_speed * deltaTime;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        animate = true;
        movement.x += this->_speed * deltaTime;
    }
    
    
    if (movement.x == 0.0f) {
        this->_row = 0;
    } else {
        this->_row = 0;
        
        if (movement.x > 0.0f) {
            this->_faceRight = true;
        } else {
            this->_faceRight = false;
        }
    }
    
    if (animate) {
        this->_animation.update(this->_row, deltaTime, this->_faceRight);
    }
    
    this->_body.setTextureRect(this->_animation.uvrect);
    this->_body.move(movement);
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(this->_body);
}
