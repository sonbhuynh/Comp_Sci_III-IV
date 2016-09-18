//*****************************************************
//	Stack
//	A set of routines to implement a simple integer stack
//
//	Procedures
//	stack_int - initialize the stack
//	stack_push - put an item on the stack
//	stack_pop - remove an item from the stack
//*****************************************************

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

const int STACK_SIZE = 100;						//Maximum size of a stack

//	the stack itself

struct stack
{
	int count;								//Number of Items in the stack
	int data[STACK_SIZE];						//The items themselves
};

//*****************************************************
//
//	stack_init -- initialize the stack
//
//	Parameters
//
//	the_stack -- stack to initialize
//
//*****************************************************

inline void stack_init(struct stack & the_stack)
{
	the_stack.count = 0;						//Zero the stack
}

//*****************************************************
//
//	stack_push - push an item on the stack
//
//	Warning: we do not check for overflow
//
//	Parameters
//
//	the_stack -- stack to use for storing the item
//	item -- item to put in the stack
//
//*****************************************************

inline void stack_push(struct stack & the_stack, const int item)
{
	the_stack.data[the_stack.count] = item;
	++the_stack.count;
}

//*****************************************************
//
//	stack_pop -- get an item off the stack
//
//	Warning: we do not check for stack underflow
//
//	Parameters
//	the_stack -- stack to get the item from
//
//	Returns
//	the top item from the stack
//
//*****************************************************

inline int stack_pop (struct stack & the_stack)
{
	//stack goes down by one

	--the_stack.count;

	//then we return the top value

	return (the_stack.data[the_stack.count]);
}

void purpose();

//a short routine to test the stack

main()
{
	struct stack a_stack;						//stack we want to use
	purpose();

	stack_init (a_stack);


	//push three values on the stack

	stack_push(a_stack, 1);
	stack_push(a_stack, 2);
	stack_push(a_stack, 3);

	//pop the items from the stack
	cout<< "Expect a 3 ->" <<stack_pop(a_stack) << '\n';
	cout<< "Expect a 2 ->" <<stack_pop(a_stack) << '\n';
	cout<< "Expect a 1 ->" <<stack_pop(a_stack) << '\n';

	return (0);
}

// This function will output the program's purpose
void purpose()
{
	cout<<"This program will demonstrate how a stack will work. ";		//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";							//Press Enter to Proceed
	getchar();
	clrscr();
}