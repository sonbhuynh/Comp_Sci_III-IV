// Program name: D1  
// Date: April 26, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  
// 
// Input:  
//
// Output:  
//
// Assumptions/Limitations:
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
struct Circle				//Definition for Circle
{
	int radius;
};

struct Rectangle			//Definition for Rectangle
{
	int width;
	int height;
};

struct Triangle
{
	int base;
	int height;
};

struct Shape				//Definition for Shape
{
	int choice;

	union shape_union
	{
		Circle circle_data;
		Rectangle rectangle_data;
		Triangle triangle_data;
	}data;
}a_shape;

// FUNCTION PROTOTYPES
void init();
int menu();
void calccircle(Shape& a_shape);
void calcrectangle(Shape& a_shape);
void calctriangle(Shape& a_shape);

double calcarea(Shape& a_shape);
void outputarea(double area);


int main()
{
	double area;											//Declaration

	init();												//Call Initialize

	do
	{
		a_shape.choice = menu();								//Call Menu

		switch (a_shape.choice)
		{
			case 1:
				calccircle(a_shape);						//Call Calc Circle
				break;
	
			case 2:
				calcrectangle(a_shape);						//Call Calc Rectangle
				break;
     	
			case 3:
				calctriangle(a_shape);						//Call Calc Triangle
				break;

			case 4:
				cout<<"\nProgram Terminated.";				//Outputs Quit message
				getch();
				exit(1);
	               break;

			default:
				cout<<"\nRe-Enter 1, 2, 3, or 4.";				//Outputs Error message
				break;
		}

		area = calcarea(a_shape);							//Call Area
		outputarea(area);									//Call Output Area

		cout<<"\n\nPress Enter to Return to Menu.";				//Press Enter to clear screen
		getchar();
		clrscr();

	}
	while (a_shape.choice != 4);
	getchar();
	return 0;
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will allow the user to enter in info. "
		<<"\nThe program will let the user find the area "
		<<"\nfor either Circle, Rectangle, or Triangle. ";		//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";
	getchar();
	clrscr();
}

// This function will output the menu to the screen
int menu()
{
	cout<<"Choose a shape that you would like to find the area: ";
	cout<<"\n\t1.	Circle ";
	cout<<"\n\t2.	Rectangle ";
	cout<<"\n\t3.	Triangle ";
	cout<<"\n\t4.	Quit ";									//Outputs Menu

	cout<<"\n\nPlease enter 1, 2, 3, or 4: ";					//Inputs Choice
	cin>>a_shape.choice;

	return (a_shape.choice);
}

// This function will calculate the area for Circle
void calccircle(Shape& a_shape)
{
	cout<<"\nEnter Radius: ";								//Inputs Radius
	cin>>a_shape.data.circle_data.radius;
}

// This function will calculate the area for Rectangle
void calcrectangle(Shape& a_shape)
{
	cout<<"\nEnter Width: ";									//Inputs Width
	cin>>a_shape.data.rectangle_data.width;

	cout<<"\nEnter Height: ";
	cin>>a_shape.data.rectangle_data.height;
}


// This function will calculate the area for Triangle
void calctriangle(Shape& a_shape)
{
	cout<<"\nEnter Base: ";									//Inputs Base
	cin>>a_shape.data.triangle_data.base;

	cout<<"\nEnter Height: ";								//Inputs Height
	cin>>a_shape.data.triangle_data.height;
}


// This function will calculate the area
double calcarea(Shape& a_shape)
{
	double area;												//Declaration

	switch (a_shape.choice)
	{
		case 1:
			area = a_shape.data.circle_data.radius * a_shape.data.circle_data.radius * 3.14;		//Calculating Circle Area
			break;

		case 2:
			area = a_shape.data.rectangle_data.width * a_shape.data.rectangle_data.height;			//Calculating Rectangle Area
			break;

		case 3:
			area = 0.5 * a_shape.data.triangle_data.base * a_shape.data.triangle_data.height;		//Calculating Triangle Area
			break;
		default:
			cout<<"\nRe-Enter 1, 2, 3, or 4.";					//Outputs Error message
			break;
	}

	return (area);
}
          	

// This function will output the area
void outputarea(double area)
{
	cout<<"\nThe Area is: "<<area;							//Outputs Area
}               