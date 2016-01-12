/****************************************
*
* Title: CST 370 Programming Assignment 1
* Abstract: Program to find substring 
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 12
*
****************************************/

#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
   //Programming Assignment (Linked List)
   LinkedList charList;
   string userInput;

   // Ask for input
   cout << "Enter a string: ";
   cin >> userInput;
   // Loop through string and insert into
   // LinkedList type char
   for ( char c : userInput )
      charList.add( c );

   // Display the items
   charList.display(cout);
   cout << endl;
   // Search for substrings
   charList.substring('A', 'B');
   return 0;
}
