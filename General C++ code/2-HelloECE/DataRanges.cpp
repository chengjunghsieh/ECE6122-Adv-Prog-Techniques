/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE2036 Class

Description:

Simple function to display data ranges
    
*/
#include <iostream> 
#include <limits>
#include <cfloat>

using namespace std; 
int main() 
{ 
    cout << "bool size: " << sizeof(bool) << " Values: true, false" << endl << endl; 
    cout << "char size: " << sizeof(char) << " range: " << CHAR_MIN << " to " << CHAR_MAX << endl << endl; 
    cout << "unsigned char size: " << sizeof(unsigned char) << " range: " << 0 << " to " << UCHAR_MAX << endl << endl;

    cout << "short int size: " << sizeof(short int) << " range: " << SHRT_MIN << " to " << SHRT_MAX << endl << endl;
    cout << "unsigned short int size: " << sizeof(unsigned short int) << " range: " << 0 << " to " << USHRT_MAX << endl << endl; 
    cout << "int size: " << sizeof(int) << " range: " << INT_MIN << " to " << INT_MAX << endl << endl;
    cout << "unsigned int size: " << sizeof(unsigned int) << " range: " << 0 << " to " << UINT_MAX << endl << endl; 
    cout << "long int size: " << sizeof(long int) << " range: " << LONG_MIN << " to " << LONG_MAX << endl << endl; 
    cout << "unsigned long int size: " << sizeof(unsigned long int) << " range: " << 0 << " to " << ULONG_MAX << endl << endl; 
    cout << "long long int size: " << sizeof(long long int) << " range: " << LLONG_MIN << " to " << LLONG_MAX << endl << endl; 
    cout << "unsigned long long int size: " << sizeof(unsigned long long int) << " range: " << 0 << " to " << ULLONG_MAX << endl << endl; 

    cout << "float size: " << sizeof(float) << " range: " << FLT_MIN << " to " << FLT_MAX << endl << endl; 
    cout << "double size: " << sizeof(double) << " range: " << DBL_MIN << " to " << DBL_MAX << endl << endl; 

return 0; 

} 
