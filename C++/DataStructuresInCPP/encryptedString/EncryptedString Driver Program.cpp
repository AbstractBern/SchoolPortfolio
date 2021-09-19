/*
	Programmer: Bernardo Flores
	Project #: 1
	Descr:	This program uses a class EncryptedString that encrypts input and shows the original input
			but or debugging purposes shows the encrypted format. This program is a package containing
			a header file, implementation file, and the client code.
	Date: September 08, 2017
*/
#include <iostream>
#include "EncryptedString.h"
#include <string>
using namespace std;
int main()
{
	char entry[200];			//character entry that holds 200 characters for testing purposes
	string newS;				//newS will store the entry array
	
	cout << "Welcome to String Encryption.." << endl;

	cout<< "First Trial with Constructor: " << endl;
	cout << "Enter a thing to encrypt: ";
	cin.getline(entry, 200);	//reads an entire for 200 characters of entr
	newS=string(entry);			//turns entry array into string and newS holds that data
	EncryptedString ex(newS);	//first call of EncryptedString constructor
	cout << "Here is the original: " << ex.get() << endl;
	cout << "Here is the string encrypted: " << ex.getEncrypted() << endl;
	

	cout<< "Second Trial with default Constructor: " << endl;
	cout << "Enter a thing to encrypt: ";
	cin.getline(entry, 200);	//reads an entire for 200 characters of entry
	newS=string(entry);			//turns entry array into string and newS holds that data
	EncryptedString to;	//first call of EncryptedString constructor
	cout << "Here is the original: " << to.get() << endl;
	cout << "Here is the string encrypted: " << to.getEncrypted() << endl;
	
	
	cout<< "Third Trial with default Constructor and Set Method: " << endl;
	cout << "Enter a thing to encrypt: ";
	cin.getline(entry, 200);	//reads an entire for 200 characters of entry
	newS=string(entry);			//turns entry array into string and newS holds that data
	EncryptedString lo;	//first call of EncryptedString constructor
	lo.Set(newS);
	cout << "Here is the original: " << lo.get() << endl;
	cout << "Here is the string encrypted: " << lo.getEncrypted() << endl;
	
	return 0;
}

