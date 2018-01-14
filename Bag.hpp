/****************************************************************
 ** File Name:      Bag.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for a container to hold the items the
 **                 player picks up
 ****************************************************************/

#ifndef Bag_hpp
#define Bag_hpp

#include <stdio.h>
#include <vector>
#include "Item.hpp"

using std::vector;

class Bag
{
private:
    vector<Item*> theBag;
    const int MAX_OXYGEN = 1;
    const int MAX_HYDROGEN = 2;

public:
    Bag();
    ~Bag();
    bool push(Item *);
    void pop();
    int oxygenCount();
    int hydrogenCount();
};
#endif
