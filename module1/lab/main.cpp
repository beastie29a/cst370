/****************************************
*
* Title: CST 370 Lab 1
* Abstract: Program to look for maxItem and
*           to see if list is ascending order
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
   // Test the class constructor
   LinkedList intList;

   // Test Empty List
   cout << "\nMax Element: " << intList.maxItem() << endl;
   if ( intList.isAscendingOrder() )
      cout << "Ascending Order";
   else
      cout << "Not Ascending Order";
   cout << endl;

   cout << "Constructing intList\n";

   // Test insert()
   intList.insert(100, 0);
   intList.display(cout);
   // Tests for single element
   cout << "\nMax Element: " << intList.maxItem() << endl;
   if ( intList.isAscendingOrder() )
      cout << "Ascending Order";
   else
      cout << "Not Ascending Order";
   cout << endl;

   // Insert and test display
   intList.insert(200, 0);
   intList.display(cout);
   cout << endl;

   intList.insert(300, 1);
   intList.display(cout);
   cout << endl;

   intList.insert(400, 1);
   intList.display(cout);
   cout << endl;
   // Test if ascending order
   if ( intList.isAscendingOrder() )
      cout << "Ascending Order";
   else
      cout << "Not Ascending Order";
   cout << endl;

   intList.insert(500, 3);
   intList.display(cout);
   cout << endl;
   if ( intList.isAscendingOrder() )
      cout << "Ascending Order";
   else
      cout << "Not Ascending Order";
   cout << endl;

   // Test for the max element
   cout << "\nMax Element: " << intList.maxItem() << endl;

   // Test destructor
   {
      LinkedList anotherList;
      for (int i = 0; i < 10; i++)
      {
         anotherList.insert(100*i, i);
      }
      cout << "\nThis is another list\n";
      anotherList.display(cout);
      // Test max element again
      cout << "\nMax Element: " << anotherList.maxItem() << endl;
   }

   // Test erase
   intList.erase(1);
   intList.erase(1);
   cout << "\n\nTwo items are erased from the first list\n";
   intList.display(cout);
   // One more max element test
   cout << "\nMax Element: " << intList.maxItem() << endl;
   cout << endl;
}
