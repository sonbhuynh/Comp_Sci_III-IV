// Program name: A11  
// Date: Feb 22, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read in 10 integers from a .dat file,
// 		then find the average and print to the screen the average
// 		and all integers that are greater than the average.
// 
// Input:  None
//
// Output:  List, Average, and Numbers greater than Average
//
// Assumptions/Limitations: Dat file exists
//--------------------------------------------------------------------------

// LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void init();			//Prototype for Initialize
void magic();			//Prototype for Magic Formula
void check(ifstream& input1);	//Prototype for Check

void readdata(ifstream& input1, int num[], int& x);	//Prototype for Read Data
double calcaverage(int total, int num[]);	//Prototype for Calc Average
void outputdata(double average, int num[]);	//Prototype for Output Data

int main()
{
	int num[10], x, total = 0;		//Declaration
	double average;
	ifstream input1;

	init();			//Function call for Initialize
	magic();			//Function call for Magic Formula
	check(input1);		//Function call for Check Input

	readdata(input1, num, x);		//Function call for Read Data
	average = calcaverage(total, num);	//Function call for Calc Average
	outputdata(average, num);			//Function call for Output Data

	getchar();
	return 0;
}


//This function will output the Program Purpose
void init()
{
	cout<<"This program will read in 10 integers from a .dat file, "			//Outputs Purpose
		<<"\nthen find the average and print to the screen the average "
		<<"\nand all integers that are greater than the average. ";

	cout<<"\n\nPress Enter to Proceed. ";			//Enter to Continue
	getchar();
	clrscr();
}

//This function contains the Magic Formula
void magic()
{
	cout.setf(ios::fixed);		//Magic formula for Screen
	cout.setf(ios::showpoint);
	cout.precision(2);
}

//This function will check and open the A11.dat file
void check(ifstream& input1)
{
	input1.open("F:/Aprogs/A11.dat");			//Opens A11.dat file

	if (input1.fail())
	{
		cout<<"Input file A11.dat failed to open. ";		//Outputs error message
		getchar();
		exit(1);
	}
}

//This function will read in data from the Dat file
void readdata(ifstream& input1, int num[], int& x)
{
	for (x = 0; x < 10; x++)
		input1 >> num[x];		//Inputs num
}

//This function will calculate the average
double calcaverage(int total, int num[])
{
	int x;
	double average;				//Declaration

	for (x = 0; x < 10; x++)
     		total += num[x];		//Calculates Total

	average = (double) total / (x);		//Calculates Average

	return (average);
}

//This function will output the average and all integers greater than average
void outputdata(double average, int num[])
{
	int x;

	cout<<"The Original List is: ";

	for (x = 0; x < 10; x++)
		cout << num[x] <<" ";				//Outputs number for Original List

	cout<<"\nThe Average is: "<<average;			//Outputs average

	cout<<"\nThe numbers that are greater than the average are: ";

	for (x = 0; x < 10; x++)
	{
        	if (num[x] > average)
		cout << num[x] <<" ";				//Outputs number if greater than average
	}
}
