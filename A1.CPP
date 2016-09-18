// Program name: A1.cpp
// Date: Jan 24, 2012
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: The program will randomly generate 5 grades for the student
//				and calculate the numeric average
// Input: None
//
// Output: The average grade of those 5 randomly generate grades
//
// Assumptions/Limitations: None
//--------------------------------------------------------------------------

//////////////////////LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//////////////////////FUNCTIONS
int randomnum();						//Prototype for Random num
int randomgrade(int num);			//Prototype for Random grade
void final(int grade, int count, int& low, int& total, int& bonus);		//Prototype for Final grade
void magic();								//Prototype for Magic formula
void initial();							//Prototype for Outputting purpose

int main()
{
	int num, count, grade, low = 200, total = 0, bonus = 0, finalgrade;					//Declaration
	double average;

	randomize();						    	//Random num generator
	randomize();
	randomize();

	magic();								//Function call for Magic

     initial();							//Function call for Initializing

	for (count = 1; count <= 5; count++)
	{
		num = randomnum();					//Function call for Random num

		grade = randomgrade(num);					//Function call for Random grade
		cout<<"\nTest "<<count<<": "<<grade;		//Outputs grade

		final(grade, count, low, total, bonus);	//Function call for Final grade

	}   
        
	total = total - low;						//Eliminating the lowest grade
	average = total / 4.0;						//Calculating average

	if (average - floor(average) >= .5)
		average = ceil(average);					//Rounding number
	else
		average = floor(average);

	finalgrade = average + bonus;					//Calculating bonus

	

	cout<<"\n\nFinal grade is: "<<finalgrade;			//Outputs final/average grade


	getchar();
	return 0;
}

//This function will generate a random number between 1-10 inclusive and returns it
int randomnum()
{
	int num;

	num = random(10) + 1;					//Randomizing num

	return (num);
}

//This function will generate a random grade
int randomgrade(int num)
{
	int grade;							//Declaration
	 
	if (num < 3)							//Randomizing grades
		grade = random(50);

	if (num >= 3 && num <= 6)
		grade = random(30) + 50;

	if (num > 6)
		grade = random(21) + 80;

     return (grade);
}

//This function will output the grades generated and the numeric average
void final(int grade, int count, int& low, int& total, int& bonus)
{
	if (grade < low)
		low = grade;						//Dropping the lowest grade

	total += grade;						//Calculate total

	if (count == 3 && grade > 85)
		bonus = 5;						//Adding 5 points to average if Test 3 grade is greater than 85
}

//This function contains the magic formula
void magic()
{
	cout.setf(ios::fixed);					//Magic formula
	cout.setf(ios::showpoint);
	cout.precision(2);
}

//This function outputs purpose statement
void initial()
{
	clrscr();								//Clears screen

	cout<<"\nThis program will generate 5 random grades and calculate the average "
		<<"\nafter dropping the lowest grade ";					//Outputs purpose statement
}