#include <iostream>
#include <cstdio>
#include <string>
#include "proj_class.h"
using namespace std;

int main(void)
{
	organizer AI;
	string str, dscd;
	int i, j, k, m, n;
	char card[4], ch, dscdc;
	cout << "1 2 3 6 9 C 4 8\n";
	for(;;){
		m = 0;
		n = 0;
		cin >> str;
		if(str == "BEGIN"){
			AI.cleanARRAY();
			continue;
		}
		if(str == "TIME"){
			cin >> i;
			AI.setTIME(i);
		}
		if(str == "MANA"){
			cin >> i;
			AI.setMANA(i);
		}
		if(str == "DECK"){
			cin >> card[0] >> card[1] >> card[2] >> card[3];
			AI.setDECK(card);     
		}
		if(str == "TOWER"){
			cin >> i >> j;	//i: TOWER id, j: TOWER hp
			AI.setTOWER(i, j);
			while(1){
				cin >> str;
				if(str != "TOWER")
					break;
				cin >> i >> j;
				AI.setTOWER(i, j);
			}
		}
		if(str == "FRIEND" || str == "ENEMY"){
			while( str != "END"){
				if(str == "FRIEND"){
					cin >> ch >> dscd >> i >> dscdc >> j >> dscd >> k;
					AI.setFRIEND(ch, i, j, k, m);
					m++;
				}          //(i, j): position, k: hp, m or n: count
				if(str == "ENEMY"){
					cin >> ch >> dscd >> i >> dscdc >> j >> dscd >> k;
					AI.setENEMY(ch, i, j, k, n);
					n++;
				}cin >> str;
			}
		}
#ifdef DEBUG
	AI.getDATA();
#endif
		if(str == "END"){
			AI.summon();
			cout << "0\n";
			AI.cleanARRAY();
		}
			

	}

	return 0;
}
