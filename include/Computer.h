/**************************************************************
                      COMPUTER INTERFACE

                ----- PUBLIC FUNCTIONS -----
1. Computer( char thatHumanMark )
    The default constructor requires the player's mark

2. performMove( Board &board )
    Call this function to allow AI to make a move
    The function requires Board object to make a move

3. getComputerMark()
    Return the mark or flag of the Computer
**************************************************************/

#ifndef COMPUTER_H
#define COMPUTER_H

#include "Board.h"

class Computer
{
private:
    // Data structure for Move that AI will use
    struct Move
    {
        Move(): row{ 0 } , col{ 0 } , score{ 0 } {}
        Move( int thatScore ): score{ thatScore } {}
        Move( int thatRow , int thatCol ): row{ thatRow} , col{ thatCol } , score{ 0 } {}

        bool operator< ( const Move &rhs ) const
        {
            return this->score < rhs.score;
        }

        int row;
        int col;
        int score;

    };

public:
   /*
    *   This constructor receives human player's mark
    *   and set computer's mark accordingly
    */
    Computer( char thatHumanMark );

   /*
    *   Public function to make AI move
    *   Calls getBestMove to find the best move
    */
    void performMove( Board &board ) const;

   /*
    *   Public function to return the mark of computer
    */
    char getComputerMark() const;

private:
   /*
    *   Internal function to find the best move that AI can make
    *   player value of 1 is Computer's turn
    *   player value of 2 is Human's turn
    */
    Move getBestMove( Board &board , char player ) const;

    // Computer's mark
    char computerMark;

    // Human Player's mark
    char humanMark;
};

#endif // COMPUTER_H
