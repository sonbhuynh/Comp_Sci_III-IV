// Son Huynh & Adam Backshall
// Program Description:
//
// Input: Movements and Lines
//
// Output: Dots Game
//
// Assumptions/Limitations: Players have a numpad 
//
//----------------------------------------------

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
		char name1[20], name2[20]; 						//variable declarations
		int x, y, z, w;
		int player, done, score1, score2;
		int flagbox1, flagbox2, flagbox3, flagbox4, flagbox5, flagbox6, flagbox7, flagbox8, flagbox9;
		int flagbox10, flagbox11, flagbox12, flagbox13, flagbox14, flagbox15, flagbox16;
		char key;
		struct Box
		{
			int left;
			int right;
			int top;
			int bottom;
		}location[4][4];

	public:             								//function protptypes
		dots();
          //~dots();
		void drawboard();
		void inputnames();
		void movement(int& player);
		void drawhoriz();
          void drawvert();
		void intro();
		void title();
		void rules();
		int returnplayer();
		char returnkey();
		int returndone();
		void checkbox(int& player);
		void compare();
};



int main()
{
	int player, done; 					//declarations
	char key;
	dots game;

	//game.intro();						//Call Intro

	//game.title();						//Call Title

	//game.rules();						//Call Rules

	game.inputnames();									//Call Input Names

	game.drawboard();									//Call Draw Board

	do
	{
		player = game.returnplayer();

		if (player == 1)
		{

			do
               {
				game.movement(player); 			//calling movement function

				key = game.returnkey();

				if (key == '0')
				{
                         clrscr();
					gotoxy(40, 7);
					cout<<"GAME OVER";
					gotoxy(40, 8);
                         game.compare();
				   	exit(1);
                    }
				game.drawhoriz();				//calling draw horizontal line function	

				game.drawvert();        			//calling draw vertical line function

				game.checkbox(player);

				done = game.returndone(); 		//returning done depending upon drawvert and horiz

			}
			while(done != 1);


               player = 2;
		}

		if (player == 2)
		{

			do
               {
				game.movement(player); 			//calling movement function

                    key = game.returnkey();

				if (key == '0')
				{
					clrscr();
					gotoxy(40, 7);
					cout<<"GAME OVER";
					gotoxy(40, 8);
                         game.compare();
				   	exit(1);
				}
				game.drawhoriz();				//calling draw horizontal line function

				game.drawvert();        			//calling draw vertical line function

				game.checkbox(player);

				done = game.returndone();

			}
			while(done != 1);


               player = 1;
		}

	}
	while(key != '0');

	
     getch();
	return 0;
}


//This function will explain the program
void dots::intro()
{
	cout<<"\n\nThis program will allow two players to go head to head in a game of 'Dots'."	//Explaining program
     <<"\n\n\t\t\tPress enter to continue";

	getch();

	clrscr();	
}


//This function will output a big ascii DOTS to the screen
void dots::title()
{
	cout<<"\t\t ||==\\\\     //==\\\\   ======   //===  \n"		//drawing big ascii DOTS title
	    <<"\t\t ||   ||   ||    ||    ||    ||       \n"
	    <<"\t\t ||   ||   ||    ||    ||     \\\\=\\\\ \n"
	    <<"\t\t ||   ||   ||    ||    ||         ||  \n"
	    <<"\t\t ||   ||   ||    ||    ||         ||  \n"
	    <<"\t\t ||==//     \\\\==//     ||     ===//  \n";
}


//This function will output the rules of the game to the screen
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

	clrscr(); 										//clearing screen
}

// This function will draw the board
void dots::drawboard()
{
	for (int x = 0; x < 5; x++)
	{
     	if (x > 0)
			cout<<endl<<endl<<endl<<endl;						//Outputs Blank Lines

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
void dots::movement(int& player)
{
	do
	{
		gotoxy(55, 1);
		cout<<setw(10)<<"x = "<<setw(2)<<x; 			//outputting current x coordinate
		gotoxy(55, 2);
		cout<<setw(10)<<"y = "<<setw(2)<<y;          	//outputting current y coordinate

		gotoxy(10, 23);

          if (player == 1)
			cout<<setw(25)<<name1<<"'s turn";

		if (player == 2)
			cout<<setw(25)<<name2<<"'s turn";

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

		if (key == '0')
		{
			break;								//Breaks out of loops if 0 is pressed
          }

		
	}
	while (key != '5');
}

void dots::drawhoriz()
{
	if(y == 1)
     {
		if(x == 15 && location[0][0].top == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[0][0].top = 1;
               done = 1;

		}

		if(x == 25 && location[0][1].top == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
          	location[0][1].top = 1;
               done = 1;
		}

		if(x == 35 && location[0][2].top == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
          	location[0][2].top = 1;
               done = 1;
		}

		if(x == 45 && location[0][3].top == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
          	location[0][3].top = 1;
               done = 1;
		}
     }

     //*****************************************************************

	if(y == 5)
     {
		if(x == 15 && location[1][0].top == 0 && location[0][0].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[1][0].top = 1;
			location[0][0].bottom = 1;
               done = 1;
		}

		if(x == 25 && location[1][1].top == 0 && location[0][1].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[1][1].top = 1;
			location[0][1].bottom = 1;
			done = 1;
		}

		if(x == 35 && location[1][2].top == 0 && location[0][2].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[1][2].top = 1;
			location[0][2].bottom = 1;
			done = 1;
		}

		if(x == 45 && location[1][3].top == 0 && location[0][3].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[1][3].top = 1;
			location[0][3].bottom = 1;
			done = 1;
		}
     }

	//*****************************************************************

	if(y == 9)
     {
     	
		if(x == 15 && location[2][0].top == 0 && location[1][0].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[2][0].top = 1;
			location[1][0].bottom = 1;
			done = 1;
		}

		if(x == 25 && location[2][1].top == 0 && location[1][1].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[2][1].top = 1;
			location[1][1].bottom = 1;
			done = 1;
		}

		if(x == 35 && location[2][2].top == 0 && location[1][2].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[2][2].top = 1;
			location[1][2].bottom = 1;
			done = 1;
		}

		if(x == 45 && location[2][3].top == 0 && location[1][3].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[2][3].top = 1;
			location[1][3].bottom = 1;
			done = 1;
		}
     }

	//*****************************************************************

	if(y == 13)
     {

		if(x == 15 && location[3][0].top == 0 && location[2][0].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][0].top = 1;
			location[2][0].bottom = 1;
			done = 1;
		}

		if(x == 25 && location[3][1].top == 0 && location[2][1].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][1].top = 1;
			location[2][1].bottom = 1;
			done = 1;
		}

		if(x == 35 && location[3][2].top == 0 && location[2][2].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][2].top = 1;
			location[2][2].bottom = 1;
			done = 1;
		}

		if(x == 45 && location[3][3].top == 0 && location[2][3].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][3].top = 1;
			location[2][3].bottom = 1;
			done = 1;
		}
     }

     //*****************************************************************

	if(y == 17)
     {

		if(x == 15 && location[3][0].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][0].bottom = 1;
			done = 1;
		}

		if(x == 25 && location[3][1].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][1].bottom = 1;
			done = 1;
		}

		if(x == 35 && location[3][2].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][2].bottom = 1;
			done = 1;
		}

		if(x == 45 && location[3][3].bottom == 0)
		{
			gotoxy(x-4, y);
			cout<<"---------"; 				//drawing horizontal line
			location[3][3].bottom = 1;
			done = 1;
		}
	}

	if (done == 0)
	{
          gotoxy(10, 21);
		//cout<<"Please select an appropriate spot";
     }

		 	
}

void dots::drawvert()
{
	//******************* TOP VERTICAL ROW [0][x] *******************

	if(x == 10 && y == 3 && location[0][0].left == 0)
	{
		gotoxy(x, y-1);				//drawing first part of vertical line
		cout<<"|";

		gotoxy(x, y);					//drawing second part of vertical line
		cout<<"|";

		gotoxy(x, y+1);				//drawing third part of vertical line
          cout<<"|";

		location[0][0].left = 1;

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
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

		done = 1;
	}
}

void dots::dots()
{
	x = 30;                     			//initializing variables
	y = 7;						
	player = 1;
	done = 0;
	score1 = 0;
	score2 = 0;
	flagbox1 = 0;
	flagbox2 = 0;
	flagbox3 = 0;
	flagbox4 = 0;
	flagbox5 = 0;
	flagbox6 = 0;
	flagbox7 = 0;
	flagbox8 = 0;
	flagbox9 = 0;
	flagbox10 = 0;
	flagbox11 = 0;
	flagbox12 = 0;
	flagbox13 = 0;
	flagbox14 = 0;
	flagbox15 = 0;
	flagbox16 = 0;

	for(z = 0; z < 4; z++)
	{
     	for(w = 0; w < 4; w++)
		{
			location[z][w].left = 0;
			location[z][w].right = 0;
			location[z][w].top = 0;
			location[z][w].bottom = 0;
		}
     }
}
/*
dots::~dots()
{
	cout<<"Data erased.";
}
*/
int dots::returnplayer()
{
	return (player);		//returns player
}

char dots::returnkey()
{
	return (key);
}

int dots::returndone()
{
	return (done);
}

void dots::checkbox(int& player)
{
	if (location[0][0].top == 1 && location[0][0].left == 1 && location[0][0].bottom == 1 && location[0][0].right == 1
	&& flagbox1 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox1 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox1 = 1;
               done = 0;
		}
	}

	if (location[0][1].top == 1 && location[0][1].left == 1 && location[0][1].bottom == 1 && location[0][1].right == 1
	&& flagbox2 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox2 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox2 = 1;
               done = 0;
		}
	}

	if (location[0][2].top == 1 && location[0][2].left == 1 && location[0][2].bottom == 1 && location[0][2].right == 1
	&& flagbox3 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox3 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox3 = 1;
               done = 0;
		}
	}

	if (location[0][3].top == 1 && location[0][3].left == 1 && location[0][3].bottom == 1 && location[0][3].right == 1
	&& flagbox4 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox4 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox4 = 1;
               done = 0;
		}
	}

	if (location[1][0].top == 1 && location[1][0].left == 1 && location[1][0].bottom == 1 && location[1][0].right == 1
	&& flagbox5 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox5 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox5 = 1;
               done = 0;
		}
	}

	if (location[1][1].top == 1 && location[1][1].left == 1 && location[1][1].bottom == 1 && location[1][1].right == 1
	&& flagbox6 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox6 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox6 = 1;
               done = 0;
		}
	}

	if (location[1][2].top == 1 && location[1][2].left == 1 && location[1][2].bottom == 1 && location[1][2].right == 1
	&& flagbox7 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox7 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox7 = 1;
               done = 0;
		}
	}

	if (location[1][3].top == 1 && location[1][3].left == 1 && location[1][3].bottom == 1 && location[1][3].right == 1
	&& flagbox1 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox8 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox8 = 1;
               done = 0;
		}
	}

	if (location[2][0].top == 1 && location[2][0].left == 1 && location[2][0].bottom == 1 && location[2][0].right == 1
	&& flagbox9 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox9 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox9 = 1;
               done = 0;
		}
	}

	if (location[2][1].top == 1 && location[2][1].left == 1 && location[2][1].bottom == 1 && location[2][1].right == 1
	&& flagbox10 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox10 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox10 = 1;
               done = 0;
		}
	}

	if (location[2][2].top == 1 && location[2][2].left == 1 && location[2][2].bottom == 1 && location[2][2].right == 1
	&& flagbox11 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox11 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox11 = 1;
               done = 0;
		}
	}

	if (location[2][3].top == 1 && location[2][3].left == 1 && location[2][3].bottom == 1 && location[2][3].right == 1
	&& flagbox12 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox12 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox12 = 1;
               done = 0;
		}
	}

	if (location[3][0].top == 1 && location[3][0].left == 1 && location[3][0].bottom == 1 && location[3][0].right == 1
	&& flagbox13 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox13 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox13 = 1;
               done = 0;
		}
	}

	if (location[3][1].top == 1 && location[3][1].left == 1 && location[3][1].bottom == 1 && location[3][1].right == 1
	&& flagbox14 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox14 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox14 = 1;
               done = 0;
		}
	}

	if (location[3][2].top == 1 && location[3][2].left == 1 && location[3][2].bottom == 1 && location[3][2].right == 1
	&& flagbox15 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
			gotoxy(x, y);
			flagbox15 = 1;
               done = 0;
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox15 = 1;
               done = 0;
		}
	}

	if (location[3][3].top == 1 && location[3][3].left == 1 && location[3][3].bottom == 1 && location[3][3].right == 1
	&& flagbox16 == 0)
	{
		if (player == 1)
		{
               gotoxy(10, 18);
			score1++;						//Increases Player 1 Score by 1
			cout<<setw(10)<<name1<<setw(10)<<"'s Score: "<<score1;	//Outputs Score 1
		}

		if (player == 2)
		{
			gotoxy(10, 19);
			score2++;						//Increases Player 2 Score by 2
			cout<<setw(10)<<name2<<setw(10)<<"'s Score: "<<score2;	//Outputs Score 2
			gotoxy(x, y);
			flagbox16 = 1;
               done = 0;
		}
	}
}

void dots::compare()
{
	if (score1 > score2)
		cout<<name1<<" won.";

	if (score1 < score2)
		cout<<name2<<" won.";

	if (score1 == score2)
     	cout<<"Tie game, everyone's a loser";
}