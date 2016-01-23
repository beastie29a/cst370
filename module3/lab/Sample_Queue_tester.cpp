/****************************************
*
* Title: CST 370 Lab 3
* Abstract: Look for characters to indicate footnote
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 19
*
****************************************/
#include <iostream>
#include <fstream>
using namespace std;

#include "Queue.h"

int main()
{
   Queue q1;
   string parseMe;
   bool store = false;
   ifstream sample("sample.txt");

   // Check if file was opened correctly
   if (!sample.is_open())
   {
      cout << "Unable to open File";
      exit(1);
   }

   // Store the first line into a string
   getline(sample,parseMe);

   // Go through string and look for { to indicate footnote
   for ( char c : parseMe )
   {
      if ( c == '{' || store == true )
      {
         // Look for end char }
         if ( c == '}' )
            store = false;
         // Skip processing beginning char
         else if ( c == '{' )
            store = true;
         // Store footnote chars in a queue
         else
            q1.enqueue(c);
      }
   }
   // Output the footnote
   q1.display(cout); 
   cout << endl; 
   // Close the file
   sample.close();
   return 0;
}
