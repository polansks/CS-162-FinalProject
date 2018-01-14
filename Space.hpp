/****************************************************************
 ** File Name:      Space.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    An abstract class for the spaces on a Board
 ****************************************************************/

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include <string>
#include "direction.h"
#include "Item.hpp"

using std::string;

class Space
{
protected:
    bool visited;
    string type;
    Space* top;
    Space* bottom;
    Space* left;
    Space* right;
    Item* item;
    bool gradingMode;
    
public:
    Space();
    Space(bool);
    Space(const Space&);
    Space& operator=(const Space&);
    virtual Space* copy() const = 0;
    virtual ~Space();
    virtual void print() = 0;
    virtual void visit();
    bool isVisited();
    void setNeighbor(Space*, DIRECTION);
    Space* getNeighbor(DIRECTION);
    string getType();
    void setItem(Item*);
    Item* getItem();
    Space* getTop() {return top;}
    Space* getBottom() {return bottom;}
    Space* getLeft() {return left;}
    Space* getRight() {return right;}
};

#endif /* Space_hpp */
