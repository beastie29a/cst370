//
//  main.cpp
//  CST370-module5
//
//  Created by Robert Contreras on 2/5/16.
//  Copyright © 2016 Robert Contreras. All rights reserved.
//

#include <iostream>
#include <array>
using namespace std;

void selectionSort( int, int[], int );
void printArray( int[], int );
double getMedianValue( int[], int );

int main()
{
   int arraySize1 = 10;
   int arraySize2 = 11;
   int toBeSorted1[10] = {4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
   int toBeSorted2[11] = {4, 6, 8, 15, 20, 22, 10, 3, 9, 2, -4};

   // Array 1 Before
   printArray(toBeSorted1, arraySize1);
   selectionSort(arraySize1, toBeSorted1, arraySize1);
   // Array 1 After
   printArray(toBeSorted1, arraySize1);

   // Array 2 Before
   printArray(toBeSorted2, arraySize2);
   selectionSort(arraySize2, toBeSorted2, arraySize2);
   // Array 2 After
   printArray(toBeSorted2, arraySize2);

   // Part 2
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

   cout << "Enter the amount of elements to sort: ";
   cin >> getK;

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

void printArray( int sortArray[], int printElements )
{
   for (int i = 0 ; i < printElements ; i++)
      cout << sortArray[i] << ",";
   cout << endl;
}

double getMedianValue( int sortArray[], int arraySize )
{
   selectionSort( arraySize, sortArray, arraySize);
   if ( arraySize%2 == 0 )
   {
      return double(sortArray[arraySize/2] + sortArray[arraySize/2 - 1])/2;
   }
   return sortArray[arraySize/2];
}
