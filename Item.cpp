/****************************************************************
 ** File Name:      Item.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    Classes for the different items
 ****************************************************************/

#include "Item.hpp"


/***************************************************************
 ** Function:       Item
 ** Description:    constructor
 ** Parameters:     none
 ***************************************************************/
Item::Item()
{
    return;
}


/***************************************************************
 ** Function:       Item
 ** Description:    copy constructor
 ** Parameters:     none
 ***************************************************************/
Item::Item(const Item &i)
{
    type = i.type;
    return;
}


/***************************************************************
 ** Function:       assignment operator for Item
 ** Description:    assignment operator
 ** Parameters:     none
 ***************************************************************/
Item& Item::operator=(const Item &i)
{
    type = i.type;
    return *this;
}


/***************************************************************
 ** Function:       ~Item
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
Item::~Item()
{
    return;
}


/***************************************************************
 ** Function:       Oxygen
 ** Description:    constructor
 ** Parameters:     none
 ***************************************************************/
Oxygen::Oxygen()
{
    type = "Oxygen";
    return;
}


/***************************************************************
 ** Function:       ~Oxygen
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
Oxygen::~Oxygen()
{
    return;
}


/***************************************************************
 ** Function:       getType
 ** Description:    returns the type of item
 ** Parameters:     none
 ***************************************************************/
string Oxygen::getType()
{
    return type;
}

/***************************************************************
 ** Function:       copy
 ** Description:    copies the item and returns a pointer to it
 ** Parameters:     none
 ***************************************************************/
Item* Oxygen::copy() const
{
    return new Oxygen(*this);
}


/***************************************************************
 ** Function:       Hydrogen
 ** Description:    constructor
 ** Parameters:     none
 ***************************************************************/
Hydrogen::Hydrogen()
{
    type = "Hydrogen";
    return;
}

/***************************************************************
 ** Function:       ~Hyrdogen
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
Hydrogen::~Hydrogen()
{
    return;
}


/***************************************************************
 ** Function:       getType
 ** Description:    returns the type of the item
 ** Parameters:     none
 ***************************************************************/
string Hydrogen::getType()
{
    return type;
}


/***************************************************************
 ** Function:       copoy
 ** Description:    copies the item and returns a pointer to it
 ** Parameters:     none
 ***************************************************************/
Item* Hydrogen::copy() const
{
    return new Hydrogen(*this);
}
