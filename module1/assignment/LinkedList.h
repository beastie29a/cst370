/****************************************
*
* Title: CST 370 Programming Assignment 1
* Abstract: Program to find substring
* Author: Robert Contreras
* ID: cont5739
* Date: Tuesday, Jan 12
*
****************************************/
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef char ElementType;

class LinkedList
{
public:
	LinkedList();   // constructor
	~LinkedList();  // destructor
	LinkedList(const LinkedList & original); //copy constructor
	void insert(ElementType item, int pos);
	void erase(int index);

	void display(ostream & out) const;
	/*--------------------------------------------------------------------
	Display the contensts of this LinkedList.
	Precondition: ostream out is open
	Postcondition: Elements of this LinkedList have been output to out.
	--------------------------------------------------------------------*/

        void add(ElementType item); // Add to the end of the list
        void substring(char a, char b); // Search for substrings

private:
	class Node
	{
	public:
		ElementType data;
		Node * next;
		//------ Node OPERATIONS
		//-- Default constrctor: initializes next member to
		Node()
			: next(NULL)
		{ }
		//-- Explicit-value constructor: initializes data member to dataValue
		//-- and next member to 0
		Node(ElementType dataValue)
			: data(dataValue), next(NULL)
		{ }
	};
	Node * first;
	int mySize;
};

#endif
