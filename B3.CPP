// Program name: B3
// Date: March 05, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will generate 20 numbers between 1-50
//               Then it will put those 20 numbers in order using Selection Sort
// 
// Input: None
//
// Output: 20 numbers in ascending order
//
// Assumptions/Limitations: No number repeats
//--------------------------------------------------------------------------

// ****** BUBBLE SORT ******

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

const MAX = 20;

// FUNCTIONS PROTOTYPES
void init();

void switchmenu(int& num_a, int& num_b);
void randomizenum(int num[MAX]);
void outputnumbers(int num[MAX]);
void bubblesort(int num[MAX]);


int main()
{
	int num[MAX];				//Declaration

	randomize();
	randomize();
	randomize();

	
	init();					//Function call for Initialize

	randomizenum(num);			//Function call for Randomize Num

	cout<<"Original list: \n";			//Outputs titles

	outputnumbers(num);			//Function call for Output Numbers

	bubblesort(num);				//Function call for Selection Sort

	cout<<"\n\n\nSorted list: \n";		//Outputs title

     outputnumbers(num);


	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will generate 20 numbers between 1-50 "            //Outputs Purpose
		<<"\nThen it will put those 20 numbers in order using Bubble Sort. ";
                 
	cout<<"\n\nPress Enter to Proceed. ";		//Press Enter to Continue
	getchar();
	clrscr();
}

//This function will contain the switch for hold, num_a and num_b
void switchmenu(int& num_a, int& num_b)
{
	int hold;				//Declaration

	hold = num_a;			//Puts num_a into hold
	num_a = num_b;			//Puts num_b into num_a
	num_b = hold;			//Puts hold into num_a
}

//This function will generate 20 random numbers, none will repeat 
void randomizenum(int num[MAX])
{
	for (int x = 0; x < MAX; x++)
	{
		num[x] = random(50) + 1;			//Generates 20 numbers for Array num[x]	

		for (int count = 0; count < x; count++)
			if (num[x] == num[count])
				x--;
	}               	
}

//This function will output the numbers to the screen
void outputnumbers(int num[MAX])
{
	cout<<"\nIndex: ";               //Outputs Index title

	for(int x = 0; x < MAX; x++)
		cout<<setw(3)<<x;			//Outputs Index


     cout<<"\nValue: ";			//Outputs Value title

	for(x = 0; x < MAX; x++)
		cout<<setw(3)<<num[x];		//Outputs Value

}

//This function will sort the numbers from least to greatest using selection sort
void bubblesort(int num[MAX])
{
	for (int x = 0; x < MAX; x++)
	{
		for (int y = 0; y < MAX - x; y++)
		{
			if (num[y] > num[y + 1])
				switchmenu(num[y], num[y + 1]);		//Sorting numbers
		}
	}
}