#include<iostream>
using namespace std;
int main() {
	int i,outemp;
	float input, accuracy;
	while (1) {
		cin >> input >> accuracy;
		for (i = 1; i < 1001; i *= 10) {          //先找出精確度
			input *= 10;
			if (accuracy*i == 1)break;
		}
		switch (i){
	     	case 1:	
			    outemp = (int)input;
				if (outemp % 10 < 5)cout << outemp / 10 << endl;
				else cout << outemp / 10 + 1 << endl;
				break;

			case 10:
				outemp = (int)input;
				if (outemp % 10 < 5) {
					outemp = outemp / 10;
					cout << (float)outemp / 10 << endl;
				}
				else {
					outemp = outemp / 10+1;
					cout << (float)outemp/10 << endl;
				}
				break;

			case 100:
				outemp = (int)input;
				if (outemp % 10 < 5) {
					outemp = outemp / 10;
					cout << (float)outemp / 100 << endl;
				}
				else {
					outemp = outemp / 10 + 1;
					cout << (float)outemp / 100 << endl;
				}
				break;

			case 1000:
				outemp = (int)input;
				if (outemp % 10 < 5) {
					outemp = outemp / 10;
					cout << (float)outemp / 1000 << endl;
				}
				else {
					outemp = outemp / 10 + 1;
					cout << (float)outemp / 1000 << endl;
				}
				break;
     		default:
	    		cout << "error" << endl;
		}
	}


	system("pause");
	return 0;
}