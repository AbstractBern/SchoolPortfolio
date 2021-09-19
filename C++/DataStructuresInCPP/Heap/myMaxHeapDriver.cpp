/*
	@programmer: Bernardo Flores
	Bonus Assignment: MaxHeap Class Template
	Descr. 1). This program implements the methods of a maxheap class using array and strings.
			2). The arraymax heap class template was completed in order for this to be completedd.
	Date: December 11, 2017
*/
#include <iostream>
#include <string>
#include "ArrayMaxHeap.h"
using namespace std;
int main()
{
	ArrayMaxHeap<int> *heapPtr = new ArrayMaxHeap<int>();	//new instasnce
	//testing add()
	heapPtr->add(100);
	heapPtr->add(110);
	heapPtr->add(70);
	heapPtr->add(90);
	heapPtr->add(80);
	
	cout << "Heap #1 (integers):" << endl;
	while (! heapPtr->isEmpty())
	{
		//heapPtr->displayArray();
		cout << "\tHeight: " << heapPtr->getHeight() << endl;
		cout << "\tNode Count: " << heapPtr->getNumberOfNodes() << endl;
		cout << "\tLargest Value: " << heapPtr->peekTop() << endl;
		cout << "\tRemove: " << (heapPtr->remove() ? "Object Removed" : "Not Removed") << endl ;
		
		cout << endl;
	}
	cout << "Pointer object " << (heapPtr->isEmpty() ? "is empty." : "is not empty.") << endl;
	delete heapPtr;
	heapPtr = nullptr;
	ArrayMaxHeap<string> *sPtr = new ArrayMaxHeap<string>();
	//adding method
	sPtr->add("alphabetize");
	sPtr->add("bits of ");
	sPtr->add("complex");
	sPtr->add("data");
	cout << "Heap #2 (strings):" << endl;
	while (! sPtr->isEmpty())
	{
		cout << "\tHeight: " << sPtr->getHeight() << endl;
		cout << "\tNode Count: " << sPtr->getNumberOfNodes() << endl;
		cout << "\tLargest Value: " << sPtr->peekTop() << endl;
		cout << "\tRemove: " << (sPtr->remove() ? "Object Removed" : "Not Removed") << endl << endl;
	}
	cout << "Pointer object " << (sPtr->isEmpty() ? "is empty." : "is not empty.");
	delete sPtr;
	sPtr=nullptr;
	return 0;
}
