/*
	@programmer: Bernardo Flores
	Programming Assignment: 8, Binary Search Tree
	Description: WIth the addition of 6  new methods, now construct a binary tree without making modifications to existing code.
	Date: December 9, 2017
*/
#include <iostream>
using namespace std;
#include "BST.h"
int main()
{
	BST<int> cloneT;	//instance of BST class object
	cout << "clone T " << (cloneT.isEmpty()? "is": "is not") << "empty" << endl;
	cout << "'cloneT': An empty instance of the BST class is made.\n" << endl;
	
	//inorder test
	cout << "cloneT inorder traversal: " << endl;
	cloneT.inorder(cout);
	
	//test insert
	cout << "Now insert many integers into cloneT.\nTry inserts integers that have or have not been repeated." << endl;int number;
	int itemNum;
	for (;;)
	{
		cout << "Insert item (-1 to stop):";
		cin >> itemNum;
		if (itemNum == -1)
			break;
		cloneT.add(itemNum);
	}	
	cout << endl;
	//graphing tree
	cloneT.graph(cout);
	//traversal inorder
	cout << endl;
	cloneT.inorder(cout);
	cout << endl;
	cout << "cloneT object" << (cloneT.isEmpty() ? " is " : " is not " ) << "empty" << endl;
	cout << "Height of tree: " << cloneT.getHeight() << endl;
	cout << "Number of Nodes: " << cloneT.getNumberOfNodes() << endl;
	cout << "Number of Leaves: " << cloneT.getNumberOfLeaves() << endl << endl;
	
	//testing remove()
	cout << "For the remove method, attempt to remove data that is or not in the tree.\n";
	for (;;)
	{
		cout << "\nRemove item (-1 when done): ";
		cin >> itemNum;
		if (itemNum == -1)
			break;
		cloneT.remove(itemNum);
		cout << "Adjustmens were made." << endl;
		cout << "Height: " << cloneT.getHeight() << "\tLeaves: " << cloneT.getNumberOfLeaves() << "\tNodes: " << cloneT.getNumberOfNodes() << endl << endl;
		cout << endl;
		cloneT.graph(cout);
	}
	cout << "\n\tAdjustments have been made." << endl;
	cout << "Height: " << cloneT.getHeight() << "\tLeaves: " << cloneT.getNumberOfLeaves() << "\tNodes: " << cloneT.getNumberOfNodes() << endl << endl;
	
	//traversal inorder
	cloneT.inorder(cout);
	cout << endl;
	//testing search()
	for (;;)
	{
		cout << "Item to find (-1 to stop): ";
		cin >> itemNum;
		if (itemNum == -1)
			break;
		cout << (cloneT.contains(itemNum) ? "found" : "not found") << endl;
	}
	//remove all contents
	cout << "Remove all data.";
	for (;;)
	{
		cout << "Remove item (all): ";
		cin >> itemNum;
		if (itemNum == -1)
			break;
		cloneT.remove(itemNum);
		cloneT.graph(cout);
	}
	cout << "cloneT object " << (cloneT.isEmpty() ? "is" : "is not") << "empty.\n";
	cout << "CloneT-> Height: " << cloneT.getHeight() << "\tLeaves: " << cloneT.getNumberOfLeaves() << "\tNodes: " << cloneT.getNumberOfNodes() << endl;
	cout << "object cloneT is now finished...Destroying object.";
	cloneT.~BST();
	return 0;
}
