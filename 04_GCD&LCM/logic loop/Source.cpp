#include<iostream>
using namespace std;
int gcd(int , int);
int lcd(int, int);
int main() {
	int input1, input2;
	while (1)
	{
		cin >> input1 >> input2;
		cout <<"GCD : "<< gcd(input1, input2)<<endl;
		cout <<"LCD : "<< lcd(input1, input2)<<endl;
	}
	system("pause");
	return 0;
}

int gcd(int a,int b) {
	if (a > b) return gcd(a - b, b);
	else if (a < b) return gcd(a, b - a);
	else if (a == b) return a;
	else if (a == 0) return b;
	else if (b == 0) return a;
}
int lcd(int a, int b) {
	int GCD = gcd(a, b);
	if (GCD == 1)return a * b;
	else if (GCD == b)return a;
	else if (GCD == a)return b;
	else return GCD * lcd( a / GCD , b / GCD );



}