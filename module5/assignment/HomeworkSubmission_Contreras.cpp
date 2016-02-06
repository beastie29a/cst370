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
   int arraySize = 11;
   int toBeSorted[11] = {4, 6, 8, 15, 20, 22, 10, 3, 9, 2, -4};

   // Array Before
   printArray(toBeSorted, arraySize);
   selectionSort(arraySize, toBeSorted, arraySize);
   // Array After
   printArray(toBeSorted, arraySize);

   // Part 2
   toBeSorted[0] = 4;
   toBeSorted[1] = 6;
   toBeSorted[2] = 8;
   toBeSorted[3] = 15;
   toBeSorted[4] = 20;
   toBeSorted[5] = 22;
   toBeSorted[6] = 10;
   toBeSorted[7] = 3;
   toBeSorted[8] = 9;
   toBeSorted[9] = 2;
   toBeSorted[10] = -4;
   int getK;

   cout << "Enter the amount of elements to sort: ";
   cin >> getK;

   selectionSort(getK, toBeSorted, arraySize);
   printArray(toBeSorted, getK);

   // Part 3
   cout << "Mediam Element is: ";
   cout << getMedianValue(toBeSorted, arraySize) << endl;
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
   if ( arraySize%2 == 0 )
   {
      return double(sortArray[arraySize/2] + sortArray[arraySize/2 + 1])/2;
   }
   return sortArray[arraySize/2];
}
