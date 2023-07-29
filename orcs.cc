#include "orcs.h"

Orcs::Orcs(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 180, 30, 25, pc, r} {}
    
char Orcs::charAt(int x, int y) {
    if (!dead() && x == getX() && y == getY()) return 'O';
    else return nextLayer->charAt(x, y);
}

bool Orcs::attack(){
    if (dead()) return false;
    int px = pc->getX();
    int py = pc->getY();
    int x = getX();
    int y = getY();
    
    if (((x - 1) <= px) && (px <= (x + 1)) && ((y - 1) <= py) && (py <= (y + 1))){
        int d = damage(getAtk(), pc->getDef());
        if(pc->getRace() == "Goblin"){
            d = d * 3 / 2;
        }
        pc->hurt(d);
        return true;
    }
    return false;
}

