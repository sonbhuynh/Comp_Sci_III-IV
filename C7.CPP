// Program name: C7  
// Date: April 12, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read in data from an external file.
// 				It will allow the user to enter a year. The program will
// 				write to the screen the movie that produced the highest
// 				revenue up to and including the year input.
// 
// Input: Year they want to search as for  
//
// Output: Movie Name and Revenue  
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

// DECLARATIONS
struct MovieInfo
{
	char name[50];
	int year;
	long revenue;
}movie[10];

// FUNCTION PROTOTYPES
void init();
void openfile(ifstream& input1);
void readdata(ifstream& input1, MovieInfo movie[10]);
void outputdata(MovieInfo movie[10]);
int inputyear();
void search(MovieInfo movie[10], int useryear);


int main()
{
	ifstream input1;												//Declaration
	int useryear;

	init();														//Function call for Initialize
	openfile(input1);												//Function call for Open File
	readdata(input1, movie);											//Function call for Read Data
	input1.close();
	outputdata(movie);												//Function call for Output Data
	useryear = inputyear();											//Function call for Input Year
	search(movie, useryear);											//Function call for Search

	getchar();
	return 0;
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will read in data from an external file. "
		<<"\nIt will allow the user to enter a year. The program will "
		<<"\nwrite to the screen the movie that produced the highest "
		<<"\nrevenue up to and including the year input. ";				//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";								//Press Enter to Continue
	getchar();
	clrscr();
}

// This function will open and check the data file
void openfile(ifstream& input1)
{
	input1.open("F:/Cprogs/C7.dat");									//Opens C7.dat file

	if (input1.fail())
	{
		cout<<"Input file C7.dat failed to open.";						//Outputs failure message
		getchar();
		exit(1);
	}
}

// This function will read in data from the data file
void readdata(ifstream& input1, MovieInfo movie[10])
{
	int x = 0;													//Declaration

	do
	{
		input1.getline(movie[x].name, 80, '\t');						//Reads in Name
		input1>>movie[x].year;										//Reads in Year
		input1>>movie[x].revenue;									//Reads in Revenue
          input1.ignore();

		x++;														//Increases x by 1
	}
	while (! input1.eof());
}

// This function will output the data onto the screen
void outputdata(MovieInfo movie[10])
{
	int x = 0;													//Declaration

     cout<<setw(20)<<"Name"<<setw(10)<<"Year"<<setw(15)<<"Revenue";			//Outputs Titles

	do
	{
		cout<<endl;

		cout<<setw(20)<<movie[x].name<<setw(10)<<movie[x].year
			<<setw(9)<<"$"<<movie[x].revenue;							//Outputs Data

		x++;														//Increases x by 1
	}
	while (x < 10);
}

// This function will allow the user to enter in a year they want to search for
int inputyear()
{
	int useryear;													//Declaration

	cout<<"\n\nPlease Enter Year: ";
	cin>>useryear;													//Inputs User Year

	return (useryear);
}

// This function will search for the movie with the highest revenue up to User Year
void search(MovieInfo movie[10], int useryear)
{
	int x = 0;													//Declaration
     int flag = 0;
	long high = -9999;
	long holdrevenue;
	char holdname[50];

	do
	{
		if (movie[x].year <= useryear)
		{
			if (movie[x].revenue >= high)
			{
               	high = movie[x].revenue;								//Assigns Revenue to High
				holdrevenue = movie[x].revenue;						//Assigns Revenue to Hold Revenue
				strcpy(holdname, movie[x].name);						//Assigns Name to Hold Name
			}

			flag = 1;												//Assigns 1 to Flag
		}

		x++;														//Increases x by 1
	}
	while (x < 10);

	if (flag == 0)
		cout<<"\nError, movie was not found. ";							//Outputs Error Message
	else
		cout<<"\nThe highest revenue movie through "<<useryear<<" was: "
			<<""<<holdname<<" -- $"<<holdrevenue;						//Outputs Result
}