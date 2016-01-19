/****************************************
*
* Title: CST 370 Programming Assignment 2
* Abstract: Sort integers using 2 stacks
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 19
*
****************************************/

#include <iostream>
#include "Stack.h"

using namespace std;

// Recursive algorithm that is called from 
// the primary method call
void checkStack( int element, Stack* one, Stack* two)
{
   // Check if element is less than top element in
   // stack two
   if ( element >= two->top() || two->empty())
      two->push(element);
   else
   {
      // Move top element from stack two to one
      one->push(two->top());
      two->pop();
      // Make recursive call
      checkStack(element, one, two);
   }
}

// Primary checkStack method call
void checkStack( Stack* one, Stack* two)
{
   int element;

   // Loop through stack one until empty
   while (!one->empty())
   {
      // Assign top element in one to variable
      element = one->top();
      one->pop();
      // Make recursive call
      checkStack(element, one, two);
   }
}

int main() {

   // Declare stacks for first example
   Stack assignmentStack1;
   Stack assignmentStack2;

   // push values to first stack
   assignmentStack1.push(1);
   assignmentStack1.push(5);
   assignmentStack1.push(3);
   assignmentStack1.push(-3);
   assignmentStack1.push(4);
   assignmentStack1.push(8);
   assignmentStack1.push(10);
   assignmentStack1.push(-5);

   cout << "Displaying Stacks before sort -" << endl;
   cout << "Stack One: ";
   assignmentStack1.display(cout);
   cout << endl;
   cout << "Stack Two: ";
   assignmentStack2.display(cout);
   cout << endl;

   // Call the checkStack sorting method
   checkStack(&assignmentStack1, &assignmentStack2);

   cout << "After sort -" << endl;
   cout << "Stack One: ";
   assignmentStack1.display(cout);
   cout << endl;
   cout << "Stack Two: ";
   assignmentStack2.display(cout);
   cout << endl;

   // Declare new stack
   Stack assignmentStack3;

   // push values to first stack
   assignmentStack1.push(1);
   assignmentStack1.push(5);
   assignmentStack1.push(-4);
   assignmentStack1.push(6);
   assignmentStack1.push(2);

   cout << endl << "Displaying Stacks before sort -" << endl;
   cout << "Stack One: ";
   assignmentStack1.display(cout);
   cout << endl;
   cout << "Stack Two: ";
   assignmentStack3.display(cout);
   cout << endl;

   // Call the checkStack sorting method
   checkStack(&assignmentStack1, &assignmentStack3);

   cout << "After sort -" << endl;
   cout << "Stack One: ";
   assignmentStack1.display(cout);
   cout << endl;
   cout << "Stack Two: ";
   assignmentStack3.display(cout);
   cout << endl;

   // Declare new stack
   Stack assignmentStack4;

   // push values to first stack
   assignmentStack1.push(1);
   assignmentStack1.push(-4);
   assignmentStack1.push(-4);
   assignmentStack1.push(6);
   assignmentStack1.push(6);
   assignmentStack1.push(9);

   cout << endl << "Displaying Stacks before sort -" << endl;
   cout << "Stack One: ";
   assignmentStack1.display(cout);
   cout << endl;
   cout << "Stack Two: ";
   assignmentStack4.display(cout);
   cout << endl;

   // Call the checkStack sorting method
   checkStack(&assignmentStack1, &assignmentStack4);

   cout << "After sort -" << endl;
   cout << "Stack One: ";
   assignmentStack1.display(cout);
   cout << endl;
   cout << "Stack Two: ";
   assignmentStack4.display(cout);
   cout << endl;

}
