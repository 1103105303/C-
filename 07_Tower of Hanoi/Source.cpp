#include<iostream>
using namespace std;
void Hanoi(int, char, char, char);
int disk01, disk02, disk03,temp;
int main(void) {

	int input;

	while (1) {
		disk01 = 1;
		disk02 = 0;
		disk03 = 0;

		cin >> input;
		Hanoi(input, 'A', 'B', 'C');
	}

	system("pasue");
	return 0;
}

void Hanoi(int n, char a, char b, char c) {
	if (n == 1) {                                       //from
		switch (a)
		{
		case 'A':
			temp = disk01;
			disk01++;
			break;
		case 'B':
			temp = disk02;
			disk02++;
			break;
		case 'C':
			temp = disk03;
			disk03++;
			break;


		default:
			break;
		}

		switch (c)                                       //to
		{
		case 'A':
			disk01 = temp;
			break;
		case 'B':
			disk02 = temp;
			break;
		case 'C':
			disk03 = temp;
			break;


		default:
			break;
		}
		
		
		cout << "Move disk "<<temp<< " from "<<a<<" to "<<c << endl; 

	}
	else {
		Hanoi(n - 1, a, c, b);
		Hanoi(1, a, b, c);
		Hanoi(n - 1, b, a, c);
	
	}
}