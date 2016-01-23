#include <iostream>
using namespace std;

#include "Queue.h"
#include "Stack.h"

int main()
{
   Queue q1;
   Stack s1;

   string myInput;

   cout << "Enter a word to check if it is a palindrome: ";
   cin >> myInput;

   for ( char c : myInput )
   {
      q1.enqueue(c);
      s1.push(c);
   }

   while( !q1.empty() )
   {
      if ( q1.front() == s1.top() )
      {
         q1.dequeue();
         s1.pop();
      }
      else
      {
         cout << "Not a palindrome!" << endl;
         exit(1);
      }
   }

   cout << "Is a palindrome!" << endl;
   return 0;
}
