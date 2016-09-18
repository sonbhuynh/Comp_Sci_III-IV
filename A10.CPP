// Program name: A10  
// Date: Feb 14, 2012  
//
// Programmer: Son Huynh
// Course: CS III
// Mrs. Roszko				Period: 1
//
// Description:  This program will either add an try to existing Store.dat and Costs.dat file, delete an entry in those files
// 		or combine both files together and create a new file
// Input:  Data entry to be added or deleted
//
// Output:  Changes to existing file or create a new file
//
// Assumptions/Limitations: Data exists within the file and only Costs is double-type
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

int menu(int choice);			//Prototype for Menu
void magic(ofstream& output1, ofstream& output2, ofstream& temp1, ofstream& temp2, ofstream& details);		//Prototype for Magic Formula
void init();

void check(ofstream& output1, ofstream& output2);		//Prototype for Check
void inputdata(int& department, int& item, int& quantity, double& cost);		//Prototype for Input Data
void appenddata(ofstream& output1, ofstream& output2, int department, int item, int quantity, double cost);		//Prototype for Append Data

void checktemp(ofstream& temp1, ofstream& temp2);		//Prototype for Check Temp
void checkinput(ifstream& input1, ifstream& input2);	//Prototype for Check Input
int inputitem();		//Prototype for Input Item
void readdata(ifstream& input1, ifstream& input2, int& department, int& item, int& quantity, double& cost);		//Prototype for Read Data
void outputtemp(ofstream& temp1, ofstream& temp2, int& useritem, int& department, int& item, int& quantity, double& cost, int& count, int& flag);		//Prototype for Output Temp 

void checkinputtemp(ifstream& inputtemp1, ifstream& inputtemp2);      //Prototype for Check Input Temp
void readtemp(ifstream& inputtemp1, ifstream& inputtemp2, int& department, int& item, int& quantity, double& cost);     //Prototype for Reading Temp files
void outputdata(ofstream& output1, ofstream& output2, int department, int item, int quantity, double cost);             //Prototype for Output Data

void checkdetails(ofstream& details);		//Prototype for Check Details
void outputdetails(ofstream& details, int department, int item, int quantity, double cost);		//Prototype for Output Details

int main()
{
	int choice;						//Declaration
	int department, item, quantity;
	int useritem, flag = 0, count = 1;
	double cost;
	char titles1[80], titles2[80];
	ifstream input1, input2, inputtemp1, inputtemp2;
	ofstream output1, output2, temp1, temp2, details;

	init();						//Prototype for Initialize
	magic(output1, output2, temp1, temp2, details);		//Prototype for Magic Formula

	do
	{
		choice = menu(choice);			//Function call for Menu

		if (choice == 4)
		{
			cout<<"\nProgram terminated. ";	//Outputs quit message
			break;
		}

		switch (choice)
		{
			case 1:
				check(output1, output2);			//Function call for Check

				inputdata(department, item, quantity, cost);			//Function call for Input Data
				appenddata(output1, output2, department, item, quantity, cost);	//Function call for Append Data

				output1.close();
				output2.close();

				break;

			case 2:
				flag = 0;

				checkinput(input1, input2);		//Function call for Check Input

				checktemp(temp1, temp2);			//Function call for Check Temp
	
				useritem = inputitem();		//Function call for Input Item

				input1.getline(titles1, 80, '\n');	//Reads in Titles from Store.dat
				input2.getline(titles2, 80, '\n');	//Reads in Titles from Costs.dat

				temp1<<setw(15)<<"Department"<<setw(16)<<"Item Number"<<setw(13)<<"Quantity";	//Outputs title to Temp 1
				temp2<<setw(16)<<"Item Number"<<setw(14)<<"Cost";							//Outputs title to Temp 2

				do
				{
					readdata(input1, input2, department, item, quantity, cost);		//Function call for Read Data
					outputtemp(temp1, temp2, useritem, department, item, quantity, cost, count, flag);		//Function call for Output Temp
				}
				while(! input1.eof());

				input1.close();
				input2.close();

				temp1.close();
				temp2.close();

				if (flag == 1)
				{
					checkinputtemp(inputtemp1, inputtemp2);          //Function call for Check Input Temp

					inputtemp1.getline(titles1, 80, '\n');			//Reads in title from Temp 1
					inputtemp2.getline(titles2, 80, '\n');			//Reads in title from Temp 2

					output1<<setw(15)<<"Department"<<setw(16)<<"Item Number"<<setw(13)<<"Quantity";		//Outputs title to Store
					output2<<setw(16)<<"Item Number"<<setw(14)<<"Cost";					//Outputs title to Costs

					do
					{
						readtemp(inputtemp1, inputtemp2, department, item, quantity, cost);        //Prototype for Reading Temp
						outputdata(output1, output2, department, item, quantity, cost);            //Prototype for Output Data
					}
					while(! inputtemp1.eof());
				}
                
				inputtemp1.close();
				inputtemp2.close();
                
				output1.close();
				output2.close();
               	
				break;

			case 3:
				checkdetails(details);		//Function call for Check Details
				checkinput(input1, input2);		//Function call for Check Store and Costs

				details<<setw(15)<<"Department"<<setw(16)<<"Item Number"<<setw(13)<<"Quantity"<<setw(14)<<"Cost";		//Outputs Titles to Details

				do
				{
					readdata(input1, input2, department, item, quantity, cost);		//Function call for Read Data (Store and Costs)

					input1.ignore();
					input2.ignore();

					outputdetails(details, department, item, quantity, cost);		//Function call for Output Details
				}
				while(! input1.eof() && ! input2.eof());
				
				input1.close();
				input2.close();
				
				details.close();

				break;
            
			default:
				cout<<"\nPlease Enter (1-3) or 4 to Quit. ";                //Outputs error message
				break;
		}

		cout<<"\n\nPress Enter to Return to Menu. ";		//Press enter to return to menu
		getchar();
		clrscr();
	}
	while (choice != 4); 

	getchar();
	return 0;
}

//This function contains the Menu
int menu(int choice)
{
	cout<<"Choose one: ";			//Outputs menu
	cout<<"\n\t1) Add an entry ";
	cout<<"\n\t2) Delete an entry ";
	cout<<"\n\t3) Compile data ";
	cout<<"\n\t4) Quit ";

	cout<<"\n\nPlease choose from above: ";
	cin>>choice;					//Inputs choice

	return (choice);
}

//This function contains the Magic Formula
void magic(ofstream& output1, ofstream& output2, ofstream& temp1, ofstream& temp2, ofstream& details)
{
	cout.setf(ios::fixed);			//Magic formula for screen
	cout.setf(ios::showpoint);
	cout.precision(2);

	output1.setf(ios::fixed);		//Magic formula for outputting to Store.dat
	output1.setf(ios::showpoint);
	output1.precision(2);

	output2.setf(ios::fixed);		//Magic formula for outputting to Store.dat
	output2.setf(ios::showpoint);
	output2.precision(2);

	temp1.setf(ios::fixed);			//Magic formula for outputting to Temp1
	temp1.setf(ios::showpoint);
	temp1.precision(2);
	
	temp2.setf(ios::fixed);			//Magic formula for outputting to Temp2
	temp2.setf(ios::showpoint);
	temp2.precision(2);

	details.setf(ios::fixed);			//Magic formula for outputting to Temp2
	details.setf(ios::showpoint);
	details.precision(2);
}

//This function will output the Program's purpose
void init()
{
	cout<<"This program will either add an try to existing Store.dat and Costs.dat file, "
		<<"\ndelete an entry in those files "
		<<"\nor combine both files together and create a new file. ";			//Outputs purpose

	cout<<"\n\nPress Enter to Proceed. ";				//Press Enter to continue
	getchar();
	clrscr();
}

//************************ Part 1 ************************

//This function will check to see if opening file fails
void check(ofstream& output1, ofstream& output2)
{
	output1.open("F:/Aprogs/Store.dat", ios::app);

	if(output1.fail())
	{
		cout<<"Output to file Costs.dat failed. ";	//Outputs error for Costs.dat
		getch();
		exit(1);
	}

	output2.open("F:/Aprogs/Costs.dat", ios::app);

	if(output2.fail())
	{
		cout<<"Output to file Store.dat failed. ";	//Outputs error for Store.dat
		getch();
		exit(1);
	}
}

//This function will allow the user to input data
void inputdata(int& department, int& item, int& quantity, double& cost)
{
	cout<<"\nEnter Department Number: ";			//Inputs Department
	cin>>department;

	cout<<"\nEnter Item Number: ";				//Inputs Item Number
	cin>>item;

	cout<<"\nEnter Quantity: ";					//Inputs Quantity
	cin>>quantity;

	cout<<"\nEnter Cost: ";						//Inputs Cost
	cin>>cost;
}

//This function will add the data to the existing data files
void appenddata(ofstream& output1, ofstream& output2, int department, int item, int quantity, double cost)
{
	output1<<"\n"<<department<<setw(33)<<item<<setw(22)<<quantity;		//Outputs data to Store.dat
	output2<<"\n"<<item<<setw(33)<<cost;							//Outputs data to Costs.dat

	cout<<"\nItem number "<<item<<" has been added ";						//Outputs success message
}

//************************ Part 2 ************************

//This function will check to see if Temp file fails
void checktemp(ofstream& temp1, ofstream& temp2)
{
	temp1.open("F:/Aprogs/storetemp.dat");			//Opens storetemp file

	if(temp1.fail())
	{
		cout<<"Output file Store Temp.dat failed. \n";	//Outputs failure message
		getch();
		exit(1);
	}


	temp2.open("F:/Aprogs/coststemp.dat");			//Opens coststemp file

	if(temp2.fail())
	{
		cout<<"Output file Costs Temp.dat failed. \n";    //Outputs failure message
		getch();
		exit(1);
	}
}

//This function will check the input files fail
void checkinput(ifstream& input1, ifstream& input2)
{
	input1.open("F:/Aprogs/Store.dat");			//Opens storetemp file

	if(input1.fail())
	{
		cout<<"Input file Store.dat failed. \n";	//Outputs failure message
		getch();
		exit(1);
	}


	input2.open("F:/Aprogs/Costs.dat");			//Opens coststemp file

	if(input2.fail())
	{
		cout<<"Input file Costs.dat failed. \n";     //Outputs failure message
		getch();
		exit(1);
	}

}
//This function will allow the user to input item number
int inputitem()
{
	int useritem;								//Declaration

	cout<<"\nEnter Item Number to Delete: ";		//Inputs user item number
	cin>>useritem;

	return (useritem);
}

//This function will read in data both Store and Costs files
void readdata(ifstream& input1, ifstream& input2, int& department, int& item, int& quantity, double& cost)
{
	input1>>department;					//Inputs department
	input1>>item;						//Inputs Item number
	input1>>quantity;					//Inputs quantity


	input2>>item;						//Inputs Item number
	input2>>cost;						//Inputs Cost
}

//This function will output data to both temp files
void outputtemp(ofstream& temp1, ofstream& temp2, int& useritem, int& department, int& item, int& quantity, double& cost, int& count, int& flag)
{
	if (useritem != item)
	{
			temp1<<"\n"<<setw(15)<<department<<setw(16)<<item<<setw(13)<<quantity;		//Outputs data to Temp1 file (Store)
			temp2<<"\n"<<setw(16)<<item<<setw(14)<<cost;			//Outputs data to Temp1 file (Costs)

	}
	else
		flag = 1;

	if (flag == 0 && temp1.eof())
		cout<<"\n\nItem not found. ";		//Outputs error message
}

//This function will check and open both temp files
void checkinputtemp(ifstream& inputtemp1, ifstream& inputtemp2)
{
	inputtemp1.open("F:/Aprogs/storetemp.dat");			//Opens storetemp file

	if(inputtemp1.fail())
	{
		cout<<"Input file Store Temp.dat failed. \n";	//Outputs failure message
		getch();
		exit(1);
	}


	inputtemp2.open("F:/Aprogs/coststemp.dat");			//Opens coststemp file

	if(inputtemp2.fail())
	{
		cout<<"Input file Costs Temp.dat failed. \n";    //Outputs failure message
		getch();
		exit(1);
	}
}

//This function will read in data from both temp files
void readtemp(ifstream& inputtemp1, ifstream& inputtemp2, int& department, int& item, int& quantity, double& cost)
{     
	inputtemp1>>department;                         //Inputs Department
	inputtemp1>>item;                                    //Inputs Item
	inputtemp1>>quantity;                              //Inputs Quantity   

     
	inputtemp2>>item;                                    //Inputs item
	inputtemp2>>cost;                                    //Inputs cost
}

//This function will output the data from Temp files back to the original dat files
void outputdata(ofstream& output1, ofstream& output2, int department, int item, int quantity, double cost)
{
	output1<<"\n"<<setw(15)<<department<<setw(16)<<item<<setw(13)<<quantity;		//Outputs data to Store.dat
	output2<<"\n"<<setw(16)<<item<<setw(14)<<cost;					//Outputs data to Costs.dat
}     

//************************ Part 3 ************************

//This function will check and open the Details file
void checkdetails(ofstream& details)
{
	details.open("F:/Aprogs/Details.dat");				//Opens Details.dat file

	if(details.fail())
	{
		cout<<"Output file Details.dat failed. \n";		//Outputs failure message
		getch();
		exit(1);
	}
}

//This function will output data from Store and Costs to Details file
void outputdetails(ofstream& details, int department, int item, int quantity, double cost)
{
	details<<"\n"<<setw(15)<<department<<setw(16)<<item<<setw(13)<<quantity<<setw(14)<<cost;	//Outputs data to Details.dat
}