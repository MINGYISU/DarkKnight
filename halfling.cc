#include "halfling.h"

Halfling::Halfling(int x, int y, Character *pc):
    xCor{x}, yCor{y}, p{pc}, race{"Halfling"}, max_hp{100}, hp{100}, atk{15}, def{20} {}

char Halfling::charAt(int x, int y) {
    if (x == xCor && y == yCor) return 'L';
    else ' ';
}

Character* Halfling::copy(int x, int y) {
    Character* h = new Halfling(x, y);
    return h;
}

bool Halfling::hurt(int dmg) {
    srand(time(0));
    int r = rand() % 2;
    if (r == 0) {   // player may miss the attack
        pc->changeHP(-dmg);
        return true;
    } else return false;
}

