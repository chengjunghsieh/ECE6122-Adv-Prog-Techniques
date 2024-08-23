/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE4122_6122 Class

Description:

Simple do while statement example.
    
*/
#include <iostream>
using namespace std;
 
int main () 
{
    unsigned int counter = 1;
    do
    {
        cout << counter << " ";
    } while (++counter < 10);
    
    counter = 1;    
    do
    {
        cout << counter << " ";
    } while (counter < 10);

    return 0;
}