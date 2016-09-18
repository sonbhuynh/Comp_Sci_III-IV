// Program name: A9  
// Date: Feb 9, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:    This program will allow the user to either
//     A) Find the minimum score and output the name of the person and the score
//     B) Output each name and score in the given range, exclusive of end values
//     C) Search the Data file, then output the name and score if found
//     D) Write the contents of the Data file to the screen with the addition of a letter grade for each name
// 
// Input: Choice A, B, C, D, or Q to Quit
//
// Output:  Whatever the user selects
//
// Assumptions/Limitations: Only 1 choice at a time
//--------------------------------------------------------------------------

//////////////////////LIBRARIES
#include <iostream.h>
#include <iomanip.h>
#include <fstream.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

void init();                   //Prototype for Output purpose

char menu();							//Prototype for Menu
void check(ifstream& input1);				//Prototype for Check input 1
void readdata(ifstream& input1, char lastname[15], char firstname[15], int& grade, char fullname[30]);	//Prototype for Reading in data

void minimum(char lastname[15], char firstname[15], char lowname[30], int& grade, int& low, int& flag);	//Prototype for Finding Minimum
void outputminimum(char lowname[30], int low);		//Prototype for Outputting minimum score

void lowhigh(int& lowvalue, int& highvalue);     //Prototype for Inputting Low + High values
void getrange(int lowvalue, int highvalue, int& grade, char fullname[30], int& flag);         //Prototype for Get Range

void inputusername(char userfullname[30]);    //Prototype for Input user name
void checkname(int& grade, char fullname[30], char userfullname[30], int& flag);    //Prototype for Checking name

void checkletter(char fullname[30], int& grade, int& flag);	//Prototype for Check Letter

int main()
{
	ifstream input1;					//Declaration
	char choice;
	char lastname[15], firstname[15], fullname[30], lowname[30];
	char userlast[15], userfirst[15], userfullname[30];
	int low = 200, grade, lowvalue, highvalue, flag = 0;

	init();                         //Function call for Outputting purpose

	do
	{
		low = 200;			//Re-initializing
          flag = 0;

		check(input1);			//Function call for Checking input file

		choice = menu();		//Function call for Menu
		
		if (choice == 'Q')
		{
			cout<<"\nProgram terminated. ";  //Outputs quit message
			break;
		}
		

		switch (choice)
		{
			case 'A':

				do
				{
					readdata(input1, lastname, firstname, grade, fullname);	//Function call for Reading in data
					minimum(lastname, firstname, lowname, grade, low, flag);    //Function call for finding minimum score
				}
				while(! input1.eof());
				
				outputminimum(lowname, low);		//Function call for Outputting minimum score

				break;

			case 'B':

               	
				lowhigh(lowvalue, highvalue);      //Function call for Inputting Low + High Values
                 
				do
				{
					readdata(input1, lastname, firstname, grade, fullname);         //Function call for Reading in data
					getrange(lowvalue, highvalue, grade, fullname, flag);       //Function call for Get Range
				}
				while(! input1.eof());
                 
				break;
                 
			case 'C':
                                
				inputusername(userfullname);		//Function call for Inputting user name
                 
				do
				{
					readdata(input1, lastname, firstname, grade, fullname);         //Function call for Reading in data
					checkname(grade, fullname, userfullname, flag);   //Function call for Checking name
				}
				while(! input1.eof());
                 
				break;

			case 'D':

				cout<<"\n"<<setw(20)<<"Name"<<setw(15)<<"Number Grade"<<setw(15)<<"Letter Grade";	//Outputs titles

				do
				{
					readdata(input1, lastname, firstname, grade, fullname);         //Function call for Reading in data
					checkletter(fullname, grade, flag);    //Function call for Check letter
				}
				while(! input1.eof());

                    break;
                 
			default:
				cout<<"\nPlease Re-enter A, B, C, D, or Q to Quit. ";    //Outputs error message
				break;
                     
		}
		
		input1.close();

		if (flag == 0)
			cout<<"\n\nError, Data Not Found ";		//Outputs error message
    	
		cout<<"\n\nPress Enter to Return to Menu. ";       //Press enter to return to menu
		getchar();
		clrscr();

	}
	while(choice != 'Q');

	getchar();
	return 0; 	
}

//This function will output the purpose of the program
void init()
{
	cout<<"\nThis program will allow the user to either: ";           //Outputs purpose
	cout<<"\n\tA) Find the minimum score and output the name of the person "
		<<"\n\t\tand the score ";
	cout<<"\n\tB) Output each name and score in the given range, "
		<<"\n\t\texclusive of end values ";
	cout<<"\n\tC) Search the Data file, then output the name and score if found ";
	cout<<"\n\tD) Write the contents of the Data file to the screen with the addition "
		<<"\n\t\tof a letter grade for each name ";
     cout<<"\n\tQ) Quit ";
     
	cout<<"\n\nPress Enter to Proceed. ";        //Press enter to proceed
	getchar();
	clrscr();
}

//This function will output the menu
char menu()
{
	char choice;						//Declaration

	cout<<"Menu: ";				//Outputs menu
	cout<<"\n\tA) Find the minimum score ";
	cout<<"\n\tB) Find scores in a specific range ";
	cout<<"\n\tC) Find a person's score ";
	cout<<"\n\tD) Write data content onto the screen ";

	cout<<"\n\nEnter your choice (Q to Quit): ";	//Inputs choice
	cin>>choice;
	choice = toupper(choice);
	cin.ignore();

	return (choice);
}

//This function will check to see if input file fails to open
void check(ifstream& input1)
{
	input1.open("F:/Aprogs/grades2.dat");	//Opens grades2.dat file

	if(input1.fail())
	{
		cout<<"Input file Grades2.dat failed to open. \n ";	//Outputs failure message
		getch();
		exit(1);
	}
}

//This function will read in the data from the grades2.dat file
void readdata(ifstream& input1, char lastname[15], char firstname[15], int& grade, char fullname[30])
{
	input1.getline(lastname, 80, ',');		//Reading in last name
	input1.ignore();

	input1.getline(firstname, 80, '*');	//Reading in first name

	input1>>grade;						//Reading in grade
	input1.ignore();

	strcpy(fullname, firstname);		//Adds last name to full
	strcat(fullname, " ");
	strcat(fullname, lastname);		//Adds first name

}

//******************** PART A **********************

//This function will find the minimum score
void minimum(char lastname[15], char firstname[15], char lowname[30], int& grade, int& low, int& flag)
{
	if (grade < low)
	{
		flag = 1;

		low = grade;					//Dropping the lowest grade

		strcpy(lowname, firstname);		//Adds last name to full
          strcat(lowname, " ");
		strcat(lowname, lastname);		//Adds first name
	}
}

//This function will output the minimum score and the person who has it
void outputminimum(char lowname[30], int low)
{
	cout<<"\n"<<setw(20)<<lowname<<setw(10)<<low;				//Outputs name and lowest score
}

//******************** PART B **********************

//This function will allow the user to input the Low and High Values
void lowhigh(int& lowvalue, int& highvalue)
{
	cout<<"\nPlease enter the Low Value: ";       //Inputs low value
	cin>>lowvalue;
     
	cout<<"\nPlease enter the High Value: ";      //Inputs high value
	cin>>highvalue;
}

//This function will find and output the person and grade if they're within the given range
void getrange(int lowvalue, int highvalue, int& grade, char fullname[30], int& flag)
{
	if (lowvalue < grade && grade < highvalue)
	{
          flag = 1;

		cout<<"\n"<<setw(20)<<fullname<<setw(10)<<grade;                 //Outputs the person and grade if within given range		
	} 
     
}

//******************** PART C **********************

//This function will allow the user to input a name they want to find
void inputusername(char userfullname[30])
{
	cout<<"\nEnter the name to search (First Last): ";		//Inputs user full name
	cin.getline(userfullname, 80, '\n');
}

//This function will check the name and output data to the screen
void checkname(int& grade, char fullname[30], char userfullname[30], int& flag)
{
	if (strcmpi(fullname, userfullname) == 0)
     {
		cout<<"\n"<<setw(20)<<fullname<<setw(10)<<grade;    //Outputs person to screen if the names match
		flag = 1;
	}
}

//******************** PART D **********************

//This function will check to see what letter grade it is and output it
void checkletter(char fullname[30], int& grade, int& flag)
{
     flag = 1;

	if (grade > 94)
		cout<<"\n"<<setw(20)<<fullname<<setw(15)<<grade<<setw(15)<<"A";		//Outputs A if grade > 94

	if (grade >= 86 && grade <= 94)
		cout<<"\n"<<setw(20)<<fullname<<setw(15)<<grade<<setw(15)<<"B";		//Outputs B if grade >= 86 and <= 94

	if (grade >= 73 && grade <= 85)
		cout<<"\n"<<setw(20)<<fullname<<setw(15)<<grade<<setw(15)<<"C";		//Outputs C if grade >= 73 and <= 85

	if (grade >= 66 && grade <= 72)
		cout<<"\n"<<setw(20)<<fullname<<setw(15)<<grade<<setw(15)<<"D";		//Outputs D if grade >= 66 and <= 72

	if (grade < 66)
		cout<<"\n"<<setw(20)<<fullname<<setw(15)<<grade<<setw(15)<<"F";		//Outputs F if grade < 66
}