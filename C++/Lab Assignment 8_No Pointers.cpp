/*	Bernardo Flores
	Complete-Need Pointers!!!
	This program asks for student names under 30 characters
	and a score. ALl inputs will be operated for an average.
	Data Types will be using pointers.
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct StudentGrade
{
	string Name;
	int Score;
};

int SizeDeclaration(int&);
void StoringPairs(StudentGrade room[], int);
void SortArray(StudentGrade room[] , int);
float AverageOfClass(StudentGrade room[] , int, float&);
void DisplayInfo(StudentGrade room[], int, float);

int main()
{
	int STUDENTS;
	float Average;
	cout<<fixed<<showpoint;
	cout<<setw(50)<<"Welcome to Test Score Averaging!"<<endl;
	SizeDeclaration(STUDENTS);
	cout<<endl;
	StudentGrade room[STUDENTS];
	StoringPairs(room, STUDENTS);
	SortArray(room, STUDENTS);
	AverageOfClass(room, STUDENTS, Average);
	DisplayInfo(room, STUDENTS, Average);
	cout<<"Have fun in class!";
	return 0;
}
int SizeDeclaration(int &STUDENTS)
{
	cout<<"How many students will you be grading? ";
	cin>>STUDENTS;
	while (STUDENTS < 0 && STUDENTS > 105)
	{
		cout<<"\nERROR!: Integer needs to be between 0 and 105."<<endl;
		cout<<"How many students will you be grading? ";
		cin>>STUDENTS;
	}
}
void StoringPairs(StudentGrade room[], int STUDENTS)
{
	string Name[30];
	for (int i=0; i<STUDENTS; i++)
	{
		cout<<"Enter name of student: ";
		cin.ignore(30, '\n');
		getline(cin, room[i].Name);
		room[i].Name=room[i].Name.substr(0,30);
		cout<<"Enter "<<room[i].Name<<"'s score: ";
		cin>>room[i].Score;
		cout<<endl;
	}
}
void SortArray(StudentGrade room[], int STUDENTS)
{
	int temp;
	bool madeAswap;
	do
	{
		madeAswap=false;
		for (int i=0; i<STUDENTS; i++)
		{
			if (room[i].Score > room[i].Score)
			{
				temp=room[i].Score;
				room[i].Score=room[i+1].Score;
				room[i+1].Score=temp;
				madeAswap=true;
			}
		}
	}while (madeAswap);
}
float AverageOfClass(StudentGrade room[], int STUDENTS, float &Average)
{
	for (int i=0; i<STUDENTS; i++)
	{
		Average+=room[i].Score;
	}
	Average=Average/STUDENTS;
	return Average;
}
void DisplayInfo(StudentGrade room[], int STUDENTS, float Average)
{
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"Name"<<setw(30)<<"Score"<<endl;
	cout<<"=================================="<<endl;
	for (int i=0; i<STUDENTS; i++)
	{
		cout<<setw(32)<<left<<room[i].Name<<room[i].Score<<endl;
	}
	cout<<"----------------------------------"<<endl;
	cout<<setw(30)<<"Average"<<Average<<endl;
}
