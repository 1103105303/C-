#include<iostream>
#include<sstream>
#include<string>

using namespace std;

string add(string S1, string S2)
{
	int temp1, temp2;
	string Result;
	istringstream is(S1);
	is >> temp1;

	istringstream ss(S2);
	ss >> temp2;

	ostringstream convert;
	convert << temp1 + temp2;
	Result = convert.str();

	return Result;

}


bool comp(string S1, string S2)
{
	int temp1, temp2;
	istringstream is(S1);
	is >> temp1;

	istringstream ss(S2);
	ss >> temp2;

	if (temp1 > temp2) return true;
	else               return false;

}

int search(char c1, string S2) 
{
	int i;
	for ( i = 0; i <= S2.size(); i++)
	{
		if (c1 == S2[i])
		return i;
	}

}



int main() 
{
	string input_NR, input_AL, swap, alpht;
	string humffman[6][3]; // 0字母 1數值 2編碼
	int now;

	cout << "連續輸入六個字母及其數值" << endl;
	for (int i = 0; i < 6; i++)
	{
		cin >> input_AL >> input_NR;
		humffman[i][0] = input_AL;
		humffman[i][1] = input_NR;
	}

	for (int i = 0; i < 6 - 1; i++)
	{
		for (int j = 0; j < 6 - i - 1; j++)
		{
			if (comp(humffman[j][1] , humffman[j + 1][1])) 
			{
				input_AL = humffman[j][0];
				input_NR = humffman[j][1];

				humffman[j][0] = humffman[j + 1][0];
				humffman[j][1] = humffman[j + 1][1];

				humffman[j + 1][0] = input_AL;
				humffman[j + 1][1] = input_NR;
			}
		}
	}
	for (int i = 0; i < 6 ; i++)
	{
		alpht += humffman[i][0];
	}


	// 最開始將最小的兩個相加


	humffman[1][0] += humffman[0][0]; //累計樹

	humffman[1][1] = add(humffman[1][1], humffman[0][1]); 

	humffman[0][2] += '0';            //左邊0
	humffman[1][2] += '1';            //右邊1


	for (int i = 1; i < 6 - 1; i++)
	{
		//整理排列
		for (int j = i; j < 6 - 1; j++)
		{
			for (int k = i; k < 6 -1 ;k++)
			{
				if (comp(humffman[k][1], humffman[k + 1][1]))
				{
					input_AL = humffman[k][0];
					input_NR = humffman[k][1];

					humffman[k][0] = humffman[k + 1][0];
					humffman[k][1] = humffman[k + 1][1];

					humffman[k + 1][0] = input_AL;
					humffman[k + 1][1] = input_NR;
				}
			}
		}
		//最小兩個相加
		//先建0 1
		for (int j = 0; j < humffman[i][0].size(); j++) 
		{
			now = search(humffman[i][0][j], alpht);
			humffman[now][2] += '0';

		}

		for (int j = 0; j < humffman[i + 1][0].size(); j++) 
		{
			now = search(humffman[i + 1][0][j], alpht);
			humffman[now][2] += '1';
		}

		humffman[i + 1][0] += humffman[i][0]; //累計樹
		humffman[i + 1][1] = add(humffman[i + 1][1], humffman[i][1]);


	}


	for (int i = 0; i < 6; i++) 
	{
		humffman[i][0] = alpht[i];
	}




	//按照字母排序
	for (int i = 0; i < 6 - 1; i++)
	{
		for (int j = 0; j < 6 - i - 1; j++)
		{
			if (humffman[j][0]>humffman[j+1][0])
			{
				input_AL = humffman[j][0];
				input_NR = humffman[j][1];
				swap = humffman[j][2];

				humffman[j][0] = humffman[j + 1][0];
				humffman[j][1] = humffman[j + 1][1];
				humffman[j][2] = humffman[j + 1][2];

				humffman[j + 1][0] = input_AL;
				humffman[j + 1][1] = input_NR;
				humffman[j + 1][2] = swap;
			}
		}
	}


	//顯示要倒著顯示
	for (int i = 0; i < 6; i++)
	{
		cout << humffman[i][0] << " : ";
		for (int j = humffman[i][2].size() - 1; j >= 0; j--)
		{
			cout << humffman[i][2][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}