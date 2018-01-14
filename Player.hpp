/****************************************************************
 ** File Name:      Player.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the player in the game
 ****************************************************************/

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Item.hpp"
#include "Bag.hpp"
#include "direction.h"

using std::string;

class Player
{
private:
    string name;
    Space* currentSpace;
    int health;
    const int STARTING_HEALTH = 25;
    Bag playerBag;
    
public:
    Player();
    Player(string, Space*);
    Player(const Player &);
    Player& operator=(const Player&);
    ~Player();
    string getName();
    void setName(string);
    Space* getCurrentSpace();
    Space* getSpace(DIRECTION);
    void setCurrentSpace(Space*);
    int getHealth();
    void move(DIRECTION);
    bool addToBag(Item *);
    int oxygenCount();
    int hydrogenCount();
    bool hasWater();
    
};
#endif /* Player_hpp */
