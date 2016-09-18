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

const int size1 = 50, size2 = 50, size3 = size1 + size2;

// FUNCTIONS PROTOTYPES
void init();

void openfiles(ifstream& list1, ifstream& list2, ofstream& list3);
void readdata(ifstream& list1, ifstream& list2, int num1[size1], int num2[size2], int& max1, int& max2, int& max3, int& x, int& y);
void outputlists(int num1[size1], int num2[size2], int& x, int& y, int& max1, int& max2);

void mergesort(int num1[size1], int num2[size2], int num3[size3], int& x, int& y, int& z, int& max1, int& max2);
void outputfinal(ofstream& list3, int num3[size3], int& z, int& max3);


int main()
{
	ifstream list1, list2;				//Declaration
	ofstream list3;
	int num1[size1], num2[size2], num3[size3];
	int max1, max2, max3;
	int x, y, z;
	
	init();					//Function call for Initialize
	openfiles(list1, list2, list3);			//Function call for Open Files

	readdata(list1, list2, num1, num2, max1, max2, max3, x, y);	//Function call for Read Data

	list1.close();
	list2.close();

	outputlists(num1, num2, x, y, max1, max2);		//Function call for Output Lists
	
	mergesort(num1, num2, num3, x, y, z, max1, max2);		//Function call for Merge Sort
	outputfinal(list3, num3, z, max3);			//Function call for Output Final

	list3.close();

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
	clrscr();
}

//This function will check and open both B2Nums1.dat and B2Nums2.dat
void openfiles(ifstream& list1, ifstream& list2, ofstream& list3)
{
	list1.open("F:/Bprogs/B2Nums1.dat");		//Opens B2Nums1.dat file

	if (list1.fail())
	{
		cout<<"Input file B2Nums1.dat failed. ";			//Outputs Failure message
		getchar();
		exit(1);
	}

	
	list2.open("F:/Bprogs/B2Nums2.dat");		//Opens B2Nums2.dat file

	if (list2.fail())
	{
		cout<<"Input file B2Nums2.dat failed. ";			//Outputs Failure message
		getchar();
		exit(1);
	}

	list3.open("F:/Bprogs/B2Merge.dat");		//Opens B2Merge.dat

	if (list3.fail())
	{
		cout<<"Output file B2Merge.dat failed. ";			//Outputs Failure message
		getchar();
		exit(1);
	}
}

//This function will read in data from B2Nums1.dat and B2Nums2.dat
void readdata(ifstream& list1, ifstream& list2, int num1[size1], int num2[size2], int& max1, int& max2, int& max3, int& x, int& y)
{
    	for (x = 0; ! list1.eof(); x++)
		list1>>num1[x];				//Reads in numbers from List 1
		
	max1 = x - 1;

	for (y = 0; ! list2.eof(); y++)
		list2>>num2[y];				//Reads in numbers from List 2

	max2 = y - 1;

	max3 = max1 + max2;					//Adding max1 and max2 to max3
}

//This function will output data from B2Nums1.dat and B2Nums2.dat
void outputlists(int num1[size1], int num2[size2], int& x, int& y, int& max1, int& max2)
{
	cout<<"ORIGINAL LISTS: ";
	cout<<"\nList 1";				//Outputs List 1 title

	cout<<"\nIndex: ";               			//Outputs Index title

	for(x = 0; x < max1; x++)
		cout<<setw(3)<<x;			//Outputs Index

	cout<<"\nValue: ";			//Outputs Value title

	for(x = 0; x < max1; x++)
		cout<<setw(3)<<num1[x];		//Outputs Value

	

	cout<<"\n\nList 2";				//Outputs List 2 title

	cout<<"\nIndex: ";               			//Outputs Index title

	for(y = 0; y < max2; y++)
		cout<<setw(3)<<y;			//Outputs Index

	cout<<"\nValue: ";			//Outputs Value title

	for(y = 0; y < max2; y++)
		cout<<setw(3)<<num2[y];		//Outputs Value
}

//This function will merge the 2 lists together
void mergesort(int num1[size1], int num2[size2], int num3[size3], int& x, int& y, int& z, int& max1, int& max2)
{
	x = 0;                        //Initialize
	y = 0;
	z = 0;
	 
	do
	{
		if (num1[x] <= num2[y])		//If num 1 is less than num 2
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

	}
	while(x < max1 && y < max2);
     
    
	while(y < max2)		//If there's more number in list 2 than list 1
	{
		num3[z] = num2[y];			//Adding numbers in list 2 to list 3
		y++;				//Increases y by 1
		z++;				//Increases z by 1
	}
     
	while(x < max1)		//If there's more number in list 1 than list 2
	{
		num3[z] = num1[x];			//Adding numbers in list 1 to list 3
		x++;				//Increases x by 1
		z++;				//Increases z by 1
	}
}

//This function will output the sorted list
void outputfinal(ofstream& list3, int num3[size3], int& z, int& max3)
{
	cout<<"\n\nSORTED LIST: ";			//Outputs SORTED LIST title
	list3<<"SORTED LIST: ";				//Outputs SORTED LIST title to file
     
	cout<<"\n\nIndex: ";               	//Outputs Index title
	list3<<"\n\nIndex: ";               	//Outputs Index title to file
	for(z = 0; z < max3; z++)
	{
		cout<<setw(3)<<z;				//Outputs Index
		list3<<setw(3)<<z;				//Outputs Index to file
	}
           
	cout<<"\nValue: ";               	//Outputs Value title
	list3<<"\nValue: ";               	//Outputs Value title to file
	for(z = 0; z < max3; z++)
	{
		cout<<setw(3)<<num3[z];			//Outputs Value
		list3<<setw(3)<<num3[z];			//Outputs Value to file
	}
}