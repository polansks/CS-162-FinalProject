/****************************************************************
 ** File Name:      ShowerSpace.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the Shower space on the board
 ****************************************************************/

#include "ShowerSpace.hpp"


/***************************************************************
 ** Function:       ShowerSpace (constructor)
 ** Description:    Creates a shower space
 ** Parameters:     none
 ***************************************************************/
ShowerSpace::ShowerSpace() : Space()
{
    type = "Shower";
    return;
}


/***************************************************************
 ** Function:       ShowerSpace (constructor)
 ** Description:    Creates a shower space
 ** Parameters:     indicator for "grading mode"
 ***************************************************************/
ShowerSpace::ShowerSpace(bool gradeMode) : Space(gradeMode)
{
    type = "Shower";
    return;
}


/***************************************************************
 ** Function:       ~ShowerSpace
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
ShowerSpace::~ShowerSpace()
{
    return;
}


/***************************************************************
 ** Function:       copy
 ** Description:    copies the space and returns a pointer to
 **                 the new one
 ** Parameters:     none
 ***************************************************************/
Space* ShowerSpace::copy() const
{
    return new ShowerSpace(*this);
}

/***************************************************************
 ** Function:       print
 ** Description:    prints the space
 ** Parameters:     none
 ***************************************************************/
void ShowerSpace::print()
{
    if (visited)
    {
        std::cout << "~";
    }
    else if (gradingMode)
    {
        std::cout << "S";
    }
    else
    {
        std::cout << " ";
    }
    return;
}

