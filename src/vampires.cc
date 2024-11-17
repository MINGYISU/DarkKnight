#include "vampires.h"

Vampire::Vampire(Map *p, int x, int y, int a, std::string r):
    Player{p, x, y, 50, 25, 25, r, a} {}

void Vampire::changeHP(int amt) {
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
}

void Vampire::attack(Character *e) {
    std::string er = e->getRace();
    if (e->hurt(damage(getAtk(), e->getDef()))) {
        if (er == "Dwarf") changeHP(-5);
        else changeHP(5);
    }
}



