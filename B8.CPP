// Program name: B8  
// Date: March 14, 2012  
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
void inputlocations(char from[80], char to[80]);
void finddistance(char from[80], char to[80], char cities[6][80], int& locationx, int& locationy, int& flagx, int& flagy);
void outputdistance(int value[6][6], int locationx, int locationy);

int main()
{
	int value[6][6];		//Declaration
	char cities[6][80] = {"Atlanta", "Boston", "Chicago", "Dallas", "New York", "Tulsa"};
	char from[80], to[80];
	int locationx, locationy;
	int flagx = 0, flagy = 0;
     ifstream input1;
    
	init();				//Function call for Initialize
	openfile(input1);		//Function call for Open File
	readdata(input1, value);		//Function call for Read Data

	input1.close();

	outputdata(value, cities);		//Function call for Output Data
	inputlocations(from, to);		//Function call for Input Locations

	finddistance(from, to, cities, locationx, locationy, flagx, flagy);		//Function call for Find Distance

	if (flagx == 0 || flagy == 0)
     {
		cout<<"Cities Not Found. ";	//Outputs Error Message
		getchar();
		exit(1);
     }

	outputdistance(value, locationx, locationy);				//Function call for Output Distance

    
	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will read numbers from a data file. "
		<<"\nPuts them in a 6 x 6 array, allows the user to input a FROM and TO location, "
		<<"\nand outputs the distance in between the two locations. ";       //Outputs Purpose
                 
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

//This function will allow the user to input the FROM and TO locations
void inputlocations(char from[80], char to[80])
{
	cout<<"\n\n\nPlease select from the following cities "		//Outputs Cities Menu
		<<"\n(Atlanta, Boston, Chicago, Dallas, New York, Tulsa) ";

	cout<<"\n\nFROM: ";						//Inputs From Location
	cin.getline(from, 80, '\n');

	cout<<"TO: ";							//Inputs To Location
	cin.getline(to, 80, '\n');
}

//This function will find the distance between 2 locations
void finddistance(char from[80], char to[80], char cities[6][80], int& locationx, int& locationy, int& flagx, int& flagy)
{
	for (int x = 0; x < 6; x++)
	{
		if (strcmpi(from, cities[x]) == 0)
          {
			locationx = x;					//Puts X into Location X
			flagx = 1;
          }
			         	

		         
		for (int y = 0; y < 6; y++)
		{
			if (strcmpi(to, cities[y]) == 0)
               {
				locationy = y;				//Puts Y into Location Y
				flagy = 1;
               }
          }
	}
}

//This function will output distance
void outputdistance(int value[6][6], int locationx, int locationy)
{
	cout<<"\nDistance is "<<value[locationx][locationy];		//Outputs Distance
}                                