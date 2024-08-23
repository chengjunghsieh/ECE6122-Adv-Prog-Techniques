/*
Author:  Jeff Hurley
Date last modified: 1/10/2019
Organization: ECE2036 Class

Description:

First C++ Class for a Grade book.
    
*/
#include <iostream>
using namespace std;

namespace FirstClass
{
    enum class LETTER_GRADES{A, B, C, D, F};
    // GradeBook Definition
    class GradeBook
    {
        public:

        // Function That displays a welcome message to the GradeBook User
        void displayMessage()
        {
            cout << "Welcome to the Grade Book!" << endl;
        }

    };
}
using namespace FirstClass;
// Function main begins th eprogram execuction
int main () 
{
    int testInt = 300;
    char testChar = (char)testInt;
    GradeBook myGradeBook;
    int testInt2(1.5);

    LETTER_GRADES currentGrade = LETTER_GRADES::A;
    myGradeBook.displayMessage(); // Calls object's function

    return 0;
}