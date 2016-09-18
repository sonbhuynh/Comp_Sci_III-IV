const int SIZE = 25;

int main()
{
	generatenum(num);				//Function call for Generate Num
	outputnumbers(num);				//Function call for Output Numbers

	getchar();
	return 0;
}

//This function will generate random non-repeating numbers from 1-99
void generatenum(int num[SIZE])
{
	for (int x = 0; x < SIZE; x++)
	{
		num[x] = random(100) + 1;			//Generates random numbers
		for (int count  = 0; count < x; count ++)
		{
			if (num[x] == num[count])
				x--;			//Decreases X by 1
		}
	}
}

//This function will output the numbers to the screen
void outputnumbers(int num[SIZE])
{
	cout<<"\nIndex: \n";               			//Outputs Index title

	for(int x = 0; x < SIZE; x++)
		cout<<setw(4)<<x;			//Outputs Index


	cout<<"\nValue: \n";			//Outputs Value title

	for(x = 0; x < SIZE; x++)
		cout<<setw(4)<<num[x];		//Outputs Value

}