#include "player.h"

Player::Player(Map *p, int x, int y,
               int cur_hp, int atk, int def,
               int max_hp) : 
               Character{p, x, y, cur_hp, atk, def},
               max_hp{max_hp} 
               {}

char Player::charAt(int x, int y) {
    if((x == getX()) && (y == getY())) return '@';
    else return nextLayer->charAt(x, y);
}

void Player::attack(Character *e) { e->hurt(damage(getAtk(), e->getDef())); }


void Player::changeHP(int amt) {
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
    else if (cur_hp > max_hp) cur_hp = max_hp;
}

void Player::drinkPot(string PotType) {
    if (PotType == "RH") {
        changeHP(10); //1 restore health
    } else if (PotType == "PH") {
        changeHP(-10); //2 poision health
    } else if (PotType == "BA") {
        CurEffect = new BA{CurEffect}; //3 boost atk
    } else if (PotType == "WA") {
        CurEffect = new WA{CurEffect}; //4 wound atk
    } else if (PotType == "BD") {
        CurEffect = new BD{CurEffect}; //5 boost def
    } else if (PotType == "WD") {
        CurEffect = new WD{CurEffect}; //6 wound def
    }
}

int getAtk() { return atk + CurEffect->changeAtk(); }

int getDef() { return def + CurEffect->changeDef(); }

