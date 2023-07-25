#ifndef PLAYER_H
#define PLAYER_H
//#include "Character.h"
#include "PotEffect.h"
#include "PotDeco.h"
#include "Water.h"
#include "BA.h"
#include "WA.h"
#include "BD.h"
#include "WD.h"
#include <string>
using namespace std;

class Player {
    public:
    int Maxhp, atk, def, CurHp;
    PotEffect *CurEffect;
    public:
    Player(int mhp, int a, int d, int c = 0, PotEffect *p = nullptr);
    void drinkPot(string PotType);
    ~Player();
};

#endif
