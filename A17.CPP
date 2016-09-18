//start low at -1 to find first value
//98%
// Program name: A17
// Date: Feb 28, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read in numbers from a data file.
// 		Outputs the numbers and their locations to the screen
// 		Allows the user to input a number they want to find
// 		Finds and outputs the location of the number.
// 
// Input:  Array to find
//
// Output:  Array's location
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

// Function Prototypes
void init();
void openfile(ifstream& input1);
void readdata(ifstream& input1, int num[50], int& high, int& low);
void outputdata(int high, int num[50]);
int inputvalue();
void search(int num[50], int low, int high, int uservalue, int& x);
void outputresult(int x);

int main()
{
	ifstream input1;				//Declaration
	int num[50], low = 0, high, uservalue, x;

	init();					//Function call for Initialize
	openfile(input1);				//Function call for Open File
	readdata(input1, num, high, low);		//Function call for Read Data
	input1.close();
	
	outputdata(high, num);			//Function call for Output Data
	uservalue = inputvalue();     			//Function call for Input Value
	search(num, low, high, uservalue, x);       	//Function call for Search
	outputresult(x);				//Function call for Output Result

	getchar();
	return 0;
}

//This function will output what the program does
void init()
{
	cout<<"This program will read in numbers from a data file. "	//Outputs purpose
		<<"\nOutputs the numbers and their locations to the screen "
		<<"\nAllows the user to input a number they want to find "
		<<"\nFinds and outputs the location of the number ";
	
	cout<<"\n\nPress Enter to Proceed. ";				//Press enter to continue
	getchar();
	clrscr();
}

//This function will check and open for input file
void openfile(ifstream& input1)
{
	input1.open("F:/Aprogs/A17.dat");			//Opens A17.dat file

	if (input1.fail())
	{
		cout<<"Input file A17.dat failed. ";		//Outputs error message
		getchar();
		exit(1);
	}
}

//This function will read in numbers from the Dat file
void readdata(ifstream& input1, int num[50], int& high, int& low)
{
	int x;
    
	for (x = 0; ! input1.eof(); x++)
		input1>>num[x];						//Reads in number
		
	high = x - 1;
}

//This function will output the numbers in the array and their corresponding location
void outputdata(int high, int num[50])
{
	int x;
     
	cout<<"\nThe Array is: ";						//Outputs title

	for (x = 0; x < high; x++)
		cout<<setw(3)<<num[x];					//Outputs Array Value


	cout<<"\nThe Location: ";						//Outputs title

	for (x = 0; x < high; x++)
		cout<<setw(3)<<x;						//Outputs Location
}

//This function will allow the user to input a value to search
int inputvalue()
{
	int uservalue;				//Declaration
    
	cout<<"\n\nEnter value to search for: ";		//Inputs value to search
	cin>>uservalue;
     
	return (uservalue);
}

//This function will find the location of the user input value
void search(int num[50], int low, int high, int uservalue, int& x)
{     


	do
	{
		x = (low + high) / 2;    

               
		if (num[x] == uservalue)
			break;						//Breaks out of loop if Num is equal to User Value
               
		if (num[x] < uservalue)
			low = x;						//Makes low equals the index if user value is less than num
               
		if (num[x] > uservalue)
			high = x;						//Makes high equals the index if user value is greater than num
               
		if ((high - low) == 1)
		{
			cout<<"Error, number not found. ";			//Outputs error message
			getchar();
			exit(1);
		}
	}
	while ((high - low) != 1);
}



//This function will output the result
void outputresult(int x)
{
	cout<<"\nThe value was found at index location "<<x;	//Outputs purpose
	getchar();
}