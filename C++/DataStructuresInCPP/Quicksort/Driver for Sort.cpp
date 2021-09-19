/*
	@programmer: Bernardo Flores
	Project # 7
	Descr: this program is an implementatino of @file quickSort.cpp
			and @file insertionSort.cpp to test the methods of both files combined
			as they sort data types.
		
	COSC 2436, PF III Data Structures
	Date: Novemeber 29, 2017
*/
#include <iostream>
#include <string>
#include "insertionSort.cpp"
#include "quickSort.cpp"
#include <array>
using namespace std;
int main()
{
	cout << "Driver Program for Sorting ADT..." << endl;
	//creation of array and size for testing
	const int SIZE= 10;
	int arr[SIZE];
	cout << "Enter 10 integers followed by a space:";
	for (int i=0; i<SIZE; i ++)
	{
		cin>>arr[i];
	}
	//creation of first and last	
	int first = 0;
	int last = SIZE-1;
	
	//Quicksort has not been Called
	cout << "Array without Quicksort function!" << endl;
	for (int i=0; i<SIZE; i ++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << sizeof(arr)/sizeof(arr[0]) << " elements of arr[] will be sorted by quickSort function."<< endl;
	quickSort(arr,first,last);
	
	//QuickSort was called
	cout << "\nQuickSort is Finished. Results below!" << endl;
	for (int i=0; i<SIZE; i ++)
	{
		cout << arr[i] << " ";
	}
	cout << "\nNew test with strings" << endl;
	const int SIZE1=12;
	string arrStr[SIZE1];
	cout << "Enter " << SIZE1 << " items of characters, seperate by space" << endl;
	for (int i=0; i<SIZE1; i ++)
	{
		cin >> arrStr[i];
	}
	last=SIZE1-1;
	cout << "Array without Quicksort function!" << endl;
	for (int i=0; i<SIZE1; i ++)
	{
		cout << arrStr[i] << " ";
	}
	cout << endl << endl;
	cout << sizeof(arrStr)/sizeof(arrStr[0]) << " elements of arr[] will be sorted by quickSort function."<< endl << endl;
	quickSort(arrStr,first,last);
	
	//QuickSort was called
	cout << "\nQuickSort is Finished. Results below!" << endl;
		for (int i=0; i<SIZE1; i ++)
	{
		cout << arrStr[i] << " ";
	}
	return 0;
}
