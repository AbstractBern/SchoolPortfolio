//class specification file
#include "EncryptedString.h"
#include <string>
#include <cctype>
using namespace std;

EncryptedString::EncryptedString()
{	encrypt="";}
EncryptedString::EncryptedString(string str)
{
	Set(str);
}
void EncryptedString::Set(string str)
{
	int count=str.length();				//holds the length of string to be manipulated
	for (int i=0; i<count; i++)			//loop 0:strnig length
	{
		while (ispunct(str[i]) || isdigit(str[i]))			//while any string cell is not character
		{
			str.erase(i,1);				//delete that string cell
			count--;					//deletion causes count decrementation
		}
		int value;						//holds the integer values of each character
		value=int(str[i]);
		if (value == 90)			//sets value to char 'A'
		{
			value = 65;
			exit;
		}
		else if (value == 122)		//sets value to char 'a'
		{
			value = 97;
			exit;
		}
		else if (value == 32)		//sets value to space ' '
		{
			value = 32;
			exit;
		}
		else						//increments value
		{
			value++;
		}
		str[i]=char(value);				//puts back int by character into each cell
	}
	encrypt=str;						//sets private data encrypt
}
string EncryptedString::get() const 
{
	string decrypt=encrypt;				//local struing var shared with the encrypted format
	for(int i=0; i<encrypt.length(); i++)
	{
		int value;						//holds char value
		value=int(encrypt[i]);
		if (value == 65)				//turns 'A' to 'Z'
		{
			value=90;
			exit;
		}
		else if (value == 97)			//turns 'a' to 'Z'
		{
			value=122;
			exit;
		}
		else if (value == 32)			//keeps value as a space ' '
		{
			value=32;
			exit;
		}
		else							//decrements value to decrypt
		{
			value--;
		}
		decrypt[i]=char(value);
	}
	return decrypt;					//returns as constant 
}
string EncryptedString::getEncrypted() const
{
	return encrypt;
}
