// Program name: C2  
// Date: March 22, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will allow the user to select from 3 different matrices.
//			The user can either select to add, subtract, or multiply any of the 3
// 			matrices together. The program will output the final matrices to the screen. 			  
// 
// Input:  2 Matrices they want to compute with
//
// Output:  Solution Matrix
//
// Assumptions/Limitations: Data Exists
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
void openfile1(ifstream& input1);
void openfile2(ifstream& input2);
void openfile3(ifstream& input3);

char menu();
void matrixmenu(int& choice1, int& choice2);

void readdata(ifstream& input, int matrix[5][5], int maxx, int maxy);
void outputdata(int matrix[5][5], int maxx, int maxy);

void calcaddition(int matrix[5][5], int matrix2[5][5], int finalmatrix[5][5], int maxx, int maxy);
void calcsubtraction(int matrix[5][5], int matrix2[5][5], int finalmatrix[5][5], int maxx, int maxy);
void calcmultiplication(int matrix[5][5], int matrix2[5][5], int finalmatrix[5][5], int maxx, int maxy, int col1);
void reinit(int finalmatrix[5][5]);

int main()
{
	char letterchoice;							//Declaration
	ifstream input;
	int choice1, choice2;
	int x1, y1, x2, y2;
	int matrix[5][5];
	int matrix2[5][5];
	int finalmatrix[5][5];

	init();								//Function call for Initialize

	do
	{
		letterchoice = menu();				//Function call for Menu

		if (letterchoice == 'Q')
		{
			cout<<"\nProgram Terminated.";	//Outputs Quit message
			break;
		}

		matrixmenu(choice1, choice2);			//Function call for Matrix Menu

		switch (choice1)
		{
			case 1:
				x1 = 3;
				y1 = 2;
				openfile1(input);			//Function call for Open File
				break;
			case 2:
				x1 = 3;
				y1 = 2;
				openfile2(input);			//Function call for Open File
				break;
			case 3:
				x1 = 2;
				y1 = 4;
				openfile3(input);			//Function call for Open File
				break;
		}

		readdata(input, matrix, x1, y1);		//Function call for Read Data
		input.close();

		switch (choice2)
		{
			case 1:
				x2 = 3;
				y2 = 2;
				openfile1(input);				//Function call for Open File
				break;
			case 2:
				x2 = 3;
				y2 = 2;
				openfile2(input);				//Function call for Open File
				break;
			case 3:
				x2 = 2;
				y2 = 4;
				openfile3(input);				//Function call for Open File
				break;
		}

		readdata(input, matrix2, x2, y2);				//Function call for Read Data
		input.close();

		switch (letterchoice)
		{
			case 'A':

				if (x1 != x2 || y1 != y2)
				{
					cout<<"\nError, Dimension does not match. ";					//Outputs Error Message
					getchar();
					break;
				}
				else
				{
					cout<<"\nMatrix 1: ";
					outputdata(matrix, x1, y1);								//Function call for Output Data
					cout<<"\nMatrix 2: ";
					outputdata(matrix2, x2, y2);								//Function call for Output Data for Matrix 2

					calcaddition(matrix, matrix2, finalmatrix, x1, y1);			//Function call for Calculating Addition

					cout<<"\nFinal Matrix: ";
					outputdata(finalmatrix, x1, y1);							//Function call for Output Data
				}
				break;

			case 'B':

				if (x1 != x2 || y1 != y2)
				{
					cout<<"\nError, Dimension does not match. ";					//Outputs Error Message
					getchar();
					break;
				}
				else
				{
					cout<<"\nMatrix 1: ";
					outputdata(matrix, x1, y1);								//Function call for Output Data
					cout<<"\nMatrix 2: ";
					outputdata(matrix2, x2, y2);								//Function call for Output Data for Matrix 2

					calcsubtraction(matrix, matrix2, finalmatrix, x1, y1);			//Function call for Calculating Subtraction

					cout<<"\nFinal Matrix: ";
					outputdata(finalmatrix, x1, y1);							//Function call for Output Data
				}
				break;

			case 'C':

				if (y1 != x2)
				{
					cout<<"\nError, Dimension does not match. ";					//Outputs Error Message
					getchar();
					break;
				}
				else
				{
					cout<<"\nMatrix 1: ";
					outputdata(matrix, x1, y1);								//Function call for Output Data
					cout<<"\nMatrix 2: ";
					outputdata(matrix2, x2, y2);								//Function call for Output Data for Matrix 2
					reinit(finalmatrix);									//Function call for Re-Initalize

					calcmultiplication(matrix, matrix2, finalmatrix, x1, y2, y1);	//Function call for Calculating Multiplication

					cout<<"\nFinal Matrix: ";
					outputdata(finalmatrix, x1, y2);							//Function call for Output Data
				}
				break;

			default:
				cout<<"\nPlease Re-enter between A, B, C, or Q.";			//Outputs Error Message
				break;

		}

		cout<<"\nPress Enter to Continue.";							//Press Enter to continue
		getchar();
		clrscr();


	}
	while (letterchoice != 'Q');

	getchar();
	return 0;
}

//This function will output what the program does
void init()
{
	cout<<"This program will allow the user to select from 3 different matrices. "			//Outputs Purpose
		<<"\nThe user can either select to add, subtract, or multiply any of the 3 "
		<<"\nmatrices together. The program will output the final matrices to the screen. ";

	cout<<"\n\nPress Enter to Proceed.";				//Press Enter to continue
	getchar();
	clrscr();
}

//This function will output the menu to the screen
char menu()
{
	char choice;									//Declaration

	cout<<"Array Operations: ";						//Outputs Menu
	cout<<"\n\tA. Add 2 matrices ";
	cout<<"\n\tB. Subtract 2 matrices ";
	cout<<"\n\tC. Multiply 2 matrices ";
	cout<<"\n\tQ. Quit ";

	cout<<"\nPlease choose A, B, C, or Q: ";			//Inputs Choice
	cin>>choice;
	choice = toupper(choice);
	cin.ignore();

	return (choice);
}

//This function allow the user to select 2 matrices they would like to use
void matrixmenu(int& choice1, int& choice2)
{
	cout<<"\nAvailable Matrices: ";					//Outputs Matrix Menu
	cout<<"\n\tMatrix 1 -> 3 x 2 ";
	cout<<"\n\tMatrix 2 -> 3 x 2 ";
	cout<<"\n\tMatrix 3 -> 2 x 4 ";

	do
	{
		cout<<"\n\nEnter First Matrix Number (1-3): ";				//Inputs First Matrix Number
		cin>>choice1;

		if (choice1 < 1 || choice1 > 3)
			cout<<"Error, please re-enter a number between 1-3. ";		//Outputs Error Message for Matrix 1

	}
	while (choice1 < 1 || choice1 > 3);


	do
	{
		cout<<"\n\nEnter Second Matrix Number (1-3): ";				//Inputs Second Matrix Number
		cin>>choice2;

		if (choice2 < 1 || choice2 > 3)
			cout<<"Error, please re-enter a number between 1-3. ";		//Outputs Error Message for Matrix 2

	}
	while (choice2 < 1 || choice2 > 3);

	cin.ignore();
}

//This function will check and open the external data file 1
void openfile1(ifstream& input1)
{
	input1.open("F:/Cprogs/C2_1.dat");								//Opens file

	if (input1.fail())
	{
		cout<<"Input file failed to open.";						//Outputs Error Message
		getchar();
		exit(1);
	}
}

//This function will check and open the external data file 2
void openfile2(ifstream& input2)
{
	input2.open("F:/Cprogs/C2_2.dat");								//Opens file

	if (input2.fail())
	{
		cout<<"Input file failed to open.";						//Outputs Error Message
		getchar();
		exit(1);
	}
}

//This function will check and open the external data file 3
void openfile3(ifstream& input3)
{
	input3.open("F:/Cprogs/C2_3.dat");								//Opens file

	if (input3.fail())
	{
		cout<<"Input file failed to open.";						//Outputs Error Message
		getchar();
		exit(1);
	}
}

//This function will read in data from the matrix
void readdata(ifstream& input, int matrix[5][5], int maxx, int maxy)
{
	for (int x = 0; x < maxx; x++)
	{
		for (int y = 0; y < maxy; y++)
			input>>matrix[x][y];								//Reads in Number from Matrix     	
	}
}

//This function will output the matrices onto the screen
void outputdata(int matrix[5][5], int maxx, int maxy)
{
	for (int x = 0; x < maxx; x++)
	{
		cout<<endl;

     	for (int y = 0; y < maxy; y++)
		cout<<setw(3)<<matrix[x][y];							//Outputs Matrix     	
	}
}

//This function will calculate matrix addition
void calcaddition(int matrix[5][5], int matrix2[5][5], int finalmatrix[5][5], int maxx, int maxy)
{
	for (int x = 0; x < maxx; x++)
	{
		for (int y = 0; y < maxy; y++)
			finalmatrix[x][y] = matrix[x][y] + matrix2[x][y];			//Calculates Final Matrix by adding first 2 matrices						    	
	}
}

//This function will calculate matrix subtraction
void calcsubtraction(int matrix[5][5], int matrix2[5][5], int finalmatrix[5][5], int maxx, int maxy)
{
	for (int x = 0; x < maxx; x++)
	{
		for (int y = 0; y < maxy; y++)
			finalmatrix[x][y] = matrix[x][y] - matrix2[x][y];			//Calculates Final Matrix by subtracting first 2 matrices						    	
	}
}

//This function will calculate the matrix multiplication
void calcmultiplication(int matrix[5][5], int matrix2[5][5], int finalmatrix[5][5], int maxx, int maxy, int col1)
{
	for (int x = 0; x < maxx; x++)
	{
		for (int y2 = 0; y2 < maxy; y2++)
		{
			for (int x2 = 0; x2 < col1; x2++)
			{
				finalmatrix[x][y2] += matrix[x][x2] * matrix2[x2][y2];		//Calculates Final Matrix by multiplying first 2 matrices
			}

		}							    	
	}
}

//This function will reintialize the array to 0
void reinit(int finalmatrix[5][5])
{
	for (int x = 0; x < 5; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			finalmatrix[x][y] = 0;								//Assigns 0 to Final Matrix
		}							    	
	}
}