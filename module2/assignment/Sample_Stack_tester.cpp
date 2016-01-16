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
#include "Stack.hpp"

using namespace std;

void checkStack( int element, Stack* one, Stack* two)
{
   if ( element >= two->top() || two->empty())
      two->push(element);
   else
   {
      one->push(two->top());
      two->pop();
      checkStack(element, one, two);
   }
}

void checkStack( Stack* one, Stack* two)
{
   int element;

   while (!one->empty())
   {
      element = one->top();
      one->pop();
      checkStack(element, one, two);
   }
}

int main() {

   Stack assignmentStack1;
   Stack assignmentStack2;

   assignmentStack1.push(1);
   assignmentStack1.push(5);
   assignmentStack1.push(3);
   assignmentStack1.push(-3);
   assignmentStack1.push(4);
   assignmentStack1.push(8);
   assignmentStack1.push(10);
   assignmentStack1.push(-5);

   checkStack(&assignmentStack1, &assignmentStack2);

   assignmentStack1.display(cout);
   cout << endl;
   assignmentStack2.display(cout);
   cout << endl;

   Stack assignmentStack3;

   assignmentStack1.push(1);
   assignmentStack1.push(5);
   assignmentStack1.push(-4);
   assignmentStack1.push(6);
   assignmentStack1.push(2);

   checkStack(&assignmentStack1, &assignmentStack3);

   assignmentStack1.display(cout);
   cout << endl;
   assignmentStack3.display(cout);
   cout << endl;

   Stack assignmentStack4;
   assignmentStack1.push(1);
   assignmentStack1.push(-4);
   assignmentStack1.push(-4);
   assignmentStack1.push(6);
   assignmentStack1.push(6);
   assignmentStack1.push(9);

   checkStack(&assignmentStack1, &assignmentStack4);

   assignmentStack1.display(cout);
   cout << endl;
   assignmentStack4.display(cout);
   cout << endl;

}
