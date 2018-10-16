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
    Game::WIDTH = 640;
    Game::HEIGHT = 480;
    Game::TITLE = "SFML - Super Mario";
    
    // run game
    Game::run();
    
    return 0;
}
