// Program name: A8
// Date: Feb 07, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description: This program will either:  
// 			a) Allow the user to input county.
//				The output list is to be a list of names (presented on the screen) of donors from the input county.
//			b) Delete a text line specified by the program user from the data file.
// Input: Choice A or B, county, text line
//
// Output: List of names of donors  
//
// Assumptions/Limitations: Only names available in data file
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

void init();									//Prototype for Initialization
char menu();							//Prototype for Menu
void check(ifstream& input1);						//Prototype for Check
void importdata(ifstream& input1, char lastname[20], char firstname[20], char address[50], char county[20]);		//Prototype for Import Data
void inputcounty(char usercounty[20]);				//Prototype for User County
void outputcounty(char lastname[20], char firstname[20], char address[50], char county[20], char usercounty[20], int& flag);	//Prototype for Output County
void inputusername(char userfirst[20], char userlast[20], char userfullname[40]);		//Prototype for Input user name
void checktemp(ofstream& temp);			//Prototype for Check Temp
void readname(ifstream& input1, char lastname[20], char firstname[20], char address[50], char county[20], char fullname[40]);	//Prototype for Reading in name
void checkname(ifstream& input1, ofstream& temp, char lastname[20], char firstname[20], char address[50], char county[20], char fullname[40], char userfullname[40], int& flag, int& count);	//Function call for Check name
void check2(ifstream& input2, ofstream& out);				//Prototype for Check 2
void readtemp(ifstream& input2, char lastname[20], char firstname[20], char address[50], char county[20]);		//Prototype for Reading in Temp
void outputmain(ifstream& input2, ofstream& out, char lastname[20], char firstname[20], char address[50], char county[20]);		//Prototype for Outputting data

int main()
{
	ifstream input1, input2;		     				//Declaration
	ofstream temp, out;
	int flag = 0, count = 1;
	char choice;
	char lastname[20], firstname[20], address[50], county[20], fullname[40];
	char usercounty[20], userfirst[20], userlast[20], userfullname[40];

	init();								//Function call for Initialization

	check(input1);							//Function call for checking opening file A8.dat

	choice = menu();							//Function call for Menu

	switch (choice)
	{
		case 'A':
			inputcounty(usercounty);			//Function call for User Input County
			
			do
			{
				importdata(input1, lastname, firstname, address, county);	//Function call for Import Data
				outputcounty(lastname, firstname, address, county, usercounty, flag);	//Function call for Outputting data
			}
			while (! input1.eof());

			if (flag == 0)
				cout<<"\nCounty not found ";			//Outputs error message	

			input1.close();

			break;

		case 'B':
			flag = 0;					//Declaration

			checktemp(temp);			//Functon call for Check temp file

			inputusername(userfirst, userlast, userfullname);		//Function call for Inputting user name

			do
			{
				readname(input1, lastname, firstname, address, county, fullname);	//Function call for Reading in name
				checkname(input1, temp, lastname, firstname, address, county, fullname, userfullname, flag, count);		//Function call for Check names
			}
			while (! input1.eof());

			input1.close();
			temp.close();

			if (flag == 1)
			{
				check2(input2, out);		//Function call for Check 2

				do
				{
					readtemp(input2, lastname, firstname, address, county);		//Function call for Reading in Temp
					outputmain(input2, out, lastname, firstname, address, county);	//Function call for Outputtng data
				}
				while (! input2.eof());
			}

			input2.close();
			out.close();

			break;

		default:
			cout<<"\nPlease Re-enter either choice A or B. ";		//Outputs error message

			break;
	}

	getchar();
	return 0;
}

//This function will output the purpose
void init()
{
	cout<<"\nThis program will either: "
		<<"\na) Allow the user to input county. "
		<<"\n\tThe output list is to be a list of names (presented on the screen) of "
		<<"\n\tdonors from the input county. "
		<<"\nb) Delete a text line specified by the program user from the data file. ";		//Outputs purpose

	cout<<"\n\nPress Enter to Proceed ";		//Press enter to continue to program
	getchar();
	clrscr();
}

//This function will check to see if input or output file fails
void check(ifstream& input1)
{
	input1.open("F:/Aprogs/A8.dat");						//Opens data file

	if(input1.fail())
	{
		cout<<"Input file A8.dat failed to open. \n";		//Outputs failure message
		getch();
		exit(1);
	}
}

//This function will check to see if Temp file fails
void checktemp(ofstream& temp)
{
	temp.open("F:/Aprogs/A8temp.dat");						//Outputs data file

	if(temp.fail())
	{
		cout<<"Output file A8temp.dat failed. \n";		//Outputs failure message
		getch();
		exit(1);
	}
}

//This function will output the menu to the screen
char menu()
{
	char choice;								//Declaration

	cout<<"A) Find people in the County you want ";	//Outputs menu
	cout<<"\nB) Delete data with selected name ";
	cout<<"\n\nWhat would you like to do: ";		//Input Choice
	cin>>choice;
	choice = toupper(choice);
	cin.ignore();

     return (choice);
}


//This function will import data from the input file
void importdata(ifstream& input1, char lastname[20], char firstname[20], char address[50], char county[20])
{
	input1.getline(lastname, 80, ',');			//Inputs last name
	input1.ignore();

	input1.getline(firstname, 80, '*');			//Inputs first name
	input1.ignore();

	input1.getline(address, 80, '*');			//Inputs address
	input1.ignore();

	input1.getline(county, 80, '\n');			//Inputs county
}

//This function will allow the user to input a county
void inputcounty(char usercounty[20])
{
	cout<<"\nWhat County would you like: ";
	cin.getline(usercounty, 80, '\n');			//Inputs user county
}


//This function will output the county if it matches with the user input county
void outputcounty(char lastname[20], char firstname[20], char address[50], char county[20], char usercounty[20], int& flag)
{
	if (strcmpi(county, usercounty) == 0)
	{
		flag ++;							//Increases flag by 1
		
		cout<<"\n"<<lastname<<", "<<firstname<<" "<<address<<"  "<<county;	//Outputs info
	}
}

//This function will allow the user to input the name they want to delete
void inputusername(char userfirst[20], char userlast[20], char userfullname[40])
{
	cout<<"\nEnter First Name: ";				//Inputs user first name
	cin.getline(userfirst, 80, '\n');

	cout<<"\nEnter Last Name: ";				//Inputs user last name
	cin.getline(userlast, 80, '\n');

	cout<<"\n\n";

	strcpy(userfullname, userfirst);			//Combining first and last name of what the user input
	strcat(userfullname, userlast);
}

//This function will read in the name from the input file and combine it into full name
void readname(ifstream& input1, char lastname[20], char firstname[20], char address[50], char county[20], char fullname[40])
{
	input1.getline(lastname, 80, ',');			//Inputs last name
	input1.ignore();

	input1.getline(firstname, 80, '*');			//Inputs first name
	input1.ignore();

	input1.getline(address, 80, '*');			//Inputs address
	input1.ignore();

	input1.getline(county, 80, '\n');			//Inputs county

	strcpy(fullname, "");					//Clears out full name previously there
	strcpy(fullname, firstname);					//Combining first and last name in the Dat file
	strcat(fullname, lastname);
}

//This function will search for the Fullname if it matches with the user input fullname
void checkname(ifstream& input1, ofstream& temp, char lastname[20], char firstname[20], char address[50], char county[20], char fullname[40], char userfullname[40], int& flag, int& count)
{
	if (strcmpi(fullname, userfullname) != 0)
	{
		if (count > 1)
			temp<<endl;				//Goes down a line of Count > 1

		temp<<lastname<<", "<<firstname<<"* "<<address<<"* "<<county;		//Outputs data to Temp file if User input name doesn't equal Name in Input Dat file

		count ++;					//Increases count by 1
	}
	else
		flag = 1;					//Assign flag to 1 if user entered name equals name in file

	if (flag == 0 && input1.eof())
		cout<<"\n\nName not found ";		//Outputs error message
}

//This function will check to see if input file and output file fail to operate
void check2(ifstream& input2, ofstream& out)
{
	input2.open("F:/Aprogs/A8temp.dat");						//Opens data file

	if(input2.fail())
	{
		cout<<"Input file A8temp.dat failed to open. \n";		//Outputs failure message
		getch();
		exit(1);
	}

	out.open("F:/Aprogs/A8.dat");						//Opens data file

	if(out.fail())
	{
		cout<<"Output file A8.dat failed. \n";		//Outputs failure message
		getch();
		exit(1);
	}
}

//This function will read in the data from the Temp file
void readtemp(ifstream& input2, char lastname[20], char firstname[20], char address[50], char county[20])
{
	input2.getline(lastname, 80, ',');			//Inputs last name
	input2.ignore();

	input2.getline(firstname, 80, '*');			//Inputs first name
	input2.ignore();

	input2.getline(address, 80, '*');			//Inputs address
	input2.ignore();

	input2.getline(county, 80, '\n');			//Inputs county
}

//This function will output data to the main file A8.dat and screen
void outputmain(ifstream& input2, ofstream& out, char lastname[20], char firstname[20], char address[50], char county[20])
{
	out<<lastname<<", "<<firstname<<"* "<<address<<"* "<<county;		//Outputs data to main file A8.dat
	cout<<lastname<<", "<<firstname<<"* "<<address<<"* "<<county;		//Outputs data to the screen

	if (! input2.eof())
	{
		out<<endl;						//Goes to next line if not end of file
		cout<<endl;						//Goes to next line if not end of file
	}
}
