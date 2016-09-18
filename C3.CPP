//output with single letter for first initial
//90%
// Program name: C3
// Date: March 27  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read in names from a data file.
// 		The names will be output to the screen in one
// 		Original List and one Sorted List alphabetically.
// 
// Input: Names from Data file  
//
// Output: Original List and Sorted List of the names  
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

// FUNCTION PROTOTYPES
void init();
void openfile(ifstream& input1);
void readdata(ifstream& input1, char name[10][2][80]);
void outputdata(char name[10][2][80]);

void sortarray(char name[10][2][80]);
void switcheroo(char first[50], char last[50]);

int main()
{
	ifstream input1;					//Declaration
     char name[10][2][80];			

	init();							//Function call for Initialize
	openfile(input1);					//Function call for Open File
	readdata(input1, name);				//Function call for Read Data
     input1.close();

	cout<<"Original List: \n";
	outputdata(name);					//Function call for Output Data

	sortarray(name);					//Function call for Sort Array

	cout<<"\n\nSorted List: \n";
	outputdata(name);					//Function call for Output Data

	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will read in names from a data file. "			//Outputs Purpose
		<<"\nThe names will be output to the screen in one "
		<<"\nOriginal List and one Sorted List alphabetically. ";

	cout<<"\n\nPress Enter to Proceed.";
	getchar();
	clrscr();
}

//This function will check and open the data file
void openfile(ifstream& input1)
{
	input1.open("F:/Cprogs/C3.dat");					//Opens C3.dat file

	if (input1.fail())
	{
		cout<<"Input file C3.dat failed. ";			//Outputs Failure Message
		getchar();
		exit(1);
	}
}

//This function will read in data from the data file
void readdata(ifstream& input1, char name[10][2][80])
{
	for (int x = 0; ! input1.eof(); x++)
	{
		input1.getline(name[x][0], 80, ' ');				//Reads in First Name
		input1.getline(name[x][1], 80, '\n');				//Reads in Last Name
	}
}

//This function will output the list of name to the screen
void outputdata(char name[10][2][80])
{
	for (int x = 0; x < 10; x++)
	{
     	cout<<endl;
     	cout<<name[x][0]<<" "<<name[x][1];					//Outputs Name
	}
}

//This function will sort the name in alphabetical order
void sortarray(char name[10][2][80])
{
	for (int x = 0; x < 10 - 1; x++)
	{
		for (int y = x + 1; y < 10; y++)
		{
			if (strcmpi(name[x][1], name[y][1]) > 0)
               {
				switcheroo(name[x][1], name[y][1]);		//Sorting last name
				switcheroo(name[x][0], name[y][0]);		//Sorting first name
               }
		}
	}
}

//This function will switch the positions of the names
void switcheroo(char first[50], char last[50])
{
	char hold[50];

	strcpy(hold, first);			//Switch places of the name
	strcpy(first, last);
	strcpy(last, hold);
}

