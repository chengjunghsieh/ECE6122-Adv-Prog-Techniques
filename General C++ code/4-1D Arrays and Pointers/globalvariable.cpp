/*
Author:  Jeff Hurley
Date last modified: 1/10/2019
Organization: ECE2036 Class

Description:

Show global variable usage
Simple function to add two integers passing parameters by pointer.
    
*/

#include <iostream>
using namespace std;
 
int gSomeNumber = 21; // Global variable 

extern int gSomeOtherNumber; // This global variable is declared in another file somewhere

// Function add two integers passed in by pointer
int add (int *pNum1, int *pNum2)
{
    return (*pNum1 + *pNum2) + gSomeNumber;
}    

int main () 
{
    int Input1 = 3;  // Local Variable
    int Input2 = 10; // Local Variable
    int Sum = 0;     // Local Variable

//    gSomeNumber += 10;
   
    Sum = add(&Input1, &Input2);
   
    cout << "The Sum is: " << Sum << endl;
    
    return 0;
}