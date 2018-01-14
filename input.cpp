/****************************************************************
 ** File Name:      input.cpp
 ** Author:         Scott Polansky
 ** Date:           Oct 1, 2017
 ** Description:    A file with function for reading user input which
 **                 performs some simple data type checking
 ****************************************************************/

#include "input.hpp"

/***************************************************************
 ** Function:       readInteger
 ** Description:    Receives input from <cin> and ensures that it
 **                 is an integer. If it is, it stores the value
 **                 in the specified destination variable. If it
 **                 not, then nothing is stored in destination.
 **
 **                 If additional input was entered after the
 **                 integer, the integer is store in destination
 **                 but the function still returns false.
 **
 ** Parameters:     the destination variable to store the integer
 ***************************************************************/
bool readInteger(int &destination)
{
    double valueIn;
    if (cin >> valueIn)
    {
        // Value was numeric. Now make sure it was an integer.
        int integerValue = valueIn;
        if (integerValue == valueIn)
        {
            destination = integerValue;
            
            // Check to make sure nothing else was entered after the integer
            string dummyString;
            if (cin.get() != '\n')
            {
                cin.clear();
                getline(cin, dummyString);
                return false;
            }
            
            return true;
        }
        else
        {
            // Clear the buffer and return FALSE
            string dummyString;
            cin.clear();
            getline(cin, dummyString);
            return false;
        }
    }
    else
    {
        // Clear the buffer and return FALSE
        string dummyString;
        cin.clear();
        getline(cin, dummyString);
        return false;
    }
}

/***************************************************************
 ** Function:       readString
 ** Description:    Receives input from <cin> and ensures that it
 **                 is a string. If it is, returns TRUE and
 **                 stores the value in the specified variable
 ** Parameters:     the destination variable to store the string
 ***************************************************************/
bool readString(string &destination)
{
    string stringIn;
    if (cin >> stringIn)
    {
        destination = stringIn;
        return true;
    }
    else
    {
        // Clear the buffer and return FALSE
        string dummyString;
        cin.clear();
        getline(cin, dummyString);
        return false;
    }
}

