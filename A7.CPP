// Program name: A7  
// Date: Feb 3, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will input a data file is made up of a department number,
//				an item number, the quantity sold, and the cost per item.
//				Then the program will process the data file to output to the screen
//				the department number and value of the sales for each line of the data file
//				as well as the total for each department.
// Input: The program will input the A7.dat file  
//
// Output: The program will output the Department number, sales, and total   
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

void magic();								//Prototype for Magic formula
void init();								//Prototype for Outputting purpose
void check(ifstream& input1);					//Prototype for Checking input file
void titles();								//Prototype for Titles
void inputdata(ifstream& input1, int& newdept, int item, int& quantity, double& cost);		//Prototype for Inputting data
void calculations(ifstream& input1, int& olddept, int& newdept, int quantity, double cost, double& sales, double& total, double& finaltotal);		//Prototype for Calculations
void outputdata(ifstream& input1, double sales, int olddept, int newdept, double total, double finaltotal);	//Prototype for Outputting data

int main()
{
	ifstream input1;						//Declaration
	int item, quantity, olddept, newdept;
	double cost, sales, total = 0, finaltotal = 0; 
           
	magic();								//Function call for Magic formula

     init();								//Function call for Outputting purpose

	check(input1);							//Function call for Checking input

	titles();								//Function call for Titles

	input1.ignore(80, '\n');					//Ignore the title line


	input1>>olddept;						//Reading in Old Department
	cout<<endl<<setw(15)<<olddept;			//Outputting Old Department

	do
	{
		inputdata(input1, newdept, item, quantity, cost);			//Function call for Inputting data
		calculations(input1, olddept, newdept, quantity, cost, sales, total, finaltotal);	//Function call for Calculations
		outputdata(input1, sales, olddept, newdept, total, finaltotal);		//Function call for Outputting data
	}
	while(!input1.eof());

	getchar();
	return 0;
}

//This program will output what the program does
void init()
{
	cout<<"\nThis program will input a data file is made up of a department number, "
		<<"\nan item number, the quantity sold, and the cost per item. "
		<<"\nThen the program will process the data file to output to the screen "
		<<"\nthe department number and value of the sales for each line of the data file "
		<<"\nas well as the total for each department. ";		//Outputs purpose of program

	cout<<"\n\nPress enter to continue ";		//Press enter to clear screen
	getchar();
	clrscr();
}

//This function contains the magic formula
void magic()
{
	cout.setf(ios::fixed);					//Magic formula for screen
	cout.setf(ios::showpoint);
	cout.precision(2);
}

//This function will check to see if input file fails
void check(ifstream& input1)
{
	input1.open("F:/Aprogs/A7.dat");			//Opens A7.dat file from F Drive

	if(input1.fail())
	{
		cout<<"Input file A7.dat failed to open \n";		//Outputs failure message
		getch();
		exit(1);
	}
}

//This function will output the Titles on the screen
void titles()
{
	cout<<setw(15)<<"Department"<<setw(10)<<"Sales"<<setw(15)<<"Totals" ;		//Outputs titles
}

//This function will import data from the data file
void inputdata(ifstream& input1, int& newdept, int item, int& quantity, double& cost)
{
	input1>>item;				//Reading in Item Number
	input1>>quantity;			//Reading in Quantity
	input1>>cost;				//Reading in Cost

	if (! input1.eof())			
		input1>>newdept;			//Reading in New Dept
}


//This function will calculate the sales, total, and final total
void calculations(ifstream& input1, int& olddept, int& newdept, int quantity, double cost, double& sales, double& total, double& finaltotal)
{
	sales = quantity * cost;			//Calculating Sales

	total += sales;				//Calculating Total

	if (! input1.eof())
	{
		if (olddept != newdept)
		{
			cout<<setw(10)<<sales;				//Outputs Sales
			cout<<endl<<setw(40)<<total<<endl;		//Outputs Totals
			finaltotal += total;				//Calculating Final Total
			total = 0;						//Resets Total to 0
		}
	}

	if (input1.eof())
	{
		cout<<setw(10)<<sales;					//Outputs Sales when it's end of line
		cout<<endl<<setw(40)<<total<<endl;			//Outputs Totals at the end of line
	}
}

//This function will output the department number, sales, and totals
void outputdata(ifstream& input1, double sales, int olddept, int newdept, double total, double finaltotal)
{
	if (input1.eof())
	{
		cout << "\n\nTotal for All Departments:"<<setw(7)<<'$'<<finaltotal;		//Outputs final total when reaches end of file
		input1.close();
		getchar();
		exit(1);
	}

	if (olddept == newdept)
		cout<<setw(10)<<sales<<endl<<setw(15)<<newdept;			//Outputs sales and new department

	if (olddept != newdept)
	{
		cout<<setw(15)<<newdept;								//Outputs new department
		olddept = newdept;
	}
}