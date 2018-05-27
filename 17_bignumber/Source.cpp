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
	cout << "��J�B��Ÿ����ӼƦr : ";
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

	//***************���k���k���ɹs******************

	//���kanswer�j�p
	if (sign == '*')
	{
		sizeofanswer = sizeofa + sizeofb + 1;//�T���*�T��Ƴ̦h����� 
		for (int i = 0; i < sizeofb; i++)    //�Q��ƶ}�l�ɹs
		{
			answer.push_back(0);
		}
		for (int i = 0; i <= sizeofa; i++)
		{
			answer.push_back(a[i]);
		}
		b[sizeofb] -= 1;                      //�̰��줸-1
		answer.push_back(0);                  //���i�෸���̰��줸
	
	}
	else if (sign != '/')
	{
		//�ɹs
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
	//��k ���t��
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
		//�i��
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
		//����
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
		//�ɦ�
		for (int i = 0; i < sizeofanswer; i++)
		{
			//�ݭn�ɦ�
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
		//�v�B�[�_��
		for (int i = 0; i <= sizeofa; i++)
		{
			for (int j = 0; j <= sizeofb; j++) 
			{
				answer[i + j] += a[i] * b[j];
			}
		}


		//�i��
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
		//���k�Aa b�e���ɹs�A����k
	case '/':
		//�ɹs
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
			count = 0; div = 0,comp = 0;                  //count���ơAdiv�P�_�O�_�����Acomp�P�_�ثe���
			while (div==0)
			{
				for (int j = 0; j <= sizeofb; j++)   //��k
				{
					div_a[i + j] -= div_b[j];
				}
				count++;
				for (int j = 0; j <= sizeofb; j++)   //�P�_�ɦ�
				{
					if (div_a[i + j] == 0) continue;      //����
					else if (div_a[i + j] > 0)            //�i�ɦ�
					{
						comp = 0;
						break;
					}
					else                              //�̤j��Ƥp��s ���i�ɦ�
					{
						comp = 1;
						break;
					}
					
				}
				if (comp == 0)                        //�ɦ�
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
				else if (comp == 1)              //�{�b��b>a�A�[�^�h�A���U�@���
				{
					for (int j = 0; j <= sizeofb; j++)   //�[�k
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

	//���h�e�����s
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