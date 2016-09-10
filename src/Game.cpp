#include "Game.h"

/*
 *   Default Constructor
 */
Game::Game( Player human ): humanPlayer{ human } , ai{ human.getMark() }
{}

/*
 *   After a player wins, announce the winner
 */
void Game::announceWinner() const
{
    std::cout << std::endl;

    if( gameBoard.whoIsWinner() == humanPlayer.getMark() ) {
        std::cout << "You have won!!";
    }
    else if( gameBoard.whoIsWinner() == ai.getComputerMark() ) {
        std::cout << "The computer has won.";
    }
    else {
        std::cout << "It's a draw.";
    }
}

/*
 *   Game Driver for Human Making a move first
 */
void Game::runHumanFirst()
{
    int row;
    int col;

    // Present the game board
    std::cout << gameBoard << std::endl;

    while( !gameBoard.gameOver() ) {
        std::cout << humanPlayer.getName() << ", you are "
                  << humanPlayer.getMark() << ". Enter your move [ row col ]: ";
        std::cin >> row >> col;

        while( !gameBoard.makeMove(row , col , humanPlayer.getMark() ) ) {
            std::cout << "Enter a valid move [ row col ]: ";
            std::cin >> row >> col;
        }

        std::cout << gameBoard << std::endl;

        if( gameBoard.gameOver() ) {
            break;
        }

        std::cout << "Computer is making a move..." << std::endl;

        ai.performMove( gameBoard );

        std::cout << gameBoard << std::endl;
    }

    announceWinner();
}

/*
 *   Game Driver for Computer making a move first
 */
void Game::runComputerFirst()
{
    int row;
    int col;

    while( !gameBoard.gameOver() ) {
        std::cout << "Computer is making a move..." << std::endl;
        ai.performMove( gameBoard );
        std::cout << gameBoard << std::endl;

        if( gameBoard.gameOver() ) {
            break;
        }

        std::cout << humanPlayer.getName() << ", you are " 
                  << humanPlayer.getMark() << ". Enter your move [ row col ]: ";
        std::cin >> row >> col;

        while( !gameBoard.makeMove(row , col , humanPlayer.getMark() ) ) {
            std::cout << "Enter a valid move [ row col ]: ";
            std::cin >> row >> col;
        }

        std::cout << gameBoard << std::endl;
    }

    announceWinner();
}
