#include "dragon.h"

Dragon::Dragon(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 150, 20, 20, pc, r} {}

char Dragon::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'D';
    else return nextLayer->charAt(x, y);
}
