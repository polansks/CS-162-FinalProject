/****************************************************************
 ** File Name:      Board.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    Board object that represents the board that
 **                 the game takes place on
 ****************************************************************/

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "Space.hpp"
#include "ShowerSpace.hpp"
#include "PhoneSpace.hpp"
#include "TableSpace.hpp"
#include "EmptySpace.hpp"
#include "Player.hpp"
#include "functions.hpp"

class Board
{
private:
    int height;
    int width;
    Space*** myBoard;
    bool validCoordinates(int, int);
    void createTables();
    void createShower();
    void createPhone();
    void createItems();
    void setNeighborSpaces();
    Player* player;
    bool gradingMode;
    
    const int DEFAULT_HEIGHT = 10;
    const int DEFAULT_WIDTH = 10;
    const int MIN_HEIGHT = 10;
    const int MIN_WIDTH = 10;
    const int NUM_TABLES = 3;
    const int NUM_OXYGENS = 10;
    const int NUM_HYDROGENS = 8;
    
    
public:
    Board();
    Board(int width, int height, bool gradeMode);
    Board(const Board&);
    Board& operator=(const Board&);
    ~Board();
    int getHeight();
    int getWidth();
    void print(int xCoord, int yCoord);
    void print();
    Space* getSpace(int xCoord, int yCoord);
    void setPlayer(Player *);
    void printNeighbors();
};
#endif
