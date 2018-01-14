/****************************************************************
 ** File Name:      Board.cpp
 ** Author:         Scott Polansky
 ** Date:           Dec 5, 2017
 ** Description:    Board object that represents the board that
 **                 the game takes place on
 ****************************************************************/

#include <iostream>
#include "Board.hpp"

/***************************************************************
 ** Function:       Board (constructor)
 ** Description:    Creates a 10x10 board with all white spaces
 ** Parameters:     none
 ***************************************************************/
Board::Board()
{
    // Create an empty board
    height = 0;
    width = 0;
    myBoard = nullptr;
    player = nullptr;
    gradingMode = false;
    return;
}

/***************************************************************
 ** Function:       Board (constructor)
 ** Description:    Creates a custom sized board with all white spaces
 ** Parameters:     height and width
 ***************************************************************/
Board::Board(int widthIn, int heightIn, bool gradeMode)
{
    gradingMode = gradeMode;
    
    // Set the dimensions
    if (heightIn < MIN_HEIGHT)
    {
        height = MIN_HEIGHT;
    }
    else
    {
        height = heightIn;
    }
    
    if (widthIn < MIN_WIDTH)
    {
        width = MIN_WIDTH;
    }
    else
    {
        width = widthIn;
    }
        
    // Create a 2D array of pointers to a Space
    myBoard = new Space**[width];
    for (int i = 0; i < width; i++)
    {
        myBoard[i] = new Space*[height];
    }
    
    // Set the array elements of myBoard to nullptr
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            myBoard[x][y] = nullptr;
        }
    }
    
    // Decide where the tables are going to go and create them
    createTables();
    
    // Choose a random spot for the shower space
    createShower();
    
    // Choose a random spot for the phone space
    createPhone();
    
    // Fill all other spaces with empty spaces
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if (myBoard[x][y] == nullptr)
            {
                myBoard[x][y] = new EmptySpace(gradingMode);
            }
        }
    }
    
    setNeighborSpaces();

    createItems();
    
    player = nullptr;
    return;
}

/***************************************************************
 ** Function:       Board (copy constructor)
 ** Description:    Creates a 10x10 board with all white spaces
 ** Parameters:     none
 ***************************************************************/
Board::Board(const Board& b)
{
    height = b.height;
    width = b.width;
    
    // Create a 2D array of pointers to a Space
    myBoard = new Space**[width];
    for (int i = 0; i < width; i++)
    {
        myBoard[i] = new Space*[height];
    }
    
    // Set the array elements of myBoard to the spaces
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            Space *temp = b.myBoard[x][y];
            myBoard[x][y] = &(*temp);
        }
    }
    setNeighborSpaces();
    player = b.player;
    gradingMode = b.gradingMode;
    
    return;
}

/***************************************************************
 ** Function:       Board (assignment operator)
 ** Description:    Creates a 10x10 board with all white spaces
 ** Parameters:     none
 ***************************************************************/
Board& Board::operator=(const Board& b)
{
    if (this != &b)
    {
        // Delete the memory in <this>
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                delete myBoard[x][y];
                myBoard[x][y] = nullptr;
            }
            delete [] myBoard[x];
            myBoard[x] = nullptr;
        }
        delete [] myBoard;
        myBoard = nullptr;
        
        
        // Copy over new elements from <b>
        height = b.height;
        width = b.width;
        
        // Create a 2D array of pointers to a Space
        myBoard = new Space**[width];
        for (int i = 0; i < width; i++)
        {
            myBoard[i] = new Space*[height];
        }
        
        // Set the array elements of myBoard to nullptr
        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                
                Space* temp = b.myBoard[x][y]->copy();
                myBoard[x][y] = temp;
            }
        }
        setNeighborSpaces();
        player = b.player;
        gradingMode = b.gradingMode;
    }
    return *this;
}

/***************************************************************
 ** Function:       ~Board (destructor)
 ** Description:    Cleans up dynamically allocated memory
 ** Parameters:     none
 ***************************************************************/
Board::~Board()
{
    // Free up all the allocated memory for the board
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            delete myBoard[x][y];
            myBoard[x][y] = nullptr;
        }
        delete [] myBoard[x];
        myBoard[x] = nullptr;
    }
    delete [] myBoard;
    myBoard = nullptr;
    
    return;
}

/***************************************************************
 ** Function:       getHeight
 ** Description:    Returns the height of the board
 ** Parameters:     none
 ***************************************************************/
int Board::getHeight()
{
    return height;
}

/***************************************************************
 ** Function:       getWidth
 ** Description:    Returns the width of the board
 ** Parameters:     none
 ***************************************************************/
int Board::getWidth()
{
    return width;
}

/***************************************************************
 ** Function:       validCoordinates
 ** Description:    Returns a boolean value indicating whether
 **                 the specified space is on the board. Will
 **                 return TRUE if it is and FALSE if the
 **                 coordinates are outside the bounds of the
 **                 board.
 ** Parameters:     x coordinate and y coordinate
 ***************************************************************/
bool Board::validCoordinates(int xCoord, int yCoord)
{
    if ((xCoord >= 0 && xCoord < width) && (yCoord >= 0 && yCoord < height))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
 ** Function:       print
 ** Description:    Prints the board with a border.
 ** Parameters:     none
 ***************************************************************/
void Board::print()
{
    // Print the top edge
    std::cout << "-";
    for (int i = 0; i < (width); i++)
    {
        std::cout << "---";
    }
    std::cout << "-";
    std::cout << std::endl;
    
    for (int y = 0; y < height; y++)
    {
        std::cout << "|";
        
        for (int x = 0; x < width; x++)
        {
            std::cout << " ";
            if (player->getCurrentSpace() == myBoard[x][y])
            {
                std::cout << "X";
            }
            else
            {
                myBoard[x][y]->print();
            }
            std::cout << " ";
        }
        
        std::cout << "|\n";
    }
    
    // Print the bottom edge
    std::cout << "-";
    for (int i = 0; i < (width); i++)
    {
        std::cout << "---";
    }
    std::cout << "-";
    std::cout << std::endl;
    
    // Print the key
    std::cout << "**Key**" << std::endl;
    std::cout << "T = table" << "\t" << "X = player" << std::endl;
    if (gradingMode)
    {
        std::cout << "S = shower" << "\t" << "P = phone" << std::endl;
    }
    std::cout << "~ = space already visisted" << std::endl;
    std::cout << std::endl;
    return;
}


/***************************************************************
 ** Function:       createTables
 ** Description:    Used by the constructors to create the tables
 **                 on the board
 ** Parameters:     none
 ** Notes:          Could potentially get stuck in an infinite
 **                 loop if there aren't enough spaces available
 **                 to put the tables.
 ***************************************************************/
void Board::createTables()
{
    int tablesCreated = 0;
    while (tablesCreated < NUM_TABLES)
    {
        // Choose the random spot for the middle of the table
        // Pick a non-edge spot to ensure that the ends of the
        // table will fit on the board
        int xCoord = randBetween(1, width - 2);
        int yCoord = randBetween(1, height - 2);
        
        int direction = randBetween(0, 1);
        bool spaceOneFree, spaceTwoFree, spaceThreeFree;
        if (direction == 0) // Table is vertical
        {
            spaceOneFree = (myBoard[xCoord][yCoord] == nullptr);
            spaceTwoFree = (myBoard[xCoord][yCoord - 1] == nullptr);
            spaceThreeFree = (myBoard[xCoord][yCoord + 1] == nullptr);
            
            // If the spots are available, then create the table
            if (spaceOneFree && spaceTwoFree && spaceThreeFree)
            {
                myBoard[xCoord][yCoord] = new TableSpace;
                myBoard[xCoord][yCoord - 1] = new TableSpace;
                myBoard[xCoord][yCoord + 1] = new TableSpace;
                tablesCreated++;
            }
        }
        else // Table is horizontal
        {
            spaceOneFree = (myBoard[xCoord][yCoord] == nullptr);
            spaceTwoFree = (myBoard[xCoord - 1][yCoord] == nullptr);
            spaceThreeFree = (myBoard[xCoord + 1][yCoord] == nullptr);
            
            // If the spots are available, then create the table
            if (spaceOneFree && spaceTwoFree && spaceThreeFree)
            {
                myBoard[xCoord][yCoord] = new TableSpace(gradingMode);
                myBoard[xCoord - 1][yCoord] = new TableSpace(gradingMode);
                myBoard[xCoord + 1][yCoord] = new TableSpace(gradingMode);
                tablesCreated++;
            }
        }
    }
    
    return;
}

/***************************************************************
 ** Function:       createShower
 ** Description:    Used by the constructors to create the shower
 **                 space on the board
 ** Parameters:     none
 ** Notes:          Could potentially get stuck in an infinite
 **                 loop if there isn't a spaces available to
 **                 put the shower.
 ***************************************************************/
void Board::createShower()
{
    int xCoord, yCoord, wall;
    bool showerCreated = false;
    
    while (showerCreated == false)
    {
        // Pick random wall to put the shower on
        wall = randBetween(1,4);
        
        // Now pick a random spot on that wall
        switch (wall)
        {
            case 1: // Top wall
                xCoord = randBetween(0, width - 1);
                yCoord = 0;
                break;
                
            case 2: // Left wall
                xCoord = 0;
                yCoord = randBetween(0, height - 1);
                break;
                
            case 3: // Bottom wall
                xCoord = randBetween(0, width - 1);
                yCoord = height - 1;
                break;
                
            case 4: // Right wall
                xCoord = width - 1;
                yCoord = randBetween(0, height - 1);
                break;

        }
        
        // Check if the space is available
        if (myBoard[xCoord][yCoord] == nullptr)
        {
            myBoard[xCoord][yCoord] = new ShowerSpace(gradingMode);
            showerCreated = true;
        }
    
    }
    
    return;
}



/***************************************************************
 ** Function:       createPhone
 ** Description:    Used by the constructors to create the phone
 **                 space on the board
 ** Parameters:     none
 ** Notes:          Could potentially get stuck in an infinite
 **                 loop if there isn't a spaces available to
 **                 put the phone.
 ***************************************************************/
void Board::createPhone()
{
    int xCoord, yCoord, wall;
    bool phoneCreated = false;
    
    while (phoneCreated == false)
    {
        // Pick random wall to put the shower on
        wall = randBetween(1,4);
        
        // Now pick a random spot on that wall
        switch (wall)
        {
            case 1: // Top wall
                xCoord = randBetween(0, width - 1);
                yCoord = 0;
                break;
                
            case 2: // Left wall
                xCoord = 0;
                yCoord = randBetween(0, height - 1);
                break;
                
            case 3: // Bottom wall
                xCoord = randBetween(0, width - 1);
                yCoord = height - 1;
                break;
                
            case 4: // Right wall
                xCoord = width - 1;
                yCoord = randBetween(0, height - 1);
                break;
        }
        
        // Check if the space is available
        if (myBoard[xCoord][yCoord] == nullptr)
        {
            myBoard[xCoord][yCoord] = new PhoneSpace(gradingMode);
            phoneCreated = true;
        }
        
    }
    
    return;
}


/***************************************************************
 ** Function:       setNeighborSpaces
 ** Description:    Sets the top, bottom, left, right pointers
 **                 for each space
 ** Parameters:     none
 ** Notes:          none
 ***************************************************************/
void Board::setNeighborSpaces()
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            // Loop through for each of the 4 pointers
            // (top, bottom, left, right)
            for (int i = 0; i < 4; i++)
            {
                Space* neighbor;
                switch (i)
                {
                    case TOP:
                    {
                        if (y != 0)
                        {
                            neighbor = myBoard[x][y - 1];
                        }
                        else
                        {
                            neighbor = nullptr;
                        }
                        break;
                    }
                    case BOTTOM:
                    {
                        if (y != (height - 1))
                        {
                            neighbor = myBoard[x][y + 1];
                        }
                        else
                        {
                            neighbor = nullptr;
                        }
                        break;
                    }
                    case LEFT:
                    {
                        if (x != 0)
                        {
                            neighbor = myBoard[x - 1][y];
                        }
                        else
                        {
                            neighbor = nullptr;
                        }
                        break;
                    }
                    case RIGHT:
                    {
                        if (x != (width - 1))
                        {
                            neighbor = myBoard[x + 1][y];
                        }
                        else
                        {
                            neighbor = nullptr;
                        }
                        break;
                    }
                    default:
                        neighbor = nullptr;
                }
                myBoard[x][y]->setNeighbor(neighbor, static_cast<DIRECTION>(i));
            }
        }
    }
    return;
}


/***************************************************************
 ** Function:       createItems
 ** Description:    Creates the Oxygen and Hydrogen items and
 **                 puts assigns them to a space
 ** Parameters:     none
 ** Notes:          Could potentially get stuck in an infinite
 **                 loop if there aren't empty spaces available
 ***************************************************************/
void Board::createItems()
{
    // First create the Oxygens
    for (int i = 0; i < NUM_OXYGENS; i++)
    {
        // Find a random empty spot to put the Oxygens
        int xCoord, yCoord;
        do
        {
            xCoord = randBetween(0, width - 1);
            yCoord = randBetween(0, height - 1);
        }
        while (myBoard[xCoord][yCoord]->getType() != "Empty" || myBoard[xCoord][yCoord]->getItem() != nullptr);
        myBoard[xCoord][yCoord]->setItem(new Oxygen());
    }
    
    // Next create the Hydrogens
    for (int i = 0; i < NUM_HYDROGENS; i++)
    {
        // Find a random empty spot to put the Hydrogens
        int xCoord, yCoord;
        do
        {
            xCoord = randBetween(0, width - 1);
            yCoord = randBetween(0, height - 1);
        }
        while (myBoard[xCoord][yCoord]->getType() != "Empty" || myBoard[xCoord][yCoord]->getItem() != nullptr);
        myBoard[xCoord][yCoord]->setItem(new Hydrogen());
    }
    
    return;
}


/***************************************************************
 ** Function:       setPlayer
 ** Description:    sets the player for the board
 ** Parameters:     none
 ** Notes:          none
 ***************************************************************/
void Board::setPlayer(Player *p)
{
    player = p;
    return;
}


/***************************************************************
 ** Function:       getSpace
 ** Description:    returns the space at the specified coordinates
 ** Parameters:     none
 ** Notes:          none
 ***************************************************************/
Space* Board::getSpace(int xCoord, int yCoord)
{
    return myBoard[xCoord][yCoord];
}

