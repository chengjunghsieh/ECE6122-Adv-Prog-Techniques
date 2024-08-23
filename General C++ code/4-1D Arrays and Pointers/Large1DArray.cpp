/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE2036 Class

Description:

Simple function to declare static array and output results
    
*/

#include <iostream>
using namespace std;

int main()
{
    long array1[10000]; // Should be initialized to zero, but be careful
    
    for (long ii = 0 ; ii < 10000 ; ii++)
    {
        array1[ii] = ii;
    }
}
