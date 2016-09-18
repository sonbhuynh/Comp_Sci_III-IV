// Program name: D2  
// Date:	May 3, 2012
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will create 2 two-dimensional arrays, 10x10 and 5x5
//			Both arrays will be filled in with random numbers from 1 to 100
//			Averages will be calculated, output and compare to the screen.  
// 
// Input: None  
//
// Output: 2 Arrays and 2 averages  
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

// PROTOTYPES
void init();
void generatearray();

int main()
{
	typedef int array[100];
     array num;

	randomize();							//Randomizing
	randomize();
	randomize();

	init();								//Call Initialize
	generatearray();						//Call Generate Array

	getchar();
	return 0;
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will create 2 two-dimensional arrays, 10x10 and 5x5 "
		<<"\nBoth arrays will be filled in with random numbers from 1 to 100 "
		<<"\nAverages will be calculated, output and compare to the screen.";		//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";		//Press Enter to Continue
	getchar();
	clrscr();
}

// This function will generate an array with random numbers
void generatearray(int array[100])
{
	int count = 0;							//Declaration
     array num;

	for (int x = 0; x < 100; x++)
	{
		num = random(100) + 1;				//Generates random numbers

		cout<<setw(5)<<num;					//Outputs Numbers
          count++;

		if (count % 10 == 0)
          {
			cout<<endl;					//Goes to next line
			count = 0;					//Resets Count to 0
		}
	}
}

//This function will output the array
//void outputarray() 