#include "human.h"

Human::Human(Map *p, int x, int y, std::string r):
    Enemy{p, x, y, 140, 20, 20, r} {}

char Human::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'H';
    else return nextLayer->charAt(x, y);
}

