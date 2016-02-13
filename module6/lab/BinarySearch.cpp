/****************************************
*
* Title: CST 370 Lab 6
* Abstract: Create different search functions
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Feb 16
*
****************************************/
#include <iostream>
using namespace std;

bool LinearSearch( int array[], int arraySize, int value);

bool IterBinarySearch( int array[], int arraySize, int value);

bool RecursiveBinarySearch( int array[], int arraySize, int value);
bool RecursiveBinarySearch( int array[], int left, int right, int value);

int main() {

   int arraySize = 9;
   int ascendingArray[] = {1, 3, 5, 7, 11, 13, 17, 19, 23};

   if ( LinearSearch(ascendingArray, arraySize, 19) )
      cout << "Found 19 in Linear Search" << endl;

   if ( IterBinarySearch(ascendingArray, arraySize, 13) )
      cout << "Found 13 in the Iterative Binary Search" << endl;

   if ( RecursiveBinarySearch(ascendingArray, arraySize, 7) )
      cout << "Found 7 in the Recursive Binary Search" << endl;

   return 0;
}

bool LinearSearch( int array[], int arraySize, int value)
{
   for (int i = 0; i < arraySize; i++)
   {
      if ( value == array[i] )
         return true;
   }

   return false;
}


bool IterBinarySearch( int array[], int arraySize, int value)
{
   int mid, left = 0, right = arraySize - 1;

   while ( left <= right )
   {
      mid = (right + left)/2;
      if ( array[mid] == value )
         return true;
      else if ( array[mid] > value )
      {
         right = mid - 1;
      }
      else
      {
         left = mid + 1;
      }
   }
   return false;
}

bool RecursiveBinarySearch( int array[], int arraySize, int value)
{
   int mid = arraySize/2, left = 0, right = arraySize - 1;

   if ( array[mid] == value )
      return true;

   return RecursiveBinarySearch(array, value, left, right);
}

bool RecursiveBinarySearch( int array[], int value, int left, int right)
{
   int mid = (right + left)/2;

   if ( array[mid] == value )
      return true;
   else if ( array[mid] > value )
   {
      return RecursiveBinarySearch( array, value, left, mid - 1);
   }
   else
   {
      return RecursiveBinarySearch( array, value, mid + 1, right);
   }
   return false;
}
