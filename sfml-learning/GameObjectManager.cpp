#include "GameObjectManager.hpp"

void GameObjectManager::add(std::string name, Platform& platform) {
    _objects.insert(std::pair<std::string, Platform>(name, platform));
}

std::map<std::string, Platform> GameObjectManager::getObjects() {
    return _objects;
}

std::map<std::string, Platform> GameObjectManager::_objects;
