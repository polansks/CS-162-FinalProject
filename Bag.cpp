/****************************************************************
 ** File Name:      Bag.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for a container to hold the items the
 **                 player picks up
 ****************************************************************/

#include "Bag.hpp"

/***************************************************************
 ** Function:       Bag
 ** Description:    constructor
 ** Parameters:     none
 ***************************************************************/
Bag::Bag()
{
    return;
}


/***************************************************************
 ** Function:       ~Bag
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
Bag::~Bag()
{
    for (int i = 0; i < theBag.size(); i++)
    {
        delete theBag[i];
        theBag[i] = nullptr;
    }
    
    return;
}


/***************************************************************
 ** Function:       push
 ** Description:    adds an item to the bag if there is room
 ** Parameters:     pointer to the item
 ***************************************************************/
bool Bag::push(Item *i)
{
    if (i->getType() == "Oxygen" && oxygenCount() < MAX_OXYGEN)
    {
        theBag.push_back(new Oxygen);
        return true;
    }
    else if (i->getType() == "Hydrogen" && hydrogenCount() < MAX_HYDROGEN)
    {
        theBag.push_back(new Hydrogen);
        return true;
    }
    return false;
}

/***************************************************************
 ** Function:       oxygenCount
 ** Description:    returns number of oxygens in the bag
 ** Parameters:     none
 ***************************************************************/
int Bag::oxygenCount()
{
    int count = 0;
    for (int i = 0; i < theBag.size(); i++)
    {
        if (theBag[i]->getType() == "Oxygen")
        {
            count++;
        }
    }
    
    return count;
}


/***************************************************************
 ** Function:       hydrogenCount
 ** Description:    returns the number of hydrogens in the bag
 ** Parameters:     none
 ***************************************************************/
int Bag::hydrogenCount()
{
    int count = 0;
    for (int i = 0; i < theBag.size(); i++)
    {
        if (theBag[i]->getType() == "Hydrogen")
        {
            count++;
        }
    }
    
    return count;
}
