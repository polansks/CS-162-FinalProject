/****************************************************************
 ** File Name:      TableSpace.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the Table spaces on the board
 ****************************************************************/

#include "TableSpace.hpp"

/***************************************************************
 ** Function:       TableSpace (constructor)
 ** Description:    Creates a table space
 ** Parameters:     none
 ***************************************************************/
TableSpace::TableSpace() : Space()
{
    type = "Table";
    return;
}


/***************************************************************
 ** Function:       TableSpace (constructor)
 ** Description:    Creates a table space
 ** Parameters:     indicator for "grading mode"
 ***************************************************************/
TableSpace::TableSpace(bool gradeMode) : Space(gradeMode)
{
    type = "Table";
    return;
}


/***************************************************************
 ** Function:       TableSpace
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
TableSpace::~TableSpace()
{
    return;
}

/***************************************************************
 ** Function:       copy
 ** Description:    creates a copy of the space and returns a
 **                 pointer to the new one
 ** Parameters:     none
 ***************************************************************/
Space* TableSpace::copy() const
{
    return new TableSpace(*this);
}


/***************************************************************
 ** Function:       print
 ** Description:    prints the space
 ** Parameters:     none
 ***************************************************************/
void TableSpace::print()
{
    if (gradingMode || visited)
    {
        std::cout << "T";
    }
    else
    {
        std::cout << " ";
    }
    return;
}

