#include <iostream>
#include "Game.h"

int main()
{
    std::string name;
    char mark;
    char choice;

    std::cout << "Welcome to C++ Tic-Tac-Toe. You will be playing against the computer.\n\n";
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Do you want to be X or O: ";
    std::cin >> mark;
    std::cout << "Do you want to make the first move? (Y or N): ";
    std::cin >> choice;

    Player human{ name , mark };

    Game game{ human };

    if( choice == 'N' ) {
        game.runComputerFirst();
    }
    else {
        game.runHumanFirst();
    }

    return 0;
}
