//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef int ElementType;

template <class T>
class LinkedList
{
public:
   LinkedList<T>();   // constructor
   ~LinkedList<T>();  // destructor
   LinkedList<T>(const LinkedList & original); //copy constructor
   void add(T item); // Add to the end of the list
   void insert(T item, int pos);
   void erase(int index);

   void display(ostream & out) const;
   ElementType sum();
   ElementType maxItem();
   bool isAscendingOrder();
   void substring(char a, char b);
   /*--------------------------------------------------------------------
    Display the contensts of this LinkedList.
    Precondition: ostream out is open
    Postcondition: Elements of this LinkedList have been output to out.
    --------------------------------------------------------------------*/

private:
   class Node
   {
   public:
      T data;
      Node * next;
      //------ Node OPERATIONS
      //-- Default constrctor: initializes next member to
      Node()
      : next(NULL)
      { }
      //-- Explicit-value constructor: initializes data member to dataValue
      //-- and next member to 0
      Node(T dataValue)
      : data(dataValue), next(NULL)
      { }
   };
   Node * first;
   int mySize;
};

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

//-- Definition of add()
template <class T>
void LinkedList<T>::add(T dataVal)
{
   (*this).insert(dataVal,mySize);
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
ElementType LinkedList<T>::maxItem()
{
   T maxElement = 0;
   Node * predPtr = first;

   if ( mySize == 1 )
      return predPtr->data;

   if ( mySize == 0 )
      return -1;

   for( int i = 0; i < mySize; i++)
   {
      if ( maxElement < predPtr->data )
         maxElement = predPtr->data;

      predPtr = predPtr->next;
   }
   return maxElement;
   
}

template <class T>
bool LinkedList<T>::isAscendingOrder()
{
   Node * predPtr = first;

   if ( mySize <= 1 )
      return true;

   for( int i = 0; i < mySize; i++)
   {
      if ( predPtr->data > predPtr->next->data )
         return false;
      predPtr = predPtr->next;
   }
   return true;
}

template <class T>
void LinkedList<T>::substring( char a, char b )
{
   Node * predPtr1 = first;
   Node * predPtr2 = first;
   string outString;
   int count = 0;

   for ( int i = 0; i < mySize; i++)
   {
      outString = "A";
      if ( a == predPtr1->data )
      {
         predPtr2 = predPtr1->next;
         for ( int j = i+1; j < mySize; j++)
         {
            if ( b == predPtr2->data)
            {
               count++;
               outString += "B";
               cout << "Substring " << count << ":" << outString << endl;
            }
            outString += predPtr2->data;
            predPtr2 = predPtr2->next;

         }
      }
      predPtr1 = predPtr1->next;
   }
   cout << "Total " << count << " substrings";

}

#endif