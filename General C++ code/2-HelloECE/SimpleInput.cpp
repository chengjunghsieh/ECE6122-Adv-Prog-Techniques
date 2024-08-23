// Every file should start with a comment describing what it contains and often copyright information.
// Use the following for every file:
/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE2036 Class

Description:

Simple function to take in an integer and display the square back to the user.


*/

#include <iostream>

int main()
{
	int iNum = 0;
	std::cout << "Please enter a number:";
	std::cin >> iNum; // Waits for user input
	std::cout << "Your number squared is: " << iNum*iNum; 

    return 0;
}
