#include <iostream>
using namespace std;
void writeBackward1(string);
string writeBackward2(string);
int main()
{
	cout<<"Enter a string: ";
	string s;
	getline(cin, s);
	writeBackward2(s);
	return 0;
}
void writeBackward1(string s)
{
	int length = s.size();
	if (length >0)
	{
		cout<<s.substr(length-1, 1);
		writeBackward1(s.substr(0, length-1));
	}
}
string writeBackward2(string s)
{	
	string first;
	string rest;
	string object;
	int length = s.size();
	if (length >0)
	{
		rest = writeBackward2(s.substr(1, length-1));
		first = s.substr(0,1);
		object = rest + first;
	}
	return object;
}
