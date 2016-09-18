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
#include <iomanip.h>
#include <fstream.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

// CLASS DECLARATION
class parity
{
	private:
		int num;
		int count;
		int value;
	public:
		parity();
		~parity();
		void inputnum();
		int calculate();
};

// PROTOTYPES
void init();
void output(int value);
char menu();

int main()
{
	parity test;								//Declaration
	char choice;
	int value;

	init();

	do
	{
		test.inputnum();						//Call Input Num
		value = test.calculate();				//Call Calculate

		choice = menu();						//Call Menu

		if (choice == 'N')
		{
			break;							//Breaks out of loop
		}
	}
	while (choice != 'N');

	output(value);								//Call Output

	getchar();
	return 0;
}

// CONSTRUCTOR
void parity::parity()
{
	count = 0;								//Initializes Count to 0
}

// DESTRUCTOR
parity::~parity()
{
	cout<<"\nError, data has been destroyed.";		//Outputs Error Message
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will allow the user to input in numbers."
		<<"\nThe program will determine if the number of items "
		<<"\nis even or odd, then output TRUE or FALSE. ";	//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";				//Press Enter to Proceed
	getchar();
	clrscr();
}

// This function will allow the user to input number
void parity::inputnum()
{
	cout<<"Enter Number: \t";					//Inputs Number
	cin>>num;

	count++;									//Increases Count by 1
}

// This function will determine if the number of items is even/odd
int parity::calculate()
{
	if (count % 2 == 1)
		return (1);							//If count of num is odd, returns 1

	if (count % 2 == 0)							//If count of num is even, returns 0
     		return (0);
}

// This function will output if the number of items is even/odd
void output(int value)
{
	if (value == 1)
		cout<<"\nFALSE, number of items is odd.";	//Outputs False if odd

	if (value == 0)
		cout<<"\nTRUE, number of items is even.";	//Outputs True if even
} 

// This function will check to see if the user wants to continue
char menu()
{
	char choice;								//Declaration

	cout<<"Continue (Y/N): ";
	cin>>choice;								//Inputs Choice
	choice = toupper(choice);
     cout<<endl;								//Outputs Blank Line

	return (choice);
}