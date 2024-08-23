#include <iostream>
using namespace std;
 
main() 
{
    int a = 21;
    int b ;

    // Value of "a" will not be increased before assignment.
    b = a++;   
    cout << "post-increment a++: b = " << b << ", a = " << a << endl ;

    a = 21;

    // Value of "a" will be increased before assignment.
    b = ++a;  
    cout << "pre-increment ++a: b = " << b << ", a = " << a << endl ;
    return 0;    
}
