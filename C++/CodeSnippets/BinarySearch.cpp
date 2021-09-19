#include <iostream>
using namespace std;
int binarySearch(const int[], int, int, int);
int main()
{
	
	
	
}
int binarySearch(const int anArray[], int first, int last, int targest)
{
	int index=0;
	if (first >last)
	{
		index=-1;
	}
	else
	{
		int mid=first + (last-first)/2;
		if (target==anArray[mid])
		{
			index=mid;
		}
		else if (target < anArray[mid])
		{
			index=binarySearch(anARray, first, mid-1, target);
		}
		else
		{
			index=binarySearh(anArray, mid+1, last, target);
		}
	}
	return index;
}
