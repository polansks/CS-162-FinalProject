/****************************************************************
 ** File Name:      Menu.cpp
 ** Author:         Scott Polansky
 ** Date:           Oct 1, 2017
 ** Description:    A menu class to create text-based menus
 ****************************************************************/

#include "Menu.hpp"
#include "input.hpp"

/***************************************************************
 ** Function:       addOption
 ** Description:    Add an option to the menu
 ** Parameters:     the name of the new option
 ***************************************************************/
void Menu::addOption(string newOption)
{
    menuOptions.push_back(newOption);
    return;
}

/***************************************************************
 ** Function:       print
 ** Description:    Print the menu for the user to see
 ** Parameters:     none
 ***************************************************************/
void Menu::print()
{
    for (int i = 0; i < menuOptions.size(); i++)
    {
        cout << i + 1 << ". " << menuOptions[i] << endl;
    }
}

/***************************************************************
 ** Function:       receiveUserSelection
 ** Description:    Receive the user's input for which item
 **                 in the menu they would like select. It ensures
 **                 that the selection is a valid one and will prompt
 **                 the user until a valid selection is entered.
 ** Parameters:     none
 ***************************************************************/
int Menu::receiveUserSelection()
{
    int userChoice;
    cout << "Please select an option: ";

    if (readInteger(userChoice))
    {
        if ((userChoice > menuOptions.size()) || (userChoice <= 0))
        {
            cout << endl << "That is not a valid option." << endl;
            return receiveUserSelection();
        }
        else
        {
            return userChoice - 1;
        }
    }
    else
    {
        cout << endl << "That is not a valid option." << endl;
        return receiveUserSelection();
    }
}
