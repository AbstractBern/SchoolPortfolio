#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>numbers(5);
	for (int &val : numbers)
	{
		cout<<"Enter an integer value: ";
		cin>>val;
	}
	cout<<"\nHere are the values you entered:\n";
	for(int val : numbers)
		cout<<val<<" ";
	cout<<endl;
	return 0;
}
