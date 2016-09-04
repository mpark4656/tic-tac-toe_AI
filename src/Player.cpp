#include "Player.h"

/*
 *   Default Constructor
 */
Player::Player( std::string theName , char theMark )
: name{ theName } , mark{ theMark }
{}

/*
 *   Return mark of this player
 */
char Player::getMark() const
{
    return mark;
}

/*
 *   Return name of this player
 */
std::string Player::getName() const
{
    return name;
}
