/****************************************
 *
 * Title: CST 370 Assignment 6
 * Abstract: Modify InsertionSort into CoolSort!
 * Author: Robert Contreras
 * ID: cont5739
 * Date: Tuesday, Feb 16
 *
 ****************************************/
#include <iostream>
using namespace std;

// Method definitions
void InsertionSort( int array[], int arraySize );
void CoolSort( int array[], int arraySize, int gap );
void printArray( int array[], int arraySize );

int main() {

   // Array for InsertionSort
   int sortArray[] = {2, 5, 6, 4, 10, 9, 8, 1, 10, 5};
   // Array for CoolSort
   int coolSortArray[] = {62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28};
   int gapArray[] = {5, 3, 1};

   // Test InsertionSort
   cout << "InsertionSort() Run:" << endl;
   cout << "Before: ";
   printArray(sortArray, 10);
   cout << "After: ";
   InsertionSort(sortArray, 10);
   printArray(sortArray, 10);

   // Test Cool Sort on base case
   cout << endl << "CoolSort() Run:" << endl;
   cout << "H =  ";
   printArray(gapArray, 3);

   for ( int i : gapArray )
   {
      CoolSort(coolSortArray, 12, i);
      cout << "H = " << i << "  ";
      printArray(coolSortArray, 12);
   }

   // Run CoolSort on sample case 1
   cout << endl << "Sample Test Case 1:" << endl;
   gapArray[0] = 5;
   gapArray[1] = 3;
   gapArray[2] = 1;

   int sampleArray1[] = {2, 5, 6, 4, 10, 9, 8, 1, 10, 5};

   cout << "Before: ";
   printArray(sampleArray1, 10);

   cout << "H =  ";
   printArray(gapArray, 3);

   for ( int i : gapArray )
   {
      CoolSort(sampleArray1, 10, i);
      cout << "H = " << i << "  ";
      printArray(sampleArray1, 10);
   }

   // Run CoolSort on sample case 2
   cout << endl << "Sample Test Case 2:" << endl;
   gapArray[1] = 2;
   int sampleArray2[] = {2, 5, 9, 4, 10, 7, 8, 1, 11, 5};

   cout << "Before: ";
   printArray(sampleArray2, 10);

   cout << "H =  ";
   printArray(gapArray, 3);

   for ( int i : gapArray )
   {
      CoolSort(sampleArray2, 10, i);
      cout << "H = " << i << "  ";
      printArray(sampleArray2, 10);
   }

   return 0;
}

// InsertionSort algorithm
void InsertionSort( int array[], int arraySize )
{
   int value, i, j;
   for (i = 0; i < arraySize ; i++)
   {
      value = array[i];
      j = i - 1;
      while ( j >= 0 && array[j] > value )
      {
         array[j + 1] = array[j];
         j = j - 1;
      }
      array[j + 1] = value;
   }
}

// Modified InsertionSort to create CoolSort
void CoolSort( int array[], int arraySize, int gap )
{
   // Extra variable h for outter loop
   int value, h, i, j;

   // Outter loop to process each element
   for ( h = 0; h < arraySize ; h++ )
   {
      // Inner loop process elements with gap added
      for ( i = h ; i < arraySize ; i = i + gap )
      {
         // Store current value from array
         value = array[i];
         // Set the couter for the final inner loop
         j = i - gap;
         // This loop handles the insertion
         while ( j >= 0 && array[j] > value )
         {
            // Swap values
            array[j + gap] = array[j];
            // Set j back to the previous location
            j = j - gap;
         }
         // Set the array value
         array[j + gap] = value;
      }
   }
}

// Method to print the array
void printArray(int array[], int arraySize)
{
   cout << "[";
   for (int i = 0; i < arraySize; i++)
   {
      if ( i != arraySize - 1)
         cout << array[i] << ",";
      else
         cout << array[i];
   }
   cout << "]" << endl;
}
