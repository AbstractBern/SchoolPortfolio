/**
 * @file Lab Assignment 1.cpp
 * @author Bernardo Flores
 * @brief This program practices the 5 basic operators (before being introduced the cmath lib.). It takes
 * 			two numbers separated by a space and caluclates sum, product, average, quotient.
 * @version 0.1
 * @date 2023-04-15 for CS Fundamentals 2 (ACC)
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	// declaring variables their respective data types for later use
	int num1; int num2; int sum; int product; int average_num; int dividend; int mod_num;
	// prompt one -- user interface to ask for separted integers
	cout<<"Enter two integers (seperated by space)\nPress [Enter] when done.: "; cin>>num1 >>num2;
	//sum adds two numbers //product multiplies, //average_num gets the average // dividend finds the division answer //mod_num finds remainder after division
	sum=num1+num2; product=num1*num2; average_num=(num1+num2)/2; dividend=num1/num2; mod_num=num1%num2;
	//prints results so user can see
	cout<<"\nThese are your results using the two numbers " <<num1<<" && "<<num2<<":"<<endl;
	cout<<"=========================\n";
	cout << fixed << setprecision(1);
	cout<<right << setw(13)<<"Sum is: "<<right << setw(3)<<sum<<endl;
	cout<<right << setw(13)<<"Product is: "<<right << setw(3)<< product<< endl;
	cout<<right << setw(13)<<"Average is: "<<right << setw(3)<< average_num<<endl;
	cout<<right << setw(10)<<"Quotient is (num1/num2): "<<right << setw(3)<< dividend<< endl;
	cout<<right << setw(13)<<"Remainder is: "<<right << setw(3)<< mod_num<< endl;
	return 0;
}