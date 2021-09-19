/* Bernardo Flores
Complete
This is a checkbook program thatcalculates withdrawals, and deposits for the monthly statement */
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
//The function Main is an operation for a Checkbook program that by either choice C D or E
//will give your service charges plus either a balance after withdrawal, deposit, or
//mothly statement.
int main()
{
	double account_balance,		//holds starting balance and is manipulated by user entry (withdrawal/deposits). validation as well
			total_fees=0.0,			//keeps an initial hold of fees. Later manipulated by Check transactions, and Total shown on End statement
			check_amount,				//holds withdrawal amount to be subtracted from account balance
			deposit_amount;					//holds deposit amount to be added to account balance
	const double SERVICE_FEE=0.25;				//consant made for check SERVICE FEE = 0.25 per check
	char user_choice;		//user_choice holds character value for transaction type entry
	
	cout<<fixed<<showpoint<<setprecision(2);				//MAKES ALL NUMBERS SHOWN AS TWO SIGNIFICANT DIGITS ex: 10.00
	cout<<"Welcome to Checkbook Program."<<endl;	//User friendly prompt
	cout<<"\n";										//Design is shown throughout using \n and \t
	cout<<"Enter your beginning balance: ";		//Prompt for starting balance
	cin>>account_balance;					//user input starting balance
	cout<<"\n";
	
	while (user_choice != 'E')			//looops transaction prompt until user inputs 'E'
	{
		cout<<"\n";
		cout<<"Transaction  Types:\n";			//Transaction types: Check, Deposit, Withdraw, and End/Monthly Statement
		cout<<"Process a Check: 'C'" << endl;
		cout<<"Process a Deposit: 'D'" << endl;
		cout<<"Monthly Statement or End: 'E'" << endl;
		cout<<"\n";
		cout<<"Enter a transaction type: ";
		cin>>user_choice;						//User input for either transaction type C, D, E
		user_choice=toupper(user_choice);

		if (user_choice == 'C')					//proccess for when user inputs C
		{
			cout<<"\n";
			cout<<"\t\t\tEnter withdrawal amount: ";		//prompt for input
			cin>>check_amount;								//user input for withdrawal amount
			cout<<"\n";
			cout<<"\t\t\tProcessed a check for $" << check_amount << endl;	//validation
			account_balance=account_balance-check_amount;		//balance operation
			cout<<"\t\t\tBalance is $" << account_balance << endl;	//prompt for current balance
			cout<<"\t\t\tService Charge: $" << SERVICE_FEE <<" per check." << endl;	//service charge notification per check
			total_fees=total_fees+SERVICE_FEE;				//total fee operation
			cout<<"\t\t\tTotal Service Charges: $" << total_fees;	//total service charges
			cout<<"\n";
		}
		else if (user_choice == 'D')			//proccess for when user inputs D
		{
			cout<<"\n";
			cout<<"\t\t\tEnter deposit amount: ";				//prompt for input
			cin>>deposit_amount;								//User input for deposit
			cout<<endl;
			cout<<"\t\t\tProcessed a deposit for $" << deposit_amount << endl;
			account_balance=account_balance+deposit_amount;			//account balance operation
			cout<<"\t\t\tBalance is $" << account_balance << endl;		//current balance
			cout<<"\t\t\tTotal Service Charges: $" << total_fees << endl;	//total service charges
			cout<<"\n";
		}
		else if (user_choice == 'E')		//proccess for when user inputs E
		{
			cout<<"\n";
			cout<<"\t\t\tEnd of the Month Statement." << endl;	//prompt
			cout<<"\t\t\t==========================="<<endl;
			account_balance=account_balance-total_fees;		//account balance operation
			cout<<"\t\t\tFinal Balance: $" << account_balance;	//Final balance
		}
		else								//Error Messaging
		{
			cout<<"Invalid Entry, Please use either 'C' 'D' or 'E'." << endl;
			cout<<"Enter a transaction type: ";
			cin>>user_choice;						//User input for either transaction type C, D, E
			user_choice=toupper(user_choice);
		}
	}
	return 0;
}
