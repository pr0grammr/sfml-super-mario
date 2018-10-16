////////////////////////////
//                        //
// SFML Learning          //
// Author: Fabian Schilf  //
//                        //
////////////////////////////

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

#include "Game.hpp"

int main(int, char const**)
{
    // settings for Game
    Game::width = 640;
    Game::height = 480;
    Game::title = "SFML - Super Mario";
    
    // get the objectmanager
    GameObjectManager manager = Game::getManager();
    Platform p1(200, 40);
    p1.setPosition(0, 40);
    p1.setColor(sf::Color(255,255,255));
    
    // add platform to game object manager
    manager.add("object1", p1);
    
    // run game
    Game::run();
    
    return 0;
}
