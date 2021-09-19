#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
using namespace std;

struct UserInfo
{
	double measured_height,height,BMI,weight;
	string name;
};
void placeCursor(HANDLE, int, int);
void displayPrompts(HANDLE);
void getUserInput(HANDLE, UserInfo&);
void displayData(HANDLE, UserInfo);

int main()
{
	UserInfo input;
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	displayPrompts(screen);
	getUserInput(screen, input);
	displayData(screen, input);
	return 0;
}
void placeCursor(HANDLE screen, int row, int col)
{
	COORD position;
	position.Y=row;
	position.X=col;
	SetConsoleCursorPosition(screen, position);
}
void displayPrompts(HANDLE screen)
{
	placeCursor(screen, 3, 45);
	cout<<"******* Data Entered *******"<<endl;
	placeCursor(screen, 5, 35);
	cout<<"Name: " << endl;
	placeCursor(screen, 7, 35);
	cout<<"Height:				Weight: "<<endl;
}
void getUserInput(HANDLE screen, UserInfo &input)
{
	placeCursor(screen, 5, 41);
	getline(cin, input.name);
	placeCursor(screen, 7, 43);
	cin>>input.measured_height;
	placeCursor(screen, 7, 80);
	cin>>input.weight;
	input.height = input.measured_height*12.0;
	input.BMI = input.weight*703/pow(input.height, 2);
}
void displayData(HANDLE screen, UserInfo input)
{
	cout<<fixed<<showpoint<<setprecision(2);
	placeCursor(screen, 10, 0);
	cout<<setw(81)<<"******Here is the data you entered.******\n\n";
	cout<<right<<setw(55)<<"Name: " << input.name << endl;
	cout<<right<<setw(55)<<right<<"Height: " << input.measured_height << endl;
	cout<<right<<setw(55)<<"Body Mass Index: " << input.BMI << endl;
}
