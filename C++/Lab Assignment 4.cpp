/**
 * @file Lab Assignment 4.cpp
 * @author Bernardo Flores
 * @brief Program asks user for month day and year. The output is in AM, EU, and Numeric.
 * @version 0.1
 * @date 2023-04-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/* Date class formates dates in numeric, american, and european. Also has an int input to string output */
class Date {
	// Only accessible thru this suite
	private:
		int month, day, year;		// assigned variables of data type int
		string getMonthName(int month){	//this function gets the value for an int 1-12, and replaces the int with January-December. Can be called
			string stringMonth;		//holds a string value that will be returned
			switch(month) {			//switch statement for int to string conversion
				case 1: stringMonth="January";
						break;
				case 2: stringMonth="February";
						break;
				case 3: stringMonth="March";
						break;
				case 4: stringMonth="April";
						break;
				case 5: stringMonth="May";
						break;
				case 6: stringMonth="June";
						break;
				case 7: stringMonth="July";
						break;
				case 8: stringMonth="August";
						break;
				case 9: stringMonth="September";
						break;
				case 10: stringMonth="October";
						break;
				case 11: stringMonth="Novemeber";
						break;
				case 12: stringMonth="December";
						break;
				default: stringMonth="January";
			}
			return stringMonth;	//return value of string
		}
	// accessible by other functions
	public:
		Date() {
			month=1;	//all three values are automaticall set depending if Date() is called
			day=1;
			year=2001;
		}
		//setParameter holds the input values from user in this set up
		//and decides whether or not the values inputted are valid months, days, and years.
		void setParameter(int newMonth,int newDay,int newYear) {	// delete else and test return; on if....
			if ((newMonth >= 1 && newMonth <= 12) && (newDay >= 1 && newDay <= 31) && (newYear >= 1950 && newYear <= 4000)) {
				month=newMonth;
				day=newDay;
				year=newYear;
			}
			else {
				cout<<fixed<<setprecision(1);
				cout<< left << setw(25) << "ONE ENTRY IS BAD!\t";
				return;
			}
		}
		//formats for numeric with prompt
		void Numeric_Format() {
			cout<< month <<"/"<< day << "/" << year;
		}
		//formats for american with prompt, calls getMonthName for conversion
		void American_Format() {
			cout<< getMonthName(month) << " " << day << ", " << year;
		}
		//swapped formatting for day and month with prompt, calls on getMonthName for conversion.
		void European_Format() {
			cout<< day << " " << getMonthName(month) << " " << year;
		}
		

};
//int main is used by users. input and outputs Plus, class setup and calls.
int main(){
	int month,	//holds month values for user
		day,	//holds day values input by user
		year;	//holds year value input by user
	cout<<fixed<<setprecision(1);	//style formatting
	Date fake,
		firstObj, 		//first instance of Date
		secondObj, 		//second instance of Date
		thirdObj;		//third instance of Date
	cout<< right << setw(60) << "Welcome to Date Formatting Class Program!" << endl;	//welcome prompt
	cout<<"Orginal Dates:" << endl;
	fake.European_Format();
	cout<<"\n"; 
	fake.Numeric_Format();
	cout<<"\n";
	fake.American_Format();
	cout<<"\n";
	cout<<"In order, enter the Month, Day, Year. Each followed by a space." << endl;
	cout<<"When done press [Enter]: ";
	cin>>month>>day>>year;
	
	firstObj.setParameter(month,day,year);		//setting pararmters for instance of date class
	secondObj.setParameter(month,day,year);		//setting paramter for second instance of date class
	thirdObj.setParameter(month,day,year);		//setting parameter for third instance of date class
	
	cout<<"\n";
	cout<<"Formatted Dates below: " << endl;
	cout<<"\n";
	//output
	cout<< right << setw(35) << "Numeric Format: ";
	firstObj.Numeric_Format();	//calls this function
	cout<<"\n\n";
	cout<< right << setw(35) << "American Format: ";
	secondObj.American_Format();	//calls american function
	cout<<"\n\n";
	cout<< right << setw(35) << "European Format: "; 
	thirdObj.European_Format();		//calls european format fuction	
	return 0;
}