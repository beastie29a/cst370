/****************************************
 *
 * Title: CST 370 Final
 * Abstract: Parts 1 and 2
 * Author: Robert Contreras
 * ID: cont5739
 * Date: Saturday, February 27th
 *
 ****************************************/

#include <iostream>
#include "LinkedList.h"

void insertArrayToLinkedList( int[], int, LinkedList &);
int findOccurences( int[], int, int );

int main()
{
   // Final Question 1
   int arraySize = 5;
   int unsortedArray[5] = {15, 20, 30, 7, 8};
   LinkedList myList;

   std::cout << "Inserting Array into LinkedList" << std::endl;
   insertArrayToLinkedList(unsortedArray, arraySize, myList);

   myList.display(std::cout);
   std::cout << std::endl;
   myList.BubbleSort();

   myList.display(std::cout);

   // Final question 2

   arraySize = 17;
   int binArray[] = {1, 1, 2, 2, 5, 5, 5, 5, 5, 5, 5, 8, 8, 9, 10, 11, 11 };
   int value = 5;


   std::cout << std::endl << findOccurences(binArray, arraySize, value);
   std::cout << std::endl;


   return 0;

}

void insertArrayToLinkedList( int array[], int arraySize, LinkedList  &myList )
{
   for ( int i = arraySize - 1; i >= 0 ; i-- )
   {
      myList.insert(array[i], 0);
   }
}

int findOccurences( int array[], int arraySize, int value )
{
   int i = 0;
   int j = arraySize;
   int mid = 0;
   int count = 0;
   while ( i < j )
   {
      mid = (i + j)/2;
      if ( value == array[mid] )
      {
         return ++count;
      }
      else if ( value < array[mid] )
         j = mid - 1;
      else
         i = mid + 1;
   }
   return count;
}