#include "halfling.h"

Halfling::Halfling(Map *p, int x, int y, Player *pc, const string race):
    Enemy{p, x, y, 100, 15, 20, pc, race} {}


//Character* Halfling::copy(int x, int y) {
 //   Character* h = new Halfling(x, y);
 //   return h;
//}

bool Halfling::hurt(int dmg) {
    srand(time(0));
    int r = rand() % 2;
    if (r == 0) {   // player may miss the attack
        pc->changeHP(-dmg);
        return true;
    } else return false;
}

char Halfling::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'L';
    else return nextLayer->charAt(x, y);
}
