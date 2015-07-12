/******************************************************************************************************
Program Filename: algorithms1234.h
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: Maximum subarray algorithms

Input: Temporary file
Output: Outputs results to output file.
******************************************************************************************************/

#ifndef ALGORITHMS_H
#define ALGORITHMS_H
struct SubArray
{
    int lowIndex;					
    int highIndex;					
    int sum;						
};
void random_Number_Generator(std::fstream& outputStream, std::fstream& inputStream);
void maximumSumOut(int largestSum, int start, int end, int arraySize, std::ofstream& outputStream, std::vector<int> num_array, int algorithmNum);
int summation(const std::vector<int>& array, int i, int j);
SubArray maxCrossSubarray(std::vector<int> array, int low, int mid, int high);
void alg3PrintSubarray(std::vector<int> array, int sizeArr, struct SubArray print, std::ofstream& outputStream, std::string fileName);
double algorithm1(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array);
double algorithm2(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array);
SubArray algorithm3(std::vector<int> array, int low, int high);
double algorithm4(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array);

#endif