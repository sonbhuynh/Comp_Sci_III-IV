// Program name: A15
// Date: Feb 25, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will read data from 2 data files named A15names.dat and A15occup.dat.  
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

void init();			//Prototype for Initialize
void check(ifstream& inputnames, ifstream& inputoccup);		//Prototype for Check
void titles();			//Prototype for Titles
void readdata(ifstream& inputnames, ifstream& inputoccup, char lastname[10][80], char firstname[10][80], char occupation[10][80], char fullname[10][80]);		//Prototype for Read Data
void outputdata(char fullname[10][80], char occupation[10][80]);		//Prototype for Output Data
void inputoccupation(char useroccup[20]);				//Prototype for Input Occupation
void search(char occupation[10][80], char useroccup[20], char fullname[10][80], int& flag);		//Prototype for Search

int main()
{
	ifstream inputnames, inputoccup;			//Declaration
	int flag = 0;
	char firstname[10][80], lastname[10][80], occupation[10][80], fullname[10][80], useroccup[20];	

	init();						//Function call for Initialize
	check(inputnames, inputoccup);			//Function call for Check
	titles();						//Function call for Titles

	readdata(inputnames, inputoccup, lastname, firstname, occupation, fullname);		//Function call for Read Data
	outputdata(fullname, occupation);		//Function call for Output Data
	inputoccupation(useroccup);					//Function call for Input Occupation
	search(occupation, useroccup, fullname, flag);	//Function call for Search

	if (flag == 0)
		cout<<"\nName not found. ";				//Outputs error message

	inputnames.close();
     inputoccup.close();
	
	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will read data from 2 data files named A15names.dat "
		<<"\nand A15occup.dat.  "		//Outputs purpose
		<<"\nThen ask for an occupation in the second list "
		<<"\nand output all the corresponding items to the screen. ";

	cout<<"\n\nPress Enter to Proceed. ";		//Press Enter to continue
	getchar();
	clrscr();
}

//This function will check and open both data files
void check(ifstream& inputnames, ifstream& inputoccup)
{
	inputnames.open("F:/Aprogs/A15NAMES.dat");	//Opens A15Names.dat file

	if (inputnames.fail())
	{
		cout<<"Input file A15Names.dat failed. ";			//Outputs error message
		getchar();
		exit(1);
	}

	inputoccup.open("F:/Aprogs/A15OCCUP.dat");		//Opens A15Occup.dat file

	if (inputoccup.fail())
	{
		cout<<"Input file A15Occup.dat failed. ";			//Outputs error message
		getchar();
		exit(1);
	}
}

void titles()
{
	cout<<setw(18)<<"Name List"<<setw(25)<<"Occupation";			//Outputs Titles
	cout<<"\n"<<setw(18)<<"---------"<<setw(25)<<"----------";			//Outputs Blank Line
}

//This function will read in data from both data files
void readdata(ifstream& inputnames, ifstream& inputoccup, char lastname[10][80], char firstname[10][80], char occupation[10][80], char fullname[10][80])
{ 
	for(int x = 0; x < 10; x++)
     {
		inputnames.getline(lastname[x], 80, ',');				//Inputs Last Name
		inputnames.ignore();

		inputnames.getline(firstname[x], 80, '\n');				//Inputs First Name

		inputoccup.getline(occupation[x], 80, '\n');			//Inputs Occupation

		strcpy(fullname[x], firstname[x]);					//Copies First name to Full name
		strcat(fullname[x], " ");						//Copies Space to Full name
		strcat(fullname[x], lastname[x]);					//Copies Last name to Full name
     }
}

//This function will output the data from both data files to the screen
void outputdata(char fullname[10][80], char occupation[10][80])
{
	for (int x = 0; x < 10; x++)
     {
		cout<<"\n"<<setw(18)<<fullname[x];		//Outputs Name
		cout<<setw(25)<<occupation[x];		//Outputs Occupation
     }
}

//This function will allow the user to input the occupation
void inputoccupation(char useroccup[20])
{
	cout<<"\n\nPlease enter an occupation: ";			//Inputs User Occupation
	cin.getline(useroccup, 80, '\n');
}

//This function will search and output the name with that occupation if found
void search(char occupation[10][80], char useroccup[20], char fullname[10][80], int& flag)
{
	cout<<"\n\nThe following people is/are "<<useroccup<<"(s): ";		//Outputs people with that occupation

	for (int x = 0; x < 10; x++)
     {
		if (strcmpi(occupation[x], useroccup)== 0)
		{
			cout<<"\n"<<setw(43)<<fullname[x];			//Outputs the person with the search occupation
		
			flag = 1;						//Sets Flag to 1
		}
	}
}	