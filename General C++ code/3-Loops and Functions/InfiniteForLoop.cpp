/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE2036 Class

Description:

Infinite for loop
    
*/

#include <iostream>
using namespace std;

int main()
{
    unsigned int counter = 1; // Assigned outside of for loop
    bool bIsTrue = true;
    
    for (; counter <= 10 && bIsTrue ; ++counter) // Multiple conditions. NO ";" at end of line
    {
        cout << counter << " ";
    }
    cout << endl;    
    
    cin >> counter; // Valid to use since still in scope
    
    for (;;) // Infinite loop
    {
        cout << "for";
        cout << endl;
    }
    
    while (true) // Infinite loop
    {
        cout << "while";
        cout << endl;
    }
    
    return 0;
}
