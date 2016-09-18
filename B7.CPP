// Program name: B7  
// Date: March 13, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read 15 numbers from a data file.
// 			Puts them in a 3 x 5 array, and finds the highest number in the array.
// 			
//
// Input: Number of Each Product sold by each salesperson  
//
// Output: 5 by 4 table   
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

// FUNCTION PROTOTYPES
void init();
void openfile(ifstream& input1);
void readdata(ifstream& input1, int value[3][5]);
void findhighest(int value[3][5], int& high, int& highposx, int& highposy);
void outputdata(int value[3][5], int high, int highposx, int highposy);

int main()
{
	int value[3][5];		//Declaration
	int high = -32000;
	int highposx, highposy;
     ifstream input1;
    
	init();				//Function call for Initialize

	openfile(input1);		//Function call for Open File
    
	readdata(input1, value);		//Function call for Read Data

	input1.close();

	findhighest(value, high, highposx, highposy);		//Function call for Find Highest

	outputdata(value, high, highposx, highposy);		//Function call for Output Data
    
	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will read 15 numbers from a data file. "
		<<"\nPuts them in a 3 x 5 array, and finds the highest number in the array. ";       //Outputs Purpose
                 
	cout<<"\n\nPress Enter to Proceed. ";        //Press Enter to Continue
	getchar();
	clrscr();
}

//This function will open/check B7.dat file
void openfile(ifstream& input1)
{
	input1.open("F:/Bprogs/B7.dat");			//Opens B7.dat

	if (input1.fail())
	{
		cout<<"Input file B7.dat failed ";		//Outputs error message
		getchar();
		exit(1);
	}
}

//This function will input the data type in from the user
void readdata(ifstream& input1, int value[3][5])
{   
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 5; y++)
			input1>>value[x][y];                          //Inputs number
	}
}

//This function will find the highest number in the array
void findhighest(int value[3][5], int& high, int& highposx, int& highposy)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			if (value[x][y] > high)
               {
				high = value[x][y];					//Assigns Value to High
				highposx = x;						//Assigns x to high position x
				highposy = y;						//Assigns y to high position y
               }
		}
	}
}

//This function will output the data into a table
void outputdata(int value[3][5], int high, int highposx, int highposy)
{
	cout<<"\n"<<setw(19)<<"Column 0";					//Outputs Column Titles
	cout<<setw(14)<<"Column 1";
	cout<<setw(14)<<"Column 2";
	cout<<setw(14)<<"Column 3";
	cout<<setw(14)<<"Column 4";

	for (int x = 0; x < 3; x++)
	{
		cout<<endl<<"Row "<<x;						//Outputs Row Titles
         
		for (int y = 0; y < 5; y++)
			cout<<setw(14)<<value[x][y];			//Outputs value
	}

	cout<<"\n\nThe highest number in the array was "<<high<<" "
		<<"and it was found at position ("<<highposx<<","<<highposy<<") ";		//Outputs Highest Number
     
	cout<<"\n\n\nPress Enter to Quit ";			//Press Enter to Quit
	getchar();
	exit(1);
}