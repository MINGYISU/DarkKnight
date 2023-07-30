#include "merchant.h"
using namespace std;

Merchant::Merchant(Map *p, int x, int y, Player *pc, ChamberOfCommerce *coc, const string r):
    Enemy{p, x, y, 30, 70, 5, pc, r}, home{coc} {}

void Merchant::call() { home->warning(); } // notify the chamber of commerce

bool Merchant::isHostile() { return home->wanted(); }

bool Merchant::attack() {
    if (dead() || !isHostile()) return false;
    int px = pc->getX();
    int py = pc->getY();
    int x = getX();
    int y = getY();
    if ((x - 1) <= px && px <= (x + 1) && (y - 1) <= py && py <= (y + 1)) {
        pc->hurt(damage(getAtk(), pc->getDef()));
        return true;
    }
    return false;
}

bool Merchant::hurt(int dmg) {
    changeHP(-dmg);
    if (!isHostile()) call();
    return true;
}

char Merchant::charAt(int x, int y) {
    if (!dead() && x == getX() && y == getY()) return 'M';
    else return nextLayer->charAt(x, y);
}

void Merchant::purchase() {
    if (isHostile()) return ;
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to the Chamber Store!" << endl;
    cout << home->display() << endl;
    cout << "Choose: ";
    int input;
    string pot;
    cin >> input;
    pot = home->sell(input);
    if (pot == "INVALID") { purchase(); }
    if (pc->getAsset() < 3) { 
        cout << "NOT ENOUGH MOENY!"; 
        return ;
    }
    if (pot == "RH") pc->gain(-3);
    else if (pot == "BD") pc->gain(-5);
    else pc->gain(-10);
    pc->drinkPot(pot);
    cout << "You Bought " << pot;
}

