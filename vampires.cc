#include "vampires.h"

void Vampires::changeHP(int amt) {
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
}

void Vampires::attack(Character *e) {
    int rand = ... % 2;
    std::string er = e->get_race();
    if ((er != "Halfling") || (er == "Halfling" && rand == 0)) {
        e->hurt(damage(atk, pc->get_Def));
        if (er == "Dwarf") changeHP(-5);
        else changeHP(5);
    }
}


void hurt(int dmg, std::string enemy) {
    changeHP(-dmg);
}
