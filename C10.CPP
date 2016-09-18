//sum incorrect, initialize total to zero  -3%
//one day late -10%
//87%

// Program name: C10  
// Date: April 19, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will read in data from an external file.
//               The user can input a state name and the program will
//               output the Interstate highway miles in the state.
// 
// Input:  State Name
//
// Output:  Interstate Highway Miles
//
// Assumptions/Limitations: Data Exists
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
struct List
{
	char state[50];
	double mileage;
	char cities[80];
};

struct Road
{
	char highway[5];
	List statelist;
}roadlist[10];

// FUNCTION PROTOTYPES
void init();
void openfile(ifstream& input);
void readdata(ifstream& input, Road roadlist[10], int& max);
void outputdata(Road roadlist[10], int max);
void inputstate(char userstate[50]);
void search(char userstate[50], Road roadlist[10], int max);

int main()
{
	ifstream input;							//Declaration
	int max;
	char userstate[50];

	init();								//Call Initialize
	openfile(input);							//Call Open File
	readdata(input, roadlist, max);					//Call Read Data
	input.close();

	outputdata(roadlist, max);						//Call Output Data
	inputstate(userstate);						//Call Input State
	search(userstate, roadlist, max);					//Call Search

	getchar();
	return 0;
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will read in data from an external file. "
		<<"\nThe user can input a statename and the program will "
		<<"\noutput the Interstate highway miles in the state. ";				//Outputs purpose

	cout<<"\n\nPress Enter to Proceed.";							//Press Enter to Continue
	getchar();
	clrscr();
}

// This program will check and open the file
void openfile(ifstream& input)
{
	input.open("F:/Cprogs/C10DATA.dat");							//Opens File

	if (input.fail())
	{
		cout<<"Input file C10DATA failed.";						//Outputs Error Message
		getch();
		exit(1);
	}
}

// This function will read in data from the file
void readdata(ifstream& input, Road roadlist[10], int& max)
{
	int x = 0;										//Declaration

	do
	{
		input.getline(roadlist[x].highway, 80, '\t');					//Reads in Highway
		input.getline(roadlist[x].statelist.state, 80, '\t');					//Reads in State
		input.ignore();

		input>>roadlist[x].statelist.mileage;						//Reads in Mileage
		input.getline(roadlist[x].statelist.cities, 80, '\n');					//Reads in Cities

		x++;									//Increases x by 1
	}
	while(! input.eof());

	max = x;										//Assigns x to max
}

// This function will output the data to the screen
void outputdata(Road roadlist[10], int max)
{
	int x = 0;										//Declaration

	cout<<setw(8)<<"Highway"<<setw(12)<<"State"<<setw(10)<<"Mileage"<<setw(10)<<"Cities";		//Outputs Titles

	do
	{
		cout<<endl;								//Outputs Blank Line

		cout<<setw(8)<<roadlist[x].highway;							//Outputs Highway
		cout<<setw(12)<<roadlist[x].statelist.state;					//Outputs State
		cout<<setw(10)<<roadlist[x].statelist.mileage;					//Outputs Mileage
		cout<<setw(5)<<roadlist[x].statelist.cities;					//Outputs Cities

		x++;									//Increases X by 1
	}
	while (x < max);
}		

// This function will allow the user to enter state name
void inputstate(char userstate[50])
{
	cout<<"\n\nEnter State Name: ";							//Inputs State Name
	cin.getline(userstate, 80, '\n');
}

// This function will find and calculate the total number of interstate highway miles in the state
void search(char userstate[50], Road roadlist[10], int max)
{
	int x = 0;                                              							//Declaration
	double total;
	int flag = 0;
     
	do
	{
		if (strcmpi(userstate, roadlist[x].statelist.state) == 0)				//If State is found
		{
			total += roadlist[x].statelist.mileage;					//Calculates Total
			flag = 1;                                         					//Assigns 1 to Flag
		}
         
		x++;									//Increases x by 1
	}
	while (x < max);

	if (flag == 0)
	{
		cout<<"\nError, State not found.";						//Outputs Error Message
		getch();
		exit(1);
	}

	cout<<"\nInterstate highway miles: "<<total;						//Outputs Result
}    
