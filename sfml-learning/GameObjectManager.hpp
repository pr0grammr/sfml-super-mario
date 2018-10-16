// Game object manager
// holds game objects to draw in window
#pragma once
#include <map>
#include "Platform.hpp"

class GameObjectManager {
public:
    static void add(std::string name, Platform& platform);
    static std::map<std::string, Platform> getObjects();
    
private:
    static std::map<std::string, Platform> _objects;
};
