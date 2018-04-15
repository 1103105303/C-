#include<iostream>
using namespace std;
int main() {
	while(1){
	int length, wide,out[100],i,count=1,total,choice;

	cin >> length >> wide;
	choice = 1;
	total = wide * length;
	for (i = 1; i <= total; i++) {
		out[i] = 0;
	}
	
	for (i = 1; i < wide; i++) {
		out[i] = count;
		count++;
	}
	for (i = wide; i <total; i += wide) {
		out[i] = count;
			count++;
	}
	for(i =wide*length;i>total-wide;i--)	{
		out[i] = count;
			count++;
	}
	for(i=wide*(length-2)+1;i>1;i-=wide){
		out[i] = count;
		count++;
	}
	i = wide+1;

	while (choice != 5)
	{
		if (out[i+1] != 0 && out[i-1] != 0 && out[i+wide] != 0 && out[i-wide] != 0)choice = 5;
		else {
			switch (choice)
			{
			case 1:if (out[i + 1] == 0) {
				i++;
				out[i] = count;
				count++;
				
			}
				   else choice = 2;
		    break;
			case 2:if (out[i + wide] == 0) {
				i += wide;
				out[i] = count;
				count++;
			}
				   else choice = 3;
		    break;
			case 3:if (out[i - 1] == 0) {
				i--;
				out[i] = count;
				count++;
			}
				   else choice = 4;
			break;
			case 4:if (out[i - wide] == 0) {
				i -= wide;
				out[i] = count;
				count++;
			}
				   else choice = 1;
			break;
			}

		}
	}
	for (int j = 1; j <= total; j++) {
		if (out[j] < 10)cout << "  " << out[j];
		else cout << " " << out[j];
		if (j%wide == 0)cout << endl;
	}




}}