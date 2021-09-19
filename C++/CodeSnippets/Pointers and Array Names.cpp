#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const int NUM_COINS=5;
	double coins[NUM_COINS] = {0.05,0.1,0.25,0.5,1.0};
	double *doublePtr;
	doublePtr=coins;
	cout<<setprecision(2);
	cout<<"Here are the values in the coins array\n";
	for (int i=0; i<NUM_COINS; i++)
	{
		cout<<doublePtr[i]<<" ";
	}
	cout<<"Here are they again.\n";
	for (int i=0; i<NUM_COINS; i++)
	{
		cout<<*(coins+i)<<" ";
	}
	cout<<endl;
	return 0;
}
