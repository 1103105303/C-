#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct fraction {

private:
	int num; //だ
	int den; //だダ

public:
	fraction(int input1, int input2) 
	{
		num = input1;
		den = input2;
	}

	fraction(int mixedF, int input1, int input2)
	{
		if (mixedF < 0)    //盿だ计璽 
		{
			num = mixedF * input2 - input1;
		}
		else               //盿だ计タ
		{
			num = mixedF * input2 + input1;
		}
		den = input2;

	}

	operator int() //int
	{
		return this->num / this->den;
	}

	operator double() //double
	{
		return (static_cast<double>(this->num) / static_cast<double>(this->den));
		
	}

	operator float() //float
	{
		return (static_cast<float>(this->num) / static_cast<float>(this->den));
	}

	friend ostream& operator <<(ostream& out, const fraction& number);

};

ostream &operator<<(ostream & out, fraction& number)
{
	out << "int = " << int(number);
	out << " float = " << fixed << setprecision(5) << float(number);
	out << " double = " << fixed << setprecision(5) << double(number) << endl;
	return out;
}


void main() {
	int  mixedF, input1, input2, temp[3], count, neg;
	string str,stemp;
	while (1) {
	    count = temp[0] = temp[1] = temp[2] = 0;
		neg = 1;
		cin >>str;
		for (int i = 0; i < str.size(); i++) 
		{
			if (str[i] == '-')neg = -1;//璽腹
			if (str[i] >= '0' && str[i] < '9') 
			{
				stemp = str[i];
				temp[count] = temp[count] * 10 + stoi(stemp);
		    }
			else if (str[i] == ',') 
			{
				temp[count] *= neg;
				count++;
				neg = 1;
			}
		
		}
		if (temp[2] == 0)     //獶盿だ计
		{
			input1 = temp[0];
			input2 = temp[1];
		}
		else                  //盿だ计
		{
			mixedF = temp[0];
			input1 = temp[1];
			input2 = temp[2];
		}
		fraction frac(mixedF, input1, input2);
		cout << frac;
	}


}
