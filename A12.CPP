// Program name: A12  
// Date: Feb 23, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will calculate:
//			1) The square root of each and puts it into List 2
// 			2) The cube of each and puts it into List 3
//			3) Round each number from list2 and put into List 4
// 
// Input: A12.dat file  
//
// Output: 4 Lists of Original, Square Root, Cube, and Rounded   
//
// Assumptions/Limitations: A12.dat File exists
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
void check(ifstream& input1);	//Prototype for Check

void readdata(ifstream& input1, int num[10]);			//Prototype for Read Data
void calcsquare(int num[10], double squareroot[10]);		//Prototype for Calc Square Root
void calccube(int num[10], int cube[10]);				//Prototype for Calc Cube
void rounding(double squareroot[10], int round[10]);				//Prototype for Rounding
void outputlists(int num[10], double squareroot[10], int cube[10], int round[10]);		//Prototype for Output Lists

int main()
{
	ifstream input1;								//Declaration
	int num[10], cube[10], round[10];
     double squareroot[10];

	init();				//Function call for Initial
	magic();				//Function call for Magic
	check(input1);			//Function call for Check

	readdata(input1, num);				//Function call Read Data
	calcsquare(num, squareroot);			//Prototype for Calc Square Root
	calccube(num, cube);				//Prototype for Calc Cube
	rounding(squareroot, round);				//Prototype for Rounding
	outputlists(num, squareroot, cube, round);			//Function call for Output lists

	getchar();
	return 0;
}

//This function will output the Program Purpose
void init()
{
	cout<<"This program will calculate: "
		<<"\n1) The square root of each and puts it into List 2 "
		<<"\n2) The cube of each and puts it into List 3 "
		<<"\n3) Round each number from list2 and put into List 4 ";		//Outputs purpose
;

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

//This function will open and check the A12.dat file
void check(ifstream& input1)
{
	input1.open("F:/Aprogs/A12.dat");				//Opens A12.dat file

	if (input1.fail())
	{
		cout<<"Input file A12.dat Failed. ";		//Outputs Error Message
		getchar();
		exit(1);
	}
}

//This function will read in data from the Dat file
void readdata(ifstream& input1, int num[10])
{
	for (int x = 0; x < 10; x++)
		input1 >> num[x];		//Inputs num
}

//This function will calculate the Square Root
void calcsquare(int num[10], double squareroot[10])
{
	int x;					//Declaration

	for (x = 0; x < 10; x++)
		squareroot[x] = sqrt((double) num[x]);		//Calculates Squareroot
}

//This function will calculate the Cube
void calccube(int num[10], int cube[10])
{
	int x;					//Declaration

	for (x = 0; x < 10; x++)
		cube[x] = pow(num[x], 3);
}

//This function will round the numbers in List 2
void rounding(double squareroot[10], int round[10])
{
	int x;					//Declaration

	for (x = 0; x < 10; x++)
	{
		if (squareroot[x] - floor(squareroot[x]) > 0.5)
			round[x] = ceil(squareroot[x]);				//Rounding number up
		else
			round[x] = floor(squareroot[x]);			//Rounding number down
	}
}

//This function will output the data to the screen
void outputlists(int num[10], double squareroot[10], int cube[10], int round[10])
{
	cout<<setw(13)<<"Original"<<setw(13)<<"Square Root"<<setw(9)<<"Cube"<<setw(12)<<"Rounded ";	//Outputs title

     for (int x = 0; x < 10; x++)
		cout<<"\n\n"<<setw(13)<<num[x]<<setw(13)<<squareroot[x]<<setw(9)<<cube[x]<<setw(11)<<round[x];			//Outputs data
}      	