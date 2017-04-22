#include "HeapArray.h"
#include "HeapSkew.h"
#include "PQHeap.h"
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;
using CSC2110::String;
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("alphabet.txt");
   int num_items = cds->size();
   cout << num_items << endl;

//while(true)
//{
	cout<<37<<endl;
   HeapSkew<CD>* sh = new HeapSkew<CD>(&CD::compare_items);
cout << 39 << endl;
   ListArrayIterator<CD>* iter = cds->iterator();
   while(iter->hasNext())
   {
      CD* cd = iter->next();
	  cout << 44 << endl;
      sh->heapInsert(cd);
   }
   delete iter;
cout << 48 << endl;
   while(!(sh->heapIsEmpty()))
   {
	   cout << 51 << endl;
      CD* cd = sh->heapRemove();
      cd->displayCD();
   }
cout << 55 << endl;
   delete sh;
//}
   deleteCDs(cds);
   delete cds;

   return 0;
}
