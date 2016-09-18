// Program name: A2 
// Date: Jan 25, 2012 
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will allow the user to input a 3-digit number,  
//				then outputs its hundred digit and remainder
// Input: 3 digit number 
//
// Output: Hundreds digit and the remainding digits 
//
// Assumptions/Limitations: 3-digit number 
//--------------------------------------------------------------------------

//////////////////////LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void magic();							//Prototype for Magic formula
void initial();						//Prototype for Outputting purpose
int input();							//Prototype for Input
void calculation(int num, int& hundreds, int& remainder);		//Prototype for Calculation
void output(int hundreds, int remainder);	//Prototype for Output

int main()
{
	int num, hundreds, remainder;			//Declaration

     initial();						//Function call for Initial

	num = input();						//Function call for Input

	calculation(num, hundreds, remainder);	//Function call for Calculation

	output(hundreds, remainder);			//Function call for Output

	getchar();
	return 0;
} 



//This function will allow the user to input a number
int input()
{
	int num;					//Declaration

	cout<<"\n\nINPUT: \t\t";		//Input number
	cin>>num;

	return(num);
}

//This function will calculate the hundreds digit and remainder
void calculation(int num, int& hundreds, int& remainder)
{
	hundreds = num / 100;					//Calculating Hundreds digit
	remainder = num % 100;					//Calculating Remainder
}

//This function will output the hundreds digit and remainder
void output(int hundreds, int remainder)
{
	cout<<"\nOUTPUT: \t"<<hundreds;			//Outputs hundreds digit
	cout<<"\n\nRemainder: \t"<<remainder;		//Outputs remainder
}

//This function contains the magic formula
void magic()
{
	cout.setf(ios::fixed);					//Magic formula
	cout.setf(ios::showpoint);
	cout.precision(2);
}

//This function outputs purpose statement
void initial()
{
	clrscr();								//Clears screen

	cout<<"\nThis program will allow the user to input a 3-digit number "
		<<"\nthen outputs its hundred digit and remainder ";		//Outputs purpose statement
}