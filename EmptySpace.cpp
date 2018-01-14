/****************************************************************
 ** File Name:      EmptySpace.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the empty spaces on the board
 ****************************************************************/

#include "EmptySpace.hpp"


/***************************************************************
 ** Function:       EmptySpace (constructor)
 ** Description:    Creates an empty space
 ** Parameters:     none
 ***************************************************************/
EmptySpace::EmptySpace() : Space()
{
    type = "Empty";
    return;
}


/***************************************************************
 ** Function:       EmptySpace (constructor)
 ** Description:    Creates an empty space
 ** Parameters:     indicator for "grading mode"
 ***************************************************************/
EmptySpace::EmptySpace(bool gradeMode) : Space(gradeMode)
{
    type = "Empty";
    return;
}


/***************************************************************
 ** Function:       ~EmptySpace
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
EmptySpace::~EmptySpace()
{
    return;
}


/***************************************************************
 ** Function:       copy
 ** Description:    creates a copy of the space and returns a
 **                 pointer to the new copy
 ** Parameters:     none
 ***************************************************************/
Space* EmptySpace::copy() const
{
    return new EmptySpace(*this);
}


/***************************************************************
 ** Function:       print
 ** Description:    prints the space
 ** Parameters:     none
 ***************************************************************/
void EmptySpace::print()
{
    if (visited)
    {
        std::cout << "~";
    }
    else
    {
        std::cout << " ";
    }
    
    return;
}
