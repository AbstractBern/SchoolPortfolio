#include <iostream>
#include <iomanip>
using namespace std;
void HelloPrompt();
void PackageTransaction(int, int, int, int, int, double, double, double dimension[], string, const double, const double, const int, float, const float Charge[], const int Pounds[], const int);
void ErrorPrompt();
double LargestDimension(double, double dimension[], const int);
float PackageCost(int, float, const float Charge[], const int Pounds[], const int);
void TransactionPrompt(int, int, float, string);
void PackageCountPrompt(int, int);
int main()
{
	const int IND=2, INDEX=15;						//const subscript for dimension array
	const double DIM_REQ=(12.0*3),			//dimension 3 feet requirement
				GIRTH_REQ=(12.0*5),			//girth 5 feet requirement
				PACK_REQ=50;				//package weight 50 pound requirement
	const float Charge[INDEX] = {1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40, 24.20, 27.30, 31.90, 38.50, 43.50, 44.80, 47.40, 55.20};
	const int Pounds[INDEX] = {1, 2,3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};
				
	double girth,
		largestDim,
		dimension[IND];
	
	string PkgStatus;
	float PkgCost;
	int Accepted=0,
		Rejected=0,
		tCount=0,
		PkgWeight,
		weight;
	cout<<fixed<<showpoint<<setprecision(2);
	HelloPrompt();
	PackageTransaction(Accepted, Rejected, tCount, PkgWeight, weight, girth,largestDim, dimension, PkgStatus, DIM_REQ, GIRTH_REQ, IND, PkgCost, Charge, Pounds, INDEX);
	cout<<endl;
	PackageCountPrompt(Accepted, Rejected);
	return 0;
}
void HelloPrompt()
{
	cout<<setw(50)<<"Lone Star Package Servicing"<<endl;
	cout<<"For each transation, enter package weight and 3 dimensions (seperate by space).";
}
void PackageTransaction(int Accepted, int Rejected, int tCount, int PkgWeight, int weight, double girth, double largestDim, double dimension[], string PkgStatus, const double DIM_REQ, const double GIRTH_REQ, const int IND, float PkgCost, const float Charge[], const int Pounds[], const int INDEX)
{
	while (weight != -1)
	{
		cout<<endl;
		cout<<"Enter package weight (pounds) and 3 dimensions (inches): ";
		cin>>weight;
		if (weight == -1)
		{	break;	}
		cin>>dimension[0]>>dimension[1]>>dimension[2];
		if ((dimension[0] <=0 || dimension[1] <=0 || dimension[2] <= 0) || (dimension[0] > DIM_REQ || dimension[1] > DIM_REQ || dimension[2] > DIM_REQ))
		{
			ErrorPrompt();
			continue;
		}
		PkgWeight=weight;
		LargestDimension(largestDim, dimension, IND);
		girth = 2 * (dimension[0]+dimension[1]+dimension[2]-largestDim);
		if (girth > GIRTH_REQ)
		{	PkgStatus="Rejected";
			Rejected+=1;
		}
		if (girth < GIRTH_REQ)
		{	PkgStatus="Accepted";
			Accepted+=1;
		}
		PackageCost(weight, PkgCost, Charge, Pounds, INDEX);
		tCount+=1;	//bad on prompt with error
		TransactionPrompt(tCount, PkgWeight, PkgCost, PkgStatus);
	}	
}
void ErrorPrompt()
{
	cout<<endl;
	cout<<setw(50)<<"ERROR! : Entries need be less than 0. Pounds < 50 and Dimensions less than 36 inches."<<endl;
	cout<<setw(50)<<"Please re-enter transaction."<<endl;
}
double LargestDimension(double largestDim, double dimension[], const int IND)
{
	for (int i=0; i<IND; i++)
	{
		if (dimension[i] > dimension[0])
		{	return largestDim=dimension[i];	}
		else if (dimension[0] > dimension[i])
		{	return largestDim=dimension[0];	}
	}
}
float PackageCost(int weight, float PkgCost, const float Charge[], const int Pounds[], const int INDEX)
{
	for (int i=0; i<INDEX; i++)
	{
		if  (weight > Pounds[i] && weight <= Pounds[i+1])
		{
			return PkgCost=Charge[i+1];
		}
		else if (weight==Pounds[i])
		{
			return PkgCost=Charge[i];
		}
 	}
}
void TransactionPrompt(int tCount, int PkgWeight, float PkgCost, string PkgStatus)
{
	cout<<endl;
	cout<<setw(50)<<"Transaction: "<< tCount <<endl;
	cout<<setw(50)<<"Status: " << PkgStatus <<endl;
	cout<<setw(50)<<"Weight: "<< PkgWeight <<endl;
	cout<<setw(50)<<"Cost: "<< PkgCost <<endl;	
}
void PackageCountPrompt(int Accepted, int Rejected)
{
	cout<<endl;
	cout<<setw(50)<<"Number of accepted packages: "<< Accepted <<endl;
	cout<<setw(50)<<"Number of rejected packages: "<< Rejected <<endl;
	cout<<"GoodBye!";
}
