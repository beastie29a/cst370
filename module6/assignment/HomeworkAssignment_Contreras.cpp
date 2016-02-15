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

void InsertionSort( int array[], int arraySize );
void CoolSort( int array[], int arraySize, int gap );
void printArray( int array[], int arraySize );

int main() {

   int sortArray[] = {2, 5, 6, 4, 10, 9, 8, 1, 10, 5};
   int coolSortArray[] = {62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28};
   int gapArray[] = {5, 3, 1};

   InsertionSort(sortArray, 10);

   printArray(sortArray, 10);

   cout << endl << "CoolSort() Run:" << endl;
   cout << "H =  ";
   printArray(gapArray, 3);

   for ( int i : gapArray )
   {
      CoolSort(coolSortArray, 12, i);
      cout << "H = " << i << "  ";
      printArray(coolSortArray, 12);
   }

   cout << endl << "Sample Test Case 1:" << endl;
   gapArray[0] = 5;
   gapArray[1] = 3;
   gapArray[2] = 1;

   int sampleArray1[] = {2, 5, 6, 4, 10, 9, 8, 1, 10, 5};

   cout << "H =  ";
   printArray(gapArray, 3);

   for ( int i : gapArray )
   {
      CoolSort(sampleArray1, 10, i);
      cout << "H = " << i << "  ";
      printArray(sampleArray1, 10);
   }

   cout << endl << "Sample Test Case 2:" << endl;
   gapArray[1] = 2;
   int sampleArray2[] = {2, 5, 9, 4, 10, 7, 8, 1, 11, 5};
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

void CoolSort( int array[], int arraySize, int gap )
{
   int value, h = 0, i, j;
   while ( h < arraySize)
   {
      for ( i = h ; i < arraySize ; i = i + gap)
      {
         value = array[i];
         j = i - gap;
         while ( j >= 0 && array[j] > value )
         {
            array[j + gap] = array[j];
            j = j - gap;
         }
         array[j + gap] = value;
      }
      h++;
   }
}

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
