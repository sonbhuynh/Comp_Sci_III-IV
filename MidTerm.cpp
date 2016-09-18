//should be a 5x6 array...not a 6 x 5  -5%
//array values should not be used for switch -5%
//dont output title to dat file or ignore those letters if you do -5%

//85%
// Son Huynh
// 1st Period
// March 21, 2012
// This program will randomly generate 30 numbers between
// 	1 - 30 inclusive. The numbers will be outputted to
// 	the screen in 5 x 6 tables; one original table and one
// 	sorted table. User can type in a number to search and
// 	the program will output the number's location on the
// 	screen. Both tables will also be outputted to an external file.

// ************** SELECTION SORT **************

// LIBRARIES
#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

const int MAX_X = 5;						//Declaration for Constant Variables
const int MAX_Y = 6;

// FUNCTION PROTOTYPES
void init();

void opennumbers(ofstream& output1);
void generate(int list[MAX_X][MAX_Y], int& num);
int randomgenerate();
void outputtofile(int list[MAX_X][MAX_Y], ofstream& output1);

void openfile(ifstream& input1);
void readdata(ifstream& input1, int list[MAX_X][MAX_Y]);
void outputdata(int list[MAX_X][MAX_Y]);
void sortarray(int list[MAX_X][MAX_Y]);
void changevalues(int list[MAX_X][MAX_Y], int& x, int& y, int& countx, int& county);
void opennewnumbers(ofstream& output2);
void outputnewfile(ofstream& output2, int list[MAX_X][MAX_Y]);
int inputnum();
void search(int list[MAX_X][MAX_Y], int usernum);


int main()
{
	ifstream input1;
	ofstream output1, output2;				//Declaration
	int list[MAX_X][MAX_Y], num;
	int usernum;

	randomize();
	randomize();
	randomize();

	init();								//Function call for Initialize

	opennumbers(output1);					//Function call for Open Numbers.Dat
	generate(list, num);					//Function call for Generate
	outputtofile(list, output1);				//Function call for Output to File
	output1.close();

	openfile(input1);						//Function call for Open File
	readdata(input1, list);					//Function call for Read Data
	input1.close();

	cout<<"Original List: \n";
	outputdata(list);						//Function call for Output Data

	sortarray(list);						//function call for Sort Array

	cout<<"\n\nSorted List: \n";
	outputdata(list);						//Function call for Output Data

	opennewnumbers(output2);					//Function call for Open New Numbers 
	outputnewfile(output2, list);				//Function call for Output to new File
	output2.close();

	usernum = inputnum();					//Function call for Input Num
	search(list, usernum);					//Function call for Search

	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will randomly generate 30 numbers between "
		<<"\n1 - 30 inclusive. The numbers will be outputted to "
		<<"\nthe screen in 5 x 6 tables; one original table and one "
		<<"\nsorted table. User can type in a number to search and "
		<<"\nthe program will output the number's location on the "
		<<"\nscreen. Both tables will also be outputted to an external file.";	//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";		//Press Enter to Continue
	getchar();
	clrscr();								//Clears Screen
}

// ****************** PART I ******************

//This function will create an external file and check it
void opennumbers(ofstream& output1)
{
	output1.open("F:/Numbers.dat");					//Creates Numbers.dat file

	if (output1.fail())
	{
		cout<<"Output to Numbers.dat file failed.";		//Outputs Error Message
		getchar();
		exit(1);
	}
}

//This function will randomly generate numbers
int randomgenerate()
{
	int num;									//Declaration

	num = random(30) + 1;						//Generates random numbers

	return (num);
}

//This function will generate 30 non-repeating random numbers
void generate(int list[MAX_X][MAX_Y], int& num)
{
	int done = 0, flag = 0;							//Declaration

	for (int x = 0; x < MAX_X; x++)
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			done = 0;								//Sets Done to 0

			while (done != 1)
			{
				num = randomgenerate();				//Function call for Randoml Generate

				flag = 0;							//Sets Flag to 0

				for (int countx = 0; countx < MAX_X; countx++)
				{
					for (int county = 0; county < MAX_Y; county++)
					{
						if (num == list[countx][county])
							flag = 1;				//Sets Flag to 1 if Num if found elsewhere
					}

					if (flag == 0)
						done = 1;					//Sets Done to 1 if Flag Remains at 0
					else
						done = 0;					//Sets Done to 0
				}
			}

			list[x][y] = num;						//Assigns Num to List
		}
	}
}

void outputtofile(int list[MAX_X][MAX_Y], ofstream& output1)
{
	output1<<"Original List: ";

	for (int x = 0; x < MAX_X; x++)
	{
		output1<<endl;							//Goes to next line

		for (int y = 0; y < MAX_Y; y++)
		{
			output1<<setw(4)<<list[x][y];			//Outputs Numbers to the external file
		}
	}
}
	

// ****************** PART II ******************

//This function will read in an external file and check it
void openfile(ifstream& input1)
{
	input1.open("F:/Numbers.dat");					//Opens Numbers.dat file

	if (input1.fail())
	{
		cout<<"Input file Numbers.dat failed.";			//Outputs Error Message
		getchar();
		exit(1);
	}
}

//This function will read in data from the Numbers.dat file
void readdata(ifstream& input1, int list[MAX_X][MAX_Y])
{
	for (int x = 0; x < MAX_X; x++)
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			input1>>list[x][y];						//Reads in Numbers from the List array
		}
	}
}

// ****************** PART III ******************

//This function will sort the array
void sortarray(int list[MAX_X][MAX_Y])
{
	for (int x = 0; x < MAX_X; x++)
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			for (int countx = 0; countx < MAX_X; countx++)
			{
				for (int county = 0; county < MAX_Y; county++)
				{
					if (list[x][y] < list[countx][county])			//Switches position if number at countx, county is bigger than number at x and y
						changevalues(list, x, y, countx, county);	//Function call for Change Values			
				}

			}

		}
	}
}

//This function will hold the numbers to use in the sort array
void changevalues(int list[MAX_X][MAX_Y], int& x, int& y, int& countx, int& county)
{
	int hold;							//Declaration

	hold = list[x][y];					//Puts List xy in Hold
	list[x][y] = list[countx][county];		//Puts List Countx and County in List xy
	list[countx][county] = hold;			//Puts hold into List countx and county
}

// ****************** PART IV ******************

//This function will output the array
void outputdata(int list[MAX_X][MAX_Y])
{
	for (int x = 0; x < MAX_X; x++)
	{
		cout<<endl;							//Goes to next line

		for (int y = 0; y < MAX_Y; y++)
		{
			cout<<setw(4)<<list[x][y];			//Outputs Numbers in the array to the screen
		}
	}
}

// ****************** PART V ******************

//This function will create an external file and check it
void opennewnumbers(ofstream& output2)
{
	output2.open("F:/NewNumbers.dat");						//Creates Numbers.dat file

	if (output2.fail())
	{
		cout<<"Output to NewNumbers.dat file failed.";		//Outputs Error Message
		getchar();
		exit(1);
	}
}


//This function will output the sorted array to a new data file
void outputnewfile(ofstream& output2, int list[MAX_X][MAX_Y])
{
	output2<<"Sorted List: ";							//Outputs Title to New File
	 
	for (int x = 0; x < MAX_X; x++)
	{
		output2<<endl;									//Goes to next line

		for (int y = 0; y < MAX_Y; y++)
		{
			output2<<setw(4)<<list[x][y];					//Outputs Numbers in the array to the screen
		}
	}
}

// ****************** PART VI ******************

//This function will allow the user to input a number they want to search for
int inputnum()
{
	int usernum;									//Declaration

	cout<<"\n\n\nEnter a number you want to search for: ";				//Inputs User Num
	cin>>usernum;

	return (usernum);
}

//This function will find the location of the inputted number and outputs it
void search(int list[MAX_X][MAX_Y], int usernum)
{
	int flagsearch = 0;								//Declaration

	for (int x = 0; x < MAX_X; x++)
	{
		for (int y = 0; y < MAX_Y; y++)
		{
			if (usernum == list[x][y])
			{
				cout<<"\n"<<usernum<<" was found at position ("<<x<<", "<<y<<")";		//Outputs Location
				flagsearch = 1;				//Assigns 1 to Flag Search
			}
		}
	}

	if (flagsearch == 0)
	{
		cout<<"\nError, number not found.";			//Outputs Error message if Flag remains at 0
		getchar();
		exit(1);
	}
}