#include <iostream>
#include <string>
#include "ArrayStack.h"
using namespace std;

int main()
{
    ArrayStack<string> stack;
    string items[5] = {"one", "two", "three", "four", "five"};

    for (int i = 0; i < 5; i++)
	{
		cout<<"Pushing item \"" << items[i] << "\""<< std::endl;
		stack.push(items[i]);

	}
	cout << endl;
   
	while (!stack.isEmpty())
	{
		cout << "Top item is \"" << stack.peek() << "\"" << endl;
		cout << "Removing top item" <<  endl;
		stack.pop();
	}
	
	cout << endl;
	cout << "Empty: " << stack.isEmpty() << endl;
}  // end driver

