//100%
// Program name: A16
// Date: Feb 27, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will output the frequencies of numbers between 12-22
// 			in a randomized array of 100 numbers.
// 
// Input: None  
//
// Output: Frequencies of each number in array  
//
// Assumptions/Limitations: That it works
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

void init();						//Prototype for Initialize

void randomizenum(int num[100]);		//Prototype for Randomizing Num
void outputnumbers(int num[100]);		//Prototype for Output Numbers
void reinitfreq(int frequency[11]);	//Prototype for Re-Initializing Frequency

void findfreq(int num[100], int frequency[11]);	//Prototype for Find Freq
void output(int num[100], int frequency[11]);	//Prototype for Output

int main()
{
	int num[100], frequency[11];				//Declaration

	randomize();				//Randomizing
	randomize();
	randomize();
	randomize();
	randomize();

	init();					//Function call for Initialize
	randomizenum(num);			//Function call for Randomizing Num
	outputnumbers(num);			//Function call for Output Numbers
	reinitfreq(frequency);		//Function call for Re-Initializing Frequency

	findfreq(num, frequency);	//Function call for Find Freq
	output(num, frequency);		//Function call for Output

	getchar();
	return 0;
}

//This function will output the program's purpose
void init()
{
	cout<<"This program will output the frequencies of numbers between 12-22 "
		<<"\nin a randomized array of 100 numbers. ";			//Outputs purpose

	cout<<"\n\nPress Enter to Proceed. ";		//Press enter to continue
	getchar();
	clrscr();
}


//This function will generate random numbers
void randomizenum(int num[100])
{
	for (int x = 0; x <= 99; x++)
		num[x] = random(11) + 12;			//Generates 100 numbers for Array num[x]
}

//This function will output the numbers to the screen
void outputnumbers(int num[100])
{
	int count = 0;				//Declaration

	for(int x = 0; x <= 99; x++)
	{
		cout<<setw(4)<<num[x];	//Outputs numbers
     		count ++;			//Increases count by 1

		if (count > 9)
		{
			cout<< endl;		//Break
			count = 0;		//Resets count to 0
		}
	}
}

//This function will re-initialize frequency array to 0
void reinitfreq(int frequency[11])
{
	for (int x = 0; x <= 11; x++)
		frequency[x] = 0;
}

//This function will find the frequency of each number
void findfreq(int num[100], int frequency[11])
{
	for (int x = 0; x <= 99; x++)
	{
		for (int i = 0; i < 11; i++)
		{
			if(num[x] == i + 12)
				frequency[i]++;		//Finds Frequency for Each number
		}
	}
}

//This function will output the values and the frequency of each value
void output(int num[100], int frequency[11])
{
	cout<<"\n"<<setw(10)<<"Value"<<setw(14)<<"Frequency";		//Outputs titles

	for(int i = 12; i < 23; i++)
		cout<<"\n"<<setw(10)<<i<<setw(14)<<frequency[i - 12];	//Outputs data

}