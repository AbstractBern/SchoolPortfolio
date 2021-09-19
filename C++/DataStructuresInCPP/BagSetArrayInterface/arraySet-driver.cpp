/** @file arraySet-Driver.cpp
	Programmer: Bernardo Flores
	Project #: 3
	Descr:	This program has made changes to the add function of LinkedBag and added a remove()
			function that removes random positions in the linked list.
	COSC 2436, PF III Data Structures
	Date: September 29, 2017
*/
#include <iostream>
#include <string>
#include "ArraySet.h"
using namespace std;

void display(ArraySet<string>& set)
{
	cout << "The set contains " << set.currentSize()
	    << " items:" << endl;
	vector<string> setItems = set.toVector();
	int numberOfEntries = static_cast<int>(setItems.size());
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << setItems[i] << " ";
	}  // end for
	cout << endl << endl;
}  // end displaySet

int main()
{
	ArraySet<string> set;
	cout << "Testing array-based Set:" << endl;
	cout << "The initial set is empty." << endl;
	cout << "isEmpty: returns " << set.emptyData() 
        << "; should be 1 (true)" << endl;
	display(set);
	string items[] = {"one", "two", "three", "four", "five"};
	cout << "Add 5 items to the set: " << endl;
	for (int i = 0; i < 5; i++)
	{
		set.addEntry(items[i]);
	}  // end for
	display(set);
		
	cout << "isEmpty: returns " << set.emptyData() 
        << "; should be 0 (false)" << endl;
	cout << "getCurrentSize: returns " << set.currentSize() 
        << "; should be 5" << endl;    
	cout << "contains(\"two\"): returns " << set.findEntry("two")
        << "; should be 1 (true)" << endl;
	cout << "contains(\"four\"): returns " << set.findEntry("four")
        << "; should be 1 (true)" << endl;
	cout << "remove(\"two\"): returns " << set.removeEntry("two")
        << "; should be 1 (true)" << endl;
	cout << "remove(\"four\"): returns " << set.removeEntry("four")
        << "; should be 1 (true)" << endl;
	cout << "remove(\"four\"): returns " << set.removeEntry("four")
        << "; should be 0 (false)" << endl;
	cout << "add(\"seven\"): returns " << set.addEntry("seven")
        << "; should be 1 (true)" << endl;
	cout << endl;
	
	display(set);
	
	cout << "After clearing the set, ";
	set.eraseData();
	cout << "isEmpty: returns " << set.emptyData()
        << "; should be 1 (true)" << endl;
    cout<<"Trying new constructor." << endl;
    //new code below for testing... 
    string array[]={"one", "three", "five"};
	ArraySet<string> set1(array, 3);
    set1.addEntry("seven");
	display(set1);
	cout<<"Set cleared now!";
	set1.eraseData();
	return 0;
}  // end main
