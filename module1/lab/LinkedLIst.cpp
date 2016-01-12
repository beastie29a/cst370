/****************************************
*
* Title: CST 370 Lab 1
* Abstract: Program to look for maxItem and
*           to see if list is ascending order
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 12
*
****************************************/ 

#include <iostream>
using namespace std;

#include "LinkedList.h"

//-- Default constructor
LinkedList::LinkedList()
{ 
	mySize = 0;
	first = NULL;
}

//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;
	
	if (mySize == 0) 
		return;

	Node * origPtr, * lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}


//-- Definition of the destructor
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;

	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}
}


//-- Definition of erase()
void LinkedList::erase(int index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}

	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for(int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}



//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}

//-- Definition of maxItem()
ElementType LinkedList::maxItem()
{
   ElementType maxElement = 0;
   Node * predPtr = first;

   // Retun the only element
   if ( mySize == 1 )
      return predPtr->data;

   // Return -1 if no items
   if ( mySize == 0 )
      return -1;

   for( int i = 0; i < mySize; i++)
   {
      // Check if current item is less than
      // Assign to maxElement if so
      if ( maxElement < predPtr->data )
         maxElement = predPtr->data;
      // move pointer to next node
      predPtr = predPtr->next;
   }
   return maxElement;
}

//-- Definition of isAscendingOrder()
bool LinkedList::isAscendingOrder()
{
   Node * predPtr = first;

   // size less than 1 return true
   if ( mySize <= 1 )
      return true;

   for( int i = 0; i < mySize; i++)
   {
      // Check if current node data is greater than
      // next nodes data
      if ( predPtr->data > predPtr->next->data )
         return false;
      predPtr = predPtr->next;
   }
   return true;
}
