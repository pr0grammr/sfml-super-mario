#include "GameObject.hpp"

GameObject::GameObject() : _rect(0, 0, 0, 0), _textureRepeat(true) {
    this->_sprite.setPosition(0, 0);
}

GameObject::GameObject(int width, int height) : _rect(0, 0, width, height), _textureRepeat(true) {
    this->_sprite.setPosition(0, 0);
}

GameObject::~GameObject(){}

void GameObject::setPosition(float x, float y) {
    this->_sprite.setPosition(x, y);
}

sf::Vector2f GameObject::getPosition() {
    return this->_sprite.getPosition();
}

void GameObject::draw(sf::RenderWindow& window) {
    window.draw(this->_sprite);
}

void GameObject::setTexture(std::string texturePath) {
    this->_texture.loadFromFile(texturePath);
    this->_texture.setRepeated(this->_textureRepeat);
    this->_sprite.setTexture(this->_texture);
    this->_sprite.setTextureRect(this->_rect);
}

bool GameObject::setTextureRepeat(bool repeat) {
    this->_textureRepeat = repeat;
}
