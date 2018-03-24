#include <iostream>
#include <string>
using namespace std;

class organizer{
	public:
		void setTIME(int i);
		void setMANA(int i);
		void setDECK(char a[]);
		void setTOWER(int i, int j);
		void setFRIEND(char ch, int i, int j, int k, int m);
		void setENEMY(char ch, int i, int j, int k, int n);
		void summon(void);
		void getDATA(void);
		void cleanARRAY(void);
	private:
		int TIME, MANA, TOWER[2][6], FRIEND[4][8], ENEMY[4][8];
		char card[4];

};
		
		
