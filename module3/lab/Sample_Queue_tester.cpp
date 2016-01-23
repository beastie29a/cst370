#include <iostream>
using namespace std;

#include "Queue.h"

int main()
{
   Queue q1;
   string parseMe = "This part is the beginning. {This part is the footnote.} This part is the end.";
   bool store = false;

   for ( char c : parseMe )
   {
      if ( c == '{' || store == true )
      {
         if ( c == '}' )
            store = false;
         else if ( c == '{' )
            store = true;
         else
            q1.enqueue(c);
      }
   }
   q1.display(cout); 
   cout << endl; 
   return 0;
}
