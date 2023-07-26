#include "vampire.h"

Vampire::Vampire(Map *p, int x, int y):
    player{p, x, y, 50, 25, 25} {
        race = "Vampire";
    }

void Vampire::changeHP(int amt) {
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
}

void Vampire::attack(Character *e) {
    std::string er = e->get_race();
    if (e->hurt(damage(getAtk(), pc->get_Def()))) {
        if (er == "Dwarf") changeHP(-5);
        else changeHP(5);
    }
}



