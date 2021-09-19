//Bernardo Flores
//Complete
//This program responds to two numbers and outputs their results according to 5 operators.
#include <iostream>
#include <iomanip>
using namespace std;
//This function, main, gives a prompt, and allows user to enter two numbers and the program then calculates its sum,product,average,quotient, and then modulus, in a column like format
int main()
{
	//allows variables to be used as integers
	int num1; int num2; int sum; int product; int average_num; int dividend; int mod_num;
		//prompt
	cout<<"Enter two integers (seperated by space)\nPress [Enter] when done.: "; cin>>num1 >>num2; //user interface asks for two numbers
	
	//sum adds two numbers //product multiplies, //average_num gets the average // dividend finds the division answer //mod_num finds remainder after division
	sum=num1+num2; product=num1*num2; average_num=(num1+num2)/2; dividend=num1/num2; mod_num=num1%num2;

	//prints results so user can see
	cout<<"\nThese are your results:" << endl;
	cout<<"=========================\n";
	cout << fixed << setprecision(1);
	cout<<right << setw(13)<<"Sum is: "<<right << setw(3)<<sum<<endl;
	cout<<right << setw(13)<<"Product is: "<<right << setw(3)<< product<< endl;
	cout<<right << setw(13)<<"Average is: "<<right << setw(3)<< average_num<<endl;
	cout<<right << setw(10)<<"Quotient is: "<<right << setw(3)<< dividend<< endl;
	cout<<right << setw(13)<<"Remainder is: "<<right << setw(3)<< mod_num<< endl;
	return 0;
}
