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
   string inputString;
   Stack revStringStack;

   cout << "PART A" << endl << endl;
   cout << "Enter a string => ";
   cin >> inputString;

   for (char c : inputString)
   {
      revStringStack.push(c);
   }

   cout << "You Enterered " << inputString << endl;
   cout << "Reverse is ";
   revStringStack.display(cout);
   cout << endl;

*/
   cout << "PART B" << endl << endl;

   int inputInt;
   int dividedInt;
   Stack intBinConvertStack;

   cout << "Enter a number: ";
   cin >> inputInt;

   dividedInt = inputInt;
   while ( dividedInt != 0 )
   {
      intBinConvertStack.push(dividedInt%2);
      dividedInt = dividedInt/2;
   }

   cout << "Decimal: " << inputInt << endl;
   cout << "Binary: ";
   intBinConvertStack.display(cout);
   cout << endl;

}


