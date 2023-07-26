#include "orcs.h"

Orcs::Orcs(Map *p, int x, int y, Character *pc):
    Enemy{p, x, y, 180, 30, 25, pc} {
        race = "Orcs";
    }
    
char Orcs::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'O';
    else return nextLayer->charAt(x, y);
}
