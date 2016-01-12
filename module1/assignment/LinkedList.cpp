/****************************************
*
* Title: CST 370 Programming Assignment 1
* Abstract: Program to find substring
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

//-- Definition of add()
void LinkedList::add(ElementType dataVal)
{
   (*this).insert(dataVal,mySize);
}

//-- Definition of substring()
void LinkedList::substring( char c1, char c2 )
{
   Node * predPtr1 = first;
   Node * predPtr2 = first;
   string outString;
   int count = 0;

   // Loop can end one less than mySize
   for ( int i = 0; i < mySize - 1; i++)
   {
      if ( c1 == predPtr1->data )
      {
         outString = predPtr1->data; 
         predPtr2 = predPtr1->next;
         for ( int j = i + 1; j < mySize; j++)
         {
            if ( c2 == predPtr2->data)
            {
               count++;
               outString += predPtr2->data;
               cout << "Substring " << count << ":" << outString << endl;
            }
            else
               outString += predPtr2->data;
            predPtr2 = predPtr2->next;
         }
      }
      predPtr1 = predPtr1->next;
   }
   cout << "Total " << count << " substrings";
}
