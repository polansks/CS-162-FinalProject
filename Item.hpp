/****************************************************************
 ** File Name:      Item.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    Classes for the different items
 ****************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>

using std::string;

class Item
{
protected:
    string type;

public:
    Item();
    Item(const Item&);
    Item& operator=(const Item&);
    virtual ~Item();
    virtual string getType() = 0;
    virtual Item* copy() const = 0;
};

class Oxygen : public Item
{
private:
    
public:
    Oxygen();
    ~Oxygen();
    virtual string getType();
    virtual Item* copy() const;
};

class Hydrogen : public Item
{
private:
    
public:
    Hydrogen();
    ~Hydrogen();
    virtual string getType();
    virtual Item* copy() const;
};
#endif
