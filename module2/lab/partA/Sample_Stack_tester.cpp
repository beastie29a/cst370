/****************************************
*
* Title: CST 370 Lab 2 Part A
* Abstract: Reverse the output of a string input
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 19
*
****************************************/
#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

   // Initialize data structures
   string inputString;
   Stack revStringStack;

   // Get user input
   cout << "PART A" << endl << endl;
   cout << "Enter a string => ";
   getline(cin,inputString);

   // Loop through input string push chars
   // into stack
   for (char c : inputString)
   {
      revStringStack.push(c);
   }

   // Return display of stack
   cout << "You Enterered " << inputString << endl;
   cout << "Reverse is ";
   revStringStack.display(cout);
   cout << endl;

   return 0;

}
