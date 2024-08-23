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
    long *ptrArray1 = new long [12]; // Should be initialized to zero, but be careful
    
    for (long ii = 0 ; ii < 12 ; ii++)
    {
        ptrArray1[ii] = ii;
        cout << ptrArray1[ii] << endl;
    }
    
    delete [] ptrArray1; // The [] must be present for arrays
}
