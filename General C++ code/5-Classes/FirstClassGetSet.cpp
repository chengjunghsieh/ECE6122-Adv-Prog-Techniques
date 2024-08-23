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
    void setCourseName(string strName)
    {
        m_CourseName = strName;
    }
    string getCourseName() const
    {
        return m_CourseName;
    }
    // Function That displays a welcome message to the GradeBook User
    void displayMessage()
    {
        cout << "Welcome to the Grade Book for " << getCourseName() << "!" << endl;
    }

    // Data Members
    private:
    string m_CourseName;

};

// Function main begins th eprogram execuction
int main () 
{
    string nameOfCourse; // string of characters to store the course name
    GradeBook myGradeBook;

    cout << "Initial course name is:" << myGradeBook.getCourseName() << endl;

    cout << "Please enter the course name:" << endl;
    getline(cin, nameOfCourse); // read a course name with blanks
    cout << endl; // output a blank line

    myGradeBook.setCourseName(nameOfCourse);
    myGradeBook.displayMessage(); // Calls object's function

    system("pause");
    return 0;
}