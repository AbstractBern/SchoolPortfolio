/*
	@author Bernardo Flores
	Project # 5
	Descr:	This progam calculates numbers based on postfix expression using a stack interface,
			and an algorithm function, that is infused with error checking for the user.
	COSC 2436, PF III Data Structures
	Date: October 22, 2017
*/
#include <iostream>
#include <string>
#include "ArrayStack.h"
#include <stdexcept>
using namespace std;
void postFixCalc(string, ArrayStack<int>&);	//prototype

int main()
{
	ArrayStack<int> stack;					//creates instance of arraystack object 
	string object;							//creates object var
	
	//prompt beginning with important information on using this program
	cout << "\tPostfix Expression Calculator with Stack Interface" << endl << endl;
	cout << "\tNotice: Seperate entries with space." << endl;
	cout << "\t\tOnly use operators: (+ , - , * , /)" << endl;
	cout << "\t\tDigits: '0' - '9' and Blank Space: ' '" << endl;
	cout << "\t\tIf space only are entered, this program will crash." << endl << endl;
	//EXAMPLE FOR USER
	cout << "\tExample of Postfix Expression: 9 2 1 - +" << endl;
	string example = "9 2 1 - +";											//creates a string
	postFixCalc(example,stack);												//string passed into algorithm function
	cout << "\tResult of expression: " << stack.peek() << endl << endl;		//processed in stack
	stack.pop();															//popped out of stack, stack now empty
	//END OF EXAMPLE
	
	cout << "Enter postfix expression (press enter to quit): ";				//start of user input
	getline(cin, object);				//input of data for object var
	while (object !="" )				//loops while object holds a filled string
	{
		try
		{
			postFixCalc(object, stack);	//call to postFixCal for algorithm, and stack usage
			int result=stack.peek();	//copy of stack peek, to ensure cooperation with if statement below.
			stack.pop();				//stack now empty
			if (stack.isEmpty())		//stack empty with no remaiders
			{							//expression is seen and stack is known to be empty
				cout << "\nResult of expression is " << result << endl;
				cout << "Stack Empty: " << stack.isEmpty() << " (Should be 1)." << endl << endl;
			}
			else if (!stack.isEmpty())	//if stack has garbage, not empty
			{
				for (int i = 0; i<object.length(); i++)
				{
					stack.pop();		//pop out everything
				}
				throw 'G';				//throw error G to be catched
			}
		}	
		catch(char exc)					//error handling
		{
			if (exc == 'G')				//G error caught
			{							//is called when values are left in the stack, stack is emptied before hand
				cout << "\t\tError: Expression is malformed in stack\n\t\t\t and has been emptied for you.\n" << endl;
			}
			else if (exc == 'X')		//X Error caught
			{							//all possible reasons why error happened is in this block
				cout << "\t\tError: You may have used:" << endl;
				cout <<	"\t\t\t1) too many/too little operators/operands.\n"
					<<	"\t\t\t2) prefix/infix notation.\n"
					<<	"\t\t\t3) invalid characters.\n"
					<<	"\t\t\t4) or the stack is empty." << endl << endl;
			}
		}
		//continuing the user for more expressions
		cout << "Enter postfix expression (press enter to quit): ";
		getline(cin, object);
		//enter is needed because of the code design
		cout << "Press enter to cotinue...";
		cin.ignore(100,'\n');			//ignores trash from getline
	}//end while
	//end program prompt
	cout << "\n\t\tThank You, Come Again!";
	return 0;
}
/**
	postFixCalc(string newObject)
	calculates the psotfix expression in main and
	stores result in the stack.
	features error throwing for catching
*/
void postFixCalc(string newObject, ArrayStack<int>& stack)
{
	for (int i=0; i<newObject.length(); i++)	//loop through string count
	{
		if (isdigit(newObject[i]))				//if digit do this
		{
			char token = newObject[i];			//store the string character as actual character
			int value;							//to store value from string integer
			if (isdigit(token))			
			{
				value=token-'0';				//stores as digit
			}
			stack.push(value);					//pushes digit onto stack
		}
		else if (isspace(newObject[i]))			//if is space ignore
		{										//although if object is nothing but space, program crashes
			continue;
		}
		else if (newObject[i] == '+'||newObject[i] == '-'||newObject[i] == '/'||newObject[i] == '*')
		{										//handling the operators
			int operand1, operand2, result;		//used to hold the operators and operands
			char op = newObject[i];				//holds the operator data to able to do the switch statement
			if (stack.isEmpty())				//catches invalid characters
			{
				throw 'X';
			}	
			operand2 = stack.peek();			//holds first num
			stack.pop();						//deletes
			if (stack.isEmpty())				//catches for overloading
			{
				throw 'X';
			}
			operand1 = stack.peek();			//holds second numb0
			stack.pop();						//deletes
			switch(op)							//hard encodes the series of algorithms to take
			{
				case '+' : result = operand1 + operand2;
					break;
				case '-' : result = operand1 - operand2;
					break; 
				case '*' : result = operand1 * operand2;
					break;
				case '/' : result = operand1 / operand2;
					break;
			}
			stack.push(result);					//only now the result is in the stack
		}
		else									//anything else if really an error
		{
			throw 'X';
		}
	}
}
