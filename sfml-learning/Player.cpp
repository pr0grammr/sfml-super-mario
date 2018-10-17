#include "Player.hpp"
#include <iostream>

void Player::setMovingPps(int pixelPerSecond) {
    this->_pixelPerSecond = pixelPerSecond;
}

int Player::getMovingPps() {
    return this->_pixelPerSecond;
}

void Player::update(int elapsedTime) {
    std::cout << "Called child" << std::endl;
    // control user input
    sf::Vector2f pos; // player position;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->_sprite.move(1, 0);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->_sprite.move(-1, 0);
    }
}
