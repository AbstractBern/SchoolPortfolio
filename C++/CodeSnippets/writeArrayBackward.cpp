//#include <iostream>
//using namespace std;
//void writeArrayBackward(const char[], int, int);
//int  main()
//{
//	const int SIZE=11;
//	char thisArray[SIZE];
//	cout<<"Enter 10 characters: ";
//	for (int i=0; i<SIZE; i++)
//	{
//		cin>>thisArray[i];
//	}
//	writeArrayBackward(thisArray,thisArray[0], thisArray[10-1]);
//	return 0;
//}
//void writeArrayBackward(const char anArray[], int first, int last)
//{
//	if (anArray == 0)
//	{
//		return;
//	}
//	else
//	{
//		cout<<anArray[10];
//		writeArrayBackward(anArray, first, anArray[10-1]);
//	}
//}

//  main calls a recursive function to print an array in reverse 
//  order

#include <iostream>
using namespace std;
void recArrayBackPrint(char[],int);
int main()
{
   char values[10] = {'a','b','c','d','e','f','g','h','i','j'};

   recArrayBackPrint(values,10);
   return 0;
}

//  print values in array in reverse order
//  preconds:	array is an array of ints
//		size > 0 (number of elements in array)
//  postconds:	parms are unchanged
//		prints array[size-1],...,array[0]

void recArrayBackPrint(char* array,int size)
{
   if (size > 0)
   {
      recArrayBackPrint(array+1,size-1);
      cout << array[0] << "   ";
   }
//  base case is empty array (size == 0), so do nothing
}

