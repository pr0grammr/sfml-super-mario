// Game object manager
// holds game objects to draw in window
#pragma once

#include <map>
#include "GameObject.hpp"

class GameObjectManager {
public:
    static void add(std::string name, GameObject& gameObject);
    static std::map<std::string, GameObject> getObjects();
    
private:
    static std::map<std::string, GameObject> _objects;
};
