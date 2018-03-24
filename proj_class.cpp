#include "proj_class.h"
void organizer::setTIME(int i){
	TIME = i;
}
void organizer::setMANA(int i){
	MANA = i;
}
void organizer::setDECK(char a[]){
	int i;
	for(i = 0; i < 4; i++)
		card[i] = a[i];
}
void organizer::setTOWER(int i, int j){
	TOWER[0][i-1] = i;
	TOWER[1][i-1] = j;	
	//not yet done, probably contain problems
}
void organizer::setFRIEND(char ch, int i, int j, int k, int m){ 
	FRIEND[0][m] = ch;
	FRIEND[1][m] = i;
	FRIEND[2][m] = j;
	FRIEND[3][m] = k;
}
void organizer::setENEMY(char ch, int i, int j, int k, int n){
	ENEMY[0][n] = ch;
	ENEMY[1][n] = i;
	ENEMY[2][n] = j;
	ENEMY[3][n] = k;
}
void organizer::summon(void){
	int i;
	
	for(i = 0; i < 4; i++){
		if(card[i] == 'C' && MANA > 7){
			cout << "1 C 5 15\n";
			MANA -= 7;
		}
		if(card[i] == '1' && MANA > 5){
			cout << "1 1 15 15\n";
			MANA -= 5;
		}
		if(card[i] == '6' && MANA > 4){
			cout << "1 6 5 15\n";
			MANA -= 4;
		}
		if(card[i] == '2' && MANA > 3){
			cout << "1 2 15 15\n";
			MANA -= 3;
		}
		if(card[i] == '3'&& MANA > 2){
			cout << "1 3 5 15\n";
			MANA -= 2;
		}
		if(card[i] == '9' && MANA > 3){
			cout << "1 9 15 15\n";
			MANA -= 3;
		}
		if(card[i] == '4' && MANA > 6){
			cout << "1 4 5 15\n";
			MANA -= 6;
		}
		if(card[i] == '8' && MANA > 5){
			cout << "1 8 15 15\n";
			MANA -= 5;
		}
	}
}
void organizer::getDATA(void){
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
	cout << ' ' << FRIEND[0][1] << ' ' << FRIEND[1][1] << ' '<<FRIEND[2][1] << ' ' << FRIEND[3][1] << endl;
	cout << endl << "***" << endl;
}
void organizer::cleanARRAY(void){
	int *p = &TOWER[0][0];
	for(; p <= &TOWER[1][5]; p++)
		*p = 0;
	for(p = &FRIEND[0][0]; p <= &FRIEND[3][7]; p++)
		*p = 0;
	for(p = &ENEMY[0][0]; p <= &ENEMY[3][7]; p++)
		*p = 0;
}
