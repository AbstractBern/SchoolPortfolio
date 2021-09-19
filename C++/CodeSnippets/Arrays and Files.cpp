#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	const int NUM_DIVS=3;
	const int NUM_QTRS=4;
	double sales[NUM_DIVS][NUM_QTRS];
	double totalSales=0;
	int div, qtr;
	ifstream inputFile;
	inputFile.open("sales1.dat");
	if (!inputFile)
	{
		cout<<"Error opening data file!"<<endl;
	}
	else
	{
		cout<<fixed<<showpoint<<setprecision(2);
		cout<<"Quarterly Sales By Division\n\n";
		for (div=0; div<NUM_DIVS; div++)
		{
			for (qtr=0; qtr<NUM_QTRS; qtr++)
			{
				cout<<"Division "  <<(div+1) <<", Quarter " <<(qtr+1) << ": $";
				inputFile >> sales[div][qtr];
				cout<< sales[div][qtr] << endl;
			}
			cout<<endl;
		}
		inputFile.close();
		for (div=0; div<NUM_DIVS; div++)
		{
			for (qtr=0; qtr<NUM_QTRS; qtr++)
			{
				totalSales += sales[div][qtr];
			}
		}
		cout<<"The total sales for the company are: $";
		cout<<totalSales << endl;
	}
	return 0;
}
