//BF
#include <iostream>
using namespace std;
const int NUM_DAYS=7;
void getSales(double daily_sales[]);
double avg(double daily_sales[]);

int main()
{
	double daily_sales[NUM_DAYS];
	double sum,average;
	cout<<"In main.";
	getSales(daily_sales);
	avg(daily_sales);
	return 0;
}

void getSales(double daily_sales[])
{
	for (int day=0;day<NUM_DAYS;day++)
	{
		cout<<"Enter daily sales for day" << day+1 << ": ";
		cin>>daily_sales[day];
	}
}

double avg(double daily_sales[])
{
	double average;
	double sum=0;
	for (int day=0;day<NUM_DAYS;day++)
	{
		sum=sum+daily_sales[day];
	}
	average=sum/NUM_DAYS;
	cout<<"Average of sales is " << average << endl;
	return average;
}
