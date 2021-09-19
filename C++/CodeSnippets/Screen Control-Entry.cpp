#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
struct UserInfo
{
	string name;
	int age;
	char gender;
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
	placeCursor(screen, 3, 25);
	cout<<"******* Data Entry Form *******"<<endl;
	placeCursor(screen, 5, 25);
	cout<<"Name: " << endl;
	placeCursor(screen, 7, 25);
	cout<<"Age:				Gender (M/F): "<<endl;
}
void getUserInput(HANDLE screen, UserInfo &input)
{
	placeCursor(screen, 5, 31);
	getline(cin, input.name);
	placeCursor(screen, 7, 30);
	cin >> input.age;
	placeCursor(screen, 7, 70);
	cin >> input.gender;
}
void displayData(HANDLE screen, UserInfo input)
{
	placeCursor(screen, 10, 0);
	cout<<"Here is the data you entered.\n";
	cout<<"Name		: " << input.name << endl;
	cout<<"Age		: " << input.age << endl;
	cout<<"Gender		: " << input.gender << endl;
}
