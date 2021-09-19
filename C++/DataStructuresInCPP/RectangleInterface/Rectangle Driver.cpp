/**
	@author: Bernardo Flores	//move method functions to header
	Assignment: 2
	Descr: Implement a rectangle class into a header and implentation file
			creating an abstract bass interface class, this gives you results
			in length, width, and area and gives default results and an error statement
			for invalid numbers.
	COSC 2436, PF III Data Structures
	September 17, 2017
*/
/** @file Rectangle Drive.cpp */
#include <iostream>
#include "Rectangle.h"
using namespace std;
/**
	main function uses abstract interface class rectangle 
	implemented and tested for client, solving for area of rectangle
*/
int main()
{
	Rectangle theTable;				//object instance
	double newL, newW;				//declares two types of vars: newL length and newW width
	
	cout<<"Rectangle Class Program..." << endl << endl;
	
	cout<<"\tNote: measurements can be decimal values and must be entered"
		<<"\t\t\trespectively and seperated by a space." << endl;
		
	cout<<"Enter length then width: ";
	cin>>newL>>newW;				//input for both values
	cout<<endl;
	
	if (theTable.setDimension(newL,newW) == false)	//if values <= 0, bool =false default results
	{
		cout<<"ERROR! MUST BE A NUMBER GREATER THAN ZERO." << endl << endl;
		cout<<"Measurement of object: " << endl;
		cout<<"\tLength: " << theTable.getLength() << endl;
		cout<<"\tWidth: " << theTable.getWidth() << endl;
		cout<<"\tArea: " << theTable.getArea() << endl;
	}
	else											//else values >0, bool=true, correct results
	{
		cout<<"Measurements of your object: " << endl;
		cout<<"\tLength: " << theTable.getLength() << endl;
		cout<<"\tWidth: " << theTable.getWidth() << endl;
		cout<<"\tArea: " << theTable.getArea() << endl;
	}
	return 0;
}
