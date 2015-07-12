/******************************************************************************************************
Program Filename: main.cpp
Project 1
Project Group 3 CS325 SU2015
Author: Jonathan Lagrew, Tri-Solomon Huynh, Yunsik Choi
Date: 7/6/2015
Description: Four algorithms for the maximum subarray problem.

Input: An array of integers.

Output: A subarray with maximum sum along with the sum.
******************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include "prepFile.h"
#include "checkFile.h"
#include "checkInput.h"
#include "algorithms1234.h"
int main()
{
   //This section will be the I/O File load

    char inputFile[] = "MSS_Problems.txt";//Input name of file
    std::ifstream if_inputStream;//Input stream
    char tempFile[] = "temp.txt";//temp file 
    std::fstream f_tempStream;//temp stream
    char tempFile2[] = "temp2.txt";//temp file 2
    std::fstream f_tempStream2;//temp stream 2
    char outputFile[] = "MSS_Results.txt";//Output file 
    std::ofstream saveoutputStream;//output stream

    fileOpens(if_inputStream, inputFile);//Checking that input file is opened 
    checkIOFile(f_tempStream, tempFile);//Checking that temp file is opened
    checkIOFile(f_tempStream2, tempFile2);//Checking temp2 
    
    //This section will output the main menu options to the screen

    bool repeat = false;//User selects if they want to return to main menu or exit the program
    char answer;//Variable for user input to quit or continue
    int menu_choice;//User's input for which menu option 
    std::vector<int> relay;// Holds values from array in input file.
    int arrayCount = 0;//Number of arrays in input file.
    double totalTime = 0;// Holds run time values.
    clock_t start, stop;//for timing
	SubArray s;//Used for algorithm3

    std::cout << "\nWelcome to our Algorithms Program. Please enter a menu choice." << std::endl; //intro message
    do //do while loop to run until bool repeat stops loop 
    {
       std::cout << "\n0). Run all 4 algorithms with MSS_Problems.txt file" << std::endl;
	   std::cout << "1). Run Algorithm 1 with MSS_Problems.txt file" << std::endl;
	   std::cout << "2). Run Algorithm 1 with n amount of random values" << std::endl;
	   std::cout << "3). Run Algorithm 2 with MSS_Problems.txt file" << std::endl;
	   std::cout << "4). Run Algorithm 2 with n amount of random values" << std::endl;
	   std::cout << "5). Run Algorithm 3 with MSS_Problems.txt file" << std::endl;
	   std::cout << "6). Run Algorithm 3 with n amount of random values" << std::endl;
	   std::cout << "7). Run Algorithm 4 with MSS_Problems.txt file" << std::endl;
	   std::cout << "8). Run Algorithm 4 with n amount of random values" << std::endl;
	   std::cout << "9). Exit." << std::endl;
	   std::cin >> menu_choice; //cin for user's selection 
	   menu_choice = validUserInput(menu_choice);//validate user input.
	   std::cin.clear();//clear input
	   std::cin.ignore(100, '\n');//ignoring 100 char or new line
	   
	   switch (menu_choice) //switch statement for menu choices
	   {
       case 0:  std::cout << "Running all algorithms with MSS_Problems.txt file." << std::endl;
          removeSymbols(if_inputStream, f_tempStream); //taking out [] and , of input file
		  arrayCount = countLinesInFiles(f_tempStream, tempFile);//getting the number of arrays in the file
		  //for loop to iterate through arrays in the file and run the algorithms on each
		  for (int i = 1; i <= arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream, tempFile, relay, i);//populates vector 
			 algorithm1(saveoutputStream, outputFile, relay);//algorithm 1
			 algorithm2(saveoutputStream, outputFile, relay);//algorithm 2
			 s = algorithm3(relay, 0, (relay.size() - 1));//algorithm 3
			 alg3PrintSubarray(relay, relay.size(), s, saveoutputStream, outputFile);
			 algorithm4(saveoutputStream, outputFile, relay); //algorithm 4
			 relay.clear();//clearing vector
		  }
		  std::cout << "Results outputted in MSS_Results.txt " << std::endl;
		  totalTime = 0;
		  arrayCount = 0;
		  break;
	   case 1: std::cout << "Running Algorithm 1 with MSS_Problems.txt file." << std::endl;
		  removeSymbols(if_inputStream, f_tempStream); 
		  arrayCount = countLinesInFiles(f_tempStream, tempFile);
		  //for loop to iterate through arrays in the file and run the algorithms on each
		  for (int i = 1; i <= arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream, tempFile, relay, i);
			 totalTime += algorithm1(saveoutputStream, outputFile, relay);
			 relay.clear();
		  }
		  std::cout << "Average Run Time " << totalTime << std::endl;
		  totalTime = 0;
		  arrayCount = 0;
		  break;

	   case 2: std::cout << "Running Algorithm 1 with n amount of random values" << std::endl;
		  random_Number_Generator(f_tempStream2, f_tempStream2);//This will create 10 arrays of randomly generated values
		  arrayCount = countLinesInFiles(f_tempStream2, tempFile2);

		  for (int i = 1; i < arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream2, tempFile2, relay, i);
			 totalTime += algorithm1(saveoutputStream, outputFile, relay);
			 relay.clear();
		  }
		  std::cout << "Average Run Time " << totalTime << std::endl;
		  totalTime = 0;
		  arrayCount = 0;
		  break;

	   case 3: std::cout << "Running Algorithm 2 with MSS_Problems.txt file." << std::endl;
		  removeSymbols(if_inputStream, f_tempStream);
		  arrayCount = countLinesInFiles(f_tempStream, tempFile);
		  //for loop to iterate through arrays in the file and run the algorithms on each
		  for (int i = 1; i <= arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream, tempFile, relay, i);
			 totalTime += algorithm2(saveoutputStream, outputFile, relay);
			 relay.clear();
		  }
		  std::cout << "Average Run Time " << totalTime << std::endl;
		  totalTime = 0;
		  arrayCount = 0;
		  break;

	   case 4: std::cout << "Running Algorithm 2 with n amount of random values" << std::endl;
		  random_Number_Generator(f_tempStream2, f_tempStream2);
		  arrayCount = countLinesInFiles(f_tempStream2, tempFile2);

		  for (int i = 1; i < arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream2, tempFile2, relay, i);
			 totalTime += algorithm2(saveoutputStream, outputFile, relay);
			 relay.clear();
		  }
		  std::cout << "Average Run Time " << totalTime << std::endl;
		  totalTime = 0;
		  arrayCount = 0;
		  break;

	   case 5: std::cout << "Running Algorithm 3 with MSS_Problems.txt file." << std::endl;
		  removeSymbols(if_inputStream, f_tempStream);
		  arrayCount = countLinesInFiles(f_tempStream, tempFile);
		  //for loop to iterate through arrays in the file and run the algorithms on each
		  for (int i = 1; i <= arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream, tempFile, relay, i);
			 start = clock();
			 s = algorithm3(relay, 0, (relay.size() - 1));
			 stop = clock();
			 totalTime += (stop - start) / double(CLOCKS_PER_SEC);

			 alg3PrintSubarray(relay, relay.size(), s, saveoutputStream, outputFile);
			 relay.clear();
		  }

		  std::cout << "Average Time: " << totalTime / arrayCount << std::endl;

		  break;

	   case 6: std::cout << "Running Algorithm 3 with n amount of random values" << std::endl;
		  random_Number_Generator(f_tempStream2, f_tempStream2);
		  arrayCount = countLinesInFiles(f_tempStream2, tempFile2);

		  for (int i = 1; i < arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream2, tempFile2, relay, i);//
			 start = clock();
			 s = algorithm3(relay, 0, (relay.size() - 1));
			 stop = clock();
			 totalTime += (stop - start) / double(CLOCKS_PER_SEC);

			 alg3PrintSubarray(relay, relay.size(), s, saveoutputStream, outputFile);
			 relay.clear();
		  }

		  std::cout << "Average Time: " << totalTime / arrayCount << std::endl;

		  break;

	   case 7: std::cout << "Running Algorithm 4 with MSS_Problems.txt file." << std::endl;
		  removeSymbols(if_inputStream, f_tempStream); 
		  arrayCount = countLinesInFiles(f_tempStream, tempFile);
		  //for loop to iterate through arrays in the file and run the algorithms on each
		  for (int i = 1; i <= arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream, tempFile, relay, i);
			 totalTime += algorithm4(saveoutputStream, outputFile, relay);
			 relay.clear();
		  }
		  std::cout << "Average Run Time " << totalTime << std::endl;
		  totalTime = 0;
		  arrayCount = 0;
		  break;

	   case 8: std::cout << "Running Algorithm 4 with n amount of random values" << std::endl;
		  random_Number_Generator(f_tempStream2, f_tempStream2);
		  arrayCount = countLinesInFiles(f_tempStream2, tempFile2);

		  for (int i = 1; i < arrayCount; i++)
		  {
			 relay = line2Vector(f_tempStream2, tempFile2, relay, i);
			 totalTime += algorithm4(saveoutputStream, outputFile, relay);
			 relay.clear();
		  }
		  std::cout << "Average Run Time " << totalTime << std::endl;
		  totalTime = 0;
		  arrayCount = 0;
		  break;

	   case 9: std::cout << "Exiting program." << std::endl;
		  return 0;
		  break;
	   }//end switch statement

	  //This section will prompt the user to go back to main menu
	   std::cout << "Back to menu? Y / N." << std::endl;
	   std::cin >> answer;
	   answer = yesOrNo(answer);
	   std::cin.clear();//clearing input
	   std::cin.ignore(100, '\n');//ignore 100 char or new line
	   answer = toupper(answer);
	   if (answer == 'N')
	   {
		  repeat = true;
	   }
    } while (repeat != true);
    {
	   std::cout << "I hope you enjoyed using our maximum subarray algorithm program." << std::endl;
    }
    //Closing file streams
    if_inputStream.close();
    f_tempStream.close();
    saveoutputStream.close();
    return 0;
};//end main
