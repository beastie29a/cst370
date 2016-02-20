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


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;

   if (item == locptr->data)
      return true;

   //call recursive function
   return search(item, locptr);
}

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

void BST::inOrder()
{
   BinNode * locptr = myRoot;
   if (locptr == NULL)
      return;
   inOrder(locptr);
}

void BST::inOrder(BinNode * locptr)
{
   if(locptr == NULL)
      return;
   inOrder(locptr->left);
   cout << locptr->data << ", ";
   inOrder(locptr->right);

}

void BST::preOrder()
{
   BinNode * locptr = myRoot;
   if (locptr == NULL)
      return;
   preOrder(locptr);
}

void BST::preOrder(BinNode * locptr)
{
   if(locptr == NULL)
      return;

   cout << locptr->data << ", ";
   preOrder(locptr->left);
   preOrder(locptr->right);

}

int BST::nodeCount()
{
   nodes = 0;
   BinNode * locptr = myRoot;
   if (locptr == NULL)
      return -1;

   return nodeCount(locptr);
}

int BST::nodeCount(BinNode * locptr)
{
   if(locptr == NULL)
      return nodes;

   nodes++;
   nodeCount(locptr->left);
   nodeCount(locptr->right);
   return nodes;
}