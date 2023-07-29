#include "dwarf.h"

Dwarf::Dwarf(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 100, 20, 30, pc, r} {}

char Dwarf::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'W';
    else return nextLayer->charAt(x, y);
}

