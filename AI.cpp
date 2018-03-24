#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>
#include "proj_class.h"
using namespace std;

int main(void) {
    organizer AI;     //object
    string str, dscd;	//str: reading first word in each line
    int i, j, k, m, n, c = 0;	//for reading numbers
    char card[4], ch, dscdc;	//dscd dscdc: discard
    srand((unsigned)time(NULL));
//	cout << "9 4 3 6 2 C 7 8\n";	//initializing
//	cout <<	"9 4 3 6 2 1 7 8\n";
    cout << "9 4 3 6 2 1 7 5\n";
    for(;;) {
        m = 0;
        n = 0;
        cin >> str;
        if(str == "BEGIN") {	//BEGIN
            AI.cleanARRAY();
            continue;
        }
        if(str == "TIME") {	//TIME
            cin >> i;
            AI.setTIME(i);
        }
        if(str == "MANA") {
            cin >> i;
            AI.setMANA(i);	//MANA
        }
        if(str == "DECK") {	//DECK
            cin >> card[0] >> card[1] >> card[2] >> card[3];
            AI.setDECK(card);
        }
        if(str == "TOWER") {	//TOWER
            cin >> i >> j;	//i: TOWER id, j: TOWER hp
            AI.setTOWER(i, j);
            while(1) {
                cin >> str;
                if(str != "TOWER")
                    break;
                cin >> i >> j;
                AI.setTOWER(i, j);
            }
        }
        if(str == "FRIEND" || str == "ENEMY") {	//FRIEND or ENEMY
            while( str != "END") {
                if(str == "FRIEND") {
                    cin >> ch >> dscd >> i >> dscdc >> j >> dscd >> k;
                    AI.setFRIEND(ch, i, j, k, m);
                    m++;
                }          //(i, j): position, k: hp, m or n: count
                if(str == "ENEMY") {
                    cin >> ch >> dscd >> i >> dscdc >> j >> dscd >> k;
                    AI.setENEMY(ch, i, j, k, n);
                    n++;
                }
                cin >> str;
            }
        }
#ifdef DEBUG
        AI.getDATA();
#endif
        if(str == "END") {
            if(c < 100) {
                AI.summon();	//set summon list
                AI.position();	//set minion position and cout
            } else {
                AI.summonP();   //summon powerful minion
                AI.position();
                if(c > 130)
                    c = 0;
            }
            c++;
            cout << "0\n";	//terminates
            AI.cleanARRAY();

        }
    }

    return 0;
}
