/*
	@author Bernardo Flores
	Project # 5
	Descr:	This progam is part using a postfix calculator with
			a stack interface and error checking.
	COSC 2436, PF III Data Structures
	Date: October 19, 2017
*/
#include <iostream>
#include <string>
#include "ArrayStack.h"
#include <stdexcept>
using namespace std;
void postFixCalc(string, ArrayStack<int>&);						//prototype

int main()
{
	ArrayStack<int> stack;
	string object;								//holds input line string
	
	//prompt beginning with notice
	cout << "\tPostfix Expression Calculator with Stack Interface" << endl << endl;
	cout << "\tNotice: Seperate entries with space." << endl;
	cout << "\t\tOnly use operators: (+ , - , * , /)" << endl;
	cout << "\t\tDigits: '0' - '9' and Blank Space: ' '" << endl << endl;	//this program can really use any integer
	cout << "If space only are entered, this program will crash." << endl;
	cout << "\tExample of Postfix Expression: 9 2 1 - +" << endl;
	
	string example = "9 2 1 - +";
	postFixCalc(example,stack);
	cout << "\tResult of expression: " << stack.peek() << endl << endl;
	stack.pop();
	
	cout << "Enter postfix expression (press enter to quit): ";
	getline(cin, object);
	while (object !="" )						//loop until contVar is N
	{
		
		try
		{
			postFixCalc(object, stack);					//statement for stack empty to reassure the user.
			cout << "\nResult of expression is " << stack.peek() << endl;
			stack.pop();							//empty the stack just for precaution
			if (!stack.isEmpty())
			{
				throw 'G';
			}
			else
			{
				cout << "Stack Empty (should be 1): " << stack.isEmpty() << " You may continue." << endl << endl;
			}
		}	
		catch(char exc)
		{
			if (exc == 'E')
			{
				cout << "\tError: You may have 1) Entered a prefix notation (overloaded/normal)" << endl;
				cout << "\t\t2) Used too little or too many operators/operands."<< endl << endl;
			}
			else if (exc == 'G')
			{
				cout << "Error: Expression is malformed in stack." << endl;
			}
			else if (exc == 'I')
			{
				cout << "Error: Expression may be malformed." << endl;
				//when all alphanet
			}
		}
		cout << "Enter postfix expression (press enter to quit): ";
		getline(cin, object);
		cout << "Press enter to cotinue...";
		cin.ignore(100,'\n');			//ignores trash from getline
		//cin.ignore(100,'\n');			//ignores trash from getline
	}//end while
	cout << "\n\t\tThank You, Come Again!";
	return 0;
}
/**
	postFixCalc(string newObject)
	calculates the psotfix expression in main and
	stores result in the stack.
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
		{
			continue;
		}
		else if (newObject[i] == '+'||newObject[i] == '-'||newObject[i] == '/'||newObject[i] == '*')//now is an operator			//anything not a digit or space
		{
			int operand1, operand2, result;		//used to hold the operators and operandsf
			char op = newObject[i];				//holds the operator data to able to do the switch statement
			if (stack.isEmpty())
			{
				throw 'I';
			}	
			operand2 = stack.peek();			//holds first num
			stack.pop();			
			if (stack.isEmpty())
			{
				throw 'E';
			}						//delete
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
		else	
		{
			throw 'I';
		}
	}
}
