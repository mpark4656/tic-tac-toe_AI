/**************************************************************
                      BOARD INTERFACE

                ----- PUBLIC FUNCTIONS -----
1. makeMove( int row , int col , char mark )
    Provide the coordinate at which you'd like to make a move
    at and the flag you'd like to mark the position with.
    If the move can't be made either because the given position
    is out-of-bound or there is already a move previously made
    at the position, this function will return false and no
    move will be made. If the requested move is successfully
    made, it will return true.

2. getPosAt( int row , int col )
    Provide the mark or flag at the specified position. This
    function is called by the overloaded operator<< and you
    should not have to call this function in the game
    application.

3. gameOver()
    Returns true if the game is over because a player has won
    or the board is full and no further moves can be made.
    This function will update winner's mark and allow you to
    call whoIsWinner(). This function has to be called after
    each player move.

4. whoIsWinner()
    This function returns the mark or flag of the player that
    has won the game or 'D' if the game is a draw. Use this
    function after gameOver() returns true to find out which
    player has won the game or if the game is a draw.
**************************************************************/

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board
{
public:
   /*
    *   Default Constructor
    */
    Board();

   /*
    *   Make a move and tell user whether the move was successful
    *   Return false if move was invalid
    */
    bool makeMove( int row , int col , char mark );

   /*
    *   Public function to return character at given position
    */
    char getPosAt( int row , int col ) const;

   /*
    *   Return true if there is a winner
    *   Update winnerMark
    *   If the board is full, return true and
    *   set winnerMark as 'D' (Draw)
    */
    bool gameOver();

   /*
    *   Return the mark of winner
    *   Called only after winner is decided by gameOver()
    */
    char whoIsWinner() const;

private:
    // Board Array
    std::vector<std::vector<char>> theBoard;

    // Store the mark of winner
    char winnerMark;

    // Store the flag of last played move - Keep track of player's turn
    char lastPlayedMark;

   /*
    *   Return true if the board is full and no further moves can be made
    */
    bool isBoardFull() const;

   /*
    *   Internal function to scan every line of the board
    *   to see if any player successfully made a line of 3
    */
    bool scanBoardForWin( char mark ) const;

   /*
    *   Internal function to convert user-friendly coordinate
    *   to actual coordinate.
    *   Accepts user-friendly coord and converts to actual
    *   array row and col
    */
    void convertToComputerCoord( int &x , int &y ) const;

   /*
    *   Internal Function to decide whether the move is correct
    *   Accepts actual array coordinates
    */
    bool isMoveValid( int row , int col , char currentPlayerMark ) const;
};

// Overload operator<< to print board in user-friendly format
std::ostream & operator<< ( std::ostream &out , const Board &rhs );

#endif // BOARD_H
