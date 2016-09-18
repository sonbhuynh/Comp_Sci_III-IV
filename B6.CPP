// Program name: B6  
// Date: March 09, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will allow the user to enter the number of each product
// 			sold by each salesperson. The program should store the number entered
// 			in a 5 by 4 table and write out the table with labels of the matrix.
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
void readdata(int value[5][4]);
void outputdata(int value[5][4]);

int main()
{
	int value[5][4];		//Declaration
    
	init();				//Function call for Initialize
    
	readdata(value);		//Function call for Read Data
	outputdata(value);		//Function call for Output Data
    
	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will allow the user to enter the number of each product "
		<<"\nsold by each salesperson. The program should store the number entered "
		<<"\nin a 5 by 4 table and write out the table with labels of the matrix. ";       //Outputs Purpose
                 
	cout<<"\n\nPress Enter to Proceed. ";        //Press Enter to Continue
	getchar();
	clrscr();
}

//This function will input the data type in from the user
void readdata(int value[5][4])
{   
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			cout<<"\nEnter Product "<<x+1<<", Salesperson "<<y+1;
			cout<<": ";
			cin>>value[x][y];                          //Inputs number
		}
	}
}

//This function will output the data into a table
void outputdata(int value[5][4])
{
	cout<<"\n\n"<<setw(27)<<"Salesperson 1 ";		//Outputs Salesperson titles
	cout<<setw(15)<<"Salesperson 2 ";
	cout<<setw(15)<<"Salesperson 3 ";
	cout<<setw(15)<<"Salesperson 4 ";

	for (int x = 0; x < 5; x++)
	{
		cout<<endl<<"Product "<<x + 1<<": ";		//Outputs Product 1;
         
		for (int y = 0; y < 4; y++)
			cout<<setw(15)<<value[x][y];			//Outputs value
	}
     
	cout<<"\n\n\nPress Enter to Quit ";			//Press Enter to Quit
	getchar();
	exit(1);
}