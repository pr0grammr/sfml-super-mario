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
    void setColor(const sf::Color& color);
    sf::Color getColor();
    void draw(sf::RenderWindow& window);
    
private:
    sf::RectangleShape _rect;
};
