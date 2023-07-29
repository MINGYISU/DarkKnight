#include "dragon.h"

Dragon::Dragon(Map *p, int x, int y, Player *pc, int hx, int hy, std::string r):
    Enemy{p, x, y, 150, 20, 20, pc, r}, hoardXCor{hx}, hoardYCor{hy} {}

char Dragon::charAt(int x, int y) {
    if (!dead() && x == getX() && y == getY()) return 'D';
    else return nextLayer->charAt(x, y);
}

bool Dragon::attack() {
    if (dead()) return false;
    int px = pc->getX();
    int py = pc->getY();
    int x = getX();
    int y = getY();
    if (((x - 1) <= px && px <= (x + 1) && (y - 1) <= py && py <= (y + 1)) //player is arround dragon
        ||((hoardXCor - 1) <= px && px <= (hoardXCor + 1)
        && (hoardYCor - 1) <= py && py <= (hoardYCor + 1))) { //player is arround dragon hoard
        pc->hurt(damage(getAtk(), pc->getDef())); //attack action
        return true;
    }
    return false;
}
