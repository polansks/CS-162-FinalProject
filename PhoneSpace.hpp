/****************************************************************
 ** File Name:      PhoneSpace.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the Phone space on the board
 ****************************************************************/

#ifndef PhoneSpace_hpp
#define PhoneSpace_hpp

#include <stdio.h>
#include <iostream>
#include "Space.hpp"

class PhoneSpace : public Space
{
private:
    
public:
    PhoneSpace();
    PhoneSpace(bool);
    ~PhoneSpace();
    virtual Space* copy() const;
    virtual void print();
    
};
#endif /* PhoneSpace_hpp */
