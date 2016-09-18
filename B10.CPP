//does not always work for A
//93%

// Program name: B10  
// Date: March 19, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:   This program will read in data from an external file,
// 			allows the user to input in element or symbolic name,
// 			and outputs the result onto the screen.
// 
// Input: Element or Symbolic Name
//
// Output: Vice Versa of what was input
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

char menu();
void readdata(ifstream& input1, char symbol[10][2][15], int& max);
void inputelement(char userelement[80]);
void findelement(char userelement[80], char symbol[10][2][15], int& flagelement, int max);
void inputsymbolic(char usersymbolic[80]);
void findsymbolic(char usersymbolic[80], char symbol[10][2][15], int& flagsymbolic, int max);

int main()
{
	char choice;					//Declaration
	ifstream input1;
	int flagelement = 0, flagsymbolic = 0;
	int max;
	char userelement[80], usersymbolic[80], symbol[10][2][15];

	init();							//Function call for Initialize
	openfile(input1);					//Function call for Open File
	readdata(input1, symbol, max);			//Function call for Read Data
     input1.close();

	do
	{
		choice = menu();				//Function call for Menu

		if (choice == 'Q')
		{
			cout<<"\nProgram Terminated.";			//Outputs Quit Message
			break;
		}

		flagelement = 0;				//Assigns Flag Element to 0
		flagsymbolic = 0;				//Assigns Flag Symbolic to 0

		switch (choice)
		{
			case 'A':
				inputelement(userelement);				//Function call for Input Element
				findelement(userelement, symbol, flagelement, max);			//Function call for Find Element

				if (flagelement == 0)
					cout<<"\nElement Not Found. ";

				break;

			case 'B':
				inputsymbolic(usersymbolic);				//Function call for Input Symbolic
				findsymbolic(usersymbolic, symbol, flagsymbolic, max);			//Function call for Find Symbolic

				if (flagsymbolic == 0)
					cout<<"\nSymbol Not Found. ";

				break;

			case 'Q':
				cout<<"\nProgram Terminated.";			//Outputs Quit Message
				getchar();
				break;

			default:
				cout<<"\nPress Re-Enter either A, B, or Q ";		//Outputs error message
				break;

		}

		cout<<"\nPress Enter to Return to Menu ";
		getchar();
		clrscr();  
             	
	}
	while (choice != 'Q');

	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will read in data from an external file, "
		<<"\nallows the user to input in element or symbolic name, "
		<<"\nand outputs the result onto the screen. ";		//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed. ";
	getchar();
	clrscr();
}

//This function will check and open the data file
void openfile(ifstream& input1)
{
	input1.open("F:/Bprogs/B10.dat");						//Opens B10.dat file

	if (input1.fail())
	{
		cout<<"Input file B10.dat failed to open. ";			//Outputs Failure Message
		getchar();
		exit(1);
	}
}

//This function will read in data from the B10.dat file
void readdata(ifstream& input1, char symbol[10][2][15], int& max)
{
	int x = 0;										//Declaration

	do
	{
		input1.getline(symbol[x][0], 80, ' ');				//Reads in Symbol
	

		if (strlen(symbol[x][0]) == 1)
			input1.ignore();							//Ignores space if Symbol only has 1 character

		input1.getline(symbol[x][1], 80, '\n');				//Reads in Element Name

          x++;											//Increases x by 1
	}
	while (! input1.eof());

	max = x - 1;								//Assigns Max as x - 1
}

//This function will output the menu to the screen and allow the user to input a choice
char menu()
{
	char choice;							//Declaration

	cout<<"Menu: ";									//Outputs Menu
	cout<<"\n\tA. Find Symbolic Name ";
	cout<<"\n\tB. Find Elements Name ";
	cout<<"\n\tQ. Quit ";

	cout<<"\n\nPlease select (enter A, B, or Q): ";			//Inputs choice
	cin>>choice;
	choice = toupper(choice);
     cin.ignore();

	return (choice);
}

// ************ PART A ************

//This function will allow the user to input the Element's name
void inputelement(char userelement[80])
{

	cout<<"\nEnter Element's Name: ";						//Inputs Element's name
	cin.getline(userelement, 80, '\n');
}

//This function will search for the input element name and output its symbolic name
void findelement(char userelement[80], char symbol[10][2][15], int& flagelement, int max)
{
	int x = 0;									//Declaration

	do
	{
		if (strcmpi(userelement, symbol[x][1]) == 0)
		{
			cout<<"\nSymbolic Name is: "<<symbol[x][0];			//Outputs Symbolic name if for the User Input Element
			flagelement = 1;						//Assigns 1 to Flag Element
		}

		x++;
	}
	while (x < max);
}  



// ************ PART B ************

//This function will allow the user to input the Symbolic name
void inputsymbolic(char usersymbolic[80])
{
	cout<<"\nEnter Symbolic Name: ";						//Inputs Symbolic name
	cin.getline(usersymbolic, 80, '\n');
}

//This function will search for the input symbolic name and output its element name
void findsymbolic(char usersymbolic[80], char symbol[10][2][15], int& flagsymbolic, int max)
{
	int x = 0;									//Declaration

	do
	{
		//cout<<usersymbolic<<"*"<<symbol[x][0]<<endl;

		if (strcmpi(usersymbolic, symbol[x][0]) == 0)
		{
			cout<<"\nElement Name is: "<<symbol[x][1];			//Outputs Symbolic name if for the User Input Element
			flagsymbolic = 1;						//Assigns 1 to Flag Symbolic
		}

		x++;
	}
	while (x < max);
}