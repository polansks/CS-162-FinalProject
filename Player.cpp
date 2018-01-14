/****************************************************************
 ** File Name:      Player.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the player in the game
 ****************************************************************/

#include "Player.hpp"

/***************************************************************
 ** Function:       Player
 ** Description:    constructor
 ** Parameters:     none
 ***************************************************************/
Player::Player()
{
    name = "";
    currentSpace = nullptr;
    health = STARTING_HEALTH;
    return;
}


/***************************************************************
 ** Function:       Player
 ** Description:    Constructor
 ** Parameters:     name and initial space
 ***************************************************************/
Player::Player(string n, Space* s)
{
    name = n;
    currentSpace = s;
    health = STARTING_HEALTH;
    return;
}


/***************************************************************
 ** Function:       Player
 ** Description:    copy constructor
 ** Parameters:     a player
 ***************************************************************/
Player::Player(const Player &p)
{
    name = p.name;
    currentSpace = p.currentSpace;
    health = p.health;
    return;
}


/***************************************************************
 ** Function:       assignment operator
 ** Description:    assignment operator
 ** Parameters:     none
 ***************************************************************/
Player& Player::operator=(const Player &p)
{
    if (this != &p)
    {
        name = p.name;
        currentSpace = p.currentSpace;
        health = p.health;
    }
    return *this;
}


/***************************************************************
 ** Function:       ~Player
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
Player::~Player()
{
    return;
}


/***************************************************************
 ** Function:       getName
 ** Description:    returns the name of the player
 ** Parameters:     none
 ***************************************************************/
string Player::getName()
{
    return name;
}


/***************************************************************
 ** Function:       setName
 ** Description:    sets the name of the player
 ** Parameters:     none
 ***************************************************************/
void Player::setName(string n)
{
    name = n;
    return;
}


/***************************************************************
 ** Function:       getSpace
 ** Description:    returns a pointer to the space in any given
 **                 direction from the player's current space
 ** Parameters:     direction
 ***************************************************************/
Space* Player::getSpace(DIRECTION d)
{
    switch (d)
    {
        case TOP:
            return currentSpace->getTop();
            break;
        case BOTTOM:
            return currentSpace->getBottom();
            break;
        case LEFT:
            return currentSpace->getLeft();
            break;
        case RIGHT:
            return currentSpace->getRight();
            break;
    }
    return nullptr;
    
}

/***************************************************************
 ** Function:       getCurrentSpace
 ** Description:    returns a pointer to the current space that
 **                 the player is occupying
 ** Parameters:     none
 ***************************************************************/
Space* Player::getCurrentSpace()
{
    return currentSpace;
}

/***************************************************************
 ** Function:       setCurrentSpace
 ** Description:    sets the current space of the player
 ** Parameters:     pointer to the space to set the player to
 ***************************************************************/
void Player::setCurrentSpace(Space* s)
{
    currentSpace = s;
    return;
}


/***************************************************************
 ** Function:       getHealth
 ** Description:    returns the player's current health score
 ** Parameters:     none
 ***************************************************************/
int Player::getHealth()
{
    return health;
}


/***************************************************************
 ** Function:       move
 ** Description:    moves the player to a different space
 ** Parameters:     the direction the player should move
 ***************************************************************/
void Player::move(DIRECTION direction)
{
    if (currentSpace->getNeighbor(direction) != nullptr && currentSpace->getNeighbor(direction)->getType() != "Table")
    {
        currentSpace = currentSpace->getNeighbor(direction);
        currentSpace->visit();
    }
    else if (currentSpace->getNeighbor(direction) != nullptr && currentSpace->getNeighbor(direction)->getType() == "Table")
    {
        std::cout << "\n*********************************************************************" << std::endl;
        std::cout << "A table is in the spot you attempted to move to. You lost a turn." << std::endl;
        std::cout << "*********************************************************************" << std::endl;
        std::cout << "(Press [Enter] to continue.)" << std::endl;
        char c = std::cin.get();
        
        currentSpace->getNeighbor(direction)->visit();
    }
    
    health--;
    return;
}


/***************************************************************
 ** Function:       addToBag
 ** Description:    adds an item to the player's bag
 ** Parameters:     pointer to the item
 ***************************************************************/
bool Player::addToBag(Item *i)
{
    return playerBag.push(i);
}


/***************************************************************
 ** Function:       oxygenCount
 ** Description:    number of oxygens in the player's bag
 ** Parameters:     none
 ***************************************************************/
int Player::oxygenCount()
{
    return playerBag.oxygenCount();
}


/***************************************************************
 ** Function:       hydrogenCount
 ** Description:    number of hydrogens in the player's bag
 ** Parameters:     none
 ***************************************************************/
int Player::hydrogenCount()
{
    return playerBag.hydrogenCount();
}


/***************************************************************
 ** Function:       hasWater
 ** Description:    indicator for whether the player has the
 **                 ingredients needed to make water
 ** Parameters:     none
 ***************************************************************/
bool Player::hasWater()
{
    if (playerBag.hydrogenCount() >= 2 && playerBag.oxygenCount() >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
