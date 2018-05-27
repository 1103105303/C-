#include<iostream>

using namespace std;
template<class T>
void Sum(T[], int);

int main()
{
	int number;
	int *input = NULL;

	 
	cout << "要幾個變數？" << endl;
	cin >> number;
	input = new int[number];

	
	for (int i = 0; i < number; i++)
	{
		cin >> input[i];
	}

	Sum(input, number);

	system("pause");
	return 0;
}
//Int double float 都可以使用
template <class T>
void Sum(T number[], int length) {
	
	int sum = 0, product = 1, square = 0;

	for (int i = 0; i < length; i++) 
	{
		sum += number[i];
		product *= number[i];
		square += (number[i] * number[i]);
	}

	cout << "Sum : " << sum << endl;
	cout << "Product : " << product << endl;
	cout << "Square of Sum : " << square << endl;
}