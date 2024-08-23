/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE4122_6122 Class

Description:

Simple function to take in an integer and display in text if it is:
    Greater than Zero
    Equal to Zero
    Less than Zero


*/

#include <iostream>

int main()
{
    int iNum = 0;
    std::cout << "Please enter a number:";
	
    std::cin >> iNum; // Waits for user input
	
    if (iNum > 0)
	{
	std::cout << "Your number is : Greater than zero";
	}
    else if (iNum < 0)
    {
        std::cout << "Your number is : Less than zero";
    }
    else
    {
        std::cout << "Your number is : Equal to zero";
    }

    return 0;
}
