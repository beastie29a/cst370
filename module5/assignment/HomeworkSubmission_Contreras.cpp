/****************************************
*
* Title: CST 370 Assignment 5
* Abstract: Use a selection sort algorithm
*    to manipulate arrays
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Feb 9
*
****************************************/
#include <iostream>
#include <array>
using namespace std;

// Define methods
void selectionSort( int, int[], int );
void printArray( int[], int );
double getMedianValue( int[], int );

int main()
{
   // Init arrays and sizes
   int arraySize1 = 10;
   int arraySize2 = 11;
   int toBeSorted1[10] = {4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
   int toBeSorted2[11] = {4, 6, 8, 15, 20, 22, 10, 3, 9, 2, -4};

   // Part 1

   // Array 1 Before
   cout << "Array 1 before sort: ";
   printArray(toBeSorted1, arraySize1);
   selectionSort(arraySize1, toBeSorted1, arraySize1);
   // Array 1 After
   cout << "Array 1 After sort: ";
   printArray(toBeSorted1, arraySize1);

   // Array 2 Before
   cout << "Array 2 before sort: ";
   printArray(toBeSorted2, arraySize2);
   selectionSort(arraySize2, toBeSorted2, arraySize2);
   // Array 2 After
   cout << "Array 2 After sort: ";
   printArray(toBeSorted2, arraySize2);

   // Part 2
   cout << "Re-initializing arrays..." << endl;
   toBeSorted1[0] = 4;
   toBeSorted1[1] = 6;
   toBeSorted1[2] = 8;
   toBeSorted1[3] = 15;
   toBeSorted1[4] = 20;
   toBeSorted1[5] = 22;
   toBeSorted1[6] = 10;
   toBeSorted1[7] = 3;
   toBeSorted1[8] = 9;
   toBeSorted1[9] = 2;

   toBeSorted2[0] = 4;
   toBeSorted2[1] = 6;
   toBeSorted2[2] = 8;
   toBeSorted2[3] = 15;
   toBeSorted2[4] = 20;
   toBeSorted2[5] = 22;
   toBeSorted2[6] = 10;
   toBeSorted2[7] = 3;
   toBeSorted2[8] = 9;
   toBeSorted2[9] = 2;
   toBeSorted2[10] = -4;
   int getK;

   // Get input from user with validation
   do {
      cout << "Enter the amount of elements to sort: ";
      cin >> getK;
      cin.clear();
      cin.ignore(INT_MAX, '\n');
   } while ( ( getK > arraySize1 || getK > arraySize2 ) || getK < 1 );

   cout << "First " << getK << " elements of Array 1: ";
   selectionSort(getK, toBeSorted1, arraySize1);
   printArray(toBeSorted1, getK);

   cout << "First " << getK << " elements of Array 2: ";
   selectionSort(getK, toBeSorted2, arraySize2);
   printArray(toBeSorted2, getK);

   // Part 3
   cout << "Mediam Element of Array 1 is: ";
   cout << getMedianValue(toBeSorted1, arraySize1) << endl;

   cout << "Mediam Element of Array 2 is: ";
   cout << getMedianValue(toBeSorted2, arraySize2) << endl;
   return 0;

}

// selection algorithm
void selectionSort( int numElements, int sortArray[], int arraySize )
{
   int min, swapMin = 0;

   for ( int i = 0 ; i < numElements ; i++ )
   {
      min = i;
      for ( int j = i + 1 ; j < arraySize ; j++)
      {
         if ( sortArray[j] < sortArray[min] )
         {
            min = j;
         }
      }
      swapMin = sortArray[i];
      sortArray[i] = sortArray[min];
      sortArray[min] = swapMin;
   }
}

// method to print contents of array
void printArray( int sortArray[], int printElements )
{
   for (int i = 0 ; i < printElements ; i++)
   {
      if ( i == printElements - 1 )
         cout << sortArray[i];
      else
         cout << sortArray[i] << ", ";
   }
   cout << endl;
}

// method to get the median value of an array
double getMedianValue( int sortArray[], int arraySize )
{
   // Sort array partially using Problem 2 logic
   selectionSort( arraySize/2 + 1, sortArray, arraySize );
   // Check if array is even
   if ( arraySize%2 == 0 )
   {
      // Return average of 2 median values
      return double(sortArray[arraySize/2] + sortArray[arraySize/2 - 1])/2;
   }
   // Return median value
   return sortArray[arraySize/2];
}
