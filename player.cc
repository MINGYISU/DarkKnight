#include "player.h"

Player::Player(Map *p, int x, int y, int max_hp,
               int atk, int def, std::string r): 
               Character{p, x, y, max_hp, atk, def, r},
               max_hp{max_hp}, asset{0} {
                CurEffect = new Water;
               }

char Player::charAt(int x, int y) {
    if((x == getX()) && (y == getY())) return '@';
    else return nextLayer->charAt(x, y);
}

void Player::attack(Character *e) { 
    bool result = e->hurt(damage(getAtk(), e->getDef())); 
}

void Player::gain(int amt) { asset += amt; }

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

int Player::getAtk() { return atk + CurEffect->changeAtk(); }

int Player::getDef() { return atk + CurEffect->changeDef(); }

bool Player::hurt(int dmg) { 
    srand(time(0));
    int r = rand() % 2;
    if (r == 0) changeHP(-dmg);
    return true;
}
