#include "Animation.hpp"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
    this->_imageCount = imageCount;
    this->_switchTime = switchTime;
    this->_totalTime = 0.0f;
    this->_currentImage.x = 0;
    
    this->uvrect.width = texture->getSize().x / float(this->_imageCount.x);
    this->uvrect.height = texture->getSize().y / float(this->_imageCount.y);
}

Animation::~Animation() {}

void Animation::update(int row, float deltaTime, bool faceRight, bool jump, bool defaultV) {
    this->_currentImage.y = row;
    this->_totalTime += deltaTime;
    
    if (this->_totalTime >= this->_switchTime) {
        this->_totalTime -= this->_switchTime;
        this->_currentImage.x++;
        
        if (this->_currentImage.x >= this->_imageCount.x) {
            this->_currentImage.x = 0;
        }
    }
    
    this->uvrect.top = this->_currentImage.y * this->uvrect.height;
    
    if (jump) {
        this->_currentImage.x = 2;
    }
    
    if (defaultV) {
        this->_currentImage.x = 0;
    }
    
    if (faceRight) {
        this->uvrect.left = this->_currentImage.x * this->uvrect.width;
        this->uvrect.width = abs(this->uvrect.width);
    } else {
        this->uvrect.left = (this->_currentImage.x + 1) * abs(this->uvrect.width);
        this->uvrect.width = -abs(this->uvrect.width);
    }
}

