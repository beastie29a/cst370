/****************************************
*
* Title: CST 370 Lab 2 Part
* Abstract: Reverse the output of a string input
* Abstract: Convert Decimal input into Binary strings
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 19
*
****************************************/
#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
/*
   // Initialize data structures
   string inputString;
   Stack revStringStack;

   // Get user input
   cout << "PART A" << endl << endl;
   cout << "Enter a string => ";
   cin >> inputString;

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

*/
   // Initialize data structures
   int inputInt;
   int dividedInt;
   Stack intBinConvertStack;

   // Get user input
   cout << "PART B" << endl << endl;
   cout << "Enter a number: ";
   cin >> inputInt;

   // Store the input int
   dividedInt = inputInt;
   // Loop to get the divison and modulo 2
   while ( dividedInt != 0 )
   {
      intBinConvertStack.push(dividedInt%2);
      dividedInt = dividedInt/2;
   }

   // Return display of stack
   cout << "Decimal: " << inputInt << endl;
   cout << "Binary: ";
   intBinConvertStack.display(cout);
   cout << endl;

}


