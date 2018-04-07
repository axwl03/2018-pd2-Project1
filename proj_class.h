#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class organizer {
  public:
    void setMANA(int i);
    void setDECK(char a[]);
    void setFRIEND(char ch, int i, int j, int m);
    void setENEMY(char ch, int i, int j, int n);
    void position(void);
    void Summon(void);
    void cleanARRAY(void);
  private:
    int TIME, MANA, FRIEND[3][30], ENEMY[3][30];
    char card[4];
};


