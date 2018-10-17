#include "Platform.hpp"

Platform::Platform() : _rect(0, 0, 0, 0), _textureRepeat(true) {
    this->_sprite.setPosition(0, 0);
}

Platform::Platform(int width, int height) : _rect(0, 0, width, height), _textureRepeat(true) {
    this->_sprite.setPosition(0, 0);
}

Platform::~Platform() {}

void Platform::setPosition(float x, float y) {
    this->_sprite.setPosition(x, y);
}

sf::Vector2f Platform::getPosition() {
    return this->_sprite.getPosition();
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(this->_sprite);
}

void Platform::setTexture(std::string texturePath) {
    this->_texture.loadFromFile(texturePath);
    this->_texture.setRepeated(this->_textureRepeat);
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setTextureRect(this->_rect);
}

bool Platform::setTextureRepeat(bool repeat) {
    this->_textureRepeat = repeat;
}
