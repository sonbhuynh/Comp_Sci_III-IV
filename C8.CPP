// Program name: C8  
// Date: April 16, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read in data from an external file.
// 			The program will output the data to the screen.
// 			The user can input a flight number they want to alter,
// 			and the program will change the value on the screen
// 			and the data file.
// 
// Input: Flight to alter and new value of flight   
//
// Output: Data from the external file
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


// ********* NOTES *********
// 1. Read + Close
// 2. Output to Screen
// 3. Input Flight Number
// 4. Binary Search
// 5. Change Value
// 6. Write to file + close
// *************************

// DECLARATIONS
struct PlaneType						//Info for PlaneType
{
	int flightnum;
	char company[20];
	char model[10];
	int seats;
};

struct IncomingType						//Info for IncomingType
{
	char origin[20];
	char laststop[20];
	int arrival;
};

struct OutgoingType						//Info for OutgoingType
{
	char destination[20];
	int depart;
	int seats;
};

struct FlightType						//Info for FlightType
{
	PlaneType plane;
	IncomingType incoming;
	OutgoingType outgoing;
}flight[10];

// FUNCTION PROTOTYPES
void init();
void openfile(ifstream& input1);
void readdata(ifstream& input1, FlightType flight[10]);
void outputscreen(FlightType flight[10]);
void inputsearch(int& flightalter, int& newflight);
void search(FlightType flight[10], int flightalter, int newflight);
void openoutputfile(ofstream& output1);
void outputdata(ofstream& output1, FlightType flight[10]);


int main()
{
	ifstream input1;										//Declaration
	ofstream output1;
     int flightalter, newflight;

	init();												//Call Initialize
	openfile(input1);										//Call Open File
	readdata(input1, flight);								//Call Read Data
	input1.close();

	outputscreen(flight);									//Call Output Screen
	inputsearch(flightalter, newflight);						//Call Input Search
	search(flight, flightalter, newflight);						//Call Search
	openoutputfile(output1);									//Call Open Output File
	outputdata(output1, flight);								//Call Output Data
     output1.close();

	getchar();
	return 0;
}

// This function will output what the program does
void init()
{
	cout<<"This program will read in data from an external file. "
		<<"\nThe program will output the data to the screen. "
		<<"\nThe user can input a flight number they want to alter, "
		<<"\nand the program will change the value on the screen "
		<<"\nand the data file. ";							//Outputs Purpose

     cout<<"\n\nPress Enter to Proceed.";						//Press Enter to Continue
	getchar();
	clrscr();
}

// This function will open and check the data file
void openfile(ifstream& input1)
{
	input1.open("F:/Cprogs/C8.dat");							//Opens Data File

	if (input1.fail())
	{
		cout<<"Input file C8.dat failed.";						//Outputs Error Message
		getchar();
		exit(1);
	}
}

// This function will read in data from the file
void readdata(ifstream& input1, FlightType flight[10])
{
	int x = 0;											//Declaration

	do
	{
		input1>>flight[x].plane.flightnum;						//Reads in Flight Num
          input1.ignore();
		input1.getline(flight[x].plane.company, 80, '\t');		//Reads in Company
		input1.getline(flight[x].plane.model, 80, '\t');			//Reads in Model
		input1>>flight[x].plane.seats;						//Reads in Seats
		input1.ignore();

		input1.getline(flight[x].incoming.origin, 80, '\t');		//Reads in Origin
		input1.getline(flight[x].incoming.laststop, 80, '\t');		//Reads in Last Stop
		input1>>flight[x].incoming.arrival;					//Reads in Arrival
		input1.ignore();

		input1.getline(flight[x].outgoing.destination, 80, '\t');	//Reads in Destination
		input1>>flight[x].outgoing.depart;						//Reads in Depart
		input1>>flight[x].outgoing.seats;						//Reads in Seats

		x++;												//Increases x by 1
	}
	while (! input1.eof());
}

// This function will output data to the screen
void outputscreen(FlightType flight[10])
{
	int x = 0;											//Declaration

	cout<<"Flt Num"<<setw(9)<<"Company"<<setw(7)<<"Model"
		<<setw(6)<<"Seats"<<setw(9)<<"Origin"<<setw(11)<<"Stop"
		<<setw(10)<<"Arrival"<<setw(7)<<"Dest."<<setw(8)<<"Depart"
          <<setw(6)<<"Seats"<<endl;

	do
	{
		cout<<setw(3)<<flight[x].plane.flightnum;				//Outputs Flight Num
		cout<<setw(11)<<flight[x].plane.company;				//Outputs Company
		cout<<setw(10)<<flight[x].plane.model;					//Outputs Model
		cout<<setw(4)<<flight[x].plane.seats;					//Outputs Seats

		cout<<setw(12)<<flight[x].incoming.origin;				//Outputs Origin
		cout<<setw(13)<<flight[x].incoming.laststop;				//Outputs Last Stop
		cout<<setw(5)<<flight[x].incoming.arrival;				//Outputs Arrival

		cout<<setw(11)<<flight[x].outgoing.destination;			//Outputs Destination
		cout<<setw(5)<<flight[x].outgoing.depart;				//Outputs Depart
		cout<<setw(5)<<flight[x].outgoing.seats;				//Outputs Seats

          cout<<endl;

		x++;												//Increases x by 1
	}
	while (x < 10);
}

// This function will allow the user to input in Flight Number to change
void inputsearch(int& flightalter, int& newflight)
{
	cout<<"\n\nFlight to alter: ";							//Inputs Flight Alter
	cin>>flightalter;

	cout<<"\nNew Value of Flight: ";							//Inputs New Value
	cin>>newflight;
}

// This function will use binary search to find the value to alter
void search(FlightType flight[10], int flightalter, int newflight)
{
	int low = -1, max = 10, flag = 0;							//Declaration

	do
	{

		if (flight[(max + low) / 2].plane.flightnum > flightalter)
			max = (max + low) / 2;							//Makes Max to average of max and low

		else
          {
			if (flight[(max + low) / 2].plane.flightnum < flightalter)
				low = (max + low) / 2;						//Makes Low to average of max and low

			else
			{
				if (flight[(max + low) / 2].plane.flightnum == flightalter)
                    {
					flight[(max + low) / 2].plane.flightnum = newflight;		//Makes Newflight to average of max and low
					flag = 1;											//Sets Flag to 1
					break;
                    }
			}
          }
	}
	while (max - low != 1);

	if (flag == 0)
     {
		cout<<"\nError, Flight Number not found.";				//Outputs Error Message
		getch();
		exit(1);
	}
	else
     	cout<<"\nFlight Number found.";						//Outputs Success Message
}

// This function will open and check the data file
void openoutputfile(ofstream& output1)
{
	output1.open("F:/Cprogs/C8.dat");							//Opens Data File

	if (output1.fail())
	{
		cout<<"Output file C8.dat failed.";					//Outputs Error Message
		getchar();
		exit(1);
	}
}

// This function will output data to the file
void outputdata(ofstream& output1, FlightType flight[10])
{
	int x = 0;											//Declaration

	do
	{
		output1<<flight[x].plane.flightnum;				//Outputs Flight Num
		output1<<'\t'<<flight[x].plane.company;					//Outputs Company
		output1<<'\t'<<flight[x].plane.model;					//Outputs Model
		output1<<'\t'<<flight[x].plane.seats;					//Outputs Seats

		output1<<'\t'<<flight[x].incoming.origin;				//Outputs Origin
		output1<<'\t'<<flight[x].incoming.laststop;				//Outputs Last Stop
		output1<<'\t'<<flight[x].incoming.arrival;				//Outputs Arrival

		output1<<'\t'<<flight[x].outgoing.destination;			//Outputs Destination
		output1<<'\t'<<flight[x].outgoing.depart;				//Outputs Depart
		output1<<'\t'<<flight[x].outgoing.seats;				//Outputs Seats

		output1<<endl;

		x++;												//Increases x by 1
	}
	while (x < 10);

     cout<<"\n\n";
	cout<<"Flight Number has been altered. Press Enter to Exit.";	//Outputs Success message
}