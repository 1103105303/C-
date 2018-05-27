#include<iostream>
using namespace std;
int main() 
{
	unsigned int value = 1;
	int input ;

	cout << "輸入要多少階層 " << endl;
	cin >> input;
	try 
	{
		if (input > 1 && input < 13)
		{
			for (int i = 2; i <= input; i++) 
			{
				value *= i;
			}
		}
		if (input > 12) 
		{
			throw input;
		}
		cout << input << "! : " << value << endl;
	}
	catch (int i)
	{
		cout << i << "! :  ==ERROR==";
	}

	system("pause");
	return 0;
			
}