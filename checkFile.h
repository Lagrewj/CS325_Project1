/******************************************************************************************************
Program Filename: checkFile.h
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: Checking input/output files open correctly. 

Input: No input
Output: Output stating file failed to open if operation failed.
******************************************************************************************************/
#ifndef FILE_CHECK_H
#define FILE_CHECK_H

void fileOpens(std::ifstream& inputStream, std::string filename);
void checkOutputFile(std::ofstream& outputStream, std::string filename);
void checkIOFile(std::fstream& fStream, std::string filename);

#endif