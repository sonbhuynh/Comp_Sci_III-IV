// Program name: A15
// Date: Feb 25, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will read data from 2 data files named “A15names.dat” and “A15occup.dat”.  
// 		Then ask for an occupation in the second list and output all the corresponding items to the screen.
// 
// Input: Occupation
//
// Output: People with that occupation
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

using namespace std;

void init();			//Prototype for Initialize
void check(ifstream& inputnames, ifstream& inputoccup);		//Prototype for Check
void readdata(ifstream& inputnames, ifstream& inputoccup, char lastname[10][80], char firstname[10][80], char occupation[10][80], char fullname[10][80]);		//Prototype for Read Data
void outputdata(char lastname[10][80], char firstname[10][80], char occupation[10][80]);		//Prototype for Output Data
void inputoccupation(char useroccup[10][80]);				//Prototype for Input Occupation
void search(char occupation[10][80], char useroccup[10][80], char fullname[10][80], int flag);		//Prototype for Search

int main()
{
	ifstream inputnames, inputoccup;			//Declaration
	int flag = 0;
	char firstname[10][80], lastname[10][80], occupation[10][80], fullname[10][80], useroccup[10][80];	

	init();						//Function call for Initialize
	check(inputnames, inputoccup);			//Function call for Check

	cout<<setw(10)<<"Name List"<<setw(14)<<"Occupation";			//Outputs Titles

	do
	{
		readdata(inputnames, inputoccup, lastname, firstname, occupation, fullname);		//Function call for Read Data
		outputdata(lastname, firstname, occupation);		//Function call for Output Data
	}
	while(! inputnames.eof());

	inputoccupation(useroccup);					//Function call for Input Occupation

	do
	{
		readdata(inputnames, inputoccup, lastname, firstname, occupation, fullname);		//Function call for Read Data
		search(occupation, useroccup, fullname, int flag);	//Function call for Search
	}
	while(! inputnames.eof());

	if (flag == 0)
		cout<<"\nName not found. ";				//Outputs error message
	
	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will read data from 2 data files named “A15names.dat” and “A15occup.dat”.  "		//Outputs purpose
		<<"\nThen ask for an occupation in the second list and output all the corresponding items to the screen. ";

	cout<<"\n\nPress Enter to Proceed. ";		//Press Enter to continue
	getchar();
	system("CLS");
}

//This function will check and open both data files
void check(ifstream& inputnames, ifstream& inputoccup)
{
	inputnames.open("C:/Users/Son-Huynh/Downloads/A15NAMES.dat");	//Opens A15Names.dat file

	if (inputnames.fail())
	{
		cout<<"Input file A15Names.dat failed. ";			//Outputs error message
		getchar();
		exit(1);
	}

	inputoccup.open("C:/Users/Son-Huynh/Downloads/A15OCCUP.dat");		//Opens A15Occup.dat file

	if (inputoccup.fail())
	{
		cout<<"Input file A15Occup.dat failed. ";			//Outputs error message
		getchar();
		exit(1);
	}
}

//This function will read in data from both data files
void readdata(ifstream& inputnames, ifstream& inputoccup, char lastname[10][80], char firstname[10][80], char occupation[10][80], char fullname[10][80])
{
	inputnames.getline(lastname, 80, ',');				//Inputs Last Name
	inputnames.ignore();

	inputnames.getline(firstname, 80, '\n');				//Inputs First Name
	inputnames.ignore();

	inputoccup.getline(occupation, 80, '\n');			//Inputs Occupation
	inputoccup.ignore();

	strcpy(fullname, firstname);					//Copies First name to Full name
	strcat(fullname, " ");					//Copies Space to Full name
	strcat(fullname, lastname);					//Copies Last name to Full name
}

//This function will output the data from both data files to the screen
void outputdata(char lastname[10][80], char firstname[10][80], char occupation[10][80])
{
	cout<<"\n"<<setw(10)<<lastname<<", "<<firstname;		//Outputs Name
	cout<<"\n"<<setw(14)<<occupation;				//Outputs Occupation
}

//This function will allow the user to input the occupation
void inputoccupation(char useroccup[10][80])
{
	cout<<"\n\nPlease enter an occupation: ";			//Inputs User Occupation
	cin.getline(useroccup, 80, '\n');
}

//This function will search and output the name with that occupation if found
void search(char occupation[10][80], char useroccup[10][80], char fullname[10][80], int flag)
{
	if (strcmpi(occupation, useroccup) == 0)
	{
		cout<<"\n\nThe following people are writers: ";		//Outputs people with that occupation
		cout<<"\n"<<setw(15)<<fullname;
	
		flag = 1;
	}
}	
