#include<iostream>
#include<string>
using namespace std;

class number
{
   public:
	   string output="";

	   void change(string nr) 
	   {
		   output = "";

		   for (int i = 0; i < nr.size(); i++)
		   {
			   if (nr[i] == '1') { output += "one"; }
			   if (nr[i] == '2') { output += "two"; }
			   if (nr[i] == '3') { output += "three"; }
			   if (nr[i] == '4') { output += "four"; }
			   if (nr[i] == '5') { output += "five"; }
			   if (nr[i] == '6') { output += "six"; }
			   if (nr[i] == '7') { output += "seven"; }
			   if (nr[i] == '8') { output += "eight"; }
			   if (nr[i] == '9') { output += "nine"; }
		   }
	   }

	   void Separate(string al,int nr )
	   {
		   temp = nr;
		   output = "";
		   for (int i = 0; i < al.size(); i++) 
		   {
			   temp--;
			   if (temp > 0)
			   {
				   output += al[i];
			   }
			   else
			   {
				   output += al[i];
				   output+=' ';
				   temp = nr;
			   }
		   }

	   }

	   void mx(string sentence)
	   {
		   count = 0;
		   output = "";
		   for (int i = 0; i < sentence.size(); i++) 
		   {
			   if (sentence[i] == ' ' )
			   {
				   output += "[";
				   output += to_string(count);
				   output += "] ";
				   count = 0;
			   }
			   else 
			   {
				   output += sentence[i];
				   count++;
			   }
		   }
		   output += "[";                          //最後一個單字
		   output += to_string(count);
		   output += "] ";

	   }

   private:
	   int temp;
	   int count;
	
};

int main() 
{
	string input;
	int choice,nbr;
	number nr;

	while (1)
	{
		cout << "1、數字轉英文 2、分隔 3、數字母" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "輸入字串 ex:1234" << endl;
			cin >> input;
			nr.change(input);
			cout << nr.output << endl;
			break;
		case 2:
			cout << "輸入字串 ex aaabbbccc 2" << endl;
			cin >> input >> nbr;
			nr.Separate(input, nbr);
			cout << nr.output << endl;
			break;
		case 3:
			cout << "輸入字串 ex: A apple a day" << endl;
	
			cin.get();
			getline(cin, input);
			nr.mx(input);
			cout << nr.output << endl;
			break;
		default:
			cout << "error" << endl;
			break;
		}


	}
	system("pause");
	return 0;
}