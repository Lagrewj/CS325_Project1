/******************************************************************************************************
Program Filename: checkFile.cpp
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: Checking input/output files open correctly. 

Input: No input
Output: Output stating file failed to open if operation failed.
******************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "checkFile.h"

/******************************************************************************************************
Function: void fileOpens(std::ifstream& inputStream, std::string filename)

Description: Checking that input file opened correctly

Parameters: std::ifstream& inputStream, std::string filename

Pre-Conditions: trying to open file
Post-Conditions: files opened 
******************************************************************************************************/
void fileOpens(std::ifstream& inputStream, std::string filename)
{
    inputStream.open(filename.c_str(), std::ios::in);
    if (inputStream.fail())
    {
	   std::cout << "There was an error opening the file.\n";
	   exit(1);
    }
}

/******************************************************************************************************
Function: void checkOutputFile(std::ofstream& outputStream, std::string filename);

Description: checking output file opens correctly.

Parameters: std::ofstream& outputStream, std::string filename

Pre-Conditions: opening file
Post-Conditions: output file opened
******************************************************************************************************/
void checkOutputFile(std::ofstream& outputStream, std::string filename)
{
    outputStream.open(filename.c_str(), std::ios::out | std::ios::app);
    if (outputStream.fail())
    {
	   std::cout << "There was an error opening output file.\n";
	   exit(1);
    }
}

/******************************************************************************************************
Function: void checkIOFile(std::fstream& inputStream, std::string filename)

Description: Checks to make sure input/output file opens.

Parameters: std::fstream& inputStream, std::string filename

Pre-Conditions: Must be attempting to open input/output file
Post-Conditions: Input/output file will be opened.
******************************************************************************************************/
void checkIOFile(std::fstream& fStream, std::string filename)
{
    fStream.open(filename.c_str(), std::ios::out | std::ios::in | std::ios::trunc);
    if (fStream.fail())
    {
	   std::cout << "There was an error opening the file.\n";
	   exit(1);
    }
}

