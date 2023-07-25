#include "halfling.h"

Halfling::Halfling(int x, int y, Character *pc):
    xCor{x}, yCor{y}, p{pc}, race{"Halfling"}, max_hp{100}, hp{100}, atk{15}, def{20} {}

Character* Halfling::copy(int x, int y) {
    Character* h = new Halfling(x, y);
    return h;
}

void Halfling::attack() {
    p->hurt(damage(atk, pc->get_Def()), race);
}

void Halfling::hurt(int dmg, std::string enemy) {
    pc->changeHP(-dmg);
}

