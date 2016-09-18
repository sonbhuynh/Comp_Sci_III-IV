// Program name: B1
// Date: March 02, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will generate 20 numbers between 1-100
//               Then it will put those 20 numbers in order using Selection Sort
// 
// Input: None
//
// Output: 20 numbers in ascending order
//
// Assumptions/Limitations: No number repeats
//--------------------------------------------------------------------------

// ****** SELECTION SORT ******

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
void selectionsort(int num[MAX]);


int main()
{
	int num[MAX];				//Declaration

	randomize();
	randomize();
	randomize();

	
	init();					//Function call for Initialize

	randomizenum(num);			//Function call for Randomize Num

	cout<<"Original list: ";			//Outputs titles

	outputnumbers(num);			//Function call for Output Numbers

	selectionsort(num);				//Function call for Selection Sort

	cout<<"\n\nSorted list: ";		//Outputs title

     outputnumbers(num);


	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will generate 20 numbers between 1-100 "            //Outputs Purpose
		<<"\nThen it will put those 20 numbers in order using Selection Sort. ";
                 
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
		num[x] = random(100) + 1;			//Generates 20 numbers for Array num[x]	

		for (int count = 0; count < x; count++)
			if (num[x] == num[count])
				x--;
	}               	
}

//This function will output the numbers to the screen
void outputnumbers(int num[MAX])
{
	cout<<"\nIndex: \n";			//Outputs Index title

	for(int x = 0; x < MAX; x++)
		cout<<setw(4)<<x;			//Outputs Index


     cout<<"\nValue: \n";			//Outputs Value title

	for(x = 0; x < MAX; x++)
		cout<<setw(4)<<num[x];		//Outputs Value

}

//This function will sort the numbers from least to greatest using selection sort
void selectionsort(int num[MAX])
{
	for (int x = 0; x < MAX - 1; x++)
	{
		for (int y = x + 1; y < MAX; y++)
		{
			if (num[x] > num[y])
               	switchmenu(num[x], num[y]);		//Sorting numbers
		}
	}
}