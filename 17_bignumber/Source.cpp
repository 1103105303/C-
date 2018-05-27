#include<iostream>
#include<string>
#include<deque>
using namespace std;		

int main() 
{
	char sign;
	int sizeofa = -1, sizeofb = -1, sizeofanswer = -1, temp, sub = 0, count;
	bool  zero = 0, div = 0, comp = 0;
	string input1, input2;
	deque<int> a, div_a;
	deque<int> b, div_b;
	deque<int>answer;
	cout << "块笲衡才腹蛤ㄢ计 : ";
	cin >> sign >> input1 >> input2;

	for (int i = 0; i < input1.size(); i++)
	{
		a.push_front((int)input1[i] - 48);
		sizeofa++;
	}

	for (int i = 0; i < input2.size(); i++)
	{
		b.push_front((int)input2[i] - 48);
		sizeofb++;
	}

	//***************埃猭猭ぃ干箂******************

	//猭answer
	if (sign == '*')
	{
		sizeofanswer = sizeofa + sizeofb + 1;//计*计程せ计 
		for (int i = 0; i < sizeofb; i++)    //计秨﹍干箂
		{
			answer.push_back(0);
		}
		for (int i = 0; i <= sizeofa; i++)
		{
			answer.push_back(a[i]);
		}
		b[sizeofb] -= 1;                      //程蔼じ-1
		answer.push_back(0);                  //Τ犯程蔼じ
	
	}
	else if (sign != '/')
	{
		//干箂
		//************ a > b ************
		if (sizeofa > sizeofb)
		{
			for (int i = 0; i < sizeofa - sizeofb; i++)
			{
				b.push_back(0);
			}
			sizeofb = sizeofa;
		}
		//************* a < b ***********
		else
		{
			for (int i = 0; i < sizeofb - sizeofa; i++)
			{
				a.push_back(0);
			}
			sizeofa = sizeofb;
		}
		sizeofanswer = sizeofa;
	}
	//搭猭 タ璽腹
	if (sign == '-')
	{
		for (int i = sizeofanswer; i >= 0; i--)
		{
			if (b[i] > a[i])
			{
				sub = -1;
				break;
			}
			else if (b[i] < a[i])break;

		}
	}
	switch (sign)
	{
	case '+':
		for (int i = 0; i <= sizeofa; i++) 
		{
			answer.push_back(a[i] + b[i]);
		}
		//秈
		for (int i = 0; i < sizeofanswer; i++)
		{
			if (answer[i] > 9)
			{
				temp = answer[i] / 10;
				answer[i] -= temp * 10;
				answer[i + 1] += temp;
			}
			else 
			{
				continue;
			}
		}
		//犯
		if (answer[sizeofanswer] > 9)
		{
			temp = answer[sizeofanswer] / 10;
			answer[sizeofanswer] -= temp * 10;
			answer.push_back(temp);
			sizeofanswer++;
		}
		break;

	case '-':
		//************** b < a ******************
		if (sub == -1)
		{
			for (int i = 0; i <= sizeofa; i++)
			{
				answer.push_back(b[i] - a[i]);
			}
		}
		//************** a < b ******************
		else
		{
			for (int i = 0; i <= sizeofa; i++)
			{
				answer.push_back(a[i] - b[i]);
			}
		}
		//
		for (int i = 0; i < sizeofanswer; i++)
		{
			//惠璶
			if (answer[i] < 0)
			{
				temp = answer[i] / -10;
				if (answer[i] + temp * 10 == 0) 
				{
					answer[i + 1] -= temp;
					answer[i] += temp * 10;
				}
				else
				{
					temp++;
					answer[i + 1] -= temp;;
					answer[i] += temp * 10;
				}
			}
			else
			{
				continue;
			}
		}


		break;
	case '*':
		//硋˙癬ㄓ
		for (int i = 0; i <= sizeofa; i++)
		{
			for (int j = 0; j <= sizeofb; j++) 
			{
				answer[i + j] += a[i] * b[j];
			}
		}


		//秈
		for (int i = 0; i <= sizeofanswer; i++)
		{
			if (answer[i] > 9)
			{
				temp = answer[i] / 10;
				answer[i] -= temp * 10;
				answer[i + 1] += temp;
			}
			else
			{
				continue;
			}
		}
		
	

		break;
		//埃猭a b玡干箂暗搭猭
	case '/':
		//干箂
		for (int i = 0; i <= sizeofa; i++) 
		{
			div_a.push_front(a[i]);
		}
		for (int i = 0; i <= sizeofb; i++)
		{
			div_b.push_front(b[i]);
		}	
		div_a.push_front(0);
		sizeofa++;
		div_b.push_front(0);
		sizeofb++;

		for (int i = 0; i <= sizeofa - sizeofb; i++) 
		{
			count = 0; div = 0,comp = 0;                  //count埃计div耞琌挡comp耞ヘ玡计
			while (div==0)
			{
				for (int j = 0; j <= sizeofb; j++)   //搭猭
				{
					div_a[i + j] -= div_b[j];
				}
				count++;
				for (int j = 0; j <= sizeofb; j++)   //耞
				{
					if (div_a[i + j] == 0) continue;      //ゼ
					else if (div_a[i + j] > 0)            //
					{
						comp = 0;
						break;
					}
					else                              //程计箂 ぃ
					{
						comp = 1;
						break;
					}
					
				}
				if (comp == 0)                        //
				{
					for (int j = sizeofb; j > 0; j--)  
					{
						if (div_a[i + j] < 0)
						{
							div_a[i + j - 1] -= 1;
							div_a[i + j] += 10;
						}

					}
				}
				else if (comp == 1)              //瞷b>a传计
				{
					for (int j = 0; j <= sizeofb; j++)   //猭
					{
						div_a[i + j] += div_b[j];
					}
					count--;
					div = 1;
				}
				else if (count == 9)
				{
					div = 1;
				}
			}
			answer.push_front(count);
			sizeofanswer++;
		}

		break;
	default:
		cout << "error" << endl;
		break;
	}



	if (sub == -1 && sign == '-') 
	{
		cout << "-";
	}

	//玡箂
	temp = sizeofanswer;
	if (sign != '+')
	{
		while (!zero)
		{
			for (int i = temp; i >= 0; i--)
			{
				if (answer[i] == 0)
				{
					answer.pop_back();
					sizeofanswer--;
				}
				else
				{
					zero++;
					break;
				}
			}
		}
	}

	for (int i = sizeofanswer; i >= 0; i--)
	{
		cout << answer[i] << " ";
	}



	system("pause");
	return 0;
}