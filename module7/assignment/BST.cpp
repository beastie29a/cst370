#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }

// Method for search, calls recursive search
bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;

   if (item == locptr->data)
      return true;

   //call recursive function
   return search(item, locptr);
}

// Recursive method for search
bool BST::search(const int & item, BinNode * locptr) const
{
   // If pointer is invalid return false
   if (locptr == NULL)
      return false;

   if (item < locptr->data)       // descend left
      return search(item, locptr->left);
   else if (locptr->data < item)  // descend right
      return search(item, locptr->right);
   else                           // item found
      return true;

}

void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

// inOrder method client call
void BST::inOrder()
{
   BinNode * locptr = myRoot;
   if (locptr == NULL) // No node here
      return;

   inOrder(locptr); // call recursive search
}

// inOrder private recursive method
void BST::inOrder(BinNode * locptr)
{
   if(locptr == NULL) // No node here
      return;

   inOrder(locptr->left); // decend left
   cout << locptr->data << ", "; // print node value
   inOrder(locptr->right); // decend right

}

// preOrder method client call
void BST::preOrder()
{
   BinNode * locptr = myRoot;
   if (locptr == NULL) // No node here
      return;

   preOrder(locptr); // call recursive method
}

// preOrder private recursive method
void BST::preOrder(BinNode * locptr)
{
   if(locptr == NULL) // No node here
      return;

   cout << locptr->data << ", "; // print node value
   preOrder(locptr->left); // decend left
   preOrder(locptr->right); // decend right

}

// nodeCount method client call
int BST::nodeCount()
{
   int nodes = 0;
   BinNode * locptr = myRoot;
   if (locptr == NULL) // No node here
      return -1;

   return nodeCount(locptr, nodes); // call recursive method
}

// nodeCount private recursive method
int BST::nodeCount(BinNode * locptr, int nodes)
{
   if(locptr == NULL) // No node here
      return nodes;

   nodes++; // Increment count
   nodes = nodeCount(locptr->left, nodes); // decend left
   nodes = nodeCount(locptr->right, nodes); // decend right
   return nodes; // return final count
}
