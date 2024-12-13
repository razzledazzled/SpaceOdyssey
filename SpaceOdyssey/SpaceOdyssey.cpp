/* Program name: SpaceOdyssey.cpp
*  Author: Anthony Harris
*  Date last updated: 25/11/2024
*  Purpose: Plays game
*/

//https://github.com/ErnestoRoja/Space-Shooter-Game.git
//https://github.com/alaminut/SFML-Space-Shooter.git

#include <SFML/Graphics.hpp>

#include <time.h>
#include "Game.h"



int main() 
{
    srand(static_cast<unsigned int>(time(0)));

    Game game;

    game.run();

    return 0;
}
