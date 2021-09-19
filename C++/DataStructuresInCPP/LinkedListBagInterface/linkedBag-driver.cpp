/*
	Programmer: Bernardo Flores
	Project #: 4
	Descr:	This program has made changes to the add function of LinkedBag and added a remove()
			function that removes random positions in the linked list.
	COSC 2436, PF III Data Structures
	Date: October 4, 2017
*/
#include <iostream>
#include <string>
#include "LinkedBag.h"
using namespace std;

void display(LinkedBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
   vector<string> bagItems = bag.toVector();
   
   int numberOfEntries = static_cast<int>(bagItems.size());
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displaySet

int main()
{
	LinkedBag<string> bag;
	cout << "Testing array-based Set:" << endl;
	cout << "The initial bag is empty." << endl;
	cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 1 (true)" << endl;
	display(bag);

	string items[] = {"one", "two", "three", "four", "one"};
	cout << "Add 5 items to the bag: " << endl;
	for (int i = 0; i < 5; i++)
	{
		bag.add(items[i]);
	}  // end for
   
   display(bag);
   cout << "isEmpty: returns " << bag.isEmpty() 
   		<< "; should be 0 (false)" << endl;
	cout << "getCurrentSize: returns " << bag.getCurrentSize() 
        << "; should be 5" << endl;    
	cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" << endl;
    cout << "remove(random integer): returns " << bag.remove()
        << "; should be 1 (true)" << endl;
	cout << "getCurrentSize: returns " << bag.getCurrentSize() 
        << "; should be 4" << endl;    
   cout << endl;
   
   display(bag);
   
   cout << "After clearing the bag, ";
   bag.clear();
   
   cout << "isEmpty: returns " << bag.isEmpty()
        << "; should be 1 (true)" << endl;
   
   return 0;
}  // end main
//int targetPos = rand() % itemCount + 1;
//		Node<ItemType>* temp = headPtr;
//		Node<ItemType>* traverse = headPtr;
//		for (int i=0; i<itemCount; i++)
//		{
//			traverse = traverse->getNext();
//			if (targetPos)
//				traverse->setNext(temp);
//		}
//		Node<ItemType>* entryNodePtr = temp;	
//		// Copy data from first node to located node
//		entryNodePtr->setItem(headPtr->getItem());
//		// Delete first node
//		Node<ItemType>* nodeToDeletePtr = headPtr;
//		headPtr = headPtr->getNext();
//		
//		// Return node to the system
//		nodeToDeletePtr->setNext(nullptr);
//		delete nodeToDeletePtr;
//		nodeToDeletePtr = nullptr;
//		
//		itemCount--;
