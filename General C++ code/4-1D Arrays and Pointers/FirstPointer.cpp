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
    long c[12] = {-45,6,0,72,1543,-89,0,62,-3,1,6453,78};
    long *ptr = nullptr; // Declare a pointer to a long and initialize it to null
    
    ptr = &c[0]; // ptr now contains the memory address of the first element of c
    cout << "Here are the memory addresses" << endl;
    
    for (int ii = 0 ; ii < 12 ; ii++)
    {
        cout << "c[" << ii << "] is at memory address: " << ptr++ << endl; // Pointer can be incremented
    }

    ptr = &c[0]; // ptr now contains the memory address of the first element of c

    cout << endl << "Here are the values stored at the memory addresses" << endl;
    for (int ii = 0 ; ii < 12 ; ii++)
    {
        cout << "c[" << ii << "]: " << (*ptr++) << endl; // Pointer can be incremented
    }
    
}
