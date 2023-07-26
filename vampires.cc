#include "vampire.h"

Vampire::Vampire(Map *p, int x, int y,
                 int cur_hp, int atk, int def,
                 int max_hp, string r) : 
                 Player{p, x, y,
                        cur_hp, atk, def,
                        max_hp}, 
                 race{r} {}

void Vampire::changeHP(int amt) {
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
}

void Vampire::attack(Character *e) {
    srand(time(0));
    int r = rand() % 2;
    std::string er = e->get_race();
    if ((er != "Halfling") || (er == "Halfling" && r == 0)) {
        if (e->hurt(damage(getAtk(), pc->get_Def()))) {
            if (er == "Dwarf") changeHP(-5);
            else changeHP(5);
        }
    }
}

void Vampire::hurt(int dmg, std::string enemy) { 
    changeHP(-dmg);
    return true;
}


