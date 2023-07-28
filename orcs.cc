#include "orcs.h"

Orcs::Orcs(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 180, 30, 25, pc, r} {}
    
char Orcs::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'O';
    else return nextLayer->charAt(x, y);
}

void Orcs::attack(){
    int d = damage(getAtk(), pc->getDef());
    if(pc->getRace() == "Goblin"){
        d = d * 3 / 2;
    }
    pc->hurt(d);
}

