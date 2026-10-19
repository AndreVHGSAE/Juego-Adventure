#include <iostream>
#include "Game.h"

int main()
{
    Game game;
    game.InitGame();
    while (game.GetPlaying())
    {
        game.mainMenu();
    }
    return 0;
}

