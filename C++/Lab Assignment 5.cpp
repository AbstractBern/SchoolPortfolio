/**
 * @file Lab Assignment 4.cpp
 * @author Bernardo Flores
 * @brief using array and operations to store business AAA group data and outputs. May need to update validation
 * @version 0.1
 * @date 2023-04-16
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <iomanip>
using namespace std;
struct General_Employee_Data {									//GE Data Struct holds variable to be saved uniquely in an array according to the employee entry
	int employee_ID, 											//stores value of employee ID
		employee_Type;											//stores value for employee union or management
	float payRate;												//stores float number for payRate per Hour
	char employee_Name[21];										//stores employee full name in 2O CELLS
};
int main() {												//main Function does all the I/O and Operations.
	const int EMPLOYEE_NUM=1;									//assigns to 4 and passes to each doubel ARRAY, ALLOWS THIS NUMBER TO BE REVISED FOR LESS OR GREATER EMPLOYEE WORKERS
	int num, num1, num2, counter=1;								//These ints are used for loops and running totals.
	const double TAX=0.15;										//asssigns const flat tax of 15% == 0.15 for Tax crediting.
	double GrossPay[EMPLOYEE_NUM], 								//creates GrossPay array to accept double values
			Tax[EMPLOYEE_NUM], 									//creates Tax array to accept double vales
			overtime_hours[EMPLOYEE_NUM], 						//cretes overtime_hour to accept double values
			NetPay[EMPLOYEE_NUM],								//creates NetPay array to accept double values
			employee_TimeCard[EMPLOYEE_NUM],					//creates employeeTime Card array to accept double values (keeps hours in an array of each emp)
			overallNetPay, overallGrossPay; 					//creates OverallNet & Gross Pay data type double. to hold sum of employee net and gross pay	
	General_Employee_Data Armadillo[EMPLOYEE_NUM];				//structure makes an object instance Armdillo Array
	cout<<fixed<<showpoint<<setprecision(2);					//formatting
	cout<<setw(65)<<"Payroll for Armadillo Automotive Group" << endl;
	for (num=0; num<EMPLOYEE_NUM; num++,counter++){				//This section asks for input from 4 employees of the AUTO. Biz. and loops 4 times each time allocating the info to the Armadillo structure
		cout<<setw(50)<<"Employee " << counter << ":" << endl;	//ID Employee Name, PayRate and Type
		cout<<setw(52)<<"-----------"<< endl;
		cout<<setw(45)<<"Employee ID: ";
		cin>>Armadillo[num].employee_ID;
		while (Armadillo[num].employee_ID < 0 ) {
			cout<<setw(45)<<"ERROR: ENTER A NUMBER GREATER THAN 0." << endl;
			cout<<setw(45)<<"Employee ID: ";
			cin>>Armadillo[num].employee_ID;	
		}
		cout<<setw(45)<<"Employee Name: ";
		cin.ignore(20, '\n');
		cin.getline(Armadillo[num].employee_Name, 20);
//			while (Armadillo[num].employee_Name)
//			{
//				cout<<setw(45)<<"Employee Name: ";
//				cin.ignore(20, '\n');
//				cin.getline(Armadillo[num].employee_Name, 20);
//			}
		cout<<setw(45)<<"Pay Rate: ";
		cin>>Armadillo[num].payRate;
		while (Armadillo[num].payRate <= 0.0) {
			cout<<setw(45)<<"ERROR: ENTER A NUMBER GREATER THAN 0." << endl;
			cout<<setw(45)<<"Pay Rate: ";
			cin>>Armadillo[num].payRate;	
		}
		cout<<setw(45)<<"|Union: 0, Management: 1|: ";
		cin>>Armadillo[num].employee_Type;
		while (Armadillo[num].employee_Type != false && Armadillo[num].employee_Type != true ) {
			cout<<setw(45)<<"ERROR: ENTER UNION: 0 OR MANAGEMENT: 1" << endl;
			cout<<setw(45)<<"|Union: 0, Management: 1|: ";
			cin>>Armadillo[num].employee_Type;
		}
	}
	cout<<setw(70)<<"====================================================" << endl;
	cout<<setw(50)<<"Hours on Shift:" << endl;					//Start of TimeCard prompt
	cout<<setw(50)<<"---------------" << endl;
	for (num1=0; num1<EMPLOYEE_NUM; num1++) {					//This part asks for the hours worked for each individual ..it loops 4 times stroring each cell at a time
		cout<<right<<setw(37)<<"Amount of Hours " << Armadillo[num1].employee_Name << " worked: ";
		cin>>employee_TimeCard[num1];
		while (employee_TimeCard[num1] <= 0.0) {
			cout<<setw(37)<<"ERROR: ENTER A NUMBER GREATER THAN 0." << endl;
			cout<<right<<setw(37)<<"Amount of Hours " << Armadillo[num1].employee_Name << " worked: ";
			cin>>employee_TimeCard[num1];
	 	}
		if (employee_TimeCard[num1] <= 40.0 && Armadillo[num1].employee_Type == 0) {												
			GrossPay[num1]=employee_TimeCard[num1]*Armadillo[num1].payRate;
			Tax[num1]=GrossPay[num1]*TAX;						//Calculates for Net Gross Pay, and Tax if expression is True
			NetPay[num1]=GrossPay[num1]-Tax[num1];				
			continue;
		}
		else if (employee_TimeCard[num1] > 40.0 && Armadillo[num1].employee_Type == 0) {
			overtime_hours[num1]=employee_TimeCard[num1]-40;	//calculates for overtime , and employee hours
			employee_TimeCard[num1]-=overtime_hours[num1];		//also gross tax and net pay if expression is true
			GrossPay[num1]=(Armadillo[num1].payRate * 1.5) * overtime_hours[num1] + (employee_TimeCard[num1] * Armadillo[num1].payRate);
			Tax[num1]=GrossPay[num1] * TAX;
			NetPay[num1]=GrossPay[num1]-Tax[num1];
			continue;
		}
		else if (employee_TimeCard[num1] <= 40.0 || employee_TimeCard[num1] > 40.0 && Armadillo[num1].employee_Type == 1) {
			GrossPay[num1] = Armadillo[num1].payRate*employee_TimeCard[num1];
			Tax[num1] = GrossPay[num1]*TAX;						//if expression is true
			NetPay[num1] = GrossPay[num1]-Tax[num1];			//this calculates for gross and net pay plus tax
			continue;
		}
	}
	cout<<setw(70)<<"====================================================" << endl;
	cout<<setw(50)<<"Payroll Report" << endl;					//Entering Payroll
	cout<<setw(50)<<"--------------" << endl;					//Formatting Done more here
	cout<<"\t"<<left<<setw(5) << "ID" << left<< setw(15) << "Name" <<right<<setw(20)<< "Gross Pay"<<right<< setw(14)<< "Tax" <<right <<setw(14) << "Net Pay" << endl;
	for (num2=0; num2<EMPLOYEE_NUM; num2++) {
		cout<<"\t"<<left<<setw(5)<< Armadillo[num2].employee_ID<<left<<setw(15)<<Armadillo[num2].employee_Name<<right<<setw(20)<<GrossPay[num2]<<right<<setw(14)<<Tax[num2]<<right<<setw(14)<<NetPay[num2]<< endl;
		cout<<"\n";
		overallGrossPay+=GrossPay[num2];						//This section prints out the results of
		overallNetPay+=NetPay[num2];							//ID Name GrossPay NetPay and Overall Gross and Net Pay
	}
	cout<<setw(25)<< "Total Gross Pay $" << overallGrossPay << setw(37) << "Total Net Pay $" << overallNetPay << endl;
	cout<<setw(76)<<"====================================================================" << endl;	
	return 0;
}