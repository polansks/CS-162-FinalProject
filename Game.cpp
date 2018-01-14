/****************************************************************
 ** File Name:      Game.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    A class for the game
 ****************************************************************/

#include "Game.hpp"


/***************************************************************
 ** Function:       Game
 ** Description:    constructor
 ** Parameters:     none
 ***************************************************************/
Game::Game()
{
    gradingMode = false;
    
    // Create the board and player
    theBoard = Board(boardWidth, boardHeight, gradingMode);
    thePlayer = Player();
    
    
    // Set the player's initial position on the board to a random
    // empty space (one that also doesn't have an item)
    int xCoord, yCoord;
    bool isTypeEmpty, noItems;
    do
    {
        xCoord = randBetween(0, boardWidth - 1);
        yCoord = randBetween(0, boardHeight - 1);
        
        Space *s = theBoard.getSpace(xCoord, yCoord);
        isTypeEmpty = (s->getType() == "Empty");
        noItems = (s->getItem() == nullptr);
        
    } while (!isTypeEmpty || !noItems);
    
    Space* initialSpace = theBoard.getSpace(xCoord, yCoord);
    thePlayer.setCurrentSpace(initialSpace);
    initialSpace->visit();
    
    
    //Set the player attribute on the board
    theBoard.setPlayer(&thePlayer);
    
    
    // Create the menu that will ask the user what moves they want to make
    moveMenu.addOption("Up");
    moveMenu.addOption("Down");
    moveMenu.addOption("Left");
    moveMenu.addOption("Right");
    
    continueGame = true;
    return;
}


/***************************************************************
 ** Function:       Game
 ** Description:    constructor
 ** Parameters:     indicator for "grading mode"
 ***************************************************************/
Game::Game(bool gradingMode)
{
    
    // Create the board and player
    theBoard = Board(boardWidth, boardHeight, gradingMode);
    thePlayer = Player();
    
    
    // Set the player's initial position on the board to a random
    // empty space (one that also doesn't have an item)
    int xCoord, yCoord;
    bool isTypeEmpty, noItems;
    do
    {
        xCoord = randBetween(0, boardWidth - 1);
        yCoord = randBetween(0, boardHeight - 1);
        
        Space *s = theBoard.getSpace(xCoord, yCoord);
        isTypeEmpty = (s->getType() == "Empty");
        noItems = (s->getItem() == nullptr);
        
    } while (!isTypeEmpty || !noItems);
    
    Space* initialSpace = theBoard.getSpace(xCoord, yCoord);
    thePlayer.setCurrentSpace(initialSpace);
    initialSpace->visit();
    
    
    //Set the player attribute on the board
    theBoard.setPlayer(&thePlayer);
    
    
    // Create the menu that will ask the user what moves they want to make
    moveMenu.addOption("Up");
    moveMenu.addOption("Down");
    moveMenu.addOption("Left");
    moveMenu.addOption("Right");
    
    this->gradingMode = gradingMode;
    continueGame = true;
    return;
}


/***************************************************************
 ** Function:       ~Game
 ** Description:    destructor
 ** Parameters:     none
 ***************************************************************/
Game::~Game()
{
    return;
}


/***************************************************************
 ** Function:       playGame
 ** Description:    plays the game until it ends
 ** Parameters:     none
 ***************************************************************/
void Game::playGame()
{
    displayIntro();
    
    Menu startMenu;
    startMenu.addOption("Yes, let's play!");
    startMenu.addOption("No, this sounds intense. I'd like to quit.");
    startMenu.print();
    
    int userSelection = startMenu.receiveUserSelection();
    if (userSelection == 1)
    {
        continueGame = false;
    }
    
    int result = -1;
    while (continueGame)
    {
        result = playRound();
    }
    
    if (result == 1)
    {
        std::cout << "\n\nCongratulations, you won!" << std::endl;
    }
    else if (result == 0)
    {
        std::cout << "\n\nWe are sorry but you have gone permanently blind due to" << std::endl;
        std::cout << "the labratory accident." << std::endl;
    }
    
    std::cout << "\n\nThe game is now over and we hope you will play again!" << std::endl;
    std::cout << "Goodbye." << std::endl;
    return;
}


/***************************************************************
 ** Function:       playRound
 ** Description:    plays a single round of the game
 ** Parameters:     none
 ***************************************************************/
int Game::playRound()
{
    // Show current health
    std::cout << "\n\n\n*******************************************************" << std::endl;
    std::cout << "You have " << thePlayer.getHealth() << " turns left." << std::endl;
    std::cout << "You currently have " << thePlayer.hydrogenCount();
    if (thePlayer.hydrogenCount() == 1)
    {
        std::cout << " Hydrogen";
    }
    else
    {
        std::cout << " Hydrogens";
    }
    std::cout << " and " << thePlayer.oxygenCount();
    if (thePlayer.oxygenCount() == 1)
    {
        std::cout << " Oxygen";
    }
    else
    {
        std::cout << " Oxygens";
    }
    std::cout << "\n*******************************************************" << std::endl;
    std::cout << std::endl;
    
    // Show the board
    theBoard.print();
    
    // Ask the user where they want to move
    std::cout << "Which direction would you like to move?" << std::endl;
    int userSelection;
    moveMenu.print();
    userSelection = moveMenu.receiveUserSelection();
    
    Space* nextSpace = thePlayer.getSpace(static_cast<DIRECTION> (userSelection));

    bool firstVisit = false;
    if (nextSpace != nullptr && nextSpace->getType() != "Table" && nextSpace->isVisited() == false)
    {
        firstVisit = true;
    }
    thePlayer.move(static_cast<DIRECTION> (userSelection));
    
    if (thePlayer.getCurrentSpace()->getType() == "Shower")
    {
        std::cout << "\n*********************************************************************" << std::endl;
        std::cout << "You found the emergency shower! You are saved and will not go blind!" << std::endl;
        std::cout << "*********************************************************************" << std::endl;
        std::cout << "(Press [Enter] to continue.)" << std::endl;
        char c = cin.get();
        continueGame = false;
    }
    else if (thePlayer.getCurrentSpace()->getType() == "Phone")
    {
        if (thePlayer.getHealth() >= TIME_FOR_RESCUE)
        {
            std::cout << "\n*********************************************************************" << std::endl;
            std::cout << "You found the phone and were able to call in time to be saved!" << std::endl;
            std::cout << "You will not go blind!" << std::endl;
            std::cout << "*********************************************************************" << std::endl;
            std::cout << "(Press [Enter] to continue.)" << std::endl;
            char c = cin.get();
            continueGame = false;
            return 1;
        }
        else
        {
            std::cout << "\n*********************************************************************" << std::endl;
            std::cout << "You found the phone, but unfortunately help will not arrive in time" << std::endl;
            std::cout << "to save you.  Keep looking for Hydrogen and Oxygen!" << std::endl;
            std::cout << "*********************************************************************" << std::endl;
            std::cout << "(Press [Enter] to continue.)" << std::endl;
            char c = cin.get();
        }
    }
    else if (thePlayer.getCurrentSpace()->getItem() != nullptr && firstVisit)
    {
        Item* theItem = thePlayer.getCurrentSpace()->getItem();
        
        std::cout << "\n*********************************************************************" << std::endl;
        std::cout << "The space you just moved to has 1 " << theItem->getType() << "!" << std::endl;
        
        if (thePlayer.addToBag(theItem) == false)
        {
            std::cout << "You already have enough, so you will leave it behind" << std::endl;
        }
        
        std::cout << "*********************************************************************" << std::endl;
        std::cout << "(Press [Enter] to continue.)" << std::endl;
        char c = cin.get();
        
        
        
        if (thePlayer.hasWater())
        {
            std::cout << "\n*********************************************************************" << std::endl;
            std::cout << "You have found the all the ingredients you need to make water!" << std::endl;
            std::cout << "You can wash your eyes will not go blind!" << std::endl;
            std::cout << "*********************************************************************" << std::endl;
            std::cout << "(Press [Enter] to continue.)" << std::endl;
            char c = cin.get();
            
            continueGame = false;
            return 1;
        }
    }
    
    if (thePlayer.getHealth() == 0)
    {
        std::cout << "\n*********************************************************************" << std::endl;
        std::cout << "You have run out of time.  You have gone blind." << std::endl;
        std::cout << "GAME OVER." << std::endl;
        std::cout << "*********************************************************************" << std::endl;
        std::cout << "(Press [Enter] to continue.)" << std::endl;
        char c = cin.get();
        continueGame = false;
        return 0;
    }
    
    return 0;
}


/***************************************************************
 ** Function:       displayIntro
 ** Description:    displays the introduction for the game
 ** Parameters:     none
 ***************************************************************/
void Game::displayIntro()
{
    std::cout << "*********************************************************************" << std::endl;
    std::cout << "**                  Labratory Accident Game                        **" << std::endl;
    std::cout << "**                             By                                  **" << std::endl;
    std::cout << "**                       Scott Polansky                            **" << std::endl;
    std::cout << "*********************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "You are a chemist working in your lab and you've had a horrible" << std::endl;
    std::cout << "accident! You spilled acid in your eyes and you cannot see." << std::endl;
    std::cout << "You must move around the lab to try and wash the acid out of" << std::endl;
    std::cout << "your eyes before the damage is irreversible and you are" << std::endl;
    std::cout << "permanently blind. There are several ways to save yourself " << std::endl;
    std::cout << "and win:" << std::endl;
    std::cout << "\n1. As you move around the lab, you can pick up beakers of" << std::endl;
    std::cout << "   Hydrogen and Oxygen.  If you pick up two Hydrogens and one" << std::endl;
    std::cout << "   Oxygen, you can make water and wash your eyes out." << std::endl;
    std::cout << "\n2. You can find the emergency shower somewhere along one of" << std::endl;
    std::cout << "   the walls of the lab and wash your eyes out." << std::endl;
    std::cout << "\n3. You can find your phone which fell somewhere on the floor" << std::endl;
    std::cout << "   during the accident and call for help. Unfortunately, it will" << std::endl;
    std::cout << "   take time for help to arrive.  If you have less than " << TIME_FOR_RESCUE << " turns left," << std::endl;
    std::cout << "   help will not arrive in time so you will have to continue looking" << std::endl;
    std::cout << "   for Hydrogen and Oxygen or the shower. If you have least" << std::endl;
    std::cout << "   " << TIME_FOR_RESCUE << " turns left when you find your phone then you will be saved!" << std::endl;
    std::cout << "\nBecause you are currently blinded by the acid in your eyes, you" << std::endl;
    std::cout << "cannot see what is in the lab.  You will not know what is in each" << std::endl;
    std::cout << "space on the board until you go to that space. There are a few lab" << std::endl;
    std::cout << "tables spread throughout the lab which may get in your way. You" << std::endl;
    std::cout << "cannot move to a space with a table and if you try to do so, you" << std::endl;
    std::cout << "will not move, but you will still have used a turn.  You have " << std::endl;
    std::cout << thePlayer.getHealth() << " total turns to try and save your sight." << std::endl;
    std::cout << "\n\nAre you ready to play?" << std:: endl;
    
    return;
}
