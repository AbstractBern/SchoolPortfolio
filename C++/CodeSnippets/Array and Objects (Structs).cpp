//array of structs
#include <iostream>
#include <iomanip>
using namespace std;

struct PayInfo
{
	int hours;
	double payRate;
};
int main()
{
	const int NUM_EMPS = 4;
	PayInfo workers[NUM_EMPS];
	double grossPay;
	cout<<"Enter the horus worked and hourl ypay rates of " << NUM_EMPS << " employees. \n";
	for (int i=0; i < NUM_EMPS; i++)
	{
		cout<<"\nHours worked by employee #"<<(i+1)<<": ";
		cin>>workers[i].hours;
		cout<<"Hourly pay rate for this employee: $";
		cin>>workers[i].payRate;
	}
	cout<<"\nHere is the gross pay for each employee.\n";
	cout<<fixed<<showpoint<<setprecision(2);
	for (int i=0; i<NUM_EMPS; i++)
	{
		grossPay=workers[i].hours*workers[i].payRate;
		cout<<"Employee #"<<(i+1);
		cout<<": $"<<setw(7)<<grossPay<<endl;
	}
	return 0;
}
