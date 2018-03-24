#include "proj_class.h"
void organizer::setTIME(int i) {
    TIME = i;
}
void organizer::setMANA(int i) {
    MANA = i;
}
void organizer::setDECK(char a[]) {
    int i;
    for(i = 0; i < 4; i++)
        card[i] = a[i];
}
void organizer::setTOWER(int i, int j) {
    TOWER[0][i-1] = i;
    TOWER[1][i-1] = j;
}
void organizer::setFRIEND(char ch, int i, int j, int k, int m) {
    FRIEND[0][m] = ch;
    FRIEND[1][m] = i;
    FRIEND[2][m] = j;
    FRIEND[3][m] = k;
}
void organizer::setENEMY(char ch, int i, int j, int k, int n) {
    ENEMY[0][n] = ch;
    ENEMY[1][n] = i;
    ENEMY[2][n] = j;
    ENEMY[3][n] = k;
}
void organizer::position(void) {
    int i, n, record = 0, j;
    for(i = 0; i < 10; i++) { //determine how many position to generate
        if(list[0][i] == 0)
            break;//If no summon slot left, break
        for(j = 0; j < 20; j++) { //deal with enemy closed to castle
            if(ENEMY[0][j] == 0)
                break;
            if(ENEMY[2][j] < 24) {
                n = ENEMY[2][j] - 11;
                n = rand() % n + 11;
                if(ENEMY[1][j] < 11) {
                    cout << "1 " << (char)list[1][i] <<' ' <<(ENEMY[1][j]+rand()%4+1) << ' '<< n << '\n';//summon between enemy and castle
                    record = 1; //record executing cout
                    break;
                } else if(ENEMY[1][j] >= 11) {
                    cout << "1 " << (char)list[1][i] <<' ' <<(ENEMY[1][j]-rand()%4-1) << ' '<< n << '\n';
                    record = 1;
                    break;
                }
            }
        }
        if(record == 0) {	//generate random position
            if(rand() % 2 == 0)
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
        if(card[i] == '5' && MANA >= 1 && FRIEND[0][4] != 0) {
            c++;
            list[0][c-1] = c;
            list[1][c-1] = '5';
            MANA -= 1;
        }
    }
}
void organizer::getDATA(void) {
    cout << "*****"<< endl << TIME << endl;
    cout << MANA << endl;
    int i;
    for(i = 0; i < 4; i++)
        cout << card[i];
    cout << endl;
    for(i = 0; i < 6; i++)
        cout << TOWER[0][i] << ' ';
    cout << endl;
    for(i = 0; i < 6; i++)
        cout << TOWER[1][i] << ' ';
    cout << endl;
    cout << FRIEND[0][1] << ' ' << FRIEND[1][1] << ' '<<FRIEND[2][1] << ' ' << FRIEND[3][1] << endl;
    for(i = 0; i < 10; i++)
        cout << list[0][i] << ' ';
    cout << endl;
    for(i = 0; i < 10; i++)
        cout << (char)list[1][i] << ' ';
    cout << endl;
    cout << endl << "***" << endl;
}
void organizer::cleanARRAY(void) {
    int *p = &TOWER[0][0];
    for(; p <= &TOWER[1][5]; p++)
        *p = 0;
    for(p = &FRIEND[0][0]; p <= &FRIEND[3][19]; p++)
        *p = 0;
    for(p = &ENEMY[0][0]; p <= &ENEMY[3][19]; p++)
        *p = 0;
    for(p = &list[0][0]; p <= &list[1][9]; p++)
        *p = 0;
}
