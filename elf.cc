#include "elf.h"

Elf::Elf():


void Elf::attack() {
    srand(time(0));
    int r = rand() % 2;
    if (r == 0 && pc->getRace() != "Drow") {
        pc->hurt(damage(getAtk(), pc->get_Def()), race);
        pc->hurt(damage(getAtk(), pc->get_Def()), race);
    }
}

