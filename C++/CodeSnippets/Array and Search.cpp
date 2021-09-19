#include <iostream>
using namespace std;
bool search(int, int list[], int);
int main()
{
	int myStuff[5]={8,2,13,11,5};
	bool found;
	found=search(11, myStuff, 5);
	if (found)
	{
		cout<<"I found the vallue 11 in my stuff"<<endl;
	}
	else
	{
		cout<<"I could not find the value in my stuff."<<endl;
	}
	return 0;
}
bool search(int srchVal, int list[], int size)
{
	bool found = false;
	//int i=0
	//while (!found && i<size)
	//
	for (int i=0; i<size; i++)
	{
		if (list[i] == srchVal)
		{
			found=true;
		}
	}
	return found;
}
/*INT search(int srchVal, int list[], int size) to find the number and whre it is
a linear or sequential search, starting front of array going through elements
Binary search only works for sorted data
int first=0, last=size-1, mid;
while (first <=last)
{
	mid=(first+last)/2;
	if list[mid]==searchVal)
	{
	where=mid
	found=tru3; //where use to equal -1
	}
	else if list[mid] < serchVal;
	first = mid+1;
	else
	last=mid-1;
}
if list[i] > list[i+]
swap(listlist[i], ;lisy[i+1]
temp=list[i]
list[i]=list[i+1]
list[i+1]=temp
