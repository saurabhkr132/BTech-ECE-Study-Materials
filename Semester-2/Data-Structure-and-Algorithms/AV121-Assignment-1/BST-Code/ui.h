/***************************************************************************
 * ui.h 
 * This file contains code for generating the menus for user interaction
 * and also validation of user input
 * *************************************************************************/ 

#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include "BST.h"

using namespace std;

bool isNumeric (string);
int getUserOption ();
void trimSpaces(string &);
void processOption (int, BST*);

