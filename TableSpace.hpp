/****************************************************************
 ** File Name:      TableSpace.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the Table spaces on the board
 ****************************************************************/

#ifndef TableSpace_hpp
#define TableSpace_hpp

#include <stdio.h>
#include <iostream>
#include "Space.hpp"

class TableSpace : public Space
{
private:
    
public:
    TableSpace();
    TableSpace(bool);
    ~TableSpace();
    virtual Space* copy() const;
    virtual void print();
    
};
#endif /* TableSpace_hpp */
