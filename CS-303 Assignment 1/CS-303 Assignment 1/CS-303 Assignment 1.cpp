// CS-303 Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayFunctions.h"
int main()
{
    std::string checkInt;//used to check if the number inputted is a int
    int inputInt;//int that was inputted.
    std::ifstream inputFile;
	int newInt;
	int indexReplace;
    
    std::string fileName = getFileName();
   
    
    //I was going to make a function to read the file and return an array of the ints inside the file but I could not figure out how to return an array
    //So now  I just stuck in main
    int intArray[100] = {0};//making an array
    
    inputFile.open(fileName);
    
    int index = 0;
    std::cout << "updated list\n";
    while (inputFile.good())
    {
        inputFile >> intArray[index];
        index++;
    }
   
	
	bool valid = false;//to check if valid input has been made yet
	while (valid != true)
	{
		try
		{
			std::cout << "What number do you want to look for?(cannot be 0, and must be an interger)\n";
			std::cin >> checkInt;
			if (std::stoi(checkInt) && checkInt[0] != '0')
				valid = true;
			else
			{
				throw std::invalid_argument("Input was invalid, input must be a number and number cannot be 0 and below.");
			}
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input was invalid, input must be a number and number cannot be 0 and below.\n";
		}
		catch (...)
		{
			std::cout << "Unkown Error occured, please try again\n";
		}
	}
	inputInt = std::stoi(checkInt);
	intInArray(inputInt, intArray);
	valid = false;
	while (valid != true)
	{
		try
		{
			std::cout << "Input a new number to replace an old number in the array\n";
			std::cin >> checkInt;
			if (std::stoi(checkInt) && checkInt[0] != '0')
			{
				newInt = stoi(checkInt);
				valid = true;
			}
			else
			{
				throw std::invalid_argument("Input was invalid, input must be a number and number cannot be 0 and below.");
			}
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input was invalid, input must be a number and number cannot be 0 and below.\n";
		}
		catch (...)
		{
			std::cout << "Unkown Error occured, please try again\n";
		}
	}
	valid = false;
	while (valid != true)
	{
		try
		{
			std::cout << "What index do you want to replace?(cannot be below 0, and must be an interger)\n";
			std::cin >> checkInt;
			if (std::stoi(checkInt)||checkInt[0]=='0')//wpuld not take 0 as an input for some reason so i did this
			{
			
				if (0 <= std::stoi(checkInt)&& std::stoi(checkInt)<index)
				{
					indexReplace = std::stoi(checkInt);
					valid = true;
					std::cout << "Old Number: " << intArray[indexReplace] << "\n";
					intArray[indexReplace] = newInt;
				}
				
			}
				
			else
			{
				throw std::invalid_argument("Input was invalid, input must be a  and number cannot be below 0 and must be under current index\n");
			}
		}
		catch (std::invalid_argument)
		{
			std::cout << "Input was invalid, input must be a number and number cannot be below 0 \n";
		}
		catch (...)
		{
			std::cout << "Unkown Error occured, please try again\n";
		}
	}
	
	std::cout << "What number would you like to add\n";
	std::cin >> checkInt;
	valid = false;
	while (valid != true)
	{
		if (stoi(checkInt) && checkInt[0] != '0');
		{
			intArray[index] = stoi(checkInt);
			index++;
		}
	}
	std::cout << checkInt << " added at index" << index - 1 << "\n";

	
	

	
}

