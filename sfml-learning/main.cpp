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
    
    // create ground
    GameObject p1(Game::width, 16);
    p1.setPosition(0, Game::height - 16);
    p1.setTexture(resourcePath() + "stage.png");
    manager.add("object1", p1); // add to manager
    
    // run game
    Game::run();
    
    return 0;
}
