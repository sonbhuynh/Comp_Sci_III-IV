// Program name: B4
// Date: March 07, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will use an insertion sort to sort a list of numbers that are read in from the user.
// 		Output the sorted list each time a number is read in.
// 
// Input: Numbers to be sorted
//
// Output: Sorted List of input numbers
//
// Assumptions/Limitations: None
//--------------------------------------------------------------------------

// ****** INSERTION SORT ******

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

const int SIZE = 50;

//FUNCTION PROTOTYPES
void init();
int inputnum();
void insertionsort(int list[SIZE], int& inspt, int& usernum);
void outputlist(int& max, int list[SIZE]);
void move(int& inspt, int& max, int& x, int list[SIZE]);


int main()
{
	int usernum;			//Declaration
	int list[SIZE], inspt, x;

	init();				//Function call for Initialize

	insertionsort(list, inspt, usernum);		//Function call for Insertion Sort

	getchar();
	return 0;
}


//This program will output the program's purpose
void init()
{
	cout<<"This program will use an insertion sort to sort a list of numbers that are read in from the user. "
		<<"\nThen, it will output the sorted list each time a number is read in. ";			//Outputs Purpose
	
	cout<<"\n\nPress Enter to Proceed. ";		//Press Enter to Continue
	getchar();
	clrscr();
}

//This function will allow the user to input number
int inputnum()
{
	int usernum;				//Declaration

	cout<<"\n\nPlease enter a number (or -1 to Quit): ";
	cin>>usernum;				//Inputs User Num

	return (usernum);
}

//This function will user insertion sort to sort the numbers input by the user
void insertionsort(int list[SIZE], int& inspt, int& usernum)
{
	int max = 0, x = 0;			//Sets Max to 0	

	usernum = inputnum();		//Function call for User Num
	list[0] = usernum;			//Assigns User Num to List

	if (usernum == -1)
	{
		cout<<"\nProgram Terminated. ";		//Outputs quit message
		exit(1);    
	}

	outputlist(max, list);		//Function call for Output List

	while(usernum != -1 && max < SIZE)
	{
		usernum = inputnum();

		inspt = 0;			//Sets Insertion Point to 0

		while(inspt <= max && usernum > list[inspt])
			inspt ++;			//Increases Insertion Point by 1

		if (inspt <= max)
     		move(inspt, max, x, list);			//Function call for Move

		list[inspt] = usernum;			 	//Puts User Num to List

		max ++;							//Increases Max by 1

		outputlist(max, list);	//Function call for Output List
	}
}

//This function will output the sorted list
void outputlist(int& max, int list[SIZE])
{
	cout<<"The Sorted List is:";			//Outputs Sorted List

	for(int x = 0; x <= max; x++)
	{
		if (list[x] == -1)
			x++;							//Increases x if list is equal to -1

		cout<<setw(3)<<list[x];				//Outputs Sorted List
     }

} 

//This function will move up or down the values
void move(int& inspt, int& max, int& x, int list[SIZE])
{
		for(x = max + 1; x >= inspt + 1; x--)
			list[x] = list[x - 1];			//Moves the values up
}