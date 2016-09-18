// Program name: A6 
// Date: Feb 02, 2012 
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read from one DATA file and write to another 
// 
// Input: Data file 
//
// Output: Write a new data file 
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

void init();									//Prototype for Outputting purpose
void magic(ofstream& output1);					//Prototype for Magic formula
void check(ifstream& input1, ofstream& output1);		//Prototype for Importing/Exporting data file
void inputdata(ifstream& input1, int& hightemp, int& lowtemp, char cityname[80]);		//Prototype for Input Data
double calculation(int hightemp, int lowtemp);		//Prototype for Calculating Average Temp
void outputdata(ofstream& output1, char cityname[80], double averagetemp);			//Prototype for Output data
void titles(ofstream& output1);					//Prototype for Titles

int main()
{
	ifstream input1;						//Declaration
	ofstream output1;
	char cityname[80];
	int hightemp, lowtemp;
     double averagetemp;

	init();								//Function call for Outputting purpose
	magic(output1);						//Function call for Magic formula

	check(input1, output1);					//Function call for Inputting CityTemp

     titles(output1);						//Function call for Titles

	do
	{
		inputdata(input1, hightemp, lowtemp, cityname);	//Function call for inputting data
		averagetemp = calculation(hightemp, lowtemp);		//Function call for calculating average temp
		outputdata(output1, cityname, averagetemp);		//Function call for outputting data
	}
	while(! input1.eof());


	output1.close();
     input1.close();
	return 0;

}

//This program will output what the program does
void init()
{
	cout<<"\nThis program will read in a data file of City Temp "
		<<"\nand write to the Average Temp to another data file";		//Outputs purpose of program

	cout<<"\nPress enter to continue ";		//Press enter to clear screen
	getchar();
	clrscr();
}

//This function contains the magic formula
void magic(ofstream& output1)
{
	cout.setf(ios::fixed);					//Magic formula for screen
	cout.setf(ios::showpoint);
	cout.precision(2);

	output1.setf(ios::fixed);				//Magic formula for Dat files
	output1.setf(ios::showpoint);
	output1.precision(2);
}

//This function will check to see if input or output file fails
void check(ifstream& input1, ofstream& output1)
{
	input1.open("F:/Aprogs/citytemp.dat");		//Opens Citytemp data file

	if(input1.fail())
	{
		cout<<"Input file CityTemp.dat failed to open. \n";		//Outputs failure message
		getch();
		exit(1);
	}

	output1.open("F:/Aprogs/cityavg.dat");		//Creates Cityavg data file

	if(output1.fail())
	{
		cout<<"Output file CityAvg.dat failed. \n";
		getch();
		exit(1);
	}

}

//This function will output the titles on the screen and the data file
void titles(ofstream& output1)
{
	cout<<setw(11)<<"City"<<setw(15)<<"Temp";
	
	output1<<setw(11)<<"City"<<setw(15)<<"Temp";
}

//This function will import the data
void inputdata(ifstream& input1, int& hightemp, int& lowtemp, char cityname[80])
{
	input1.getline(cityname, 80, '\n');		//Reading in input file

	input1>>hightemp;						//Reading in high temp

	input1>>lowtemp;						//Reading in low temp

     input1.ignore();
}

//This function will calculating the average 
double calculation(int hightemp, int lowtemp)
{
	double averagetemp;						//Declaration

	averagetemp = (hightemp + lowtemp) / 2.0;	//Calculating average temperature

	return (averagetemp);
}

//This function will output the data to the screen and the data file
void outputdata(ofstream& output1, char cityname[80], double averagetemp)
{
	cout<< '\n' <<setw(11)<<cityname;			//Outputs city name to screen
	output1<< '\n' <<setw(11)<<cityname;		//Outputs city name to data file

	cout<<setw(15)<<averagetemp;			//Outputs average temp to screen
	output1<<setw(15)<<averagetemp;		//Outputs average temp to data file
}