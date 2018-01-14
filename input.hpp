/****************************************************************
 ** File Name:      input.hpp
 ** Author:         Scott Polansky
 ** Date:           Oct 1, 2017
 ** Description:    A file with function for reading user input which
 **                 performs some simple data type checking
 ****************************************************************/

#ifndef input_hpp
#define input_hpp

#include <iostream>
#include <string>

using std::string;
using std::cin;

bool readInteger(int &destination);
bool readString(string &destination);

#endif
