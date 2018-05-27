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

	int Shp, Smp, Satk,sa; //主角
	int Mhp, Mmp, Matk,ma; //怪獸
	int count = 0;      //回合
	cout << "輸入角色能力數值" << endl;
	cin >> Shp >> Smp >> Satk;
	Summoner smr;
	cout << "輸入怪獸能力數值" << endl;
	cin >> Mhp >> Mmp >> Matk;
	Monster mstr;

	smr.Create(Shp, Smp, Satk);
	mstr.Create(Mhp, Mmp, Matk);
	

	while (smr.dead == 0 && mstr.dead == 0) //存活
	{
		count++;
		sa = rand() % Satk + 1;
		ma = rand() % Matk + 1;
		smr.atked(ma);   //攻擊數值
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