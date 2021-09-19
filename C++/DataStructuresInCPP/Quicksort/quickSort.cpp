//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 11-5.
#include <iostream>
#include <algorithm>
using namespace std;

/** Arranges the first, middle, and last entries in an theArray into ascending order.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the first element to consider in array.
 @param last  The index of the last element to consider in array. */
template <class ItemType>
void sortLastMiddleFirst(ItemType theArray[], int first, int mid, int last)
{
	if(theArray[first] >= theArray[mid])
	{
		swap(theArray[first],theArray[mid]);
	}
	if (theArray[mid] >= theArray[last])
	{
		swap(theArray[mid],theArray[last]);
	}
	if(theArray[first] >= theArray[mid])
	{
		swap(theArray[first],theArray[mid]);
	}
} // end sortLastMiddleFirst

/** median-of-three pivot selection for arrays of at least MIN_SIZE
    entries.
 @pre  array[first..last] is an array.
 @post  array[first..last] is sorted.
 @param array  The given array.
 @param first  The index of the first element to consider in array.
 @param last  The index of the last element to consider in array. */
template <class ItemType>
int partition(ItemType theArray[], int first, int last)
{
	int mid = first + (last-first)/2;
	sortLastMiddleFirst(theArray, first, mid, last);
	swap(theArray[mid],theArray[last-1]);
	int pivotIndex = last-1;
	ItemType pivot = theArray[pivotIndex];
	int indexFromLeft = first + 1;
	int indexFromRight = last-2;
	bool done = false;
	while (! done)
	{
		while (theArray[indexFromLeft] < pivot)
		{
			indexFromLeft = indexFromLeft + 1;
		}
		while (theArray[indexFromRight] > pivot)
		{
			indexFromRight = indexFromRight - 1;
		}
		if (indexFromLeft < indexFromRight)
		{
			swap(theArray[indexFromLeft],theArray[indexFromRight]);
			indexFromLeft = indexFromLeft + 1;
			indexFromRight = indexFromRight - 1;
		}
		else
		{
			done = true;
		}
	}
	swap(theArray[pivotIndex],theArray[indexFromLeft]);
	pivotIndex = indexFromLeft;
	return pivotIndex;
}

/** Sorts an array into ascending order. Uses the quick sort with
    median-of-three pivot selection for arrays of at least MIN_SIZE
    entries, and uses the insertion sort for other arrays.
 @pre  theArray[first..last] is an array.
 @post  theArray[first..last] is sorted.
 @param theArray  The given array.
 @param first  The index of the first element to consider in theArray.
 @param last  The index of the last element to consider in theArray. */
template <class ItemType>
void quickSort(ItemType theArray[], int first, int last)
{

//	static string side = "All";
 	const int MIN_SIZE = 4;
//	cout << ">> side: "<<side<< endl;
	if (last-first +1 < MIN_SIZE)
	{
		cout << "Calling insertionSort with " << last-first +1 << " array[] elements." << endl;
		insertionSort(theArray, first, last);
	}
	else
	{
		
		// Create the partition: S1 | Pivot | S2
		int pivotIndex = partition(theArray, first, last);
		
		//display size of left size
//		int begin=first;
//		int end=pivotIndex-1;
//		int size=end-begin+1;
		cout << "Call to quickSort with a Left size: " << pivotIndex-first << " Right Size: " << last-pivotIndex <<  endl;
		//side+=" L";
		// Sort subarrays S1 and S2
		quickSort(theArray, first, pivotIndex - 1);
		
//		begin=pivotIndex+1;
//		end=last;
//		size=end-begin+1;
//		cout << "Call to quickSort( Left size: " << size << " Right Size: " << size <<  endl;
		//side+= " R";
		quickSort(theArray, pivotIndex + 1, last);
		
	}  // end if
	//cout << "<< side: "<<side<< endl;
	//side = side.substr(0,side.size()-2);
}  // end quickSort
