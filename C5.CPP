// Program name: C5  
// Date: April 11, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will allow the user to input First, Last, MI, Age, and Income
// 
// Input: Name, Age, Income  
//
// Output: Name, Age, Income  
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
struct StudentType
{
	char last[10];
	char first[10];
	char initial;
	int age;
	double income;
}student[5];

// FUNCTION PROTOTYPES
void init();
void input(StudentType student[5]);
void output(StudentType student[5]);

int main()
{
	init();													//Function call for Initialize

	input(student);											//Function call for Input

	output(student);											//Function call for Output

	getchar();
	return 0;
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will allow the user to input First, Last, MI, Age, and Income. "
		<<"\nThe program will then output the info for each person in a Full Name, "
		<<"\nAge, and Income format onto the screen. ";					//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";								//Press Enter to Continue
	getchar();
	clrscr();
}

// This function will allow the user to input data for each student
void input(StudentType student[5])
{
	for (int x = 0; x < 5; x++)
     {
		cout<<"\n\nStudent "<<x + 1;											//Outputs Student Number

		cout<<"\nEnter Last Name: \t\t";
		cin.getline(student[x].last, 80, '\n');								//Inputs Last Name
		student[x].last[0] = toupper(student[x].last[0]);

		cout<<"\nEnter First Name: \t\t";
		cin.getline(student[x].first, 80, '\n');							//Inputs First Name
		student[x].first[0] = toupper(student[x].first[0]);

		cout<<"\nEnter Middle Initial: \t\t";
		cin>>student[x].initial;											//Inputs Middle Initial
		student[x].initial = toupper(student[x].initial);
		cin.ignore();

		cout<<"\nEnter Student's Age: \t\t";
		cin>>student[x].age;											//Inputs Age

		cout<<"\nEnter Student's Income: \t";
		cin>>student[x].income;											//Inputs Income
          cin.ignore();
     }
}

void output(StudentType student[5])
{
	for (int x = 0; x < 5; x++)
     {
		cout<<"\n\nName: \t\t"<<student[x].first<<" "<<student[x].initial<<". "<<student[x].last;		//Outputs Name
		cout<<"\nAge: \t\t"<<student[x].age;												//Outputs Age
		cout<<"\nIncome: \t$"<<student[x].income;
	}
} 	 