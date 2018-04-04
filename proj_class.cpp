#include "proj_class.h"
void organizer::setMANA(int i) {
    MANA = i;
}
void organizer::setDECK(char a[]) {
    int i;
    for(i = 0; i < 4; i++)
        card[i] = a[i];
}
void organizer::setFRIEND(char ch, int i, int j, int m) {
    FRIEND[0][m] = ch;
    FRIEND[1][m] = i;
    FRIEND[2][m] = j;
}
void organizer::setENEMY(char ch, int i, int j, int n) {
    ENEMY[0][n] = ch;
    ENEMY[1][n] = i;
    ENEMY[2][n] = j;
}
void organizer::position(void) {
    int i, n, record = 0, j, f1 = 0, f2 = 0, e1 = 0, e2 = 0;
    for(i = 0; i < 30; i++) {
        if(ENEMY[0][i] != 0 && ENEMY[1][i] < 11)
            e1++;	//count the number of ENEMY in x<11
        if(ENEMY[0][i] != 0 && ENEMY[1][i] >= 11)
            e2++;	//count the number of ENEMY in x>=11
        if(FRIEND[0][i] != 0 && FRIEND[1][i] < 11 && FRIEND[2][j] > 11)
            f1++;	//count the number of FRIEND in x<11
        if(FRIEND[0][i] != 0 && FRIEND[1][i] >= 11 && FRIEND[2][j] > 11)
            f2++;	//count the number of FRIEND in x>=11
    }
    for(i = 0; i < 20; i++) { //determine how many position to generate
        if(list[0][i] == 0)
            break;//If no summon slot left, break

        if(list[1][i] == '9') { //put 9 in the front
            cout << "1 " << (char)list[1][i] <<' ' <<(rand()%20+1) << ' '<<(rand()%4+20) << '\n';
            break;
        }

        for(j = 0; j < 30; j++) { //deal with enemy closed to castle
            if(ENEMY[0][j] == 0)
                break;
            if(ENEMY[2][j] < 24) {
                n = ENEMY[2][j] - 11;
                n = rand() % n + 11;
                if(e1 - f1 > e2 - f2) {
                    cout << "1 " << (char)list[1][i] <<' ' <<(ENEMY[1][j]+rand()%4+1) << ' '<< n << '\n';//summon between enemy and castle
                    record = 1; //record executing cout
                    break;
                } else if(e1 -f1 <= e2 -f2) {
                    cout << "1 " << (char)list[1][i] <<' ' <<(ENEMY[1][j]-rand()%4-1) << ' '<< n << '\n';
                    record = 1;
                    break;
                }
            }
        }
        if(record == 0) {	//generate random position
            if(e1 - f1 > e2 - f2)
                cout << "1 " << (char)list[1][i] << ' ' << (rand()%6+3)<< ' ' << (rand()%13+11) << '\n';
            else cout << "1 " << (char)list[1][i] << ' ' << (rand()%6+13)<< ' ' << (rand()%13+11) << '\n';
        }
    }
}
void organizer::summonP(void) {
    int i, c = 0;
    for(i = 0; i < 4 ; i++) {
        if(card[i] == '7' && MANA >= 8) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '7';
            MANA -= 8;
        }
        if(card[i] == 'C' && MANA >= 7) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = 'C';
            MANA -= 7;
        }
        if(card[i] == '4' && MANA >= 6) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '4';
            MANA -= 6;
        }
    }
}
void organizer::summon(void) {
    int i, c = 0;
    for(i = 0; i < 4; i++) {
        if(card[i] == '1' && MANA >= 5) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '1';
            MANA -= 5;
        }
        if(card[i] == '6' && MANA >= 4) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '6';
            MANA -= 4;
        }
        if(card[i] == '2' && MANA >= 3 && FRIEND[0][3] != 0) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '2';
            MANA -= 3;
        }
        if(card[i] == '3'&& MANA >= 2) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '3';
            MANA -= 2;
        }
        if(card[i] == '9' && MANA >= 3) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '9';
            MANA -= 3;
        }
        if(card[i] == '8' && MANA >= 5 && FRIEND[0][5] != 0) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '8';
            MANA -= 5;
        }
        if(card[i] == '5' && MANA >= 1) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '5';
            MANA -= 1;
        }
    }
}
void organizer::cleanARRAY(void) {
    int *p;
    for(p = &FRIEND[0][0]; p <= &FRIEND[2][29]; p++)
        *p = 0;
    for(p = &ENEMY[0][0]; p <= &ENEMY[2][29]; p++)
        *p = 0;
    for(p = &list[0][0]; p <= &list[1][19]; p++)
        *p = 0;
}
