#include "Platform.hpp"

Platform::Platform() : _rect(sf::Vector2f(0, 0)) {
    this->_rect.setPosition(0, 0);
}

Platform::Platform(int width, int height) : _rect(sf::Vector2f(width, height)) {
    this->_rect.setPosition(0, 0);
}

Platform::~Platform() {}

void Platform::setPosition(float x, float y) {
    this->_rect.setPosition(x, y);
}

sf::Vector2f Platform::getPosition() {
    return this->_rect.getPosition();
}

void Platform::setColor(const sf::Color& color) {
    this->_rect.setFillColor(sf::Color(color.r, color.g, color.b));
}

sf::Color Platform::getColor() {
    return this->_rect.getFillColor();
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(this->_rect);
}
