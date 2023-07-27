#include "human.h"

Human::Human(Map *p, int x, int y, Player *pc, std::string r = "Merchant"):
    Enemy{p, x, y, 140, 20, 20, pc, r} {}

char Human::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'H';
    else return nextLayer->charAt(x, y);
}

