/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE4122_6122 Class

Description:

Simple function to declare static array and output results
    
*/

#include <iostream>
using namespace std;

int main()
{
    long c[12] = {-45,6,0,72,1543,-89,0,62,-3,1,6453,78};
    
    for (int ii = 0 ; ii < 12 ; ii++)
    {
        cout << "c[" << ii << "]: " << c[ii] << endl;
    }
}
