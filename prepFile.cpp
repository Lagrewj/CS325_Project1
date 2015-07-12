/******************************************************************************************************
Program Filename: prepFile.cpp
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: Preping files for algorithms. 
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "checkFile.h"
#include "prepFile.h"

/******************************************************************************************************
Function: void outputResult2File(std::ifstream& ioStream, std::ofstream& saveto, std::string filename);

Description: output results to file. 

Parameters: std::ifstream& ioStream, std::ofstream& saveto, std::string filename

Pre-Conditions: input and output file required
Post-Conditions: ifstream copied to outstream
******************************************************************************************************/
void outputResult2File(std::ifstream& ifStream, std::ofstream& saveto, std::string filename)
{
    checkOutputFile(saveto, filename);
    std::string line;
    getline(ifStream, line);
    while (ifStream)
    {
	   saveto << line << std::endl;

	   getline(ifStream, line);
    }
    ifStream.clear();
    ifStream.seekg(0L, std::ios::beg);
}

/******************************************************************************************************
void removeSymbols(std::ifstream& inputStream, std::string fileName)

Description: takes out symbols in file

Parameters: std::ifstream& inputStream, std::string fileName

Pre-Conditions: input file open
Post-Conditions: output file without symbols
******************************************************************************************************/
void removeSymbols(std::ifstream& inputStream, std::fstream& tempStream)
{
    std::vector<char> lines;//maing vector
    while (inputStream)//while loop to iterate through lines
    {
	   char ch;
	   int count = 0;
	   ch = inputStream.get();//get char from file
	   while (ch != EOF)//another while loop while not end of file
	   {
		  if (ch != ',' && ch != '[' && ch != ']')//remove symbols
		  {
			 lines.push_back(ch);
			 count++;
		  }

		  ch = inputStream.get();//go to next line
	   }
	   for (int i = 0; i < count; i++)
	   {
		  tempStream << lines[i];//Outputs to temp file
	   }
	   lines.clear();
    }
    inputStream.clear();
    inputStream.seekg(0L, std::ios::beg);
    tempStream.clear();
    tempStream.seekg(0L, std::ios::beg);
}

/******************************************************************************************************
std::vector<int> line2Vector(std::fstream& inputStream, std::string fileName, std::vector<int> number, int thisArray)

Description: puts numbers from a line into a vector.

Parameters: std::fstream& inputStream, std::string fileName, std::vector<int> number, int thisArray

Pre-Conditions: input file open
Post-Conditions: numbers put into vector
******************************************************************************************************/
std::vector<int> line2Vector(std::fstream& inputStream, std::string fileName, std::vector<int> number, int thisArray)
{
    int arrayCount = 0;//counting lines
    std::vector<std::string> lines;//vector
    getline(inputStream, fileName);//first line
    while (inputStream)//loop to iterate through lines
    {
	   arrayCount++;
	   lines.push_back(fileName);
	   std::istringstream iss(fileName);
	   int next = 0;
	   if (arrayCount == thisArray)
	   {
		  while (iss >> next)
		  {
			 number.push_back(next);
		  }
		  return number;
	   }
	   else
	   {
		  lines.clear();
	   }
    }
}

/******************************************************************************************************
int countLinesInFiles(std::fstream& inputStream, std::string fileName)

Description: Counts number of lines in each file

Parameters: std::fstream& inputStream, std::string fileName

Pre-Conditions: input file open
Post-Conditions: number of lines returned
******************************************************************************************************/
int countLinesInFiles(std::fstream& inputStream, std::string fileName)
{
    int count = 0;
    getline(inputStream, fileName);
    count++;
    while (!inputStream.eof())//iterate each line in file.
    {
	   count++;
	   getline(inputStream, fileName);//next line
    }
    inputStream.clear();
    inputStream.seekg(0L, std::ios::beg);
    return count;
}
