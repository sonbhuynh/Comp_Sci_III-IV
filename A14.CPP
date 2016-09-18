// Program name: A14  
// Date: Feb 24, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will use a linear search to find the index of an input value in a random list of 20 numbers from 1 – 50
// 		and output the original list to the screen with each index.
// 
// Input:  Value you want to search for
//
// Output:  Index of that Value
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

void init();				//Prototype for Initialize
void randomize(int num[20]);			//Prototype for Randomize
void outputvalues(int num[20]);		//Prototype for Output Values
int inputnumber();				//Prototype for Input Num
void search(int num[20], int& flag, int& usernum);	//Prototype for Search

int main()
{
	int num[20], flag = 0, usernum;			//Declaration

	randomize();					//Random Num Generator
	randomize();
	randomize();

	init();					//Function call for Initialize
	randomize(num);				//Function call for Randomize
	outputvalues(num);				//Function call Output Values
	usernum = inputnumber();				//Function call for Input User Num
	search(num, flag, usernum);			//Function call for Search

	if (flag == 0)
		cout<<"\nError, value not found. ";	//Outputs error message

	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will use a linear search to find the index of an input value in a "
		<<"\nrandom list of 20 numbers from 1 - 50 "
		<<"\nand output the original list to the screen with each index. ";		//Outputs purpose

	cout<<"\n\nPress Enter to Proceed. ";		//Press enter to go on to next screen
	getchar();
	clrscr();
}


//This function will generate random numbers
void randomize(int num[20])
{
	for (int x = 0; x < 20; x++)
		num[x] = random(50) + 1;			//Generates 20 numbers for Array num[x]
}

//This function will output the random numbers corresponding with the index to screen
void outputvalues(int num[20])
{
	cout<<"Index: ";					//Outputs Index title

	for (int x = 0; x < 20; x++)
		cout << setw(3) << x;			//Outputs Index number

	cout<<"\nValue: ";					//Outputs Value title

	for (x = 0; x < 20; x++)
		cout << setw(3) << num[x];		//Outputs Value number
}

//This function will allow the user to input the number to search
int inputnumber()
{
	int usernum;						//Declaration

	cout << "\n\nPlease enter the value you are searching for: ";		//Inputs User Num
	cin >> usernum;

	return (usernum);
}

//This function will search for the value
void search(int num[20], int& flag, int& usernum)
{
	for (int x = 0; x < 20; x ++)
	{
		if (usernum == num[x])
		{
			cout<<"\n"<<"The value "<<usernum<<" was found at index "<<x;		//Outputs result if found
			flag = 1;
		}
	}
}