#include <iostream>
using namespace std;

#include "LinkedList.h"

//-- Default constructor
template <class T>
LinkedList<T>::LinkedList()
{
   mySize = 0;
   first = NULL;
}

//-- Definition of the copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList & origList)
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
template <class T>
LinkedList<T>::~LinkedList()
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
template <class T>
void LinkedList<T>::insert(T dataVal, int index)
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
template <class T>
void LinkedList<T>::erase(int index)
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
template <class T>
void LinkedList<T>::display(ostream & out) const
{
   Node * ptr = first;
   while (ptr != 0)
   {
      out << ptr->data << " ";
      ptr = ptr->next;
   }
}

//-- Definition of sum()
template <class T>
ElementType LinkedList<T>::sum()
{
   ElementType total = 0;
   Node * predPtr = first;

   for( int i = 0; i < mySize; i++)
   {
      total += predPtr->data;
      predPtr = predPtr->next;
   }

   return total;
}
template <class T>
T LinkedList<T>::maxItem()
{
   T maxElement = 0;
   Node * predPtr = first;

   for( int i = 0; i < mySize; i++)
   {
      if ( maxElement < predPtr->data )
         maxElement = predPtr->data;

      predPtr = predPtr->next;
   }
   return maxElement;

}