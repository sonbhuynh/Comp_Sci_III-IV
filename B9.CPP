//goes out of range
//program cannot run
//80%
// Program name: B9  
// Date: March 15, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read numbers from a data file.
// 			Puts them in a 6 x 6 array, allows the user to input a FROM and TO location,
//			and outputs the distance in between the two locations. 
// 			
//
// Input: FROM and TO locations 
//
// Output: Mileage chart, distance between 2 locations   
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
void readdata(ifstream& input1, int value[6][6]);
void outputdata(int value[6][6], char cities[6][80]);

void inputstart(char start[80], char cities[6][80], int& startx, int& flagstartx, int& starty, int& flagstarty);
void inputlocations(char next[80]);
void finddistance(char start[80], char next[80], char cities[6][80], int& locationx, int& locationy, int& flagx, int& flagy);

int calculatedistance(int value[6][6], int locationx, int locationy);
void outputdistance(int totaldist);

int main()
{
	int value[6][6];		//Declaration
	char cities[6][80] = {"Atlanta", "Boston", "Chicago", "Dallas", "New York", "Tulsa"};
	char start[80], next[80];
     char choice;
	int locationx, locationy;
	int startx, starty;
	int flagstartx = 0, flagstarty = 0;
	int flagx = 0, flagy = 0;
     int totaldist = 0;

     ifstream input1;
    
	init();					//Function call for Initialize
	openfile(input1);			//Function call for Open File
	readdata(input1, value);		//Function call for Read Data

	input1.close();

	outputdata(value, cities);		//Function call for Output Data
	inputstart(start, cities, startx, flagstartx, starty, flagstarty);				//Function call for Input Start

	if (flagstartx == 0 || flagstarty == 0)
	{
		cout<<"ERROR: Start City Not Found. ";	//Outputs Error Message
		getchar();
		exit(1);
	}

	do
	{
		inputlocations(next);		//Function call for Input Locations

		if (strcmpi(next, "Q") == 0)
			break;

		finddistance(start, next, cities, locationx, locationy, flagx, flagy);		//Function call for Find Distance

		totaldist += calculatedistance(value, locationx, locationy);

          cout<<"\nTotal Dist: "<<totaldist<<endl;

		if (flagx == 0 || flagy == 0)
	     {
			cout<<"ERROR: City Not Found. ";	//Outputs Error Message
			getchar();
			exit(1);
	     }

	}
	while ((strcmpi(next, "Q") != 0));

	outputdistance(totaldist);				//Function call for Output Distance
    
	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will read numbers from a data file. "
		<<"\nPuts them in a 6 x 6 array, allows the user to input a "
		<<"\nFROM and TO locations, and outputs the total distance. ";       //Outputs Purpose
                 
	cout<<"\n\nPress Enter to Proceed. ";        //Press Enter to Continue
	getchar();
	clrscr();
}

//This function will open/check B8.dat file
void openfile(ifstream& input1)
{
	input1.open("F:/Bprogs/B8.dat");			//Opens B8.dat

	if (input1.fail())
	{
		cout<<"Input file B8.dat failed ";		//Outputs error message
		getchar();
		exit(1);
	}
}

//This function will input the data type in from the user
void readdata(ifstream& input1, int value[6][6])
{   
	for (int x = 0; x < 6; x++)
	{
		for (int y = 0; y < 6; y++)
			input1>>value[x][y];                          //Reads in numbers
	}
}

//This function will output the data into a table
void outputdata(int value[6][6], char cities[6][80])
{
	cout<<setw(16)<<"TO: ";
     cout<<"\nFROM: ";
	cout<<setw(13)<<"Atlanta";						//Outputs Column Titles
	cout<<setw(11)<<"Boston";
	cout<<setw(11)<<"Chicago";
	cout<<setw(11)<<"Dallas";
	cout<<setw(11)<<"New York";
	cout<<setw(11)<<"Tulsa";

	for (int x = 0; x < 6; x++)
	{
     	cout<<"\n"<<setw(8)<<cities[x];					//Outputs Cities
         
		for (int y = 0; y < 6; y++)
			cout<<setw(11)<<value[x][y];					//Outputs value
	}
}

//This function will allow the user to input the START city
void inputstart(char start[80], char cities[6][80], int& startx, int& flagstartx, int& starty, int& flagstarty)
{
	cout<<"\n\n\nPlease select from the following cities "		//Outputs Cities Menu
		<<"\n(Atlanta, Boston, Chicago, Dallas, New York, Tulsa) ";

	cout<<"\n\nEnter Start City: ";						//Inputs Start Location
	cin.getline(start, 80, '\n');

	//strcpy(holdstart, start);

	for (int x = 0; x < 6; x++)
	{
		if (strcmpi(start, cities[x]) == 0)
          {
			startx = x;					//Puts X into Start X
			flagstartx = 1;				//Assigns 1 to Flag Start X
          }		         	

		         
		for (int y = 0; y < 6; y++)
		{
			if (strcmpi(start, cities[y]) == 0)
               {
				starty = y;				//Puts Y into Start Y
				flagstarty = 1;			//Assigns 1 to Flag Start Y
               }
          }
	}
}

//This function will allow the user to input the FROM and TO locations
void inputlocations(char next[80])
{
	cout<<"Enter Next City on trip (Q to quit): ";			//Inputs Next Location
	cin.getline(next, 80, '\n');
}

//This function will find the distance between 2 locations
void finddistance(char start[80], char next[80], char cities[6][80], int& locationx, int& locationy, int& flagx, int& flagy)
{
	for (int x = 0; x < 6; x++)
	{
		if (strcmpi(start, cities[x]) == 0)
          {
			locationx = x;					//Puts X into Location X
			flagx = 1;					//Assigns 1 to Flag x
          }	         	

		for (int y = 0; y < 6; y++)
		{
			if (strcmpi(next, cities[y]) == 0)
               {
				locationy = y;				//Puts Y into Location Y
				flagy = 1;				//Assigns 1 to Flag y
               }
          }
	}
}

//This function will calculate the total distance
int calculatedistance(int value[6][6], int locationx, int locationy)
{
	int totaldist = 0;							//Declaration

	totaldist += value[locationx][locationy];		//Calculates total Dist

	return (totaldist);
} 

//This function will output distance
void outputdistance(int totaldist)
{
	cout<<"\nTotal Distance is "<<totaldist<<" mile(s).";		//Outputs Distance
}                                