//******************************************************
//
//	Stack
//	A file implementing a simple stack class
//
//******************************************************

#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

const int STACK_SIZE = 3;					//Maximum size of a stack

//******************************************************
//
//	Stack Class
//
//	Member Functions
//		init - initialize the stack
//		push - put an item on the stack
//		pop - remove an item from the stack
//
//******************************************************

//the stack itself

class stack
{
	private:
		int count;						//Number of items in the stack
		int data[STACK_SIZE];				//The items themselves
	public:
		//Initialize the stack
		void init(void);

		//Push an item on the stack
		void push(const int item);

		//Pop an item from the stack
		int pop(void);

		//Output function
          void output(void);
};

//******************************************************
//
//	stack::init - initialize the stack
//
//******************************************************

inline void stack::init(void)
{
	count = 0;							//Zero the stack
}

inline void stack::output(void)
{
     cout<<"Stack: ";

	for (int x = 0; x < count; x++)
		cout<<data[x]<<" ";
}

//******************************************************
//
//	stack::push - push an item on the stack
//
//	Warning: we do not check for overflow
//
//	Parameters
//		item - item to put in the stack
//
//******************************************************


//******************************************************
//
//	stack::pop - get an item off the stack
//
//	Warning: we do nto check for stack underflow
//
//	Returns
//		the top item from the stack
//
//******************************************************



void purpose();
int menu();
int enternumber();


//A short routine to test the stack

main()
{
	int usernumber;						//Declaration
     int choice;
	stack a_stack;							//Stack we want to use

	purpose();

	a_stack.init();

	do
	{
		a_stack.output();
		choice = menu();						//Call Menu

		switch (choice)
		{
			case 1:
				usernumber = enternumber();		//Call Enter Number
				a_stack.push(usernumber);		//Pushes in number to stack

					                    	
				break;

			case 2:
				cout<<"\nNumber Popped: "<<a_stack.pop() << '\n';		//Outputs Message if Popped

				break;

			case 3:
				cout<<"\nProgram Terminated.";	//Outputs Error Message
				getch();
				exit(1);
				break;

			default:
				cout<<"\nPlease Re-Enter 1, 2 ,or 3.";
				break;
          }


		cout<<"\nPress Enter to Return to Menu";		//Press enter to return to main menu
		getchar();
          clrscr();
	}
     while (choice != '3');

	return (0);
}

//This function will output the program purpose
void purpose()
{
	cout<<"This program will demonstrate how to use "
		<<"\npush and pop functions. ";		//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";		//Press Enter to Continue
	getchar();
	clrscr();
}

//This function will allow the user to choose what to do
int menu()
{
	int choice;							//Declaration

	cout<<"\n\nMenu: ";						//Outputs menu
	cout<<"\n\t1. Put ";
	cout<<"\n\t2. Get ";
	cout<<"\n\t3. Quit ";

	cout<<"\n\nPlease input 1, 2, or 3: ";		//Inputs choice
	cin>>choice;

	return (choice);
}

//This function will allow the user to input a number to be pushed
int enternumber()
{
	int usernumber;						//Declaration

	cout<<"\nEnter number: ";				//Inputs number to be pushed
	cin>>usernumber;

	return (usernumber);
}

//This function will check for overflow of push
void stack::push(const int item)
{
	data[count] = item;
	++count;

	if (count > STACK_SIZE)
	{
		cout<<"\nError, overflow.";		//Outputs Error Message
          count--;
		getch();
		clrscr();
	}
}

//This function will check for underflow of pop
int stack::pop(void)
{
	if (count <= 0)
	{
		cout<<"\nError, underflow.";		//Outputs Error Message
          count++;
		getch();
		clrscr();
	}

	//stack goes down by one
	count--;

	//then we return the top value
	return (data[count]);
}