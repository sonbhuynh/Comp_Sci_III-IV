// Program name: A18  
// Date: Mar 01, 2012
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will output the frequencies of numbers between 1-50
// 			in a randomized array of 20 numbers.
// 
// Input: None  
//
// Output: Frequencies of each number in array  
//
// Assumptions/Limitations: That it works
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

void init();						//Prototype for Initialize

void randomizenum(int num[50]);		//Prototype for Randomizing Num
void outputnumbers(int num[50]);		//Prototype for Output Numbers

int main()
{
	int num[50];				//Declaration

	randomize();				//Randomizing
	randomize();
	randomize();

	init();					//Function call for Initialize
	randomizenum(num);			//Function call for Randomizing Num
	outputnumbers(num);			//Function call for Output Numbers

	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will output the frequencies of numbers between 1-50 "
		<<"\nin a randomized array of 20 numbers. ";			//Outputs purpose

	cout<<"\n\nPress Enter to Proceed. ";		//Press enter to continue
	getchar();
	clrscr();
}


//This function will generate random numbers
void randomizenum(int num[50])
{
	for (int x = 0; x <= 19; x++)
     {
		num[x] = random(20) + 1;			//Generates 20 numbers for Array num[x]	

		for (int count = 0; count < x; count++)		//Loops until one
			if (num[x] == num[count])
				x--;							//Decreases Index if Number repeats
	}               	
}

//This function will output the numbers to the screen
void outputnumbers(int num[50])
{
	int count = 0;					//Declaration

	for(int x = 0; x <= 19; x++)
	{
		cout<<setw(4)<<num[x];		//Outputs numbers
     		count ++;				//Increases count by 1

		if (count > 9)
		{
			cout<< endl;			//Break
			count = 0;			//Resets count to 0
		}
	}
}