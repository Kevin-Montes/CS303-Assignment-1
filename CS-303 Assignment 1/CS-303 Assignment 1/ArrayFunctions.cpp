#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ArrayFunctions.h"

bool intInArray(int target, int arrayChecked[])
{
	
	for (int i = 0; arrayChecked[i]!=0; i++)
	{
		
		if (target == arrayChecked[i])
		{
			std::cout << target << " is in the Array at Index " << i<<"\n";
			return true;
		}
	}
	std::cout << target << " is not in the Array\n";
	return false;
}
std::string getFileName()
{
	std::string fileName;
	std::ifstream checkValidFile;
	while (true)
	{
		try
		{
			std::cout << "What file do you want to read integers from?\n";
			std::cin >> fileName;
			checkValidFile.open(fileName);
			if (checkValidFile.is_open())
			{
				checkValidFile.close();
				return fileName;
			}
			throw std::runtime_error("Could not find file//could not open file, try again\n");
		}
		catch (std::runtime_error)
		{
			std::cout << "Could not find file//could not open file, try again\n";
		}
		catch (...)
		{
			std::cout << "Unkown error occurred\n";
		}
	}

}





	
	//old function I had to redo because i did not know we would be getting a file to read the integers in the array
	/*std::string input;//will be used to catch any invalid input(anything 0 and below and anything that is not a digit.)
	int size;
	bool valid = false;//to check if valid input has been made yet
	while (valid != true)
	{
		try
		{
			std::cout << "How big would you like your array to be?\n";
			std::cin >> input;
			if (std::stoi(input) && input[0] != '0')
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
	size = std::stoi(input);
	return size;
	*/



