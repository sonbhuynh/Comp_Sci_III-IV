// Program name: D9  
// Date: May 4, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will allow the user to input in
//				a list of numbers. The program will calculate
// 				nand output the sum on to the screen.
// 
// Input: Numbers  
//
// Output: Total  
//
// Assumptions/Limitations: None
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
class book
{
	private:
		double num;
		double total;
	public:
		book();
		~book();
		void magic();
		void getdata();
		void addsum();
		double gettotal();
};


// PROTOTYPES
void init();
char menu();
void output(double total);


int main()
{
	book checkbook;							//Declaration
	char choice;
	double total;

	checkbook.magic();
	init();								//Call Initialize

	do
	{
		checkbook.getdata();					//Call Get Data
		checkbook.addsum();					//Call Add Sum
		total = checkbook.gettotal();					//Call Get Total

		choice = menu();						//Call Menu

		if (choice == 'N')
		{
			break;						//Breaks out of loop
		}
	}
	while (choice != 'N');

	output(total);							//Call Output

	getchar();
	return 0;
}

// CONSTRUCTOR
void book::book()
{
	total = 0;								//Initializes Sum to 0
}

// DESTRUCTOR
book::~book()
{
	cout<<"\nError, data has been destroyed.";				//Outputs Error Message
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will allow the user to input in "
		<<"\na list of numbers. The program will calculate "
		<<"\nand output the sum on to the screen. ";			//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";					//Press Enter to Proceed
	getchar();
	clrscr();
}

// This function contains the magic formula
void book::magic()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);								//Magic formula
}

// This function will allow the user to input in numbers
void book::getdata()
{
	cout<<"Enter in number: $";				//Inputs Number
	cin>>num;
}

// This function will add up the sum
void book::addsum()
{
	total += num;							//Calculates Total/Sum
}

// This function will returns the total
double book::gettotal()
{
	return (total);						//Returns Total
}

// This function will output the sum to the screen
void output(double total)
{
	cout<<"\nTotal: \t$"<<total;				//Outputs Total
}

// This function will check to see if the user wants to continue
char menu()
{
	char choice;							//Declaration

	cout<<"Continue (Y/N): ";
	cin>>choice;							//Inputs Choice
	choice = toupper(choice);
     cout<<endl;							//Outputs Blank Line

	return (choice);
}