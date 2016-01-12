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

   cout << "Enter a string: ";
   cin >> userInput;
   for ( char c : userInput )
      charList.add( c );

   charList.display(cout);
   cout << endl;
   charList.substring('A', 'B');
}
