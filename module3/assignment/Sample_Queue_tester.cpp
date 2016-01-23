/****************************************
*
* Title: CST 370 Assignment 3
* Abstract: Use a queue and stack to check for palindromes
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 26
*
****************************************/
#include <iostream>
using namespace std;

#include "Queue.h"
#include "Stack.h"

int main()
{
   Queue q1;
   Stack s1;

   string myInput;

   // Get word from user
   cout << "Enter a word to check if it is a palindrome: ";
   cin >> myInput;

   // Add the opjects to each structure
   for ( char c : myInput )
   {
      q1.enqueue(c);
      s1.push(c);
   }

   // Loop through structure
   while( !q1.empty() )
   {
      // Compare beginning of queue with top of stack
      if ( q1.front() == s1.top() )
      {
         q1.dequeue();
         s1.pop();
      }
      // Any non-matches makes this not a palindrome
      else
      {
         cout << "Not a palindrome!" << endl;
         exit(1);
      }
   }

   cout << "Is a palindrome!" << endl;
   return 0;
}
