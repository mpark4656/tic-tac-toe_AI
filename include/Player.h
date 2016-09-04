/**************************************************************
                      PLAYER INTERFACE

                ----- PUBLIC FUNCTIONS -----
1. Player()
    The default constructor requires the player's name and the
    mark that he / she would like to use.
2. getMark()
    Returns the flag that this player is using to mark his
    position on the board

3. getName()
    Return the name this player is using in this game
**************************************************************/


#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
   /*
    *   Default Constructor
    */
    Player( std::string theName , char theMark );

   /*
    *   Return mark of this player
    */
    char getMark() const;

   /*
    *   Return name of this player
    */
    std::string getName() const;

private:
    std::string name;
    char mark;
};

#endif // PLAYER_H
