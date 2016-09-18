// Program name: D12
// Date: May 08, 2012  
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

// CLASS DECLARATION
class dots
{
	private:
		char name1[20], name2[20];
		int x, y;
          char key;
	public:
		dots();
          ~dots();
		void drawboard();
		void inputnames();
		void movement(char key);     	
};
	

// PROTOTYPES


int main()
{
	dots game;										//Declaration
     char key;

	game.inputnames();									//Call Input Names
	game.drawboard();									//Call Draw Board

     game.movement(key);


	getchar();
	return 0;
}

// CONSTRUCTOR
void dots::dots()
{
	x = 30;
	y = 7;
}

// DESTRUCTOR
dots::~dots()
{
	cout<<"Data erased.";
} 

// This function will draw the board
void dots::drawboard()
{
	for (int x = 0; x < 5; x++)
	{
     	if (x > 0)
			cout<<endl<<endl<<endl<<endl;					//Outputs Blank Lines

		for (int y = 0; y < 5; y++)
		{
			cout<<setw(10)<<"o";						//Draws Board
		}
	}
}

// This function will allow the players to enter their names
void dots::inputnames()
{
	cout<<"Enter Name for Player 1: ";						//Inputs Player 1 Name
	cin.getline(name1, 80, '\n');


	cout<<"\nEnter Name for Player 2: ";					//Inputs Player 2 Name
	cin.getline(name2, 80, '\n');


     clrscr();											//Clears Screen
}

// This function will allow the user to move
void dots::movement(char key)
{
	do
	{
		gotoxy (x, y);								//Starts at middle of screen
          key = getch();

		if (key == '2' && y < 17)					//Moves Down				
		{
			gotoxy (x, y + 2);						//Goes Down by 2
			y += 2;
		}

		if (key == '8' && y > 1)						//Moves Up
		{
			gotoxy (x, y - 2);						//Goes Up by 2
			y -= 2;
		}

		if (key == '4' && x > 10)					//Moves Left
		{
			gotoxy (x - 5, y);						//Goes Left by 5
			x -= 5;
		}

		if (key == '6' && x < 50)					//Moves Right
		{
			gotoxy (x + 5, y);						//Goes Right by 5	
			x += 5;
		}
	}
	while (key != '5');
}

// This function will check if a box has been made
/*void dots::checkbox(int score1, int score2)
{
	if (((x == 15 && y == 1) && (x == 10 && y == 3) && (x == 15 && y == 5) && (x == 20 && y == 3))
		|| ((x == 25 && y == 1) && (x == 20 && y == 3) && (x == 25 && y == 5) && (x == 30 && y == 3))
		|| ((x == 35 && y == 1) && (x == 30 && y == 3) && (x == 35 && y == 5) && (x == 40 && y == 3))
		|| ((x == 45 && y == 1) && (x == 40 && y == 3) && (x == 45 && y == 5) && (x == 50 && y == 3))
		|| ((x == 15 && y == 5) && (x == 10 && y == 7) && (x == 15 && y == 9) && (x == 20 && y == 7))
		|| ((x == 25 && y == 5) && (x == 20 && y == 7) && (x == 25 && y == 9) && (x == 30 && y == 7))
		|| ((x == 35 && y == 5) && (x == 30 && y == 7) && (x == 35 && y == 9) && (x == 40 && y == 7))
		|| ((x == 45 && y == 5) && (x == 40 && y == 7) && (x == 45 && y == 9) && (x == 50 && y == 7))
		|| ((x == 15 && y == 9) && (x == 10 && y == 11) && (x == 15 && y == 13) && (x == 20 && y == 11))
		|| ((x == 25 && y == 9) && (x == 20 && y == 11) && (x == 25 && y == 13) && (x == 30 && y == 11))
		|| ((x == 35 && y == 9) && (x == 30 && y == 11) && (x == 35 && y == 13) && (x == 40 && y == 11))
		|| ((x == 45 && y == 9) && (x == 40 && y == 11) && (x == 45 && y == 13) && (x == 50 && y == 11))
		|| ((x == 15 && y == 13) && (x == 10 && y == 15) && (x == 15 && y == 17) && (x == 20 && y == 15))
		|| ((x == 25 && y == 13) && (x == 20 && y == 15) && (x == 25 && y == 17) && (x == 30 && y == 15))
		|| ((x == 35 && y == 13) && (x == 30 && y == 15) && (x == 35 && y == 17) && (x == 40 && y == 15))
		|| ((x == 45 && y == 13) && (x == 40 && y == 15) && (x == 45 && y == 17) && (x == 50 && y == 15)))
	{
		if (player == 1)
		{
			score1++;						//Increases Player 1 Score by 1
			cout<<name1<<"Score: "<<score1;	//Outputs Score 1
		}

		if (player == 2)
		{
			score2++;
			cout<<name2<<"Score: "<<score2;	//Outputs Score 2
		}
	}
}*/

void dots::drawvert()
{
	//******************* TOP VERTICAL ROW [0][x] *******************

	if(x == 10 && y == 3)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

          location[0][0].left = 1;
	}

	if(x == 20 && y == 3)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[0][0].right = 1;
          location[0][1].left = 1;
	}

	if(x == 30 && y == 3)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[0][1].right = 1;
          location[0][2].left = 1;
	}

	if(x == 40 && y == 3)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[0][2].right = 1;
          location[0][3].left = 1;
	}

	if(x == 50 && y == 3)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[0][3].right = 1;
	}

	//******************* SECOND VERTICAL ROW [1][x] *******************

	if(x == 10 && y == 7)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

          location[1][0].left = 1;
	}

	if(x == 20 && y == 7)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[1][0].right = 1;
          location[1][1].left = 1;
	}

	if(x == 30 && y == 7)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[1][1].right = 1;
          location[1][2].left = 1;
	}

	if(x == 40 && y == 7)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[1][2].right = 1;
          location[1][3].left = 1;
	}

	if(x == 50 && y == 7)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[1][3].right = 1;
	}

	//******************* THIRD VERTICAL ROW [2][x] *******************

	if(x == 10 && y == 11)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[2][0].left = 1;
	}

	if(x == 20 && y == 11)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[2][0].right = 1;
          location[2][1].left = 1;
	}

	if(x == 30 && y == 11)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[2][1].right = 1;
          location[2][2].left = 1;
	}

	if(x == 40 && y == 11)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[2][2].right = 1;
          location[2][3].left = 1;
	}

	if(x == 50 && y == 11)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[2][3].right = 1;
	}

	//******************* BOTTOM VERTICAL ROW [3][x] *******************

	if(x == 10 && y == 15)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[3][0].left = 1;
	}

	if(x == 20 && y == 15)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[3][0].right = 1;
          location[3][1].left = 1;
	}

	if(x == 30 && y == 15)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[3][1].right = 1;
          location[3][2].left = 1;
	}

	if(x == 40 && y == 15)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[3][2].right = 1;
          location[3][3].left = 1;
	}

	if(x == 50 && y == 15)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[3][3].right = 1;
	}
}


// This function will check to see if a box has been made
void dots::checkbox()
{
	if ((location[0][0].top = 1 && location[0][0].left = 1 && location[0][0].bottom = 1 && location[0][0].right = 1)
		|| (location[0][1].top = 1 && location[0][1].left = 1 && location[0][1].bottom = 1 && location[0][1].right = 1)
		|| (location[0][2].top = 1 && location[0][2].left = 1 && location[0][2].bottom = 1 && location[0][2].right = 1)
		|| (location[0][3].top = 1 && location[0][3].left = 1 && location[0][3].bottom = 1 && location[0][3].right = 1)
		|| (location[1][0].top = 1 && location[1][0].left = 1 && location[1][0].bottom = 1 && location[1][0].right = 1)
		|| (location[1][1].top = 1 && location[1][1].left = 1 && location[1][1].bottom = 1 && location[1][1].right = 1)
		|| (location[1][2].top = 1 && location[1][2].left = 1 && location[1][2].bottom = 1 && location[1][2].right = 1)
		|| (location[1][3].top = 1 && location[1][3].left = 1 && location[1][3].bottom = 1 && location[1][3].right = 1)
		|| (location[2][0].top = 1 && location[2][0].left = 1 && location[2][0].bottom = 1 && location[2][0].right = 1)
		|| (location[2][1].top = 1 && location[2][1].left = 1 && location[2][1].bottom = 1 && location[2][1].right = 1)
		|| (location[2][2].top = 1 && location[2][2].left = 1 && location[2][2].bottom = 1 && location[2][2].right = 1)
		|| (location[2][3].top = 1 && location[2][3].left = 1 && location[2][3].bottom = 1 && location[2][3].right = 1)
		|| (location[3][0].top = 1 && location[3][0].left = 1 && location[3][0].bottom = 1 && location[3][0].right = 1)
		|| (location[3][1].top = 1 && location[3][1].left = 1 && location[3][1].bottom = 1 && location[3][1].right = 1)
		|| (location[3][2].top = 1 && location[3][2].left = 1 && location[3][2].bottom = 1 && location[3][2].right = 1)
		|| (location[3][3].top = 1 && location[3][3].left = 1 && location[3][3].bottom = 1 && location[3][3].right = 1))
	{
		if (player == 1)
		{
			score1++;						//Increases Player 1 Score by 1
			cout<<name1<<"Score: "<<score1;	//Outputs Score 1
		}

		if (player == 2)
		{
			score2++;						//Increases Player 2 Score by 2
			cout<<name2<<"Score: "<<score2;	//Outputs Score 2
		}
	}
}