/*
Author:  Jeff Hurley
Date last modified: 1/10/2019
Organization: ECE2036 Class

Description:

First C++ Class for a Grade book.
    
*/
#include <iostream>
#include <string>
using namespace std;

// GradeBook Definition
class GradeBook
{
    public:
    // Function That displays a welcome message to the GradeBook User
    void displayMessage(string courseName)
    {
        cout << "Welcome to the Grade Book for " << courseName << "!" << endl;
    }

};

// Function main begins th eprogram execuction
int main () 
{
    string nameOfCourse; // string of characters to store the course name
    GradeBook myGradeBook;
    cout << "Please enter the course name:" << endl;
    getline(cin, nameOfCourse); // read a course name with blanks
    cout << endl; // output a blank line

    myGradeBook.displayMessage(nameOfCourse); // Calls object's function

    system("pause");
    return 0;
}