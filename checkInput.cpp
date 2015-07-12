/******************************************************************************************************
Program Filename: checkInput.cpp
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: Input validation

Input: User's input from keyboard. 

Output: Output to screen to prompt new input.
******************************************************************************************************/

#include <iostream>
#include <string>
#include "checkInput.h"

/******************************************************************************************************
Function: int validUserInput(int input)

Description: Checking user input. 

Parameters: int input
Pre-Conditions: user's input
Post-Conditions: input number be int value 0 through 9
******************************************************************************************************/
int validUserInput(int input)
{
    while (std::cin.fail() || input > 9 || input < 0)
    {
	   std::cout << "You did not enter a proper menu item" << std::endl;
	   std::cout << "Enter a new number 1-9." << std::endl;
	   std::cin.clear(); 
	   std::cin.ignore(100, '\n'); 
	   std::cin >> input;
    }
    return input;
}


/******************************************************************************************************
Function: char yesOrNo(char input)

Description: This function checks to make sure the input for selecting Y or N are correct.

Parameters: int input.
Pre-Conditions: User must assign a value for input.
Post-Conditions: The input value must be a n, N, y, or Y
******************************************************************************************************/
char yesOrNo(char input) //lower case and upper case valid
{
    while (input != 'y' && input != 'Y' && input != 'n' && input != 'N')
    {
	   std::cout << "Not valid input. Try again." << std::endl;
	   std::cout << "Enter 'Y' for yes and 'N' for no." << std::endl;
	   std::cin.clear();
	   std::cin.ignore(100, '\n'); 
	   std::cin >> input;
    }
    return input;
}

/******************************************************************************************************
Function: int inputIsInt(int input)

Description: Ensures input is an integer.

Parameters: int input
Pre-Conditions: user input
Post-Conditions: input checked that it is an int
******************************************************************************************************/
int inputIsInt(int input)
{
    while (std::cin.fail() ) 
    {
	   std::cout << "That was not an integer" << std::endl;
	   std::cout << "Enter a number" << std::endl;
	   std::cin.clear(); 
	   std::cin.ignore(100, '\n'); 
	   std::cin >> input;
    }
    return input;
}
