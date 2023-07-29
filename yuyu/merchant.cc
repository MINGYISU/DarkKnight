#include "merchant.h"
using namespace std;

Merchant::Merchant(Map *p, int x, int y, Player *pc, const string r):
    Enemy{p, x, y, 30, 70, 5, pc, r} {}

void Merchant::call() { home->warning(); } // notify the chamber of commerce

bool Merchant::isHostile() { return home->wanted(); }

void Merchant::attack() {
    if (isHostile()) pc->hurt(damage(getAtk(), pc->getDef()));
}

bool Merchant::hurt(int dmg) {
    changeHP(-dmg);
    if (!isHostile()) call();
    return true;
}

char Merchant::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'M';
    else return nextLayer->charAt(x, y);
}
