/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE4122_6122 Class

Description:

Simple function to display the first ten positive integers
    
*/

#include <iostream>
using namespace std;

int main()
{
    for (unsigned int counter = 1 ; counter <= 10 ; ++counter)
    {
        cout << counter << " ";
    }
    cout << endl;
    
    return 0;
}
