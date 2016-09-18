//incomplete..no insertion sort
//no search
//syntax errors
//20%
// Program name: B5  
// Date: March 12, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read in data from the B5.dat file.
// 			The user should now be able to input a state and then
//			get a list printed of all the people born in that state.
// 
// Input: State  
//
// Output: People Born in that State  
//
// Assumptions/Limitations: Data file exists
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

const int SIZE = 80;

// FUNCTION PROTOTYPES
void init();
void openfile(ifstream& input1);
void readdata(ifstream& input1, char name[SIZE], char city[SIZE], char state[SIZE]);
void inputstate(char userstate[SIZE]);

int main()
{
	ifstream input1;					//Declaration
	char name[SIZE], city[SIZE], state[SIZE];
	char userstate[SIZE];

	init();							//Function call for Initialize
	openfile(input1);					//Function call for Open File

	readdata(input1, name, city, state);			//Function call for Read Data

	input1.close();



	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will read the names from the B5.dat file. "		//Outputs Purpose
		<<"\nThe user should now be able to input a state and then "
		<<"\nget a list printed of all the people born in that state. ";

	cout<<"\n\nPress Enter to Proceed. ";		//Press Enter to Continue
	getchar();
	clrscr();
}

//This function will open and check the data file
void openfile(ifstream& input1)
{
	input1.open("F:/Bprogs/B5.dat");			//Opens B5.dat file

	if (input1.fail())
	{
		cout<<"Input file B5.dat ";			//Outputs error message
		getchar();
		exit(1);
	}
}

//This function will read in data from the B5.dat file
void readdata(ifstream& input1, char name[SIZE], char city[SIZE], char state[SIZE])
{
	for (int x = 0; x < SIZE; x++)
	{
		input1.getline(name, 80, '\n');		//Reads in Name

		input1.getline(city, 80, ', ');		//Reads in City
		input1.getline(state, 80, '\n');		//Reads in State
	}
}

//This function will allow the user to enter the state
void inputstate(char userstate[SIZE])
{
	cout<<"Enter State Name: ";				//Inputs State Name
	cin.getline(userstate, 80, '\n');
}

//This function will use the insertion sort method to find the people born in the search state
void search(char userstate[SIZE],
{
	inputstate(userstate);					//Function call for Input State

	state[SIZE] = userstate;					//Assigns UserState into the State array

