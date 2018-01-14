/****************************************************************
 ** File Name:      Menu.hpp
 ** Author:         Scott Polansky
 ** Date:           Oct 1, 2017
 ** Description:    A menu class to create text-based menus
 ****************************************************************/

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Menu
{
private:
    vector<string> menuOptions;
    int optionSelected;
    
public:
    void addOption(string);
    void print();
    int receiveUserSelection();
    
};
#endif
