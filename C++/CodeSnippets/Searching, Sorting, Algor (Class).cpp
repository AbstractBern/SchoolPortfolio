#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Inventory
{
	private:
		string itemCode;
		string description;
		double price;
	public:
		Inventory()
		{	itemCode="XXX"; description=" "; price=0.0;	}
		Inventory(string c, string d, double p)
		{
			itemCode=c;
			description=d;
			price=p;
		}
		string getCode() const
		{
			string code=itemCode;
			return code;
		}
		string getDescription() const
		{
			string d=description;
			return d;
		}
		double getPrice() const
		{
			return price;
		}
};
void displayInventory(const Inventory[], int);
void bubbleSort(Inventory[], int);
int main()
{
	const int SIZE=6;
	Inventory silverware[SIZE]=
							{ Inventory("S15", "soup spoon", 2.35),
							  Inventory("S12", "teaspoon", 2.19),
							  Inventory("F15", "dinner fork", 3.19),
							  Inventory("F09", "salad fork", 2.25),
							  Inventory("K33", "knife", 2.35),
							  Inventory("K41", "steak knife", 4.15)	};
	cout<<"Here is the original data.\n";
	displayInventory(silverware, SIZE);
	bubbleSort(silverware, SIZE);
	cout<<"Here is the sorted data.\n";
	displayInventory(silverware, SIZE);
	return 0;					  
}
void displayInventory(const Inventory object[], int size)
{
	for (int i=0; i < size; i++)
	{
		cout<<setw(5)<<left<<object[i].getCode()
			<< setw(13) << left << object[i].getDescription()
			<< "$" << right << object[i].getPrice() << endl;
	}
}
void bubbleSort(Inventory array[], int size)
{
	Inventory temp;
	bool swap;
	do
	{
		swap=false;
		for (int count=0; count <(size-1); count++)
		{
			if (array[count].getCode() > array[count+1].getCode())
			{
				temp=array[count];
				array[count]=array[count+1];
				array[count+1]=temp;
				swap=true;
			}
		}
	}while(swap);
}
