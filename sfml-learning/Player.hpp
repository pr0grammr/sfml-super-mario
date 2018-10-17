// Player class
// defines player animations and behavior

#pragma once
#include "GameObject.hpp"

class Player : public GameObject {
public:
    
    // using base constructor
    using GameObject::GameObject;
    
    void setMovingPps(int pixelPerSecond);
    int getMovingPps();
    void update(int elapsedTime);
    
private:
    
    int _pixelPerSecond;
};


