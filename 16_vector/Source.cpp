#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main() 
{
	int number, input, size = -1, choice, count = 0, sizeofa = 0, sizeofb = 0, same = 0;
	string temp_a, temp_b;
	vector<int> VT;
	vector<int> tempVT;
	queue<int> QE;
	deque<char> a, b, add, sub;
	

	cout << "請輸入1、串列 2、柱列，轉柱列 3、字串加減法 :  ";
	cin >> choice;

	//****************兩個串列轉柱列******************
	switch (choice)
	{
	case 1:
		cout << "How many number you want to push ? ";
		cin >> number;
		cout << endl << "push" << endl;
		for (int i = 0; i < number; i++)
		{
			cout << "Step " << i << " : ";
			cin >> input;
			VT.push_back(input);
			size++;
		}

		for (int i = 0; i <= size; i++)
		{
			tempVT.push_back(VT.back());
			VT.pop_back();
		}

		cout << endl << "POP" << endl;
		for (unsigned int i = 0; i <= size; i++)
		{
			cout << "Step " << count++ << " : " << tempVT.back() << endl;
			tempVT.pop_back();
		}
		break;
	case 2:
		//****************柱列函式******************
		cout << "How many number you want to push ? ";
		cin >> number;
		cout << endl << "push" << endl;
		for (unsigned int i = 0; i < number; i++)
		{
			cout << "Step " << i << " : ";
			cin >> input;
			QE.push(input);
			size++;
		}

		cout << endl << "POP" << endl;
		for (int i = 0; i <= size; i++)
		{
			cout << "Step " << count++ << " : " << QE.front() << endl;
			QE.pop();
		}
	
	break;

	case 3:
		cout << "a : ";
		cin >> temp_a;
		cout << "b : ";
		cin>> temp_b;
		for (int i = 0; i < temp_a.size(); i++)
		{
			a.push_back(temp_a[i]);
			add.push_back(temp_a[i]);
			sizeofa++;
		}

		for (int i = 0; i < temp_b.size(); i++)
		{
			b.push_back(temp_b[i]);
			sizeofb++;
		}
		//************a + b**************
		for (int i = 0; i < sizeofb; i++)
		{
			add.push_back(b[0]);
			b.pop_front();

		}
		cout << "c = a + b = ";
		for (int i = 0; i < add.size(); i++)
		{
			cout << add[i];
		}
		cout << endl;

		//************a - b**************
		cout << "d = a - b = ";
		for (int i = 0; i < sizeofa; i++) 
		{
			if (a[i] != temp_b[same])
			{
				for (int j = i-same; j <= i; j++)   
				{
					sub.push_back(a[j]);
				}
				same = 0;
			}
			else if (same < sizeofb - 1)    //deque[i] i從0開始 size會多1
			{
				same++;
			}
			else                         //a字串中有b
			{
				same = 0;
			}
		}

		
		for (int i = 0; i < sub.size(); i++)
		{
			cout << sub[i];
		}
		cout << endl;

		break;
	default:
		cout << "error" << endl;
		break;
	}
	system("pause");
	return 0;

}