#include<iostream>
#include<time.h>
using namespace std;

int main() {

	srand(time(NULL));



	int input, temp;
while(1){
	cin >> input;
	int *qq = new int[input];
	for (int i = 0; i < input; i++)
	{
		qq[i] = rand() % 10;
	}
	cout << " array = > { ";
	for (int i = 0; i < input; i++)
	{
		if (i != 0)cout << ",";
		cout << qq[i] << " ";
	}
	cout << "}" << endl;

	for (int i = 0; i < input - 1; i++)
	{
		for (int j = 0; j < input - i - 1; j++)
		{
			if (qq[j] > qq[j + 1]) {
				temp = qq[j];
				qq[j] = qq[j + 1];
				qq[j + 1] = temp;

			}
		}
	}
	cout << " array = > { ";
	for (int i = 0; i < input; i++)
	{
		if (i != 0)cout << ",";
		cout << qq[i] << " ";
	}
	cout << "}" << endl;

	delete[] qq;

}
	system("pause");
	return 0;
}