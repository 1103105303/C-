#include<iostream>
#include<string>
using namespace std;

struct Score_system
{
	string name;
	string number;
	int score;
	Score_system* next;
	Score_system* pre;
};
int main() {

	string name;
	string number;
	int i, input, score, first = 0, count = 0;
	Score_system* head = new Score_system();
	Score_system* current = head;
	Score_system* follow;
	Score_system* temp;
	Score_system* temp2;



	while (1) {

		cout << " === Add(0) / Delete(1) / Show(2) === " << endl;
		cout << "Function you want :  " ;
		cin >> input;

		switch (input)
		{
		case 0:
			if (first == 0) {
				cin >> name >> number >> score;

				head->name = name;
				head->number = number;
				head->score = score;

				head->next = NULL;
				head->pre = NULL;

				first++;
				count++;
			}
			else {
				cin >> name >> number >> score;

				current->next = new Score_system();
				follow = current;
				current = current->next;

				current->name = name;
				current->number = number;
				current->score = score;

				current->next = NULL;
				current->pre = follow;
				count++;
			}
			break;

		case 1:
			cout << "Which do you want to delete : ";
			cin >> input;


			if (input > count)cout << "error" << endl;
			else {
				if (input == 1) {              //�h�Y
					follow = head;
					if (follow->next == NULL)free(head);     //�R���̫�@��
					else {
						temp = head->next;
						free(head);
						head = temp;
						head->pre = NULL;
					}

				}
				else if (input == count) {     //�h��
					follow = head;
					for (i = 1; i < input; i++) {
						follow = follow->next;
					}
					temp = follow->pre;
					free(follow);
					temp->next = NULL;
				
				}
				else {
					follow = head;
					for (i = 1; i < input; i++) { 
						follow = follow->next;
					}
					temp = follow->pre; //�O�sPre; 
					temp2 = follow -> next;//�O�snext
					free( follow);
					temp->next = temp2;
					temp2->pre = temp;
				}
				count--;
			}

			break;

		case 2:
			follow = head;
			for (i = 1; i < count + 1; i++) {
				cout <<i<<"=> "<< follow->name << " " << follow->number << " " << follow->score << endl;
				if(follow->next!=NULL) follow = follow->next;
			
			}

			break;

		default:
			cout << "error" << endl;
			break;
		}


	}


	system("pause");

}