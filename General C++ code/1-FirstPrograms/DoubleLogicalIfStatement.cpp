/*
Author:  Jeff Hurley
Date last modified: 8/27/2020
Organization: ECE4122_6122 Class

Description:

Simple function to take in an integer and display in text if it is:
    Equal to Zero
    Not Equal to Zero
*/

#include <iostream>

int main()
{
    int iNum = 0;
    std::cout << "Please enter a number:";
    std::cin >> iNum; // Waits for user input
	
    if (iNum < 0 || iNum > 0)
    {
        std::cout << "Using && operator Your number is : Not Equal to zero" << std::endl;
    }
    else
    {
        std::cout << "Using && operator Your number is : Equal to zero" << std::endl;
    }
	
    if (!iNum)
    {
        std::cout << "Using ! operator Your number is : Equal to zero" << std::endl;
    }
    else
    {
        std::cout << "Using ! operator Your number is : Not Equal to zero" << std::endl;
    }
    return 0;
}
