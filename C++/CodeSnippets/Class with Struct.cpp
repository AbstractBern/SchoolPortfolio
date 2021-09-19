//passes a structure var to one function by reference  aand to another as a constant reference
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct InvItem	//holds data for invetory time
{
	int partNum;
	string description;
	int onHand;
	double price;
};
//functin protoype
void getItemData(InvItem &);	//will receive new values to its vars

void showItem(const InvItem &);	//used for display as the new variables

int main()
{
	InvItem obj;
	
	getItemData(obj);
	showItem(obj);
	return 0;
}
void getItemData(InvItem &item)	//stores data from user into this invitem struct passed to struct function by reference
{
	cout<<"Enter the part number: ";
	cin>>item.partNum;
	cout<<"Enter the part description: ";
	cin.get();	//used for passing carriage return
	getline(cin, item.description);
	cout<<"Enter the quantity on hand: ";
	cin>>item.onHand;
	cout<<"Enter the unit price: ";
	cin>>item.price;
}
void showItem(const InvItem &item)
{
	cout<<fixed<<showpoint<<setprecision(2)<<endl;
	cout<<"Part Number	: "<<item.partNum <<endl;
	cout<<"Description	: "<<item.description<<endl;
	cout<<"Units On Hard: "<<item.onHand<<endl;
	cout<<"Price		: "<<item.price<<endl;
}
//tried to do local struct but could not

