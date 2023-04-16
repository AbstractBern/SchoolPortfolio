//Bernardo Flores
//Complete
//This program is a revised program for a checkbook.
//This program adds insuff. funds fee, and below one-thousand dollar fees one time throughout the program
//If need be. otherwise; this program calculates deposits, and withdrawals for the end of the month.
#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
void withdrawal(double &account_balance, double &total_fees, double transaction_amount, const double SERVICE_FEE, const double INSUFFICIENT_FUNDS, const double BELOW_BALANCE_FEE, bool &below_fee,bool &below_funds);
void deposit(double &account_balance,double &total_fees, double transaction_amount, const double SERVICE_FEE, const double INSUFFICIENT_FUNDS, const double BELOW_BALANCE_FEE);
//The function main: Holds a welcome prompt, asks for strarting balance, and trans. amounts, 
//loops a menu throughout, and calls functions upon choice, and loads error messages if something went wrong.
int main() {
	double account_balance,	//reference variable to be manipulated, holds amount for account_balance
			total_fees=0.0,	//initial value, to be manipulated by accumulating types of service fees
			transaction_amount;	//holds users amount to be calculated
	const double SERVICE_FEE=0.35,	//constant service fee to be used for total_fees charged when checks are transacted.
				INSUFFICIENT_FUNDS=30.00,	//constant service fee to be used for total fees when charged when balance <= 0.
				BELOW_BALANCE_FEE=8.00;	//a fee given when the balance is below 1000.00 dollars. 
	char transaction_choice;	//a char variable used for user input of menu choice, either C or D or E
	bool below_fee=false,	//bool used as a condition for fees. If false, insuff. and below-balance fee will be added 
		below_funds=false;	//bool used as condition for fees, if true insuff. and below_balance fee will not be added.
	cout<< right << setw(61) << "Welcome to Checkbook Program!" << endl;
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"Starting Balance: ";
	cin>>account_balance;
	cout<<"\n";
	//loops a menu
	while (transaction_choice != 'E') {
		cout<<"Transaction  Types:  Enter Type followed by a space then an Amount.\n" << endl;
		cout<<"Process a Check: 'C'" << endl;
		cout<<"Process a Deposit: 'D'" << endl;
		cout<<"Monthly Statement/End: 'E'" << endl;
		cout<<"\n";
		cout<<"Enter a transaction Type with Amount: ";
		cin>>transaction_choice;
		transaction_choice=toupper(transaction_choice);
		//if user presses C, these actions are done. Opens the deposit function
		if (transaction_choice == 'C') {
			cout<<"Enter transaction amount: "; 
			cin>>transaction_amount;
			if (transaction_amount > 0.0) {
				withdrawal(account_balance,total_fees,transaction_amount,SERVICE_FEE,INSUFFICIENT_FUNDS,BELOW_BALANCE_FEE,below_fee,below_funds);
				continue;
			}
			else {
				cout<<"Error Message: Invalid Amound!" << endl;
			}
		}
		// if user presses D, these actions are done. Opens the withdrawal function
		else if (transaction_choice == 'D') {
			cout<<"Enter transaction amount: "; 
			cin>>transaction_amount;
			if (transaction_amount > 0.0) {
				deposit(account_balance,total_fees,transaction_amount,SERVICE_FEE,INSUFFICIENT_FUNDS,BELOW_BALANCE_FEE);
				continue;
			}
			else {
				cout<<"Error Message: Invalid Amount!" << endl;
			}
		}
		//Ends the program, and shows Monthly statement.
		else if (transaction_choice == 'E') {
			cout<<"\n";
			cout<< right << setw(49) << "-----------------" << endl;
			cout<< right << setw(49) << "Monthly Statement" << endl;
			cout<< right << setw(49) << "================="<< endl;
			account_balance=account_balance-total_fees;
			cout<< right << setw(47) << "Final Balance: $" << account_balance << endl;
		}
		//Error Message if user presses anything but C  D or E.
		else {
			cout<<"\n";
			cout<<"Invalid Transaction Type! Enter 'C' 'D' or 'E'" << endl;
			continue;
		}
	}
	return 0;
}
//Withdrawal function: give prompts of transaction, withdrawal amounts, account _balance, and total service charges.
//Depending on the condition, this function will calculate for below balance fees, and insufficient funds.
//Overall calculates for withdrawals.
void withdrawal(double &account_balance,double &total_fees,double transaction_amount,const double SERVICE_FEE,const double INSUFFICIENT_FUNDS,const double BELOW_BALANCE_FEE,bool &below_fee,bool &below_funds) {
	cout<<"\n";
	cout<< right << setw(49) << "-----------" << endl;
	cout<< right << setw(49) << "TRANSACTION" << endl;
	cout<< right << setw(49) << "==========="<< endl;
	cout<< right << setw(47) << "Withdrawal Amount: $" << right << transaction_amount << endl;
	account_balance=account_balance-transaction_amount;
	cout<< right << setw(47) << "Account Balance: $" << account_balance << endl;
	cout<< right << setw(47) << "Service Charge(Per Check): $" << right << SERVICE_FEE << endl;
	//condition for account balance, and below balance fee, plus calculations
	if (((account_balance > 0.00) && (account_balance < 1000.00)) && (below_fee == false)) {
		//rework this area: my mindset is that how will i stop or begin the operations
		cout<< right << setw(55) << "Account Balance BELOW $1000.00!" << right << endl;
		cout<< right << setw(47) << "Service Charge added (One Time): $" << right << BELOW_BALANCE_FEE << endl;
		total_fees=total_fees+SERVICE_FEE;
		total_fees=BELOW_BALANCE_FEE+SERVICE_FEE;
		cout<< right << setw(47) << "Total Service Charges: $" << right <<total_fees << endl;
		cout<<"\n";
		below_fee=true;
		return;
	}
	//condition for account balance, and below balance fee, plus calculations
	else if (((account_balance > 0.00) && (account_balance < 1000.00)) && (below_fee==true)) {
		total_fees=total_fees+SERVICE_FEE;
		cout<< right << setw(47) << "Total Service Charges: $" << right <<total_fees << endl;
		cout<<"\n";
		return;		
	}
	//condition for account balance, and below balance fee, plus calculations
	else if ((account_balance >= 1000.00) && (below_fee ==false)) {
		total_fees=total_fees+SERVICE_FEE;
		cout<< right << setw(47) << "Total Service Charges: $" << right <<total_fees << endl;
		cout<<"\n";
		return;
	}
	//condition for account balance, and below balance fee, plus calculations
	else if ((account_balance >= 1000.00) && (below_fee == true)) {
		total_fees=total_fees+SERVICE_FEE;
		cout<< right << setw(47) << "Total Service Charges: $" << right <<total_fees << endl;
		cout<<"\n";
		return;
	}
	//condition for account balance, and insufficient funds fee, plus calculations
	else if ((account_balance <= 0.00) && (account_balance < 1000.00)) {
		cout<< right << setw(47) << "Account below $0.00. Adding $" << INSUFFICIENT_FUNDS << " to total fees." << endl;
		total_fees=total_fees+INSUFFICIENT_FUNDS+SERVICE_FEE;
		cout<< right << setw(55) << "Account Balance BELOW $1000.00!" << right << endl;
		cout<< right << setw(47) << "Total Service Charges: $" << right <<total_fees << endl;
		cout<<"\n";
		return;
	}
	//condition for account balance, and insufficient funds fee, plus calculations

}
//Deposit function: prompts for transaction, deposit amount, account_balance, and total fees.
//Calculations for depositing.
void deposit(double &account_balance,double &total_fees, double transaction_amount, const double SERVICE_FEE, const double INSUFFICIENT_FUNDS, const double BELOW_BALANCE_FEE) {
	//shows deposit info, and charges.
	cout<<"\n";
	cout<< right << setw(47) << "-----------" << endl;
	cout<< right << setw(47) << "TRANSACTION" << endl;
	cout<< right << setw(47) << "==========="<< endl;
	cout<< right << setw(47) << "Deposit Amount: $" << right << transaction_amount << endl;
	account_balance=account_balance+transaction_amount;
	cout<< right << setw(47) << "Account Balance: $" << right << account_balance << endl;
	cout<< right << setw(47) << "Total Service Charges: $" << right << total_fees << endl;
	cout<< "\n";
}