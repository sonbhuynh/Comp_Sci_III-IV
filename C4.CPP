// Program name: C4
// Date: March 29, 2012  
//
// Programmer: Son Huynh, Nathan Stevens
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will simulate a Tic-Tac-Toe game in a 3x3 board.
// 				Up to 2 players can take turn to play the game using X and O.
// 
// Input: X or O from the user to designated box  
//
// Output: X and O, the board, and declaration of winner   
//
// Assumptions/Limitations: People know how to play Tic-Tac-Toe, and they have a keyboard.

// LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>


// FUNCTION PROTOTYPES
void init();
void rules();
void board();
void start(int array[3][3], int& x, int& y, int position[3][3]);
void input(char& key, int array[3][3], int& x, int& y, int& a, int& b, int& symbol, int position[3][3]);
void check(int position[3][3], int& flag, int& symbol);

int main()
{
	char key;															//Variable Declarations
     int array[3][3];
	int position[3][3], symbol = 0;;
	int x, y, a = 14, b = 4;
     int flag = 0;

	init();															//Call Initialize function
     rules();															//Call Rules function
	board();															//Call board function
	start(array, x, y, position);											//Call start function

     do
	{
		input(key, array, x, y, a, b, symbol, position);						//Call input function
		check(position, flag, symbol);									//Call check function

	}
	while (array[0][0] == 0 || array[0][1] == 0 || array[0][2] == 0
		  || array[1][0] == 0 || array[1][1] == 0 || array[1][2] == 0
		   || array[2][0] == 0 || array[2][1] == 0 || array[2][2] == 0);

	gotoxy(33,25);														//Go to bottom of screen													//Go to bottom of screen

	if (flag == 0)														//If nobody won
	{
     	cout << "No Player Wins.";										//Outputs message
	}


	getchar();
     return 0;
	
}

// This function will output the program's purpose
void init()
{
	cout<<"This program will simulate a Tic-Tac-Toe game in a 3x3 board. "
		<<"\nUp to 2 players can take turn to play the game using X and O. ";		//Outputs Purpose

	cout<<"\n\nPress Enter to Proceed.";									//Press Enter to Continue
	getchar();
	clrscr();
}

// This function will output the rules of the game
void rules()
{
	cout<<"INSTRUCTIONS: ";

	cout<<"\n\nUse arrow keys to move the cursor. Press 5 to place the mark.";		//Outputs Instructions

	cout<<"\n\nCONDITIONS: ";

	cout<<"\n\nTwo players, X and O, who take turns marking the spaces in a 3×3 grid. "
		<<"\n\tThe player who succeeds in placing three respective marks "
		<<"\n\tin a horizontal, vertical, or diagonal row wins the game. "		//Outputs Conditions
		<<"\n\tIn the event neither player have 3 marks on the board, "
		<<"\n\tthe game is considered a tie and the game restarts. "; 

	cout<<"\n\nEXAMPLES: \n";
	cout<<"\nO  |     |  X ";											//Outputs Examples
     cout<<"\t\t\tX  |  O  |   ";
	cout<<"\n----------- ";
	cout<<"\t\t\t----------- ";
	cout<<"\n   |  O  |  O ";
     cout<<"\t\t\t   |  O  |  X "; 
	cout<<"\n----------- ";
	cout<<"\t\t\t----------- ";
	cout<<"\nX--|--X--|--X ";
     cout<<"\t\t\tX  |  X  |  O ";
	cout<<"\n\nPlayer X wins.";
	cout<<"\t\t\tNo player wins.";

	cout<<"\n\nPress Enter to Play.";										//Press Enter to Continue
	getchar();
     clrscr();
}

//This function will draw the board on the screen
void board()
{
	for (int x = 0; x < 81; x++) 											//Init x = 0, if < 80, increase x
	{
		gotoxy(x,8);													//Go to postition (x,8)
          cout << '_';													//Output board
	}

	for (x = 0; x < 81; x++) 											//Init x = 0, if < 80, increase x
	{
		gotoxy(x,17);													//Go to postition (x,16)
          cout << '_';													//Output board
	}

	for (int y = 0; y < 26; y++) 											//Init y = 0, if < 26, increase y
	{
		gotoxy(27,y);													//Go to postition (27,y)
          cout << '|';													//Output board
	}

	for (y = 0; y < 26; y++) 											//Init y = 0, if < 26, increase y
	{
		gotoxy(53,y);													//Go to postition (53,y)
          cout << '|';													//Output board
	}
}

//This function will start the game
void start(int array[3][3], int& x, int& y, int position[3][3])
{
	for (x = 0; x < 3; x++)												//Init x = 0, if < 3, increase x
	{
		for (y = 0; y < 3; y++)											//Init y = 0, if < 3, increase y
		{
			array[x][y] = 0;											//Set each square empty
               position[x][y] = 2;
		}
	}	

	x = 0;															//X = 0
	y = 0;                                                                          //Y = 0

	gotoxy(14,4);
}

//This function will let the user move around the screen
void input(char& key, int array[3][3], int& x, int& y, int& a, int& b, int& symbol, int position[3][3])
{
	
	
//----------------------------------------------MOVING----------------------------------------------------------------------

		key = getch();													//Input keystroke

		if (key == '6' && x != 2)										//If user moves right, and
		{
               x++;														//Increase x

			a += 27;													//Increase a by 27

			gotoxy(a,b);												//Go left	
		}

		if (key == '4' && x != 0)										//If user moves left, and
		{
               x--;														//Decrease x

			a -= 27;													//Decrease a by 27

			gotoxy(a,b);												//Go left	
		}

		if (key == '8' && y != 0)										//If user moves up, and
		{
               y--;														//Decrease y

			b -= 9;													//Decrease b by 9

			gotoxy(a,b);												//Go left	
		}

		if (key == '2' && y != 2)										//If user moves down, and
		{
               y++;														//Increase y

			b += 9;													//Increase b by 9

			gotoxy(a,b);												//Go left	
		}

//---------------------------------------------CHECKING--------------------------------------------------------------------

		if (key == '5' && array[x][y] == 0)								//If enter and square is empty
		{
			if (symbol % 2 == 0)										//If x turn
			{
				gotoxy(a-2,b-2);                                         	//Output large x
                    cout << "\\   /" << endl;

                    gotoxy(a-2,b-1);
                    cout << " \\ /" << endl;

                    gotoxy(a-2,b);
                    cout    << "  X" << endl;

                    gotoxy(a-2,b+1);
                    cout    << " / \\" << endl;

                    gotoxy(a-2,b+2);
                    cout << "/   \\";

				gotoxy(a,b);

				position[x][y] = 0;										//Track x

				array[x][y] = 1;
			}

			else
			{
				gotoxy(a-2,b-2);                                         //Output big o
                    cout << "  *  " << endl;
                       
                    gotoxy(a-2,b-1);
                    cout << " * * " << endl;

                    gotoxy(a-2,b);
                    cout << "*   *" << endl;

                    gotoxy(a-2,b+1);
                    cout << " * * " << endl;

                    gotoxy(a-2,b+2);
                        cout << "  *  " << endl;

				gotoxy(a,b);											//Output o

				position[x][y] = 1;										//Track 0

				array[x][y] = 1;
			}

               symbol++;
		}

         
  

	
}

//This function will check for the winner
void check(int position[3][3], int& flag, int& symbol)
{
	if ((position[0][0] == 0 && position[0][1] == 0 && position[0][2] == 0) 		//If winning combination
		  || (position[0][0] == 1 && position[0][1] == 1 && position[0][2] == 1)
		  || (position[1][0] == 0 && position[1][1] == 0 && position[1][2] == 0)
		  || (position[1][0] == 1 && position[1][1] == 1 && position[1][2] == 1)
		  || (position[2][0] == 0 && position[2][1] == 0 && position[2][2] == 0)
		  || (position[2][0] == 1 && position[2][1] == 1 && position[2][2] == 1)
		  || (position[0][0] == 0 && position[1][0] == 0 && position[2][0] == 0)
		  || (position[0][0] == 1 && position[1][0] == 1 && position[2][0] == 1)
		  || (position[0][1] == 0 && position[1][1] == 0 && position[2][1] == 0)
		  || (position[0][1] == 1 && position[1][1] == 1 && position[2][1] == 1)
		  || (position[0][2] == 0 && position[1][2] == 0 && position[2][2] == 0)
		  || (position[0][2] == 1 && position[1][2] == 1 && position[2][2] == 1)
		  || (position[0][0] == 0 && position[1][1] == 0 && position[2][2] == 0)
		  || (position[0][0] == 1 && position[1][1] == 1 && position[2][2] == 1)
		  || (position[2][0] == 0 && position[1][1] == 0 && position[0][2] == 0)
		  || (position[2][0] == 1 && position[1][1] == 1 && position[0][2] == 1))
	{
          flag = 1;													//Activate flag

		gotoxy(33,25);												//Go to bottom of screen

		if (symbol % 2 == 0)										//If x wins
		{
			cout << "Player O Wins!!";								//Output winning message
		}

		
          else
		{
			cout << "Player X Wins!!";								//Output winning message
		}
	}
}

