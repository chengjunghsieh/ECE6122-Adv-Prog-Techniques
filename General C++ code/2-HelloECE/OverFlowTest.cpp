#include <iostream>
using namespace std;
 
main() 
{
    short a = 32767;
    
    cout << "a++:" << a++ << endl;
    cout << "a++:" << a++ << endl;
    cout << "a++:" << a++ << endl;
    cout << "a++:" << a++ << endl;

    unsigned short b = 1;
    
    cout << endl;
    cout << "b--:" << b-- << endl;
    cout << "b--:" << b-- << endl;
    cout << "b--:" << b-- << endl;
    cout << "b--:" << b-- << endl;
    return 0;
}
