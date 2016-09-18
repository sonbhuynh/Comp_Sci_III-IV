//----------------------------------------------
// Program Name: dots.cpp
// Assignment: dots
// Date: 05/08/2012
//
// Programmer: Adam Backshall
// Course: CS IV
// Teacher: Mrs. Roszko			Period: 1
//
// Program Description:
//
// Input:
//
// Output:
//
// Assumptions/Limitations: 
//
//----------------------------------------------

//Libraries
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

class dots
{
	public:
		void intro();

		void title();

		void rules();

		void drawvert();

          void drawhoriz();
};

int main()
{
	dots game;

	game.intro();

	game.title();

	game.rules();

	do
	{
		if (player == 1)
          {
			game.movement(key); 			//calling movement function

			game.drawhoriz();				//calling draw horizontal line function	

			game.drawvert();        			//calling draw vertical line function

               player = 2;
		}

		if (player == 2)
          {
			game.movement(key); 			//calling movement function

			game.drawhoriz();				//calling draw horizontal line function	

			game.drawvert();        			//calling draw vertical line function

               player = 1;
		}
	}

     getch();
	return 0;
}

void dots::intro()
{
	cout<<"\n\nThis program will allow two players to go head to head in a game of 'Dots'."
     <<"\n\n\t\t\tPress enter to continue";

	getch();

	clrscr();	
}

void dots::title()
{
	cout<<"\t\t ||==\\\\     //==\\\\   ======   //===  \n"
	    <<"\t\t ||   ||   ||    ||    ||    ||       \n"
	    <<"\t\t ||   ||   ||    ||    ||     \\\\=\\\\ \n"
	    <<"\t\t ||   ||   ||    ||    ||         ||  \n"
	    <<"\t\t ||   ||   ||    ||    ||         ||  \n"
	    <<"\t\t ||==//     \\\\==//     ||     ===//  \n";
}

void dots::rules()
{
	cout<<"\nThe rules are as follows:\n"
	<<"\n1. Players enter their names and choose a letter to represent them\n"
	<<"2. Players take turns drawing a line to connect two dots, one line per turn\n"
	<<"3. The player who completes a square fills it in with his/her letter\n"
     <<"4. If a player fills in a square, they get an extra turn afterwards\n"
	<<"5. The player with the most squares owned at the end is the winner\n"
	<<"6. Move the cursor with the number pad(2, 4, 6, 8), choose a spot with 5\n"
	<<"7. At any time during the game press 0 to quit and see current score"
	<<"\n\n\t\t\tPress enter to begin";

	getch();

	clrscr();
}

void dots::drawhoriz()
{
	if(y == 1
	|| y == 5
	|| y == 9
	|| y == 13
	|| y == 17)
	{
		gotoxy(x-4, y);
		cout<<"---------"; 				//drawing horizontal line
     }
}

void dots::drawvert()
{
	if(y == 3
	|| y == 7
	|| y == 11
	|| y == 15)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
		cout<<"|";
     }
}