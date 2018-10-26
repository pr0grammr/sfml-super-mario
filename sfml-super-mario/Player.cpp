#include "Player.hpp"
#include <math.h>
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
    _animation(texture, imageCount, switchTime)
{
    this->_speed = speed;
    this->_row = 0;
    this->_faceRight = true;
    this->_jumpHeight = jumpHeight;
    this->_canJump = true;
    this->_isJumping = false;
    this->_speedMultiply = 1.5;
    
    this->_body.setSize(sf::Vector2f(16, 29));
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
    this->_velocity.x = 0.0f;
    sf::Vector2f pos = this->_body.getPosition();
    
    // max jump height
    float maxJumpHeight = 200.0f;
    
    // check if animation should start
    bool animate = false;
    
    // move left
    if (pos.x >= 0.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        animate = true;
        float tmpSpeed = sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? this->_speed * this->_speedMultiply : this->_speed;
        this->_velocity.x -= tmpSpeed;
    }
    
    // move right
    if (pos.x <= 624.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        animate = true;
        float tmpSpeed = sf::Keyboard::isKeyPressed(sf::Keyboard::S) ? this->_speed * this->_speedMultiply : this->_speed;
        this->_velocity.x += tmpSpeed;
    }
    
    // jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->_canJump) {
        this->_canJump = false;
        this->_isJumping = true;
        this->_velocity.y = -sqrtf(2.0f * 981.0f * this->_jumpHeight);
    }
    
    if (this->_isJumping) {
        animate = false;
        this->_velocity.y += 981.0f * deltaTime;
    }
    
    if (pos.y > 435.0f) {
        this->_canJump = true;
        this->_isJumping = false;
        this->_velocity.y = 0.0f;
        this->setPosition(pos.x, 435);
    }
    
    
    if (this->_velocity.x == 0.0f) {
        
        this->_row = 0;
    } else {
        this->_row = 0;
        
        if (this->_velocity.x > 0.0f) {
            this->_faceRight = true;
        } else {
            this->_faceRight = false;
        }
    }
    
    bool defaultV = false;
    bool jump = false;
    
    if (!animate) {
        defaultV = true;
        jump = false;
    }
    
    if (this->_isJumping) {
        defaultV = false;
        jump = true;
    }
    
    this->_animation.update(this->_row, deltaTime, this->_faceRight, jump, defaultV);
    
    this->_body.setTextureRect(this->_animation.uvrect);
    this->_body.move(this->_velocity * deltaTime);
    
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(this->_body);
}
