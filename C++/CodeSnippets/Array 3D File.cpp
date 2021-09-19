#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_SECTIONS=3,
		ROWS_IN_SECTION=5,
		SEATS_IN_ROW=8;
typedef double seatTable[][ROWS_IN_SECTION][SEATS_IN_ROW];
//function prototypes
void fillArray(seatTable);
void showArray(const seatTable);
int main()
{
	double seats[NUM_SECTIONS][ROWS_IN_SECTION][SEATS_IN_ROW];
	fillArray(seats);
	showArray(seats);
	return 0;
}
//recives addres of 3d array and fill it wit data read in from file
void fillArray(seatTable array)
{
	ifstream dataIn;
	dataIn.open("seats.dat");
	if (!dataIn)
	{	cout<<"Error opening file.\n";	}
	else
	{
		for (int section=0; section<NUM_SECTIONS; section++)
			for (int row=0; row<ROWS_IN_SECTION; row++)
				for (int seat=0; seat<SEATS_IN_ROW; seat++)
					dataIn>>array[section][row][seat];
		dataIn.close();
	}
}
//display 3d array of double whose address is passed
void showArray(const seatTable array)
{
	cout<<fixed<<showpoint<<setprecision(2);
	for (int section=0; section<NUM_SECTIONS; section++)
	{
		cout<<"\n\nSection" << (section+1);
		for (int row=0; row<ROWS_IN_SECTION; row++)
		{
			cout<<"\nRow " << (row+1) << ": ";
			for (int seat=0; seat<SEATS_IN_ROW; seat++)
				cout<<setw(7)<<array[section][row][seat];
		}
	}
	cout<<endl;
}
