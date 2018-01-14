/****************************************************************
 ** File Name:      functions.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A random function
 ****************************************************************/

#include "functions.hpp"

/***************************************************************
 ** Function:       randBetween
 ** Description:    generates a random number within a given
 **                 range
 ** Parameters:     the highest and lowest desired possible values
 ***************************************************************/
int randBetween(int lo, int hi)
{
    // Make sure lo <= hi and swap if not
    if (lo > hi)
    {
        int temp = hi;
        hi = lo;
        lo = temp;
    }
    
    int numPossibilities = hi - lo + 1;
    return rand() % numPossibilities + lo;
}
