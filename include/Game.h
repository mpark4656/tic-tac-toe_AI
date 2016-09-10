/**************************************************************
                      GAME INTERFACE

                ----- PUBLIC FUNCTION -----
Game()
    The default constructor requires a human player object.

run()
    This function drives the game until a player wins. Call
    this function from main() in order to start the game.
**************************************************************/

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "Computer.h"

class Game
{
public:
   /*
    *   Default Constructor
    */
    Game( Player human );

   /*
    *   Game Driver for Human making a move first
    */
    void runHumanFirst();

   /*
    *   Game Driver for Computer making a move first
    */
    void runComputerFirst();

private:
    Board gameBoard{};
    Player humanPlayer;
    Computer ai;

   /*
    *   After a player wins, announce the winner
    */
    void announceWinner() const;
};

#endif // GAME_H
