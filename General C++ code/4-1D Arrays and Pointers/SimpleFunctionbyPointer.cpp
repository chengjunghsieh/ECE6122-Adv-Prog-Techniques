/*
Author:  Jeff Hurley
Date last modified: 1/10/2019
Organization: ECE2036 Class

Description:

Simple function to add two integers passing parameters by pointer.
    
*/

#include <iostream>
using namespace std;
 
// Function add two integers passed in by pointer
int add (int *pNum1, int *pNum2)
{
    return (*pNum1 + *pNum2);
}    

int main () 
{
    int Input1 = 3;
    int Input2 = 10;
    int Sum = 0;
   
    Sum = add(&Input1, &Input2);
   
    cout << "The Sum is: " << Sum << endl;
    
    return 0;
}