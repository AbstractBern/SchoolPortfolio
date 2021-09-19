#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	const int SIZE=48;
	double tablePrice[SIZE];
	ifstream PricingTable, prices;
	char alpha;
	int partC;
	string data;
	double priceOf, 
		pricing;
	PricingTable.open("PartPricing.txt");
	prices.open("partspricing.txt");
	cout<<setw(50)<<"Green Gamma Team"<<endl;
	cout<<"Team Prototype Cost Analysis (Rock Retrieval and Mineral Identification)"<<endl;
	cout<<"Group   "<<"Part Price      "<<"Count   "<<"Pricing"<<endl;
	getline(PricingTable, data, '\n');
	while (!PricingTable.fail())
	{
		getline(PricingTable, data, '\n');
		cout<<data<<endl;
	}
	float price, sum=0;
	for (int i=0; i<SIZE; i++)
	{
		prices>>price;
		tablePrice[i]=price;
	}
	cout<<tablePrice[0]<<" ";
	for (int i=0; i<SIZE; i++)
	{
		sum+=tablePrice[i];
	}
	cout<<sum;
	return 0;
}
