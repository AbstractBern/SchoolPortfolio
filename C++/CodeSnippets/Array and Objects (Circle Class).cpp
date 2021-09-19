//uses array of objects
#include <iostream>
#include <iomanip>
#include "Circle.h"
using namespace std;
const int NUM_CIRCLES = 4;
int main()
{
	Circle Obj1[NUM_CIRCLES];
	for (int i = 0; i < NUM_CIRCLES; i++)
	{
		double r;
		cout<<"Enter the radius for circle " << (i+1) << ": ";
		cin>>r;
		Obj1[i].setRadius(r);
	}
	cout << fixed << showpoint << setprecision(2);
	cout << "\nHere are the areas of the " << NUM_CIRCLES
		 << " Circles.\n";
	for (int i = 0; i < NUM_CIRCLES; i++)
	{
		cout << "Circle " << (i+1) << setw(8)
			 << Obj1[i].findArea() << endl;
	}
	return 0;
}
