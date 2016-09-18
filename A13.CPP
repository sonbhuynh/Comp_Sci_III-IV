// Program name: A13
// Date: Feb 23, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will calculate read in 20 numbers
// 			from a data file. Then multiply the first number by 1
// 			second number by 2, so on. Then add together to get a total.
// 
// Input: None  
//
// Output: Numbers and the Sum
//
// Assumptions/Limitations: A13.dat file
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

void init();				//Prototype for Initialize
void magic();				//Prototype for Magic Formula
void check(ifstream& input1);		//Prototype for Check

void readdata(ifstream& input1, int num[20]);		//Prototype for Read Data
void calculations(int num[20], int multiply[20], int& total);   //Prototype for Calculations
void outputdata(int multiply[20], int total);         //Prototype for Output Data

int main()
{
	ifstream input1;				//Declaration
	int num[20], multiply[20], total = 0;
	
	init();				//Function call for Initialize
	magic();			//Function for Magic Formula
	check(input1);			//Function call for Check
	
	readdata(input1, num);				//Function call for Read Data
	calculations(num, multiply, total);		//Function call for Calculations
	outputdata(multiply, total);			//Function call for Output Data

	getchar();
	return 0;
}

//This function will output the Program Purpose
void init()
{
	cout<<"This program will calculate read in 20 numbers "		//Outputs purpose
		<<"\nfrom a data file. Then multiply the first number by 1 "
          <<"\nsecond number by 2, so on. Then add together to get a total. ";

	cout<<"\n\nPress Enter to Proceed. ";			//Enter to Continue
	getchar();
	clrscr();
}

//This function contains the Magic Formula
void magic()
{
	cout.setf(ios::fixed);					//Magic formula for Screen
	cout.setf(ios::showpoint);
	cout.precision(2);
}

//This function will open and check the A12.dat file
void check(ifstream& input1)
{
	input1.open("F:/Aprogs/A13.dat");				//Opens A12.dat file

	if (input1.fail())
	{
		cout<<"Input file A13.dat Failed. ";		//Outputs Error Message
		getchar();
		exit(1);
	}
}

//This function will read in data from the Dat file
void readdata(ifstream& input1, int num[20])
{
	for (int x = 0; x < 20; x++)
		input1 >> num[x];			//Inputs num
}

//This function will multiply each number by itself, and total it
void calculations(int num[20], int multiply[20], int& total)
{
	for (int x = 0; x < 20; x++)
	{
		multiply[x] = num[x] * (x + 1);		//Calculates Multiply Array
		total += multiply[x];			//Calculates Total
	}
}

//This function will output the data to the screen
void outputdata(int multiply[20], int total)
{
	for (int x = 0; x < 20; x++)
	{
		if (multiply[x] % 14 == 0)         
			cout<<endl;
		else
		{
			cout<<multiply[x];		//Output multiply[x]
            
			if (x < 19)			//If not the end
				cout<<" + ";            //Output plus
		}
	}
	
	cout << " = " << total;				//Output total
}