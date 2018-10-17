// Platform class
// Mario can run or jump on it
#pragma once
#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform();
    Platform(int width, int height);
    ~Platform();
    
    // define dimensions and position
    int width, height;
    
    void setPosition(float x, float y);
    sf::Vector2f getPosition();
    void draw(sf::RenderWindow& window);
    void setTexture(std::string texturePath);
    bool setTextureRepeat(bool repeat);
    
private:
    sf::IntRect _rect;
    sf::Texture _texture;
    sf::Sprite _sprite;
    bool _textureRepeat;
};
