#include "dragon.h"

Dragon::Dragon(Map *p, int x, int y, Character *pc):
    Enemy{p, x, y, 150, 20, 20, pc} {
        race = "Dragon";
    }

char Dragon::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'D';
    else return nextLayer->charAt(x, y);
}
