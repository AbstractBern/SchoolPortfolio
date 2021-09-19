#include <iostream>
using namespace std;
int getNumberOfGroups(int, int);
int main()
{
	int x, y;
	cout<<"ENter for two";
	cin>>x>>y;
	cout<<getNumberOfGroups(x,y);
	return 0;
}
int getNumberOfGroups(int n, int k)
{
	if ( (k==0) || (k==n))
	{
		return 1;
	}
	else if (k>n)
	{
		return 0;
	}
	else
	{
		return getNumberOfGroups(n-1,k-1) + getNumberOfGroups(n-1,k);
	}
}
