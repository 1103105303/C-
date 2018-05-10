#include <iostream>
#include <string>
using namespace std;
struct number {
	int value;
	number* next;
};

int main() {
	int input;
	cout << "Please enter the number : ";
	cin >> input;
	number* head = new number();
	head->value = input;
	head->next = NULL;
	number* current = head;
	while (1) {
		cout << "Please enter the number : ";
		cin >> input;
		if (input == -1)break;

		current->next = new number();

		current = current->next;
		current->value = input;
		
		current->next = NULL;

	}
	current = head;
	while (1) {
		cout << current->value<<"  ";
		current = current->next;
		if (current == NULL)break;
	
	}
	cout << endl;
	system("pause");
	return 0;

}





