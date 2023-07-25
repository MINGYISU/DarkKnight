#include "Player.h"
using namespace std;

Player::Player(int mhp, int a, int d, int c, PotEffect *p):
    Maxhp{mhp}, atk{a}, def{d} {
        CurHp = Maxhp;
        CurEffect = new Water;
    }

void Player::drinkPot(string PotType) {
    if (PotType == "RH") {
        CurHp += 10;//1 restore health
    } else if (PotType == "PH") {
        CurHp -= 10;//2 poision health
    } else if (PotType == "BA") {
        CurEffect = new BA{CurEffect};//3 boost atk
    } else if (PotType == "WA") {
        CurEffect = new WA{CurEffect};//4 wound atk
    } else if (PotType == "BD") {
        CurEffect = new BD{CurEffect};//5 boost def
    } else if (PotType == "WD") {
        CurEffect = new WD{CurEffect};//6 wound def
    }
}

Player::~Player() {
    delete CurEffect;
}
