/****************************************************************
 ** File Name:      EmptySpace.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the empty spaces on the board
 ****************************************************************/

#ifndef EmptySpace_hpp
#define EmptySpace_hpp

#include <stdio.h>
#include <iostream>
#include "Space.hpp"

class EmptySpace : public Space
{
private:
    
public:
    EmptySpace();
    EmptySpace(bool);
    ~EmptySpace();
    virtual Space* copy() const;
    virtual void print();
};

#endif /* EmptySpace_hpp */
