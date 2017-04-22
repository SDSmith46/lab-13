#if !defined HEAPSKEW_H
#define HEAPSKEW_H

#include "BinaryTree.h"
#include "wx/wx.h"

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
	int comp = comp_items(left->getRootItem(), right->getRootItem);
	if (comp == 1)
	{
		merge(right, left);
	}
	BinaryTree<T>* LL = left->getLeft();
	left->setLeft(NULL);
	BinaryTree<T>* LR = left->getRight();
	left->setRight(NULL);
	left->setRight(LL);
	if (LR == NULL)
	{
		LL->setLeft(right);
	}
	else
	{
		Left->setLeft(merge(LR,right));
		return left;
	}
	
}

template < class T >
void HeapSkew<T>::heapInsert(T* item)
{
	BinaryTree<T>* right = new BinaryTree(item);
	bt = merge(bt,right);
}

template < class T >
T* HeapSkew<T>::heapRemove()
{
	bt = merge(bt->getLeft(), bt->getRight());
}

template < class T >
void HeapSkew<T>::draw(wxDC& dc, int width, int height)
{
   bt->draw(dc, width, height);
}

template < class T >
void HeapSkew<T>::mouseClicked(int x, int y) {bt->mouseClicked(x, y);}

#endif
