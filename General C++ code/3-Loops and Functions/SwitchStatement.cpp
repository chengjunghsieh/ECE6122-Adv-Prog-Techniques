/*
Author:  Jeff Hurley
Date last modified: 1/8/2019
Organization: ECE2036 Class

Description:

Simple switch statement example.
    
*/

#include <iostream>
using namespace std;
 
int main () 
{
   
   char grade = 'A'; // Initialize grade
   cout << "Please enter letter for grade: "; 
   cin >> grade;
   
   switch(grade) 
   {
      case 'A' :
         cout << "Excellent job!" << endl; 
         break;
      case 'B' :
         cout << "Good job" << endl;
         break;
      case 'C' :
         cout << "Fair job" << endl;
      case 'D' :
         cout << "You just passed" << endl;
         break;
      case 'F' :
         cout << "You have to try again" << endl;
         break;
      default :
         cout << "Invalid grade" << endl;
   }

   switch(grade) 
   {
      case 'A' :
      case 'B' :
      case 'C' :
      case 'D' :
         cout << "You passed" << endl;
         break;
      case 'F' :
         cout << "You Failed" << endl;
         break;
      default :
         cout << "Invalid grade" << endl;
   }
   
   return 0;
}