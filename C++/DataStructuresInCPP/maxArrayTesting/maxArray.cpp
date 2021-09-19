#include <iostream>
using namespace std;
int maxArray(int arr[], int, int);
int main()
{
	int n;
	cout<<"The array is of data type integers."
	cout<<"Enter a size of array: ";
	cin>>n;
	int array[n], count=1;
	//user friendly to count the entries inside array
	for (int i=0; i<n; i++)
	{
		cout<<"Enter " << count++ <<"st "<< "item: ";
		cin>>array[i];
	}
	cout<<"\nThese are your numbers.";
	//display of array
	for( int i=0; i<n; i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<"The largest is: ";
	cout<<maxArray(array, 0, n-1);
	return 0;

}
/**
	@post if successful this module returns a value that is greatest in the arr[]
	@param integer arr[], first element in arr[], last element in arr[]
	@returns left if greatest value is in the left half, right if greatest value is in the right half
*/
int maxArray(int arr[], int first, int last)
{
	if (first == last)
	{
		return arr[first];
	}
	int mid = (first+last)/2;
	int left = maxArray(arr,first, mid);	//cuts array in half and finds max left side
	int right = maxArray(arr,mid+1, last);	//cuts array in halds and finds max right side
	if (left > right)						//comparison of greatest in the two halves
	{
		return left;
	}
	else
	{
		return right;
	}
}
