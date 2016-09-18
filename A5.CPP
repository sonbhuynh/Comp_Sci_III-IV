// Program name: A5 
// Date: Feb 1, 2012 
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will input an employee's gross wages.
//			 Then calculate the taxes (25%), union dues (5%)  and net pay.
//			 Then write all this information to a Data file
// 
// Input: Users will input Employee's number and Gross Pay 
//
// Output: Program will output Taxes, Union dues, and Net pay to the screen and data file
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

void input(int& employee, double& grosspay);		//Prototype for inputting data function
void calculation(double& grosspay, double& taxes, double& dues, double& netpay);	//Prototype for Calculating function
void outputdata(ofstream& output1, int employee, double grosspay, double taxes, double dues, double netpay);		//Prototype for Outputting data
void magic(ofstream& output1);				//Prototype for magic formula
void purpose();							//Prototype for purpose

int main()
{
	ofstream output1;					//Declaration
	int employee;
	double grosspay, taxes, dues, netpay;
	char choice;

	output1.open("F:/Aprogs/A5.dat");

     purpose();						//Function call for outputting purpose
	magic(output1);					//Function call for magic formula
     
	if(output1.fail())
	{
		cout<<"Outputting to A5.dat failed. \n";		//Outputs error message
		getch();
		exit(1);
	}

	output1<<setw(8)<<"Employee"<<setw(14)<<"Gross Pay"<<setw(10)<<"Taxes"
		<<setw(9)<<"Dues"<<setw(12)<<"Net Pay";				//Outputs Titles to data file

	do
	{
		input(employee, grosspay);						//Function call for Inputting data
		calculation(grosspay, taxes, dues, netpay);			//Function call for Calculation
		outputdata(output1, employee, grosspay, taxes, dues, netpay);		//Function call for Outputting data

		cout<<"\n\nEnter another record? (Y/N): ";			//Inputs Y or N
		cin>>choice;
		choice = toupper(choice);
          clrscr();
	}
	while(choice != 'N');

	output1.close();
     return 0;
}

//This function will allow the user to input the employee's number and gross pay
void input(int& employee, double& grosspay)
{
	cout<<"\nEnter Employee's number: ";		//Input employee's number
	cin>>employee;

	cout<<"\nEnter Gross Pay: $";				//Input gross pay
	cin>>grosspay;
}

//This function will calculate the Taxes, Union dues and Net Pay
void calculation(double& grosspay, double& taxes, double& dues, double& netpay)
{
	taxes = grosspay * .25;					//Calculating Taxes
	dues = grosspay * .05;					//Calculating Union dues
	netpay = grosspay - taxes - dues;			//Calculating Net Pay
}

//This function will output the data to the screen and data file
void outputdata(ofstream& output1, int employee, double grosspay, double taxes, double dues, double netpay)
{
	cout<<"\n"<<setw(8)<<"Employee"<<setw(14)<<"Gross Pay"<<setw(10)<<"Taxes"
			<<setw(9)<<"Dues"<<setw(12)<<"Net Pay";				//Outputs Titles to screen

	cout<<"\n"<<setw(8)<<employee<<setw(14)<<grosspay<<setw(10)<<taxes<<setw(9)<<dues<<setw(12)<<netpay;		//Outputs data on screen
              
	output1<<"\n"<<setw(8)<<employee<<setw(14)<<grosspay<<setw(10)<<taxes<<setw(9)<<dues<<setw(12)<<netpay;	//Outputs data to data file
                   
}

//This function contains the magic formula
void magic(ofstream& output1)
{
	cout.setf(ios::fixed);					//Magic formula
	cout.setf(ios::showpoint);
	cout.precision(2);

	output1.setf(ios::fixed);				//Magic formula
	output1.setf(ios::showpoint);
	output1.precision(2);
}

void purpose()
{
	cout<<"\nThis program will input an employee's gross wages. "				//Outputs purpose
		<<"\nThen calculate the taxes (25%), union dues (5%) and net pay. "
		<<"\nThen write all this information to a Data file. ";

	cout<<"\n\nPress enter to continue ";
	getchar();
	clrscr();

}