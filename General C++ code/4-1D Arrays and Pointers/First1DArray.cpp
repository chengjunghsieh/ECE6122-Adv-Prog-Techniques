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
    long array2[3] {0, 7865, 4536785};
    long nSingleNum1 {12345};
    long nSingleNum2 (54321);

    for (int ii = 0 ; ii < 12 ; ii++)
    {
        cout << "c[" << ii << "]: " << c[ii] << endl;
    }
}
