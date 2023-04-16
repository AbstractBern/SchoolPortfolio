/*	
	Bernardo Flores
	Complete
	This program asks for student names (owrks for 30 char or less)
	and a test grade (as integer). All scores will be combined for an average.
	Inputs should not be floating point number.
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct StudentGrade {
	string Name;
	int Score;
};
int SizeDeclaration(int&);								//prototype for declaring size and referencing it back to main.
void StoringPairs(StudentGrade *room, int);				//prototype for Storing information into pointer array of struct.
void SortArray(StudentGrade *room, int);				//prototype for sorting array of struct pointer
float AverageOfClass(StudentGrade *room, int, float&);	//prototype for Averaging the pointer with array of struct
void DisplayInfo(const StudentGrade *room, int, float);	//Prototype for displaying information of pointer
														
int main() {									//Main function declares: necessary data types, such as student, average, and pointer to StudentGrade array.
											//Additionally calls all 5 functions for program to work
	int STUDENTS;							//holds integer reference for amount of STUDENTS needed to be average
	float Average;							//holds float reference for Average operation of all students scores
	cout<<fixed<<showpoint;					//formatting
	cout<<setw(50)<<"Welcome to Test Score Averaging!"<<endl;
	SizeDeclaration(STUDENTS);				//Call to SizeDeclaration returns reference of students for that amount of elements in Array
	cout<<endl;
	StudentGrade *room;						//holds null value to *ptr room of type StudentGrade struct
	room = new StudentGrade[STUDENTS];		//holds array of stuct StudentGrade to pointer room
	StoringPairs(room, STUDENTS);			//Call to storing information in pointer
	SortArray(room, STUDENTS);				//Call to Sort the information in pointer
	AverageOfClass(room, STUDENTS, Average);//Call to AverageClass that returns the Average of all scores
	DisplayInfo(room, STUDENTS, Average);	//Calll to display scores and names of pointer
	cout<<"Have fun in class!";
	return 0;
}
int SizeDeclaration(int &STUDENTS) {						//SizeDeclaration function asks for the amount of students needed to be graded
														//and returns the STUDENT for a element size by reference
	cout<<"How many students will you be grading? ";
	cin>>STUDENTS;
	while (STUDENTS < 0 && STUDENTS > 105)				//loops if only the numbers are not in range until a number is valid
	{
		cout<<"\nERROR!: Integer needs to be between 0 and 105."<<endl;
		cout<<"How many students will you be grading? ";
		cin>>STUDENTS;
	}
	return STUDENTS;
}
void StoringPairs(StudentGrade *room, int STUDENTS)		//StoringPairs function asks for Name of Student and Score that student for the STUDENT amount
{														//information is inputted to pointer variable
	for (int i=0; i<STUDENTS; i++)
	{
		cout<<"Enter name of student: ";
		cin.ignore(30, '\n');
		getline(cin, room->Name);
		room->Name=room->Name.substr(0,30);				//Name
		cout<<"Enter "<<room->Name<<"'s score: ";
		cin>>room->Score;								//Score
		cout<<endl;
		room++;
	}
}
void SortArray(StudentGrade *room, int STUDENTS)		//SortArray function takes information from pointer variable room and
{														//sorts it from increasing order
	int temp;											//holds copy of arraay
	string temp1;
	bool madeAswap;										//holds True or False for stopping array calc
	do
	{
		madeAswap=false;								//holds bool for false
		for (int i=0; i<STUDENTS-1; i++)
		{
			if (room[i].Score > room[i+1].Score)		//if true: begans sorting
			{
				temp=room[i].Score;						//sort score
				room[i].Score=room[i+1].Score;
				room[i+1].Score=temp;
				temp1=room[i].Name;						//sorts name according to score 
				room[i].Name=room[i+1].Name;
				room[i+1].Name=temp1;
				madeAswap=true;							//bool declared true if calc correct
			}
			//room++;
		}
	}while (madeAswap);
	//for (int i=0; i<STUDENTS; i++)//...If one were to print out the new array. This would work.
	//{
	//	cout<<room->Name;
	//	room++;
	//}
}
float AverageOfClass(StudentGrade *room, int STUDENTS, float &Average)	//AverageOfClass function
{														//returns by reference the average of combined student grades
	Average=0.0;										//sets average to 0 fo accumulation
	for (int i=0; i<STUDENTS; i++)						//looping for sum
	{
		Average+= room->Score;
		room++;
	}
	Average=Average/STUDENTS;							//Sum divided the students for Average
	return Average;										//return
}
void DisplayInfo(const StudentGrade *room, int STUDENTS, float Average)	//DisplayInfo function
{														//Displays information from pointer variable struct
	cout<<fixed<<showpoint<<setprecision(2);			//formats for two decimal points
	cout<<"Name"<<setw(30)<<"Score"<<endl;				//Prompt for name/score
	cout<<"=================================="<<endl;
	for (int i=0; i<STUDENTS; i++)						//loops through pointer variable
	{
		cout<<setw(32)<<left<<room->Name<<room->Score<<endl;
		room++;							
	}
	cout<<"----------------------------------"<<endl;
	cout<<setw(30)<<"Average"<<Average<<endl;			//Average prompt
}
