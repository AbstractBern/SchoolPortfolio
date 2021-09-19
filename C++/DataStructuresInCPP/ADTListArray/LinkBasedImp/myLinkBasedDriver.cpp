// ArrayList example driver
// This is not a thorough test of the class, but it exercises all class methods.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations
using namespace std;

void displayList(ListInterface<string>* listPtr)
{
	if (listPtr->isEmpty())
		cout << "The list is empty" << endl;
	else
	{
		cout << "The list contains " << endl;
		for (int pos = 1; pos <= listPtr->getLength(); pos++)
		{
			cout << listPtr->getEntry(pos) << " ";
   		}
		cout << endl;
	}
}

int main()
{

	ListInterface<string>* listPtr = new LinkedList<string>();
	
	cout << "List should be empty" << endl;;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;
	cout << "One and Three inserted." << endl;
	listPtr->insert(1, "one");
	listPtr->insert(2, "three");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;		
	cout << "Five is inserted." << endl;
	listPtr->insert(3, "five");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;	
	cout << "seven is inserted." << endl;
	listPtr->insert(4, "seven");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;	
	cout << "five is inserted." << endl;
	listPtr->insert(5, "nine");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	
	// Linked implementation does not have a fixed size, so no need to test for full List
	/*
	cout << "List should be full; next insert should fail" << endl;
	if (listPtr->insert(6, "six"))
         cout << "Inserted \"six\" at position 6" << endl;
    else
         cout << "Cannot insert \"six\" at position 6" << endl;
    displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	*/
	
	cout << "Remove first entry" << endl;
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;
	
	cout << "Remove last entry" << endl;
	listPtr->remove(4);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;
	
	cout << "Remove five and seven." << endl;
	listPtr->remove("five");
	listPtr->remove("seven");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;

	cout << "Try to remove entry from empty list" << endl;
	if (listPtr->remove(1))
         cout << "Removed an entry" << endl << endl;
    else
         cout << "Cannot remove entry" << endl << endl;
	
	cout << "Inserting one, nine and fourteen" << endl;
	listPtr->insert(1, "one");
	listPtr->insert(2, "nine");
	listPtr->insert(3, "fourteen");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;		
	
	cout << "One at Position: " << listPtr->getPosition("one") << endl;
	cout << "nine at Position: " << listPtr->getPosition("nine") << endl;
	cout << "fourteen at Position: " << listPtr->getPosition("fourteen") << endl;
	cout << "Clearing list" << endl;
	listPtr->clear();
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;	
	return 0;
}  // end main
