#include<iostream>
#include<time.h>
#include <windows.h>

using namespace std;

class Organism 
{
    public:
		int HP;
		int MP;
		bool dead;
	void atked(int atked) {
		
		if (HP - atked > 0) 
		{ 
			HP -= atked;
			dead = 0;
		}
		else 
		{
			HP = 0;
			dead = 1;
		}
	}
    
};

class Summoner : public Organism 
{
    public:
		int maxatk;
		
		void Create(int Shp,int Smp,int Satk) 
		{
			HP = Shp;
			MP = Smp;
			maxatk = Satk;
			dead = 0;
		}


};


class Monster: public Organism
{
    public:
		int maxatk;
		int atk;

		void Create(int Mhp, int Mmp, int Matk)
		{
			HP = Mhp;
			MP = Mmp;
			maxatk = Matk;
			dead = 0;
		}
};
int main() {

	srand(time(NULL));

	int Shp, Smp, Satk,sa; //�D��
	int Mhp, Mmp, Matk,ma; //���~
	int count = 0;      //�^�X
	cout << "��J�����O�ƭ�" << endl;
	cin >> Shp >> Smp >> Satk;
	Summoner smr;
	cout << "��J���~��O�ƭ�" << endl;
	cin >> Mhp >> Mmp >> Matk;
	Monster mstr;

	smr.Create(Shp, Smp, Satk);
	mstr.Create(Mhp, Mmp, Matk);
	

	while (smr.dead == 0 && mstr.dead == 0) //�s��
	{
		count++;
		sa = rand() % Satk + 1;
		ma = rand() % Matk + 1;
		smr.atked(ma);   //�����ƭ�
		mstr.atked(sa);

		Sleep(1000);

		cout << "#" << count << endl;
		cout << "Summoner hurt Monster  " << sa << " HP" << endl;
		cout << "Monster hurt Summoner " << ma << " HP" << endl;
		if (smr.HP == 0)
		{
			cout << "Summoner Died" << endl;
		}
		else
		{
			cout << "Summoner HP is  " << smr.HP << endl;
		}
		if (mstr.HP == 0)
		{
			cout << "Monster Died." << endl;
		}
		else
		{
			cout << "Monster HP is  " << mstr.HP << endl;
		}
		cout << endl << endl;
		
	}

	system("pause");

	return 0; 
}