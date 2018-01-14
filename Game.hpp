/****************************************************************
 ** File Name:      Game.hpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the game
 ****************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <string>
#include "Player.hpp"
#include "Board.hpp"
#include "Menu.hpp"
#include "direction.h"

using std::string;

class Game
{
private:
    Player thePlayer;
    Board theBoard;
    Menu moveMenu;
    bool continueGame;
    int playRound();
    const int boardWidth = 10;
    const int boardHeight = 10;
    const int TIME_FOR_RESCUE = 5;
    bool gradingMode;
    
public:
    Game();
    Game(bool);
    ~Game();
    void playGame();
    void displayIntro();

};
#endif /* Game_hpp */
