// Program name: C6  
// Date: April 11, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will allow the user to enter Name, State, Year
// 				Acreage, and Comments. The information entered for each park
// 				will be outputted to the screen and to an external data file.
// 				The user can enter a state name to search for a park, and all
// 				the information about that park will be outputted to the screen.
// 
// Input: Name, State, Year, Acreage, and Comments. Also user input state  
//
// Output: Data to the screen and data file, and parks in the input state  
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
struct ParkInfo
{
	char name[20];
	char state[3];
	int year;
	long acreage;
	char comments[30];
}park[20];

// FUNCTION PROTOTYPES
void init();
void inputdata(ParkInfo park[20]);
void openfile(ofstream& output1);
void outputdata(ofstream& output1, ParkInfo park[20]);
void outputscreen(ParkInfo park[20]);
void inputstate(char userstate[3]);
void search(char userstate[3], ParkInfo park[20]);

int main()
{
	int x = 0;												//Declaration
	ofstream output1;
     char userstate[3];

	init();													//Function call for Initialize

	inputdata(park);											//Function call for Input Data
	openfile(output1);											//Function call for Open File
	outputdata(output1, park);									//Function call for Output Data
	output1.close();

	outputscreen(park);											//Function call for Output Screen

	inputstate(userstate);										//Function call for Input State
	search(userstate, park);										//Function call for Search

	getchar();
	return 0;
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will allow the user to enter Name, State, Year "
		<<"\nAcreage, and Comments. The information entered for each park "
		<<"\nwill be outputted to the screen and to an external data file. "
		<<"\nThe user can enter a state name to search for a park, and all "
		<<"\nthe information about that park will be outputted to the screen. ";			//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";											//Press Enter to Continue
	getchar();
	clrscr(); 
}

// This function will allow the user to input data for each park
void inputdata(ParkInfo park[20])
{
	int x = 0;												//Declaration

	do
	{
		cout<<"\nEnter Park "<<x+1<<" Name (or Quit): ";
		cin.getline(park[x].name, 80, '\n');						//Inputs Name

		if (strcmpi(park[x].name,"quit") == 0)
		{
			cout<<"\nYou have Quit. ";							//Outputs Quit Message
			break;
          }

		cout<<"\nEnter State Name: ";
		cin.getline(park[x].state, 80, '\n');						//Inputs State

		cout<<"\nEnter Year: ";
		cin>>park[x].year;										//Inputs Year

		cout<<"\nEnter Acreage: ";
		cin>>park[x].acreage;									//Inputs Acreage
          cin.ignore();

		cout<<"\nEnter Comments: ";
		cin.getline(park[x].comments, 80, '\n');					//Inputs Comments

		x++;													//Increases x by 1
	}
	while(strcmpi(park[x].name,"quit") != 0);
}

// This function will opens and checks an output file
void openfile(ofstream& output1)
{
	output1.open("F:/Cprogs/C6.dat");								//Opens C6.dat file

	if (output1.fail())
	{
		cout<<"Output to file C6.dat failed. ";						//Outputs Error Message
		getchar();
		exit(1);
	}
}

// This function will output data to the C6.dat file
void outputdata(ofstream& output1, ParkInfo park[20])
{
	int x = 0;												//Declaration

	do
	{
		output1<<park[x].name;									//Outputs Park Name

		output1<<'\t'<<park[x].state;								//Outputs State

		output1<<'\t'<<park[x].year;								//Outputs Year

		output1<<'\t'<<park[x].acreage;							//Outputs Acreage

		output1<<'\t'<<park[x].comments;							//Outputs Comments

		x++;													//Increases x by 1

          output1<<endl;											//Goes to next line
	}
	while(strcmpi(park[x].name,"quit") != 0);
}

// This function will output data to the screen
void outputscreen(ParkInfo park[20])
{
	int x = 0;												//Declaration

	cout<<"\n\n"<<setw(12)<<"Name"<<setw(12)<<"State"<<setw(12)<<"Year"
		<<setw(12)<<"Acreage"<<setw(16)<<"Comments"<<endl;			//Outputs Titles

	do
	{
		cout<<endl;

		cout<<setw(12)<<park[x].name;								//Outputs Park Name

		cout<<setw(12)<<park[x].state;							//Outputs State

		cout<<setw(12)<<park[x].year;								//Outputs Year

		cout<<setw(12)<<park[x].acreage;							//Outputs Acreage

		cout<<setw(16)<<park[x].comments;							//Outputs Comments

		x++;													//Increases x by 1
	}
	while(strcmpi(park[x].name,"quit") != 0);
}

// This function will allow the user to input in the state they want to search for
void inputstate(char userstate[3])
{
	cout<<"\n\nPlease Enter State Name: ";
	cin.getline(userstate, 80, '\n');								//Inputs User State
}

// This function will search for the user input state and output the park
void search(char userstate[3], ParkInfo park[20])
{
	int x = 0;												//Declaration

	do
	{
		if (strcmpi(userstate, park[x].state) == 0)
		{
			cout<<"\n\t"<<park[x].name<<" - "<<park[x].comments;		//Outputs park(s) in that state
		}

          x++;													//Increases x by 1
	}
	while (strcmpi(park[x].name,"quit") != 0);
}