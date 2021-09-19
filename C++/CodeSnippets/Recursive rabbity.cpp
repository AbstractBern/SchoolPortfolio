#include <iostream>
using namespace std;
int rabbit(int);
int main()
{
	int count;
	cout<<"Enter a number for rabbity fibonacci: ";
	cin>>count;
	cout <<rabbit(count);

	return 0;
}
int rabbit(int n)
{
	if (n<=2)
	{
		return 1;
	}
	else
	{
		return rabbit(n-1) + rabbit(n-2);
	}
}
