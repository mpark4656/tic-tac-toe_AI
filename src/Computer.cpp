#include "Computer.h"
#include <vector>
#include <algorithm>

/*
 *   This constructor receives human player's mark
 *   and set computer's mark accordingly
 */
Computer::Computer( char thatHumanMark )
: computerMark{ (thatHumanMark == 'O') ? 'X' : 'O' } , humanMark{ thatHumanMark }
{}

/*
 *   Public function to return the mark of computer
 */
char Computer::getComputerMark() const
{
    return computerMark;
}

/*
 *   Public function to make AI move
 *   Calls getBestMove to find the best move
 */
void Computer::performMove( Board &board ) const
{
    Move nextAIMove = getBestMove( board , computerMark );

    // Convert to Human-Friendly Coordinate since makeMove()
    // was designed to take such input from human.
    // For example, makeMove() does not take 0 row or col
    nextAIMove.row += 1;
    nextAIMove.col += 1;

    board.makeMove( nextAIMove.row , nextAIMove.col , computerMark );
}

/*
 *   Internal function to find the best move that AI can make
 *   player value of 1 is Computer's turn
 *   player value of 2 is Human's turn
 */
Computer::Move Computer::getBestMove( Board &board , char player ) const
{
    // Base cases. Return score if the game is over
    // Return Move with score of 10 if computer wins the game
    // Return Move with score of -10 if computer loses the game
    // Return Move with score of 0 if it's a draw
    if( board.scanBoardForWin(computerMark) ) {
        return Move{ 10 };
    }
    else if( board.scanBoardForWin(humanMark) ) {
        return Move{ -10 };
    }
    else if( board.isBoardFull() ){
        return Move{ 0 };
    }

    // Store all moves
    std::vector<Move> moves;

    // Minimax recursion to check all empty spots on the board and simulate
    // computer and human moves.
    for( int row = 0 ; row < 3 ; row++ ) {
        for( int col = 0 ; col < 3 ; col++ ) {
            char position = board.getPosAt( row , col );

            if( position == ' ' ) {
                Move aiMove{ row , col };

                board.setPosAt( row , col , player );

                if( player == computerMark ) {
                    aiMove.score = getBestMove( board , humanMark ).score;
                }
                else {
                    aiMove.score = getBestMove( board , computerMark ).score;
                }

                moves.push_back( aiMove );

                // Reset the position after simulation to prevent changing the real board
                board.setPosAt( row , col , ' ' );
            }
        }
    }

    std::vector<Move>::iterator itr;

    if( player == computerMark ) {
        itr = std::max_element( moves.begin() , moves.end() );
    }
    else {
        itr = std::min_element( moves.begin() , moves.end() );
    }

    return *itr;
}
