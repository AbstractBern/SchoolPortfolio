/*
	@programmer: Bernardo Flores
	Project # 6
	Descr:
		
	COSC 2436, PF III Data Structures
	Date: October 28, 2017
*/
#include <iostream>
#include <string>
#include "ArrayList.h" 
using namespace std;

void displayList(ListInterface<std::string>* listPtr)
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
	ListInterface<std::string>* listPtr = new ArrayList<std::string>();
	
	cout << "List should be empty" << endl;;
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;
	
	listPtr->insert(1, "three");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;	
	
	listPtr->insert(2, "six");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;		
	
	listPtr->insert(3, "nine");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;	
	
	listPtr->insert(4, "twelve");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;	
	
	listPtr->insert(5, "zero");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	
	cout << "List should be full; next insert should fail" << endl;
	if (listPtr->insert(7, "seven"))
         cout << "Inserted \"seven\" at position 7" << endl;
    else
         cout << "Cannot insert \"seven\" at position 7" << endl;
    displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 5" << endl << endl;
	
	cout << "Remove third entry" << endl;
	listPtr->remove(3);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;
	
	cout << "Remove last entry" << endl;
	listPtr->remove(4);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 3" << endl << endl;
	
	cout << "Remove remaining entries" << endl;
	listPtr->remove(3);
	listPtr->remove(2);
	listPtr->remove(1);
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 0" << endl << endl;

	cout << "Try to remove entry from empty list" << endl;
	if (listPtr->remove(1))
         cout << "Removed an entry" << endl;
    else
         cout << "Cannot remove entry" << endl;
	
	listPtr->insert(1, "twenty one");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 1" << endl << endl;		
	listPtr->insert(2, "zero");
	listPtr->insert(3, "eight");
	listPtr->insert(4, "nine");
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 4" << endl << endl;
	cout << "twenty one is at position: " << listPtr->getPosition("twenty one") << endl;
	cout << "zero is at position: " << listPtr->getPosition("zero") << endl;
	cout << "eight is at position: " << listPtr->getPosition("eight") << endl;
	cout << "nine is at position: " << listPtr->getPosition("nine") << endl;
	
	displayList(listPtr);
	listPtr->remove("zero");
	listPtr->remove("twenty one");
	cout << "zero and twenty one are now removed." << endl;
	cout << "List is Empty: " << listPtr->isEmpty() << "should be 0." << endl;
	
	displayList(listPtr);
	cout << "Length : " << listPtr->getLength() << "; should be 2" << endl << endl;
	cout << "Clearing List..." << endl;
	listPtr->clear();
	cout<< "...Done." << endl;
	cout << "List is Empty: " << listPtr->isEmpty() << " Shouuld be 1.";
	return 0;
}  // end main
