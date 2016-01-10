#include <iostream>
using namespace std;

#include "LinkedList.h"

int main()
{
   

   // Test the class constructor
   LinkedList<int> intList;
   cout << "Constructing intList\n";

   // Test insert()
   intList.insert(100, 0);
   intList.display(cout);
   cout << endl;
   cout << "Total Sum: " << intList.sum() << endl;

   intList.insert(200, 0);
   intList.display(cout);
   cout << endl;
   cout << "Total Sum: " << intList.sum() << endl;

   intList.insert(300, 1);
   intList.display(cout);
   cout << endl;
   cout << "Total Sum: " << intList.sum() << endl;

   intList.insert(400, 1);
   intList.display(cout);
   cout << endl;
   cout << "Total Sum: " << intList.sum() << endl;

   intList.insert(500, 3);
   intList.display(cout);
   cout << endl;

   cout << "\nMax Element: " << intList.maxItem() << endl;

   cout << "Total Sum: " << intList.sum() << endl;

   // Test destructor
   {
      LinkedList<int> anotherList;
      for (int i = 0; i < 10; i++)
      {
         anotherList.insert(100*i, i);
      }
      cout << "\nThis is another list\n";
      anotherList.display(cout);
      cout << "\nMax Element: " << anotherList.maxItem() << endl;
   }

   // Test erase
   intList.erase(1);
   intList.erase(1);
   cout << "\n\nTwo items are erased from the first list\n";
   intList.display(cout);
   cout << endl;

   cout << "Total Sum: " << intList.sum() << endl;

   //Programming Assignment (Linked List)
   LinkedList<char> charList;
   string userInput;

   cout << "Enter a string: ";
   cin >> userInput;
   for ( char c : userInput )
      charList.add( c );

   charList.display(cout);
   cout << endl;
   charList.substring('A', 'B');
}
