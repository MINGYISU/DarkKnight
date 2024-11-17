#include "halfling.h"

Halfling::Halfling(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 100, 15, 20, pc, r} {}


bool Halfling::hurt(int dmg) {
    srand(time(0));
    int r = rand() % 2;
    if (r == 0) {   // player may miss the attack
        changeHP(-dmg);
        return true;
    } else return false;
}

char Halfling::charAt(int x, int y) {
    if (!dead() && x == getX() && y == getY()) return 'L';
    else return nextLayer->charAt(x, y);
}
