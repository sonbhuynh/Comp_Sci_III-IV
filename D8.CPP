// Program name:  
// Date:  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  
// 
// Input:  
//
// Output:  
//
// Assumptions/Limitations:
//--------------------------------------------------------------------------

// LIBRARIES

#include <iostream.h>
#include <conio.h>
#include <stdio.h>

//Structure for a bank certificate of deposit:

struct CDAccount
{
	private:
		double balance;
		double interest_rate;
		int term;  		//months until maturity
	public:
		void get_data();
		void magic();
		void calculation();
		int getterm();
          double getbalance();     	
};


//Post condition:  the_account.balance and the_account.interest_rate
//have been given values that the user entered at the keyboard

//PROTOTYPES
void init();
void output (int term, double balance);

int main ( )
{
	CDAccount account;					//Declaration
	int term;
     double balance;

	init();							//Call Initialize
	account.magic();					//Call Magic

	account.get_data();					//Call Get Data
	account.calculation();				//Call Calculation

	term = account.getterm();			//Call Get Term
	balance = account.getbalance();		//Call Get Balance

	output(term, balance);				//Call Output

	getchar();
	return 0;
}

void CDAccount::get_data (void)
{
	cout << "Enter account balance: $ ";											//Inputs Balance
	cin >> balance;
	cout << "Enter account interest rate: ";										//Inputs Interest Rate	
	cin >> interest_rate;
	cout<< "Enter the number of months until maturity (must be 12 or fewer months): ";		//Inputs term
	cin >> term;
}

void CDAccount::calculation (void)
{
	double rate_fraction, interest;

	rate_fraction = interest_rate/100.0;
	interest = balance * rate_fraction * (term/12.0);
	balance = balance + interest;						//Calculates balance
}

void CDAccount::magic (void)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);								//Magic formula
}

int CDAccount::getterm(void)
{
	return (term);									//Returns Term
}

double CDAccount::getbalance(void)
{
	return (balance);								//Returns Balance      							
}

void output (int term, double balance)
{
	cout << "\nWhen your CD matures in " <<term << " months, "
	    << "it will have a balance of $ " << balance;		//Outputs final balance
}

void init()
{
	cout<<"This program will calculate the bank account balance "
		<<"\nby allowing the user to input the initial balance, "
		<<"\ninterest rate, and term. ";				//Outputs purpose

	cout<<"\n\nPress Enter to Proceed.";				//Press Enter to continue
	getchar();
	clrscr();
}