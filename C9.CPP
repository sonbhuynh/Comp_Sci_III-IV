// Program name: C9  
// Date: April 18, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will read in data from an external file
// 				The program will output the Company, Flight Num, and
// 				Arrival Time to the screen. The arrival time will be
// 				sorted and the new sorted data will be outputted to
// 				new external file.
// 
// Input: None  
//
// Output: Original and Sorted Data to screen and data file  
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
	int hours;
     int minutes;
}flight[10];

// FUNCTION PROTOTYPES
void init();
void openfile(ifstream& input1);
void readdata(ifstream& input1, FlightType flight[10], int& max);
void converttime(FlightType flight[10], int max);
void sorttime(FlightType flight[10], int max);
void switcheroo(FlightType flight[10], int x, int y);
void outputscreen(FlightType flight[10], int max);
void openoutputfile(ofstream& output1);
void outputdata(ofstream& output1, FlightType flight[10], int max);
void outputoriginalscreen(FlightType flight[10], int max);

int main()
{
	ifstream input1;										//Declaration
	ofstream output1;
	int hours[10], minutes[10];
     int max;

	init();												//Call Initialize
	openfile(input1);										//Call Open File
	readdata(input1, flight, max);							//Call Read Data
	input1.close();

     cout<<"ORIGINAL DATA: \n";
	outputoriginalscreen(flight, max);							//Call Output Screen

	cout<<endl;

	sorttime(flight, max);									//Call Sort Time
	converttime(flight, max);								//Call Convert Time
     cout<<"SORTED DATA: \n";
	outputscreen(flight, max);								//Call Output Screen

	openoutputfile(output1);									//Call Open Output File
	outputdata(output1, flight, max);							//Call Output Data
     output1.close();

	getchar();
	return 0;
}

// This function will output what the program does
void init()
{
	cout<<"This program will read in data from an external file. "
		<<"\nThe program will output the Company, Flight Num, and "
		<<"\nArrival Time to the screen. The arrival time will be "
		<<"\nsorted and the new sorted data will be outputted to "
		<<"\nnew external file. ";

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
void readdata(ifstream& input1, FlightType flight[10], int& max)
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

     max = x - 1;
}

// This function will convert military time to 24-hour format time
void converttime(FlightType flight[10], int max)
{
	int x = 0;											//Declaration

	do
	{
		if (flight[x].incoming.arrival >= 1300)
			flight[x].hours = (flight[x].incoming.arrival - 1200) / 100;		//Calculates Hours
		else
			flight[x].hours = flight[x].incoming.arrival / 100;				//Calculates Hours

		flight[x].minutes = flight[x].incoming.arrival % 100;					//Calculates Minutes
                      
		x++;												//Increases x by 1
	}
	while (x < max);
}

// This function will sort the arrival time
void sorttime(FlightType flight[10], int max)
{

	for (int x = 0; x < max - 1; x++)
	{
		for (int y = x + 1; y < max; y++)
		{
			if (flight[x].incoming.arrival > flight[y].incoming.arrival)
			{
				switcheroo(flight, x, y);					//Call Switcheroo
			}
		}
	}
}

// This function will output data to the screen
void outputoriginalscreen(FlightType flight[10], int max)
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
	while (x < max);
}

// This function will output data to the screen
void outputscreen(FlightType flight[10], int max)
{
	int x = 0;											//Declaration

	cout<<setw(15)<<"Company"<<setw(15)<<"Flight Number"
		<<setw(13)<<"Arrival"<<endl;

	do
	{
		cout<<setw(15)<<flight[x].plane.company;				//Outputs Company
		cout<<setw(15)<<flight[x].plane.flightnum;				//Outputs Flight Num

		if (flight[x].hours == 0)
			cout<<setw(10)<<flight[x].hours + 12<<":";			//Outputs 12 if hour is 0
          else
			cout<<setw(10)<<flight[x].hours<<":";				//Outputs Arrival

		if (flight[x].minutes < 10)							
			cout<<"0";									//Outputs 0 if minutes is less than 10

		cout<<flight[x].minutes;								//Outputs Minutes

		if (flight[x].incoming.arrival >= 1200)
			cout<<" P.M.";									//Outputs PM if it's passed noon
		else
          	cout<<" A.M.";									//Outputs AM if not passed noon

          if (x < max - 1)
			cout<<endl;									//Outputs Blank Line

		x++;												//Increases x by 1
	}
	while (x < max);
}

// This function will switch the value in the struct
void switcheroo(FlightType flight[10], int x, int y)
{
	FlightType hold;										//Declaration

	hold = flight[x];										//Puts num_a into hold
	flight[x] = flight[y];									//Puts num_b into num_a
	flight[y] = hold;										//Puts hold into num_a
}

// This function will open and check an output file
void openoutputfile(ofstream& output1)
{
	output1.open("F:/Cprogs/C8sorted.dat");						//Creates Data File

	if (output1.fail())
	{
		cout<<"Output file C8sorted.dat failed.";				//Outputs Error Message
		getchar();
		exit(1);
	}
}

// This function will output the data to an external file
void outputdata(ofstream& output1, FlightType flight[10], int max)
{
	int x = 0;											//Declaration

	do
	{
		output1<<flight[x].plane.company;						//Outputs Company
		output1<<"\t"<<flight[x].plane.flightnum;				//Outputs Flight Num

		if (flight[x].hours == 0)
			output1<<"\t"<<flight[x].hours + 12<<":";			//Outputs 12 if hour is 0
          else
			output1<<"\t"<<flight[x].hours<<":";				//Outputs Arrival

		if (flight[x].minutes < 10)							
			output1<<"0";									//Outputs 0 if minutes is less than 10

		output1<<flight[x].minutes;							//Outputs Minutes

		if (flight[x].incoming.arrival >= 1200)
			output1<<" P.M.";								//Outputs PM if it's passed noon
		else
          	output1<<" A.M.";								//Outputs AM if not passed noon

          if (x < max - 1)
			output1<<endl;									//Outputs Blank Line

		x++;
	}
	while (x < max);
}