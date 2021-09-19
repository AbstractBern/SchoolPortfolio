#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
const int LEN=21;
struct TimeSheet			//struct TimeSheet holds float HoursinWeek.
{
	float HoursInWeek;		//Time sheet struct will hold float HoursInWeek from the trans9 txt file
};
class Employee				//class Employee holds id, name, pay, dependent, and type of information and member functions for seting and getting
{
	
	private:
		int id;				//holds integer id 
		char name[LEN];		//holds string value name
		double hourlypay;	//holds double value hourlpay
		int numDeps;		//holds number value of deps
		int type;			//holds int value of type union/management
	public:
		Employee(int initId=0, char initName[]={0}, double initHourlyPay=0.0, int initNumDeps=0, int initType=0);
		bool set(int newId, char newName, double newHourlyPay, int newNumDeps, int newType);
		int getId();
		char getName();
		double getHourlyPay();
		int getNumDeps();
		int getType();
};
Employee::Employee(int initId, char initName[], double initHourlyPay, int initNumDeps, int initType)	//default constructor
{
	bool status=set(initId, initName[LEN], initHourlyPay, initNumDeps, initType);
	if (!status)
	{
		id=0;
		name[LEN];
		hourlypay=0.0;
		numDeps=0;
		type=0;
	}
}
bool Employee::set(int newId, char newName, double newHourlyPay, int newNumDeps, int newType)	//sets data
{
	bool status=false;
	if (newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && newType >= 0 && newType <=1)
	{
		status=true;
		id=newId; 
		name[LEN]=newName;
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
char Employee::getName()	//return name
{	
	return name[LEN];
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
int main()
{
	const int EMP_NUM=101;
	const double TAX=0.15;	//holds const duble value of 0.15 tax
	Employee AAG[EMP_NUM];		//class employee object instance AAG of employee count
	TimeSheet EMP_AAG[EMP_NUM];	//struct TimeSheet variable EMP_AAG of employee count
	char name[LEN];			//holds a string name
	double ratepay,			//holds double value ratepay
		GrossPay[EMP_NUM], 		//creates GrossPay array to accept double values			
		Tax[EMP_NUM], 			//creates Tax array to accept double vales
		overtime_hours[EMP_NUM],	//cretes overtime_hour to accept double values
		NetPay[EMP_NUM],				//creates NetPay array to accept double value
		employee_TimeCard[EMP_NUM],			//creates employeeTime Card array to accept double values (keeps hours in an array of each emp)			
		overallNetPay, overallGrossPay, 	//creates OverallNet & Gross Pay data type double. to hold sum of employee net and gross pay
		hoursworked;
	int id,								//holds an integer id.
		id1,						
		dep,						//holds a integer dependents
		type;					//holds an integer type for union or management	
	ifstream MasterFile;	//ifstream object Master File is made for reading
	ifstream TimeSheetFile;	//ifstream TimeSheetFile made as an instance made for reading
	ofstream PayrollFile;	//PayrollFile made for writing file...4
	cout<<"eginning";
	MasterFile.open("master10.txt");	//open master9 txt
	TimeSheetFile.open("trans10.txt");		//trans9 txt
	PayrollFile.open("PayrollReport10.txt");	//opens payroll txt file
	if (!MasterFile && !TimeSheetFile && !PayrollFile)	//if error prints statement
	{
		cout<<"Something went wrong bruh"<<endl;
	}
	cout<<"here";
	for (int i=0; i<EMP_NUM; i++)
	{
		MasterFile>>id;					//holds file data id to this
		MasterFile.getline(name, LEN);	//reads line up to the pound sign and brings data into name
		MasterFile.ignore();			//ignore space
		MasterFile>>ratepay;			//reads data into ratepay
		MasterFile.ignore();			//ignore space
		MasterFile>>dep;				//reads data into dependents
		MasterFile.ignore();			//ignore space
		MasterFile>>type;				//reads into type (union or management)
		MasterFile.ignore();
		AAG[i].set(id,name[LEN],ratepay,dep,type);	//sets data from master9 txt into  the object class employee
	}
	cout<<"Now";
	for (int i=0; i<EMP_NUM; i++)
	{
		TimeSheetFile>>id1>>hoursworked;				//reads id from trans 9 txt file
		if (id1 == AAG[i].getId())
		{
			EMP_AAG[i].HoursInWeek=hoursworked;		//sets hoursworked from the trans9 file
		}
	}
	for (int i=0; i<EMP_NUM; i++)
	{
		cout<<EMP_AAG[i].HoursInWeek<<"  class   "<<AAG[i].getId()<<endl;
	}
	MasterFile.close();				//close master file
	TimeSheetFile.close();			//close timesheet file
	PayrollFile.close();
	return 0;
}
