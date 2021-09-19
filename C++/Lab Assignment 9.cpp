/*
	Bernardo Flores
	Complete (For the most part, this does not have functions nor a good floating point standard or formatting).
	This program is a revising of a payroll program that uses class employee and struct. It imports two files of timehseet and masterfile
	It turns information into a Payroll File.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
struct TimeSheet			//struct TimeSheet holds float HoursinWeek.
{
	float HoursInWeek;		//Time sheet struct will hold float HoursInWeek from the trans9 txt file
};
class Employee				//class Employee holds id, name, pay, dependent, and type of information and member functions for seting and getting
{
	private:
		int id;				//holds integer id 
		string name;		//holds string value name
		double hourlypay;	//holds double value hourlpay
		int numDeps;		//holds number value of deps
		int type;			//holds int value of type union/management
	public:
		Employee(int initId=0, string initName="", double initHourlyPay=0.0, int initNumDeps=0, int initType=0);
		bool set(int newId, string newName, double newHourlyPay, int newNumDeps, int newType);
		int getId();
		string getName();
		double getHourlyPay();
		int getNumDeps();
		int getType();
};
Employee::Employee(int initId, string initName, double initHourlyPay, int initNumDeps, int initType)	//default constructor
{
	bool status=set(initId, initName, initHourlyPay, initNumDeps, initType);
	if (!status)
	{
		id=0;
		name="";
		hourlypay=0.0;
		numDeps=0;
		type=0;
	}
}
bool Employee::set(int newId, string newName, double newHourlyPay, int newNumDeps, int newType)	//sets data
{
	bool status=false;
	if (newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && newType >= 0 && newType <=1)
	{
		status=true;
		id=newId; 
		name=newName;
		hourlypay=newHourlyPay;
		numDeps=newNumDeps;
		type=newType;
	}
	return status;
}
int Employee::getId()	//return id
{	
	return id;
 }
string Employee::getName()	//return name
{	
	return name;
}
double Employee::getHourlyPay()	//return hourlypay
{	
	return hourlypay;
}
int Employee::getNumDeps()		//return num deps
{	
	return numDeps;	
}
int Employee::getType()			//return get type
{	
	return type;
}
int main()					//Main does all the calculations and requirements forthis program to work
{
	const double TAX=0.15;	//holds const duble value of 0.15 tax
	const int EMP=6;		//holds employee count
	Employee AAG[EMP];		//class employee object instance AAG of employee count
	TimeSheet EMP_AAG[EMP];	//struct TimeSheet variable EMP_AAG of employee count
	string name;			//holds a string name
	double ratepay,			//holds double value ratepay
		GrossPay[EMP], 		//creates GrossPay array to accept double values			
		Tax[EMP], 			//creates Tax array to accept double vales
		overtime_hours[EMP],	//cretes overtime_hour to accept double values
		NetPay[EMP],				//creates NetPay array to accept double value
		employee_TimeCard[EMP],			//creates employeeTime Card array to accept double values (keeps hours in an array of each emp)			
		overallNetPay, overallGrossPay, 	//creates OverallNet & Gross Pay data type double. to hold sum of employee net and gross pay
		hoursworked;
	int id,								//holds an integer id.
		id1,						
		dep,						//holds a integer dependents
		type;					//holds an integer type for union or management	
	ifstream MasterFile;	//ifstream object Master File is made for reading
	ifstream TimeSheetFile;	//ifstream TimeSheetFile made as an instance made for reading
	ofstream PayrollFile;	//PayrollFile made for writing file...4
	MasterFile.open("master9.txt");	//open master9 txt
	TimeSheetFile.open("trans9.txt");		//trans9 txt
	PayrollFile.open("PayrollReport9.txt");	//opens payroll txt file
	if (!MasterFile && !TimeSheetFile && !PayrollFile)	//if error prints statement
	{
		cout<<"Something went wrong bruh"<<endl;
	}
	for (int i=0; i<EMP; i++)
	{
		TimeSheetFile>>id1>>hoursworked;				//reads id from trans 9 txt file
		EMP_AAG[i].HoursInWeek=hoursworked;		//sets hoursworked from the trans9 file
	}
	for (int i=0; i<EMP; i++)
	{
		MasterFile>>id;					//holds file data id to this
		getline(MasterFile, name, '#');	//reads line up to the pound sign and brings data into name
		MasterFile.ignore();			//ignore space
		MasterFile>>ratepay;			//reads data into ratepay
		MasterFile.ignore();			//ignore space
		MasterFile>>dep;				//reads data into dependents
		MasterFile.ignore();			//ignore space
		MasterFile>>type;				//reads into type (union or management)
		AAG[i].set(id,name,ratepay,dep,type);	//sets data from master9 txt into  the object class employee
	}
	MasterFile.close();				//close master file
	TimeSheetFile.close();			//close timesheet file

	for (int j=0; j<EMP; j++)		//this portino does calculations for the object information and hoursworked struct timehseet
	{
		
		if (EMP_AAG[j].HoursInWeek <= 40.0 && AAG[j].getType()== 0)
		{										
			GrossPay[j]=EMP_AAG[j].HoursInWeek*AAG[j].getHourlyPay();
			Tax[j]=GrossPay[j]*TAX;						//Calculates for Net Gross Pay, and Tax if expression is True
			NetPay[j]=GrossPay[j]-Tax[j];				
			continue;
		}
		else if (EMP_AAG[j].HoursInWeek > 40.0 && AAG[j].getType()== 0)
		{
			overtime_hours[j]=EMP_AAG[j].HoursInWeek-40;	//calculates for overtime , and employee hours
			employee_TimeCard[j]-=overtime_hours[j];		//also gross tax and net pay if expression is true
			GrossPay[j]=(AAG[j].getHourlyPay()* 1.5) * overtime_hours[j] + (EMP_AAG[j].HoursInWeek * AAG[j].getHourlyPay());
			Tax[j]=GrossPay[j] * TAX;
			NetPay[j]=GrossPay[j]-Tax[j];
			continue;
		}
		else if (EMP_AAG[j].HoursInWeek <= 40.0 || EMP_AAG[j].HoursInWeek > 40.0 && AAG[j].getType() == 1)
		{
			GrossPay[j] = AAG[j].getHourlyPay()*EMP_AAG[j].HoursInWeek;
			Tax[j] = GrossPay[j]*TAX;						//if expression is true
			NetPay[j] = GrossPay[j]-Tax[j];			//this calculates for gross and net pay plus tax
			continue;
		}
	}
	cout<<fixed<<showpoint<<setprecision(2);
	PayrollFile <<setw(50) << "Payroll Report"<<endl;
	PayrollFile<<right<<setw(20)<<"ID"<<setw(7)<<"Name"<<setw(21)<<"Gross Pay"<<setw(10)<<"Tax"<<setw(10)<<"Net Pay"<<endl;
	for (int i=0; i<EMP; i++)		//prints get data from object and seets overall net and gross pay
	{
		PayrollFile<<setw(20)<<AAG[i].getId()<<setw(23)<<AAG[i].getName()<<setw(2)<< GrossPay[i]<<setw(10)<<Tax[i]<<setw(10)<<NetPay[i]<<endl;
		overallGrossPay+=GrossPay[i];						//This section prints out the results of
		overallNetPay+=NetPay[i];
	}
	PayrollFile<<setw(38)<<"Overall Gross Pay: $"<<overallGrossPay<<setw(38)<<"Overall Net Pay: $"<<overallNetPay;
	PayrollFile.close();
	cout<<"Loading data into file..."<<endl;
	Sleep(2000);
	cout<<"Payroll Report File Complete";
	return 0;
}
