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

// Method definitions
bool LinearSearch( int array[], int arraySize, int value);
bool IterBinarySearch( int array[], int arraySize, int value);
bool RecursiveBinarySearch( int array[], int arraySize, int value);
bool RecursiveBinarySearch( int array[], int left, int right, int value);

int main() {

   int arraySize = 9;
   int ascendingArray[] = {1, 3, 5, 7, 11, 13, 17, 19, 23};

   // Call bool LinearSearch function to locate 19
   if ( LinearSearch(ascendingArray, arraySize, 19) )
      cout << "Found 19 in Linear Search" << endl;

   // Call bool Interative Binary Search function to locate 13
   if ( IterBinarySearch(ascendingArray, arraySize, 13) )
      cout << "Found 13 in the Iterative Binary Search" << endl;

   // Call bool Recursive Binary Search function to locate 7
   if ( RecursiveBinarySearch(ascendingArray, arraySize, 7) )
      cout << "Found 7 in the Recursive Binary Search" << endl;

   return 0;
}

// Linear Search method
bool LinearSearch( int array[], int arraySize, int value)
{
   // Loop through array to locate element
   for (int i = 0; i < arraySize; i++)
   {
      if ( value == array[i] )
         return true;
   }

   return false;
}

// Iterative Binary Search
bool IterBinarySearch( int array[], int arraySize, int value)
{
   // Setup the values for the search
   int mid, left = 0, right = arraySize - 1;

   // Loop through until the left location is equal to the right
   while ( left <= right )
   {
      // Get the middle elememnt
      mid = (right + left)/2;
      // First case see if mid element is equal to the value
      if ( array[mid] == value )
         return true;
      // Check if mid element is greater then the value
      else if ( array[mid] > value )
      {
         // Change the end of the array search
         right = mid - 1;
      }
      // Else element is less than the value
      else
      {
         // Change the begining of the array search
         left = mid + 1;
      }
   }
   return false;
}

bool RecursiveBinarySearch( int array[], int arraySize, int value)
{
   // Setup the values
   int mid = arraySize/2, left = 0, right = arraySize - 1;

   // First case see if mid element is equal to the value
   if ( array[mid] == value )
      return true;

   // Execute the recursive method
   return RecursiveBinarySearch(array, value, left, right);
}

bool RecursiveBinarySearch( int array[], int value, int left, int right)
{
   // Setup the midpoint
   int mid = (right + left)/2;

   // Check if value is less than
   if ( array[mid] > value )
   {
      // Run the Recursive Method with a shorter end of array
      return RecursiveBinarySearch( array, value, left, mid - 1);
   }
   // Check if value is greater than
   else if ( array[mid] < value )
   {
      // RUn the Recursieve Method with the beginning moved one past mid
      return RecursiveBinarySearch( array, value, mid + 1, right);
   }

   // Not less than or greater so must be equal
   return true;
}
