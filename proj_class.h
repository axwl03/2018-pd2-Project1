#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class organizer {
  public:
    void setTIME(int i);
    void setMANA(int i);
    void setDECK(char a[]);
    void setTOWER(int i, int j);
    void setFRIEND(char ch, int i, int j, int k, int m);
    void setENEMY(char ch, int i, int j, int k, int n);
    void position(void);
    void summonP(void);
    void summon(void);
    void getDATA(void);
    void cleanARRAY(void);
  private:
    int TIME, MANA, TOWER[2][6], FRIEND[4][20], ENEMY[4][20], list[2][10];
    char card[4];

};


