#include <iostream>
#include <iomanip> // for std::setprecision()

int main()
{
    double dValue = 1.0/3.0;
    float fValue = 1.0f/3.0f;
    std::cout << std::setprecision(16); // show 16 digits    
    std::cout << "dValue: " << dValue << std::endl;
    std::cout << "fValue: " << fValue;
   return 0;
}
