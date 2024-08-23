/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE4122_6122 Class

Description:

Simple function to add two integers using prototype declaration.
    
*/

#include <iostream>
using namespace std;

// Function Prototypes 
// Function add two integers passed in by reference
int add (int &Num1, int &Num2);

int main () 
{
    int Input1 = 3;
    int Input2 = 10;
    int Sum = 0;
   
    Sum = add(Input1, Input2);
   
    cout << "The Sum is: " << Sum << endl;
    
    return 0;
}

// Function add two integers passed in by reference
int add (int &Num1, int &Num2)
{
    return (Num1+Num2);
}    