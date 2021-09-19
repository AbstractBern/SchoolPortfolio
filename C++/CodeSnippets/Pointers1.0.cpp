/*	
	Relationsihip between pointers and reference parameters
	Relationship between pointers and arrays (part 1)
	Pointers and objects/structs
	---------------------------------------------------------------------------------
	Pointer: a variable that holds the memroy address of something (another variable)
	
	int num=3; *ptr; 	<-- do not do this, confusing
	deblar a pointer					
	ex: int num=3;
	int *ptr;	int* ptr;	int * ptr;		
	& - address of operayor (unary operator)
	* - takes the value and gets value pointer points to (dereference operator */
#include <iostream>
using namespace std;
void get(int&);
/*int smain()
{
	int num=3;
	int *ptr;
	ptr= &num;
	cout<<num<<endl;
	cout<<ptr<<endl;
	num=5;
	*ptr=7;
*/
/*int main()
{
	int num;
	get(num);
	cout<<"Num is "<<num<<endl;
	return 0;
	
}
void get(int &num)
{
	cout<<"Enteran integer value: ";
	cin>>num;
}
*/
int main()
{
	int num;
	get(int *ptr);
	cout<<"num is "<<num<<endl;
	return 0;
}
void get(int *ptr)
{
	cout<<"Enter an integer value: ";
	cin>>*ptr;
}	
/*
int list[4]={10,20,30,40}
print(list, 4)
return 0;
void print(list[], size)
for int=0; i<size; i++)
	cout<<list[i]<<' ';
cout<<endl;

int list[4]={10,20,30,40}
print(	, 4)
return 0;
void print(int* list, int size)
{
	for int i=0; i<size; i++)
	`	cout<<list[i]<<endl;
	cout<<endl;
}
*/
	
