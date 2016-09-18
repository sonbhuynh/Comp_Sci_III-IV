// Program name: B2
// Date: March 06, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will read in 2 data files (B2Nums1.dat and B2Nums2.dat) and merges them into one sorted list.  
// 		Write each original list to the screen, followed by the sorted list.
// 
// Input: B2Nums1.dat and B2Nums2.dat
//
// Output: 3 Lists
//
// Assumptions/Limitations: File data exists
//--------------------------------------------------------------------------

// ****** MERGE SORT ******

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

using namespace std;

const int MAX1 = 10, MAX2 = 10, MAX3 = MAX1 + MAX2;

// FUNCTIONS PROTOTYPES
void init();

void openfiles(ifstream& list1, ifstream& list2);
void readdata(ifstream& list1, ifstream& list2, int num1[MAX1], int num2[MAX2], int& x, int& y);
void outputlists(int num1[MAX1], int num2[MAX2], int x, int y);

void mergesort(int num1[MAX1], int num2[MAX2], int num3[MAX3], int& x, int& y, int& z);
void outputfinal(int num3[MAX3], int& z);


int main()
{
	ifstream list1, list2;				//Declaration
	int num1[MAX1], num2[MAX2], num3[MAX3];
	int x, y, z;
	
	init();					//Function call for Initialize
	openfiles(list1, list2);			//Function call for Open Files

	readdata(list1, list2, num1, num2, x, y);	//Function call for Read Data
	outputlists(num1, num2, x, y);		//Function call for Output Lists
	
	mergesort(num1, num2, num3, x, y, z);		//Function call for Merge Sort
	outputfinal(num3, z);			//Function call for Output Final
	
	list1.close();
	list2.close();

	getchar();
	return 0;
}


//This function will output the program's purpose
void init()
{
	cout<<"This program will read in 2 data files (B2Nums1.dat and B2Nums2.dat) and merges them into one sorted list. "
		<<"\nWrite each original list to the screen, followed by the sorted list. ";			//Outputs Purpose
                 
	cout<<"\n\nPress Enter to Proceed. ";		//Press Enter to Continue
	getchar();
	system("CLS");
}

//This function will check and open both B2Nums1.dat and B2Nums2.dat
void openfiles(ifstream& list1, ifstream& list2)
{
	list1.open("C:/Users/Son-Huynh/Downloads/B2Nums1.dat");		//Opens B2Nums1.dat file

	if (list1.fail())
	{
		cout<<"Input file B2Nums1.dat failed. ";			//Outputs Failure message
		getchar();
		exit(1);
	}

	
	list2.open("C:/Users/Son-Huynh/Downloads/B2Nums2.dat");		//Opens B2Nums2.dat file

	if (list2.fail())
	{
		cout<<"Input file B2Nums2.dat failed. ";			//Outputs Failure message
		getchar();
		exit(1);
	}
}

//This function will read in data from B2Nums1.dat and B2Nums2.dat
void readdata(ifstream& list1, ifstream& list2, int num1[MAX1], int num2[MAX2], int& x, int& y)
{
	for (x = 0; x < MAX1; x++)
		list1>>num1[x];				//Reads in numbers from List 1
		

	for (y = 0; y < MAX2; y++)
		list2>>num2[y];				//Reads in numbers from List 2
}

//This function will output data from B2Nums1.dat and B2Nums2.dat
void outputlists(int num1[MAX1], int num2[MAX2], int x, int y)
{
	cout<<"ORIGINAL LISTS: ";
	cout<<"\n\nList 1";				//Outputs List 1 title

	cout<<"\nIndex: \n";               			//Outputs Index title

	for(int x = 0; x < MAX1; x++)
		cout<<setw(3)<<x;			//Outputs Index

	cout<<"\nValue: \n";			//Outputs Value title

	for(x = 0; x < MAX1; x++)
		cout<<setw(3)<<num1[x];		//Outputs Value

	

	cout<<"\n\nList 2";				//Outputs List 2 title

	cout<<"\nIndex: \n";               			//Outputs Index title

	for(int y = 0; y < MAX2; y++)
		cout<<setw(3)<<y;			//Outputs Index

	cout<<"\nValue: \n";			//Outputs Value title

	for(y = 0; y < MAX2; y++)
		cout<<setw(3)<<num2[y];		//Outputs Value
}

//This function will merge
void mergesort(int num1[MAX1], int num2[MAX2], int num3[MAX3], int& x, int& y, int& z)
{
	x = 0;                        //Initialize
	y = 0;
	z = 0;
     
	do
	{
		if (num1[x] < num2[y])		//If num 1 is less than num 2
		{
			num3[z] = num1[x];		//Assigns num 1 to the first number in num 3
			x++;			//Increases x by 1
			z++;			//Increases z by 1
		}
         
		if (num2[y] < num1[x])		//If num 2 is less than num 1
		{
			num3[z] = num2[y];		//Assigns num 2 to the first number in num 3
			y++;			//Increases y by 1
			z++;			//Increases z by 1
		}
         
		if (num1[x] == num2[y])		//If num 1 is equal to num 2
		{
			num3[z] = num1[x];		//Assigns num 1 to the first number in num 3
			x++;			//Increases x by 1
			z++;			//Increases z by 1
            
			num3[z] = num2[y];		//Assigns num 2 to the first number in num 3
			y++;			//Increases y by 1
			z++;			//Increases z by 1
		}
	}
	while(x < MAX1 || y < MAX2);
     
     
	while(x >= MAX1 && y < MAX2)		//If there's more number in list 2 than list 1
	{
		num3[z] = num2[y];			//Adding numbers in list 2 to list 3
		y++;				//Increases y by 1
		z++;				//Increases z by 1
	}
     
	while(y >= MAX2 && x < MAX1)		//If there's more number in list 1 than list 2
	{
		num3[z] = num1[x];			//Adding numbers in list 1 to list 3
		x++;				//Increases x by 1
		z++;				//Increases z by 1
	}
}

//This function will output the sorted list
void outputfinal(int num3[MAX3], int& z)
{
	cout<<"\n\n\nSORTED LIST: ";			//Outputs SORTED LIST title
     
	cout<<"\n\nIndex: \n";               			//Outputs Index title
	for(z = 0; z < MAX3; z++)
		cout<<setw(3)<<z;				//Outputs Index
           
	cout<<"\nValue: \n";               			//Outputs Value title
	for(z = 0; z < MAX3; z++)
		cout<<setw(3)<<num3[z];			//Outputs Value
}
