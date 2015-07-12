/******************************************************************************************************
Program Filename: prepFile.h
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: Preparing files for algorithms
******************************************************************************************************/

#ifndef FILE_ACTION_H
#define FILE_ACTION_H

void outputResult2File(std::ifstream& ifStream, std::ofstream& saveto, std::string filename);
void removeSymbols(std::ifstream& inputStream, std::fstream& tempStream);
std::vector<int> line2Vector(std::fstream& inputStream, std::string fileName, std::vector<int> number, int thisArray);
int countLinesInFiles(std::fstream& inputStream, std::string fileName);

#endif