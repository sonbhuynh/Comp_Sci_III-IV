// Program name: A3 
// Date: Jan 31, 2012 
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will output the last name, first name, and grade to a file  
// 
// Input: First name, last name, and grade 
//
// Output: First name, last name, and grade to an external file 
//
// Assumptions/Limitations: None
//--------------------------------------------------------------------------

//////////////////////LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	 ofstream output1;				//Declaration
	 char first [15], last [15], grade, choice;

	 output1.open("F:/Aprogs/A3.dat");

	 if(output1.fail())
	 {
		cout<<"Output file A3.dat opening failed. \n";		//Outputs failure message
		getch();
		exit(1);
	 }

      cout<<"\nThis program will output the last name, first name, and grade to a file ";	//Outputs purpose

	 do
	 {
		cout<<"\n\nEnter name: ";

		cout<<"\nFirst: ";			//Inputs first name
	     cin.getline(first, 80, '\n');

	     cout<<"\nLast: ";			//Inputs last name
	     cin.getline(last, 80, '\n');

		cout<<"\nEnter letter grade: ";	//Inputs grade
		cin>>grade;
		grade = toupper(grade);

		output1<<last<<", "<<first<<"* "<<grade<<"\n";	//Outputs data to data file

		cout<<"\n"<<last<<", "<<first<<"* "<<grade;		//Outputs data to screen 

		cout<<"\nEnter another record? (Y/N): ";		//Inputs Y or N
		cin>>choice;
		choice = toupper(choice);
          cin.ignore();
	 }
	 while (choice != 'N');

      output1.close();
	 return 0;
}