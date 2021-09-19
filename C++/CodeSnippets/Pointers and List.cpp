#include <iostream>
using namespace std;

int main()
{
	const int SIZE=5;
	int numbers[SIZE];
	cout<<"Enter "<<SIZE<<" numbers: ";
	for (int count=0; count<SIZE; count++)
	{
		cin>>*(numbers+count);
	}
	cout<<"Here are the numbers you entered.\n";
	for (int i=0; i<SIZE; i++)
	{
		cout<<*(numbers)<< " ";
	}
	cout<<endl;
	return 0;
}

