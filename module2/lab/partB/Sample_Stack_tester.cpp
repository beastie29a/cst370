/****************************************
*
* Title: CST 370 Lab 2 Part B
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

   // Initialize data structures
   int inputInt;
   int dividedInt;
   Stack intBinConvertStack;

   // Get user input
   cout << "PART B" << endl << endl;
   cout << "Enter a number: ";
   cin >> inputInt;

   // Input validation
   if ( inputInt < 0 )
   {
      cout << "Must be positive integer!" << endl;
      exit(1);
   }

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

   return 0;
}
