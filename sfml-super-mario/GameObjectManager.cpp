#include "GameObjectManager.hpp"

void GameObjectManager::add(std::string name, GameObject& gameObject) {
    _objects.insert(std::pair<std::string, GameObject>(name, gameObject));
}

std::map<std::string, GameObject> GameObjectManager::getObjects() {
    return _objects;
}

std::map<std::string, GameObject> GameObjectManager::_objects;
