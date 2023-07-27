#include "orcs.h"

Orcs::Orcs(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 180, 30, 25, pc, r} {}
    
char Orcs::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'O';
    else return nextLayer->charAt(x, y);
}
