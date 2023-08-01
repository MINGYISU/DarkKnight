#include "player.h"

Player::Player(Map *p, int x, int y, int max_hp,
               int atk, int def, std::string r, int a, Equipment *e): Character{p, x, y, max_hp, atk, def, r},
               max_hp{max_hp}, asset{a}
{
    CurEffect = new Water;
    if (e != nullptr)
    {
        CurEquip = e;
    }
    else
    {
        CurEquip = new Fist{nullptr};
    }
}

Player::~Player() { 
    delete CurEffect; 
    delete CurEquip;
}

char Player::charAt(int x, int y) {
    if((x == getX()) && (y == getY())) {
        if (dead()) return 'X';
        else return '@';
    }
    else return nextLayer->charAt(x, y);
}

void Player::attack(Character *e) { 
    if (e->hurt(damage(getAtk(), e->getDef()))) {
        std::string er = e->getRace();
        if (e->dead() && er != "Human" && er != "Dragon" && er != "Merchant") {
            srand(time(0));
            gain(rand() % 2 + 1);
        }
    }
}

void Player::gain(int amt) { 
    if (asset + amt < 0) return ;
    else asset += amt;
}

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

int Player::getAtk() {
    int a = atk + CurEffect->changeAtk() + CurEquip->cAtk();
    if (a < 0) return 0;
    else return a;
}

int Player::getDef() {
    int d = atk + CurEffect->changeAtk() + CurEquip->cDef();
    if (d < 0) return 0;
    else return d; 
}

bool Player::hurt(int dmg) { 
    srand(time(0));
    if (rand() % 2 == 0) {
        changeHP(-dmg);
        return true;
    } else {
        return false;
    }
}


int Player::getAsset() {
    return asset;
}

void Player::setHP(int hp) {
    cur_hp = hp;
}

string Player::getEquip(){
    return CurEquip->itemName();
}

void Player::useEquip(Equipment * equip){
    delete CurEquip;
    CurEquip = nullptr;
    CurEquip = equip;
}
