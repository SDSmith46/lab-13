#if !defined HEAPSKEW_H
#define HEAPSKEW_H

#include "BinaryTree.h"
#include "wx/wx.h"
#include <iostream>
using namespace std;

template < class T >
class HeapSkew : public Drawable
{

   private:
      BinaryTree<T>* bt;
      int sze;
      BinaryTree<T>* merge(BinaryTree<T>* left, BinaryTree<T>* right);

      int (*compare_items) (T* item_1, T* item_2);

   public:
      HeapSkew(int (*comp_items) (T* item_1, T* item_2));
      ~HeapSkew();

      bool heapIsEmpty();
      void heapInsert(T* item);
      T* heapRemove();

      void draw(wxDC& dc, int width, int height);
      void mouseClicked(int x, int y);

};

// this is a MAXHEAP (largest items to top alphabetical order)
template < class T >
HeapSkew<T>::HeapSkew(int (*comp_items) (T* item_1, T* item_2)) : Drawable()
{ 
   bt = new BinaryTree<T>();
   sze = 0;

   compare_items = comp_items;
}

template < class T >
HeapSkew<T>::~HeapSkew() 
{ 
   delete bt;
}  

template < class T >
bool HeapSkew<T>::heapIsEmpty()
{
   return sze == 0;
}

template < class T >
BinaryTree<T>* HeapSkew<T>::merge(BinaryTree<T>* left, BinaryTree<T>* right)
{
	if (left ==  NULL)
	{
		return right;
	}
	else if (right == NULL)
	{
		return left;
	}
	int comp = compare_items(left->getRootItem(), right->getRootItem());
	if (comp == 1)
	{
		merge(right, left);
	}
	BinaryTree<T>* LL = left->detachLeftSubtree();
	BinaryTree<T>* LR = left->detachRightSubtree();
	//left->setRight(NULL);
	left->attachRightSubtree(LL);
	if (LR == NULL)
	{
		LL->attachLeftSubtree(right);
	}
	else
	{
		left->attachLeftSubtree(merge(LR,right));
		return left;
	}
	
}

template < class T >
void HeapSkew<T>::heapInsert(T* item)
{
	BinaryTree<T>* right = new BinaryTree<T>(item);
	cout << 89 << endl;
	bt = merge(bt,right);
	cout << 91 << endl;
}

template < class T >
T* HeapSkew<T>::heapRemove()
{
	bt = merge(bt->detachLeftSubtree(), bt->detachRightSubtree());
}

template < class T >
void HeapSkew<T>::draw(wxDC& dc, int width, int height)
{
   bt->draw(dc, width, height);
}

template < class T >
void HeapSkew<T>::mouseClicked(int x, int y) {bt->mouseClicked(x, y);}

#endif
