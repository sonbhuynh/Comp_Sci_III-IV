// Program name: A4
// Date: Jan 31, 2012 
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will process a DATA file, outputs to the screen the program that it 
//		reads in, then the total number of line
// Input: User will input the Address of the file 
//
// Output: The program will output the file's content
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
	ifstream input1;					//Declaration
	char filename[20], line[80];
	int count = 0;

	cout<<"\nThis program will allow the user to enter the address of a file "
		<<"\nand opens it on the screen ";						//Outputs purpose
	getchar();
     clrscr();

	cout<<"\nEnter the address of the file: ";
	cin.getline(filename, 80, '\n');		//Inputs DATA file

	input1.open(filename);

	if(input1.fail())
	{
		cout<<"Input file "<<filename<<" opening failed. \n";		//Outputs failure message
		getch();
		exit(1);
	}

	cout<<"\nThe program read in is: ";	

	do
	{
		input1.getline(line, 80, '\n');		//Reading in input file
		cout<<"\n"<<line;

		count++;							//Increases count by 1

		if (count % 20 == 0)
		{
			cout<<"\nPress Enter to continue ";		//Press enter to go to next page
			getch();
			clrscr();
		}

	}
	while (! input1.eof());

	cout<<"\n\nThe total number of lines in this program is: "<<count;		//Outputs number of line

     input1.close();
	return 0;
}