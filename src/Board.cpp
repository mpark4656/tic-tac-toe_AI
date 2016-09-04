#include "Board.h"
#include <vector>
#include <string>
#include <cassert>

const char NO_WINNER = ' ';

/*
 *   Default Constructor
 */
Board::Board(): winnerMark{ ' ' } , lastPlayedMark{ 'U' }
{
    std::vector<char> line = { ' ' , ' ' , ' ' };
    theBoard = { line , line , line };
}

/*
 *   Public function to return character at given position
 */
char Board::getPosAt( int row , int col ) const
{
    convertToComputerCoord( row , col );
    return theBoard[row][col];
}

/*
 *   Make a move and tell user whether the move was successful
 *   Return false if move was invalid
 */
bool Board::makeMove( int row , int col , char mark )
{
    convertToComputerCoord( row , col );

    if( isMoveValid(row , col , mark) ) {
        theBoard[row][col] = mark;
        lastPlayedMark = mark;
        return true;
    }

    return false;
}

/*
 *   Internal Function to decide whether the move is correct
 *   Accepts actual array coordinates
 */
bool Board::isMoveValid( int row , int col , char currentPlayerMark ) const
{
    // Current player's mark can't match the last played mark
    assert( currentPlayerMark != lastPlayedMark );

    if( row < 0 || col < 0 || row > 2 || col > 2 ) {
        return false;
    }

    if( theBoard[row][col] != ' ' ) {
        return false;
    }

    return true;
}

/*
 *   Return true if there is a winner
 *   Update winnerMark
 *   If the board is full, return true and
 *   set winnerMark as 'D' (Draw)
 */
bool Board::gameOver()
{
    if( scanBoardForWin( lastPlayedMark ) ) {
        winnerMark = lastPlayedMark;
        return true;
    }
    else if( isBoardFull() ) {
        winnerMark = 'D';
        return true;
    }
    else {
        return false;
    }
}

/*
 *   Return true if the board is full and no further moves can be made
 */
bool Board::isBoardFull() const
{
    for( int row = 0 ; row < 3 ; row++ ) {
        for( int col = 0 ; col < 3 ; col++ ) {
            if( theBoard[row][col] == ' ' ) {
                return false;
            }
        }
    }

    return true;
}

/*
 *   Internal Function to scan every line of the board
 *   to see if any player successfully made a line of 3
 *   Return true if there is a line of 3 for given mark
 */
bool Board::scanBoardForWin( char mark ) const
{
    int counter1 = 0; // Store count of horizontal lines
    int counter2 = 0; // Store count of vertical lines

    // Check vertical and horizontal lines
    for( int row = 0 ; row < 3 ; row++ ) {
        for( int col = 0 ; col < 3 ; col++ ) {
            if( theBoard[row][col] == mark ) {
                counter1++;
            }
            if( theBoard[col][row] == mark ) {
                counter2++;
            }
        }

        if( counter1 == 3 || counter2 == 3 ) {
            return true;
        }
        else{
            counter1 = 0;
            counter2 = 0;
        }
    }

    // Check Diagonal Lines
    if( theBoard[0][0] == mark && theBoard[1][1] == mark && theBoard[2][2] == mark ) {
        return true;
    }
    if( theBoard[0][2] == mark && theBoard[1][1] == mark && theBoard[2][0] == mark ) {
        return true;
    }

    return false;
}

/*
 *   Return the mark of winner
 *   Call only after winner is decided
 */
char Board::whoIsWinner() const
{
    assert( winnerMark != NO_WINNER );
    return winnerMark;
}

/*
 *   Internal function to convert user-friendly coordinate
 *   to actual coordinate.
 *   Accepts user-friendly coord and converts to actual
 *   array row and col
 */
void Board::convertToComputerCoord( int &x , int &y ) const
{
    x -= 1;
    y -= 1;
}

/*
 *   Overload operator<< to print board in user-friendly format
 */
std::ostream & operator<< ( std::ostream &out , const Board &rhs )
{
    out << "    1   2   3\n\n";

    for( int row = 1 ; row <= 3 ; row++ ) {
        out << row << "   ";

        for( int col = 1 ; col <= 3 ; col++ ) {
            std::string pipe = ( col == 3 ) ? "" : " | ";
            out << rhs.getPosAt( row , col ) << pipe;
        }

        std::string underline = ( row == 3 ) ? "\n" : "\n   -----------\n";
        out << underline;
    }

    return out;
}
