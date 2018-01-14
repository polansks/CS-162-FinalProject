/****************************************************************
 ** File Name:      main.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    The main function for the program
 ****************************************************************/

#include <iostream>
#include "Board.hpp"
#include "Game.hpp"

int main(int argc, const char * argv[])
{
    // Notify the user if they entered an invalid number of arguments
    if (argc != 1 && argc != 2)
    {
        std::cout << "\nInvalid usage. Please enter at most 1 argument.\n\n" << std::endl;
        return 0;
    }
    
    // Notify the user if the user entered an invalid argument
    if (argc == 2 && !(atoi(argv[1]) == 0 || atoi(argv[1]) == 1))
    {
        std::cout << "\nInvalid usage. Please enter an argument of 0 or 1 (or no arguments)" << std::endl;
        std::cout << "0 = Normal game play. Spaces are hidden until they have been visited." << std::endl;
        std::cout << "1 = Grading game play. Special spaces are visible to make grading easier.\n\n" << std::endl;
        
        return 0;
    }
    
    // Play in "grading mode" if the user entered an argument of 1
    // Grading mode shows all table, phone and shower spaces so that their location
    // is known making it easier to test their functionality
    if (argc == 2 && atoi(argv[1]) == 1)
    {
        std::cout << "\n\nThe game will be in GRADING MODE. Tables, Shower and Phone" << std::endl;
        std::cout << "will be visible the entire game to aid in grading." << std::endl;
        std::cout << "\n\nPress [Enter] to continue." << std::endl;
        char c = cin.get();
        
        Game g(atoi(argv[1]));
        g.playGame();
    }
    // Play in normal mode. The contents of the spaces are hidden until the user
    // moves to the space
    else
    {
        Game g;
        g.playGame();
    }
    
    return 0;
}
