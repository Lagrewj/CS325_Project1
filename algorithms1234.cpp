/******************************************************************************************************
Program Filename: algorithms1234.cpp
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: In this file are the 4 max subarray algorithms

Input: Temporary file  

Output: numOfCoins will be outputted to file
******************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>
#include <stdio.h>
#include "algorithms1234.h"
#include "checkFile.h"
#include "checkInput.h"

/******************************************************************************************************
void random_Number_Generator(std::fstream& outputStream, std::fstream& inputStream)

Description: This will generate random integers and output to temp.

Parameters: std::fstream& outputStream, std::fstream& inputStream

Pre-Conditions: Output file open.
Post-Conditions: Values written to file. 
******************************************************************************************************/
void random_Number_Generator(std::fstream& outputStream, std::fstream& inputStream)
{
    int n; //number of integers to create
    int random_num;//holding variable
    std::cout << "Type how many random values to generate." << std::endl;
    std::cin >> n;
    n = inputIsInt(n);//checking input is valid 
    srand(time(0)); //new numbers generated each run through 
    for (int i = 0; i < 10; i++)
    {
	   for (int i = 0; i < n; i++)
	   {
		  random_num = (rand() % 2000 - 1000); //random number between -1000 and 1000
		  outputStream << random_num << " ";//output to temp text file
	   }
	   outputStream << '\r' << '\n';
    }
    inputStream.clear();//clears eof
    inputStream.seekg(0L, std::ios::beg);//Will move back to beginning
}

/******************************************************************************************************
void maximumSumOut(int largestSum, int start, int end, int arraySize, std::ofstream& outputStream,
                  std::vector<int> num_array, int algorithmNum)

Description: This will output each array and its max subarray.

Parameters: int largestSum, int start, int end, int arraySize, std::ofstream& outputStream,
            std::vector<int> num_array, int algorithmNum

Pre-Conditions: output file open
Post-Conditions: data output to output file
******************************************************************************************************/
void maximumSumOut(int largestSum, int start, int end, int arraySize, std::ofstream& outputStream,
    std::vector<int> num_array, int algorithmNum)
{//iterate through array
    outputStream << "Algorithm "<< algorithmNum << std::endl;
    outputStream << '\r';
    outputStream << "Array: ";
    for (int i = 0; i < arraySize; i++)
    {
	   outputStream << num_array[i];
	   if (i < arraySize - 1)
       {
           outputStream << ", ";
       }
    }
    outputStream << '\r' << '\n';
    outputStream << "Subarray: ";
    if (largestSum == 0)
    {
	   outputStream << "(empty)";
    }
    else
    {
	   for (int i = start; i <= end; i++)
	   {
		  outputStream << num_array[i];
		  if(i < end )
          {
              outputStream << ", ";
          }
	   }
    }
    outputStream << '\r' << '\n';
    outputStream << "Max sum: " << largestSum << std::endl;
    outputStream << '\r' << '\n';
    outputStream << '\r' << '\n';
}

/******************************************************************************************************
int summation(const std::vector<int>& array, int i, int j)

Description: Sums each value in the array. 

Parameters: const std::vector<int>& array, int i, int j

Pre-Conditions: none
Post-Conditions: array summed
******************************************************************************************************/
int summation(const std::vector<int>& array, int i, int j)
{
    int sum = 0;
    for (i; i <= j; i++)
    {
	   sum += array[i];
    }
    return sum;
}

/******************************************************************************************************
SubArray maxCrossSubarray(std::vector<int> array, int low, int mid, int high)

Description: For algorithm 3, divide and conquer. 

Parameters: std::vector<int> array, int low, int mid, int high

Pre-Conditions: Must be a vector with values
Post-Conditions: none 
******************************************************************************************************/
SubArray maxCrossSubarray(std::vector<int> array, int low, int mid, int high)
{
    int leftSum = 0;					//max sum of left subarray
    int rightSum = 0;					//max sum of right subarray
    int sum = 0;						//initialize sums
    int i;
	struct SubArray maxCross;			//struct
    for (i = mid; i >= low; i--)		//for loop for left
    {
	   sum = sum + array[i];			
	   if (sum > leftSum){
		  leftSum = sum;
		  maxCross.lowIndex = i;			
	   }
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++)	//for loop for right
    {
	   sum = sum + array[i];				
	   if (sum > rightSum){
		  rightSum = sum;
		  maxCross.highIndex = i;			
	   }
    }
    maxCross.sum = leftSum + rightSum; //max sum of cross subarray
    return maxCross;
}

/******************************************************************************************************
void alg3PrintSubarray(std::vector<int> array, int sizeArr, struct SubArray print, std::ofstream& outputStream,
                   std::string fileName)

Description: prints out data for alg 3. 

Parameters: std::vector<int> array, int sizeArr, struct SubArray print, std::ofstream& outputStream,
            std::string fileName

Pre-Conditions: output file open
Post-Conditions: output to file 
******************************************************************************************************/
void alg3PrintSubarray(std::vector<int> array, int sizeArr, struct SubArray print, std::ofstream& outputStream,
                   std::string fileName)
{
    checkOutputFile(outputStream, fileName);
    outputStream << "Algorithm 3" << std::endl;
    outputStream << '\r';
    outputStream << "Original Array: ";
    for (int i = 0; i < sizeArr; i++)
    {
	   outputStream << array[i];
        if (i < sizeArr - 1)
       {
           outputStream << ", ";
       }
    }
    outputStream << '\r' << '\n';
    outputStream << "Subarray: ";
    if (print.sum == 0)
    {
	   outputStream << "(empty)";
    }
    else
    {
	   for (int i = print.lowIndex; i <= print.highIndex; i++)
	   {
		  outputStream << array[i];
		  if(i < print.highIndex )
          {
              outputStream << ", ";
          }
	   }
    }
    outputStream << '\r' << '\n';
    outputStream << "Max sum equals: " << print.sum << std::endl;
    outputStream << '\r' << '\n';
    outputStream << '\r' << '\n';
    outputStream.close();
}

/******************************************************************************************************
double algorithm1(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array)

Description: From input file will sum each line and output max subarray.

Parameters: std::ofstream& outputStream, std::string fileName, const std::vector<int>& array

Pre-Conditions: output file open
Post-Conditions: max subarray output to output file
******************************************************************************************************/
double algorithm1(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array)
{
    int currentMaxSum = 0;                
    int nextSum = 0;             
    unsigned long startMax = 0;     
    unsigned long endMax = 0;       
    double runTime = 0;
    int arraySize = 0;
    checkOutputFile(outputStream, fileName); 
    clock_t start, stop;//run time analysis
    unsigned int i;
    unsigned int j;
    start = clock();
    for (i = 0; i < array.size(); i++)
    {
	   nextSum = 0;
	   for (j = i; j < array.size(); j++)
	   {
		  nextSum = summation(array, i, j);

		  if (nextSum > currentMaxSum)
		  {
			 startMax = i;
			 endMax = j;
			 currentMaxSum = nextSum;
		  }
	   }

    }
    stop = clock();                     //end run time
    runTime = ((double)(stop - start) / CLOCKS_PER_SEC);//output in sec
    arraySize = array.size();
    maximumSumOut(currentMaxSum, startMax, endMax, arraySize, outputStream, array, 1);
    outputStream.close();
    return runTime;
} 

/******************************************************************************************************
double algorithm2(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array)

Description: From input file will sum each line and output max subarray.
		   
Parameters: std::ofstream& outputStream, std::string fileName, const std::vector<int>& array

Pre-Conditions: file must be open
Post-Conditions: max subarray output to output file
******************************************************************************************************/
double algorithm2(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array)
{
    int currentMaxSum = 0;                 
    int nextSum = 0;            		    
    unsigned long startMax = 0;         
    unsigned long endMax = 0;            
    double runTime = 0;
    int arraySize = 0;
    checkOutputFile(outputStream, fileName); 
    clock_t start, stop;//run time                   
    unsigned int i;
    unsigned int j;
    start = clock();
    for (i = 0; i < array.size(); i++)
    {
	   nextSum = 0;
	   for (j = i; j < array.size(); j++)
	   {
		  nextSum += array[j];
		  if (nextSum > currentMaxSum)
		  {
			 startMax = i;
			 endMax = j;
			 currentMaxSum = nextSum;
		  }
	   }
    }
    stop = clock();//end run time                     
    runTime = ((double)(stop - start) / CLOCKS_PER_SEC);
    arraySize = array.size();
    //Display the numOfCoins from Algorithm 2 to MSS_numOfCoins.txt
    maximumSumOut(currentMaxSum, startMax, endMax, arraySize, outputStream, array, 2);
    outputStream.close();
    return runTime;
} 

/*****************************************************************************
Function: Algorithm 3

Purpose: Divide and Conquer algorithm

Parameters: vector of ints
******************************************************************************/
SubArray algorithm3(std::vector<int> array, int low, int high)
{
	SubArray pass;
	SubArray leftMSS;						
	SubArray rightMSS;					
	SubArray crossMSS;								
    if (high == low)					
    {
	   pass.lowIndex = low;			
	   pass.highIndex = high;			
	   pass.sum = array[low];		
	   return pass;
    }
    else
    {
	   int mid = (low + high) / 2;		
	   leftMSS = algorithm3(array, low, mid); 
	   rightMSS = algorithm3(array, (mid + 1), high); 
	   crossMSS = maxCrossSubarray(array, low, mid, high);
	   if (leftMSS.sum >= rightMSS.sum && leftMSS.sum >= crossMSS.sum)
	   {
		  return leftMSS;
	   }
	   else if (rightMSS.sum >= leftMSS.sum && rightMSS.sum >= crossMSS.sum)
	   {
		  return rightMSS;
	   }
	   else
	   {
		  return crossMSS;
	   }
    }
}

/********************************************************************************************************
Function: Algorithm 4

Purpose: Linear time algorithm based on Kadane's algorithm. 
Source: http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

Parameters: array with at least one value
*********************************************************************************************************/
double algorithm4(std::ofstream& outputStream, std::string fileName, const std::vector<int>& array)
{
    int currentMaxSum = 0;                 //var for current max sum
    int nextSum = 0;                       //var for the next array index	 //value after adding next array index
    unsigned int startMax = 0;             //index of start of max sub array
    unsigned int endMax = 0;               //index of end of max sub array
    int existingStart = 0;				   //the start of last array
    bool getStart = true;				   //bool for needing start
    int arraySize = 0;            
    double runTime = 0;
    checkOutputFile(outputStream, fileName);
    clock_t start, stop;                  //run time
    unsigned int i;
    start = clock();                    
    for (i = 0; i < array.size(); i++)
    {
	   nextSum += array[i];             //add the next element in array
	   if (nextSum > 0 && getStart)     //Do we need to set a starting index?
	   {
		  startMax = i;               //set start index of max sub array
		  getStart = false;
	   }
	   if (nextSum < 0){
		  nextSum = 0;                //max sum can not be less than 0
		  getStart = true;           //getting new start location
		  existingStart = startMax;
	   }
	   else if (currentMaxSum < nextSum)//larger sum
	   {
		  endMax = i;                 //updating new end 
		  currentMaxSum = nextSum;
	   }
	   if (startMax > endMax)
	   {
		  startMax = existingStart;
	   }
    }
    stop = clock();                     
    runTime = ((double)(stop - start) / CLOCKS_PER_SEC);
    arraySize = array.size();
    //Outputting numOfCoins to file
    maximumSumOut(currentMaxSum, startMax, endMax, arraySize, outputStream, array, 4);
    outputStream.close();
    return runTime;
} 
