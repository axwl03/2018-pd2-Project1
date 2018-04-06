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
    int i, j, k, m, n;	//for reading numbers
    char card[4], ch, dscdc;	//dscd dscdc: discard
    srand((unsigned)time(NULL));
//	cout << "9 4 3 6 2 C 7 8\n";	//initializing
//	cout <<	"9 4 3 6 2 1 7 8\n";
    cout << "7 4 6 2 9 C 1 5\n";
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
            while(1) {
                cin >> str;
                if(str != "TOWER")
                    break;
                cin >> i >> j;
            }
        }
        if(str == "FRIEND" || str == "ENEMY") {	//FRIEND or ENEMY
            while( str != "END") {
                if(str == "FRIEND") {
                    cin >> ch >> dscd >> i >> dscdc >> j >> dscd >> k;
                    if(m < 30)
                        AI.setFRIEND(ch, i, j, m);
                    m++;
                }          //(i, j): position, k: hp, m or n: count
                if(str == "ENEMY") {
                    cin >> ch >> dscd >> i >> dscdc >> j >> dscd >> k;
                    if(n < 30)
                        AI.setENEMY(ch, i, j, n);
                    n++;
                }
                cin >> str;
            }
        }
        if(str == "END") {
            AI.Summon();
            cout << "0\n";	//terminates
            AI.cleanARRAY();

        }
    }

    return 0;
}
