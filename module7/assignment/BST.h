#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
public:
   /***** Function Members *****/
   BST();
   bool empty() const;
   bool search(const int & item) const;
   void insert(const int & item);

private:
   /***** Node class *****/
   class BinNode
   {
   public:
      int data;
      BinNode * left;
      BinNode * right;

      // BinNode constructors
      // Default -- data part is default int value; both links are null.
      BinNode()
      : left(0), right(0)
      {}

      // Explicit Value -- data part contains item; both links are null.
      BinNode(int item)
      : data(item), left(0), right(0)
      {}

   };// end of class BinNode declaration

   /***** Data Members *****/
   BinNode * myRoot;
   int nodes;

// Mothods for programming assignment
public:
   bool search(const int & item, BinNode * locptr) const;
   void inOrder();
   void inOrder(BinNode * locptr);
   void preOrder();
   void preOrder(BinNode * locptr);
   int nodeCount();
   int nodeCount(BinNode * locptr);
}; // end of class declaration

#endif
