#include "merchant.h"
using namespace std;

Merchant::Merchant(Map *p, int x, int y, Player *pc, const string r):
    Enemy{p, x, y, 30, 70, 5, pc, r} {}

void Merchant::call() { home->warning(); } // notify the chamber of commerce

bool Merchant::isHostile() { return home->wanted(); }

void Merchant::attack() {
    int px = pc->getX();
    int py = pc->getY();
    int x = getX();
    int y = getY();
    if ((x - 1) <= px && px <= (x + 1) && (y - 1) <= py && py <= (y + 1)) {
        if (isHostile()) pc->hurt(damage(getAtk(), pc->getDef()));
    }
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
