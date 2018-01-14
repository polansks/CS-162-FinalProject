/****************************************************************
 ** File Name:      ShowerSpace.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the Shower space on the board
 ****************************************************************/

#ifndef ShowerSpace_hpp
#define ShowerSpace_hpp

#include <stdio.h>
#include <iostream>
#include "Space.hpp"

class ShowerSpace : public Space
{
private:
    
public:
    ShowerSpace();
    ShowerSpace(bool);
    ~ShowerSpace();
    virtual Space* copy() const;
    virtual void print();
    
};
#endif /* ShowerSpace_hpp */
