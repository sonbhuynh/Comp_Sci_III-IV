// Program name: Book Project  
// Date: April 23, 2012  
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

const int BOOKS = 50;

// DECLARATIONS
struct BookInfo
{
	char title[80];
	char author[30];
	int year;
	char type[20];
}books[BOOKS];

// FUNCTION PROTOTYPES
// ********** PART A **********
void openfile1(ifstream& input);
void readdata(ifstream& input, BookInfo books[BOOKS], int& num_books);
void openfile2(ofstream& output);

// ********** PART C **********
void insertbook(BookInfo books[BOOKS], int& num_books);

// ********** PART D **********
void movevalue(int num_books, BookInfo books[BOOKS]);

// ********** PART E **********
void savedata(ofstream& output, BookInfo books[BOOKS], int num_books);


int main()
{
	ifstream input;								//Declaration
	ofstream output;
	int num_books;
     char select;

	do
	{
		cout<< "Menu: "
	    << "\nA) Fill book list from file"							//Output menu
	    << "\nB) See book list by category"
	    << "\nC) Insert book into list"
	    << "\nD) Delete book from list"
	    << "\nE) Save current list to disk"
	    << "\nQ) Quit"
	    << "\nEnter (A, B, C, D, E, or Q): ";
		cin>> select; 											//Input selection
		select = toupper(select);
          cin.ignore();

		if (select == 'Q')
		{
			cout<<"\nYou have quit.";							//Outputs Quit Message
			getch();
			exit(1);
		}

		switch (select)
		{
          	case 'A':

     			// ***** PART A *****
				openfile1(input);								//Call Open File
				readdata(input, books, num_books);					//Call Read Data
				input.close();
				break;
			case 'C':
				insertbook(books, num_books);						//Call Insert Book
				break;
			case 'D':
				movevalue(num_books, books);
                    break;
               	
			case 'E':
				openfile2(output);								//Call Open File 2
				savedata(output, books, num_books);				//Call Save Data
				output.close();
                    break;
			default:
				cout<<"Re-enter A, B, C, D.";
				getch();
				break;
          }

	}
     while (select != 'Q');

	getchar();
	return 0;
}

// ********** PART A **********
// This function will check and open the file
void openfile1(ifstream& input)
{
	input.open("F:/Cprogs/Books.txt");					//Opens File

	if (input.fail())
	{
		cout<<"Input File Books.Txt failed to open.";	//Outputs Error Message
		getch();
		exit(1);
	}
}

// This function will read in data from the external file
void readdata(ifstream& input, BookInfo books[BOOKS], int& num_books)
{
	int x = 0;									//Declaration

	do
	{
		input.getline(books[x].title, 80, '\t');		//Reads in Title
		input.getline(books[x].author, 80, '\t');		//Reads in Author
		input.ignore();

		input>>books[x].year;						//Reads in Year

		input.getline(books[x].type, 80, '\n');			//Reads in Type

		x++;										//Increases x by 1
	}
	while (! input.eof());

     num_books = x;									//Finds number of books

	cout<<"\nData was successfully imported. ";			//Outputs Success Message
	getchar();
	clrscr();
}

// This function will check and open the file
void openfile2(ofstream& output)
{
	output.open("F:/Cprogs/Books.txt", ios::app);		//Opens File

	if (output.fail())
	{
		cout<<"Output File Books.Txt failed.";			//Outputs Error Message
		getch();
		exit(1);
	}
}

// ********** PART C **********
// This function will allow the user to enter info for the book
void insertbook(BookInfo books[BOOKS], int& num_books)
{
	char usertitle[80];								//Declaration
	char userauthor[30];
	int useryear;
	char usertype[20];
     char typechoice;

	cout<<"\nPlease enter Title: \t";					//Inputs Title
	cin.getline(usertitle, 80, '\n');

	cout<<"Please enter Author: \t";					//Inputs Author
	cin.getline(userauthor, 80, '\n');

	cout<<"Please enter Year: \t";					//Inputs Year
	cin>>useryear;

	cout<<"\nBooks Category: ";				    		//Outputs Categories
	cout<<"\n\tA. Fiction. ";
	cout<<"\n\tB. Non-Fiction. ";
	cout<<"\n\tC. Advice/Other. ";

	cout<<"\nEnter A, B, or C: ";						//Inputs Category
	cin>>typechoice;
	typechoice = toupper(typechoice);

	switch (typechoice)
	{
		case 'A':
			strcpy(usertype, "Fiction");				//Assigns Fiction to Type
			break;

		case 'B':
			strcpy(usertype, "Non-Fiction");			//Assigns Non-Fiction to Type
			break;

		case 'C':
			strcpy(usertype, "Advice");				//Assigns Advice to Type
			break;

		default:
			cout<<"\nRe-Enter either A, B, or C.";		//Outputs Error Message
			break;
	} 

	strcpy(books[num_books + 1].title, usertitle);		//Inserts User Title to list
	strcpy(books[num_books + 1].author, userauthor);		//Inserts User Author to list
     books[num_books + 1].year = useryear;				//Inserts User Year to list
	strcpy(books[num_books + 1].type, usertype);			//Inserts User Type to list

	num_books++;									//Increases Num Books by 1

	cout<<"\nData Successfully Added.";				//Outputs Success Message
	getch();
	clrscr();
}

// ********** PART D **********
// This function will move the positions of the books
void movevalue(int num_books, BookInfo books[BOOKS])
{
	int inspt = 0;									//Declaration
	char userbook[80];
	int x = 0;
     int flag = 0;

	cout<<"\nEnter Book Title to be deleted: ";			//Inputs Book to be deleted
     cin.getline(userbook, 80, '\n');

	do
	{
		if (strcmpi(userbook, books[x].title) == 0)
		{
			inspt++;								//Increases Insertion Point

			strcpy(books[x].title, books[x+1].title);	//Moving Values Up

			flag = 1;								//Make Flag 1

		}

		x++;										//Increases x by 1
	}
	while (x < num_books);

	if (flag == 0)
	{
		cout<<"Book could not be found.";				//Outputs Error message
		getch();
		clrscr();
	}

	cout<<"\nBook has been deleted.";
	getch();
	clrscr();
}

// ********** PART E **********
// This function will save the data and send it to the Disk
void savedata(ofstream& output, BookInfo books[BOOKS], int num_books)
{
     output<<endl;
	output<<books[num_books].title;						//Outputs Title
	output<<'\t'<<books[num_books].author;			//Outputs Author
	output<<'\t'<<books[num_books].year;			//Outputs Year
	output<<'\t'<<books[num_books].type;			//Outputs Type

	cout<<"\nData Successfully Saved.";				//Outputs Success Message
	getch();
     clrscr();
}