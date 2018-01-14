/****************************************************************
 ** File Name:      Space.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    An abstract class for the spaces on a Board
 ****************************************************************/

#include "Space.hpp"


/***************************************************************
 ** Function:       Space (constructor)
 ** Description:    Creates an empty space
 ** Parameters:     none
 ***************************************************************/
Space::Space()
{
    visited = false;
    top = bottom = left = right = nullptr;
    item = nullptr;
    gradingMode = false;
    return;
}


/***************************************************************
 ** Function:       Space (constructor)
 ** Description:    Creates an empty space with a specified
 *8                 "grading mode"
 ** Parameters:     grading mode
 ***************************************************************/
Space::Space(bool gradingMode)
{
    visited = false;
    top = bottom = left = right = nullptr;
    item = nullptr;
    this->gradingMode = gradingMode;
    return;
}


/***************************************************************
 ** Function:       Space (copy constructor)
 ** Description:    copy constructor
 ** Parameters:     a space
 ***************************************************************/
Space::Space(const Space &s)
{
    visited = s.visited;
    type = s.type;
    top = s.top;
    bottom = s.bottom;
    left = s.left;
    right = s.right;
    gradingMode = s.gradingMode;
    
    if (s.item != nullptr)
    {
        item = s.item->copy();
    }
    else
    {
        item = nullptr;
    }
    return;
}

/***************************************************************
 ** Function:       assignment operator
 ** Description:    assignment operator
 ** Parameters:     a space
 ***************************************************************/
Space& Space::operator=(const Space &s)
{
    visited = s.visited;
    type = s.type;
    top = s.top;
    bottom = s.bottom;
    left = s.left;
    right = s.right;
    gradingMode = s.gradingMode;
    
    if (s.item != nullptr)
    {
        item = s.item->copy();
    }
    else
    {
        item = nullptr;
    }
    return *this;
}


/***************************************************************
 ** Function:       ~Space
 ** Description:    Destructor
 ** Parameters:     none
 ***************************************************************/
Space::~Space()
{
    delete item;
    return;
}


/***************************************************************
 ** Function:       visit
 ** Description:    updates the visit member variable to TRUE
 ** Parameters:     none
 ***************************************************************/
void Space::visit()
{
    visited = true;
    return;
}


/***************************************************************
 ** Function:       getType
 ** Description:    returns the type of space
 ** Parameters:     none
 ***************************************************************/
string Space::getType()
{
    return type;
}


/***************************************************************
 ** Function:       setNeighbor
 ** Description:    sets one of the neighbor spaces for this space
 ** Parameters:     pointer to the neighboring space, and
 **                 a direction corresponding to the pointer to
 **                 update
 ***************************************************************/
void Space::setNeighbor(Space *s, DIRECTION direction)
{
    switch (direction)
    {
        case TOP:
            top = s;
            break;
            
        case BOTTOM:
            bottom = s;
            break;
            
        case LEFT:
            left = s;
            break;
            
        case RIGHT:
            right = s;
    }
    
    return;
}


/***************************************************************
 ** Function:       getNeighbor
 ** Description:    returns a pointer to one of the neighbor
 **                 spaces
 ** Parameters:     a direction corresponding to the neighbor
 **                 space of interest
 ***************************************************************/
Space* Space::getNeighbor(DIRECTION d)
{
    switch (d)
    {
        case TOP:
            return top;
            break;
            
        case BOTTOM:
            return bottom;
            break;
            
        case LEFT:
            return left;
            break;
            
        case RIGHT:
            return right;
            break;
    }
    
    return nullptr;
}


/***************************************************************
 ** Function:       setItem
 ** Description:    sets the item pointer for a space
 ** Parameters:     pointer to an item
 ***************************************************************/
void Space::setItem(Item *i)
{
    item = i;
    return;
}


/***************************************************************
 ** Function:       getItem
 ** Description:    returns a pointer to the item in the space
 ** Parameters:     none
 ***************************************************************/
Item* Space::getItem()
{
    return item;
}


/***************************************************************
 ** Function:       isVisited
 ** Description:    indicates whether the space has been visited
 **                 yet
 ** Parameters:     none
 ***************************************************************/
bool Space::isVisited()
{
    return visited;
}
