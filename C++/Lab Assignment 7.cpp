//Bernardo Flores
//Complete
//This program determins Shipping Cost, weight, transaction count, and Status of Packages shipped
// by Lone Star Package Service within the State of Texas
#include <iostream>
#include <iomanip>
using namespace std;
void HelloPrompt();
void ErrorPrompt();
float PackageCost(int, float, const float Charge[], const int Pounds[], const int);
void TransactionPrompt(int, int, float, string);
void PackageCountPrompt(int, int);

//main function holds intitalizes data and makes a loop and also calls to functions for processing packages.
int main()
{
	const int IND=2, INDEX=15;				//const subscript for dimension array
	const double DIM_REQ=(12.0*3),			//dimension 3 feet requirement
				GIRTH_REQ=(12.0*5),			//girth 5 feet requirement
				PACK_REQ=50;				//package weight 50 pound requirement
	const float Charge[INDEX] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.20, 27.30, 31.90, 38.50, 43.50, 44.80, 47.40, 55.20};//used to calculate the Charge according to 
	const int Pounds[INDEX] = {1, 2,3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};		//Weight and Pounds is used for the purpose of finding the Charge of the Package
	double girth,							//used to hold the value of dimension times 2 - largest dim.
		largestDim,							//used for calculating girth, holds the largest Dimension of the three through a loop
		dimension[IND];						//holds 3 dimensions
	string PkgStatus;						//holds either "Accepted" or "Rejected"
	float PkgCost;							//hold the PkgCost according to Pounds and Charge Array
	int Accepted=0,							//holds the running total for Accepted Packs
		Rejected=0,							//holds the running total for Rejected Packs
		tCount=0,							//holds running total for Transaction count
		PkgWeight,							//holds the PkgWeight the user entered, which mirrors weight
		weight;								//used to predetermine if the program should quit and if doesnt Pkgweight=weight for it to be passed on
	cout<<fixed<<showpoint<<setprecision(2);
	HelloPrompt();							//Service Name Prompt
	while (weight != -1)					//loops for all transaction until weight or user enters -1
	{
		cout<<endl;
		cout<<"Enter package weight (pounds) and 3 dimensions (inches): ";
		cin>>weight;						//ask for weight to predetermine if the program should exit and drop to the Package Count
		if (weight == -1)
		{	break;	}				
		cin>>dimension[0]>>dimension[1]>>dimension[2];
		if ((dimension[0] <=0 || dimension[1] <=0 || dimension[2] <= 0) || (dimension[0] > DIM_REQ || dimension[1] > DIM_REQ || dimension[2] > DIM_REQ))
		{
			ErrorPrompt();					//used to call error message if the requirements ^above are met
			continue;
		}
		PkgWeight=weight;					//passes weight to PgWeight
		for (int i=0; i<IND; i++)			//this loop determines what the largestDimension will be according to the array of Dimension
		{
			if (dimension[i] > dimension[0])
			{	largestDim=dimension[i];	}
			else if (dimension[0] > dimension[i])
			{	largestDim=dimension[0];	}
		}
		girth = 2 * (dimension[0]+dimension[1]+dimension[2]-largestDim);	//sets girth according to information given
		if (girth > GIRTH_REQ)				//decides if Pkg status should increment Rejected 
		{	PkgStatus="Rejected";			//and give PjgStatus "rejected" string
			Rejected+=1;
		}
		if (girth < GIRTH_REQ)				//decides if PkgStatus should be given string "accepted"
		{	PkgStatus="Accepted";			//and increment accepted
			Accepted+=1;
		}
		for (int i=0; i<INDEX; i++)			//loop decides what the PkgCost should be determined by the Charge and Pound Array
		{									//Parallel Array
			if  (weight > Pounds[i] && weight <= Pounds[i+1])
			{
				PkgCost=Charge[i+1];
			}
			else if (weight==Pounds[i])
			{
				PkgCost=Charge[i];
			}
		}
		tCount+=1;							//incrementing transaction count
		TransactionPrompt(tCount, PkgWeight, PkgCost, PkgStatus);//call to the function for prompt
	}	
	cout<<endl;
	PackageCountPrompt(Accepted, Rejected);//call to the package count
	return 0;
}
//this function is for welcoming prompt
void HelloPrompt()							
{
	cout<<setw(50)<<"Lone Star Package Servicing"<<endl;
	cout<<"For each transation, enter package weight and 3 dimensions (seperate by space). or -1 to quit";
}
//this function prints an error message
void ErrorPrompt()							
{
	cout<<endl;
	cout<<setw(50)<<"ERROR! : Entries need be less than 0. Pounds < 50 and Dimensions less than 36 inches."<<endl;
	cout<<setw(50)<<"Please re-enter transaction."<<endl;
}
//Tihs function prints out the information given
void TransactionPrompt(int tCount, int PkgWeight, float PkgCost, string PkgStatus)	
{
	cout<<endl;
	cout<<setw(50)<<"Transaction: "<< tCount <<endl;
	cout<<setw(50)<<"Status: " << PkgStatus <<endl;
	cout<<setw(50)<<"Weight: "<< PkgWeight <<endl;
	cout<<setw(50)<<"Cost: "<< PkgCost <<endl;	
}
//this function prints out accepted and rejected packages
void PackageCountPrompt(int Accepted, int Rejected)
{
	cout<<endl;
	cout<<setw(50)<<"Number of accepted packages: "<< Accepted <<endl;
	cout<<setw(50)<<"Number of rejected packages: "<< Rejected <<endl;
	cout<<"GoodBye!";
}
