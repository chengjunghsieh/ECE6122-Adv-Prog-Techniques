/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE2036 Class

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
    
    cout << endl;
    
    counter = 1;    
    do
    {
        cout << counter << " ";
    } while (counter++ < 10);

    return 0;
}