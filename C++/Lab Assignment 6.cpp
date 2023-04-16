//Bernardo Flores
//Complete
//This an array program that asks for amount of food eaten for 7 days per monkey
//and results in its average, least eaten, and largest eaten.
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MONK = 3;																	//used for cells in Monkey_DailyIntake[HERE][], for loop range also
const int NUM_DAYS = 7;																//used for cells in Monkey_DailyIntake[][HERE], for loop range also
void doInput();
void Display(const double Monkey_DailyIntake[][NUM_DAYS], const string Week[], const string Monkey[], const int, const int);//prototype 
float AverageIntake_OfAll(const double Monkey_DailyIntake[][NUM_DAYS], const int, const int);								//prototype
float WhoAteTheLeast(const double Monkey_DailyIntake[][NUM_DAYS], const int, const int);									//prototype
float WhoAteTheLargest(const double Monkey_DailyIntake[][NUM_DAYS], const int, const int);									//prototype

int main(){							//Main function does calls function that loops and calls all function
	doInput();
	return 0;
}
void doInput(){						//declares data and loops through cin and input info of monkey and food
	const string Week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};		//creates a array to be able to display days of week for I & O.
	const string Monkey[] = {"1","2","3"};											//creates a array to display Monkey count for I & O display
	double Monkey_DailyIntake[MONK][NUM_DAYS];										//creates an array that accepts double values for MONKey count and the DAYS
	float average,																	//creates average to return a called function 
		least, 																		//creates least to return a called function
		largest;																	//creates largest to return a called function
	cout<<"Welcome!" <<endl;
	for (int monkey=0; monkey<MONK; monkey++) {										//loops 3x7 for input on 3 monkeys for 7 days
		for	(int day=0; day<NUM_DAYS; day++) {	
			cout<<"Enter pounds of food eaten by monkey " << Monkey[monkey] << " on " << Week[day] << ": ";
			cin>>Monkey_DailyIntake[monkey][day];
		}
	}
	cout<<"Calculating Results..."; 
	Sleep(4000);	
	cout<<fixed;																	//formatting
	cout<<endl;
	
	cout<<"POUNDS OF FOOD EATEN BY MONKEY AND DAY OF WEEK" << endl;
	cout<<endl;
	cout<<setw(8)<<"Monkey";
	
	Display(Monkey_DailyIntake, Week, Monkey, MONK, NUM_DAYS);						//calls display to input information for each monkey in the day
	average=AverageIntake_OfAll(Monkey_DailyIntake, MONK, NUM_DAYS);				//assigns average function to be able to be called
	least=WhoAteTheLeast(Monkey_DailyIntake, MONK, NUM_DAYS);						//assigns least function to be able to be called
	largest=WhoAteTheLargest(Monkey_DailyIntake, MONK, NUM_DAYS);					//assigns largest function to be able to be called
	
	cout<<"The combined average of food all monkeys in the week: "<<average;		//displays average
	cout<<endl;
	cout<<"The least amount of food eaten by any monkey in any day: "<<least;		//displays least
	cout<<endl;
	cout<<"The largest amount of food eaten by any monkey in any day: "<<largest;	//displays largest
	
}
void Display(const double Monkey_DailyIntake[][NUM_DAYS], const string Week[], const string Monkey[], const int MONK, const int NUM_DAYS) {																					//Display function 	passes all arrays and const int
	cout<<fixed<<showpoint<<setprecision(1);										//nd displays all input info
	for (int day=0; day<NUM_DAYS; day++){											//displasy days of the week and Monkey is in Main
		cout<<setw(8)<<Week[day];
	}
	cout<<endl;
	for (int monkey=0; monkey<MONK; monkey++){										//displasy for three monkeys all the food in 7 days
		cout<<setw(8)<<Monkey[monkey];
		for (int days=0; days<NUM_DAYS; days++) {
			cout<<setw(8)<<Monkey_DailyIntake[monkey][days];
		}
		cout<< endl;
	}
	cout<<endl;
}
float AverageIntake_OfAll(const double Monkey_DailyIntake[][NUM_DAYS], const int MONK, const int NUM_DAYS) {	//AverageIntake_OfALl  passes MonkeyIntake array and const ints
	float sum=0;																				//returns float average
	for (int monk=0; monk<MONK; monk++)	{													//sums all the monkeys food eaten 
		for (int day=0; day<NUM_DAYS; day++) {
			sum+=Monkey_DailyIntake[monk][day];
		}
	}
	return sum/NUM_DAYS;																	//returns average 
}
float WhoAteTheLeast(const double Monkey_DailyIntake[][NUM_DAYS], const int MONK, const int NUM_DAYS) {																							//WHoAteTHeLeast is passed the MonkeyIntake array and const ints
	float lowest=Monkey_DailyIntake[0][0];													//assigns lowest as a beginnning array  cell;
	for (int monkey=0; monkey<MONK; monkey++) {
		for (int day=0; day<NUM_DAYS; day++) {												//tests whether a number is least in the array and gives that as
			//least amount eaten out of all monekys in the week
			if (Monkey_DailyIntake[monkey][day] < lowest) {
				lowest=Monkey_DailyIntake[monkey][day];
			}
		}
	}
	return lowest;																			//returns lowest
}
float WhoAteTheLargest(const double Monkey_DailyIntake[][NUM_DAYS], const int MONK, const int NUM_DAYS)	{
																					//WhoAteTheLargest is passed the monkeyIntake array and const ints
	float largest = Monkey_DailyIntake[0][0];										//is given the largest variable as array cell beginning
	for (int monkey=0; monkey<MONK; monkey++) {										//for the monekys in the days of the weeks
		//this loop will find the largest in the week out of all the monekys
		for (int day=0; day<NUM_DAYS; day++) {										//and store that as the largest
			if (Monkey_DailyIntake[monkey][day] > largest) {
				largest=Monkey_DailyIntake[monkey][day];
			}
		}
	}
	return largest;																	//returns largest
}