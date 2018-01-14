/****************************************************************
 ** File Name:      PhoneSpace.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the Phone space on the board
 ****************************************************************/

#include "PhoneSpace.hpp"


/***************************************************************
 ** Function:       PhoneSpace (constructor)
 ** Description:    Creates a phone space
 ** Parameters:     none
 ***************************************************************/
PhoneSpace::PhoneSpace() : Space()
{
    type = "Phone";
    return;
}


/***************************************************************
 ** Function:       PhoneSpace (constructor)
 ** Description:    Creates a phone space
 ** Parameters:     indicator for "grading mode"
 ***************************************************************/
PhoneSpace::PhoneSpace(bool gradeMode) : Space(gradeMode)
{
    type = "Phone";
    return;
}


/***************************************************************
 ** Function:       ~PhoneSpace
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
PhoneSpace::~PhoneSpace()
{
    return;
}


/***************************************************************
 ** Function:       copy
 ** Description:    copies the space and returns a pointer to the
 **                 copy
 ** Parameters:     none
 ***************************************************************/
Space* PhoneSpace::copy() const
{
    return new PhoneSpace(*this);
}


/***************************************************************
 ** Function:       print
 ** Description:    prints the space
 ** Parameters:     none
 ***************************************************************/
void PhoneSpace::print()
{
    if (visited)
    {
        std::cout << "~";
    }
    else if (gradingMode)
    {
        std::cout << "P";
    }
    else
    {
        std::cout << " ";
    }
    
    return;
}
