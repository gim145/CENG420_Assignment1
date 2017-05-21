// main.cpp
#include <iostream>
#include "Siga.hpp"

int main()
{

    Siga Game;
    Game.drawBoard();

    do
    {

        Game.printTurn();

       if (Game.playerHuman())     // human turn?
            Game.humanMove();
        else
            Game.computerMove();

        Game.drawBoard();
        Game.nextTurn();

    }
    while (!Game.Winner());

    return 0;
}