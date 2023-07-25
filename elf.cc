#include "elf.h"

void Elf::attack() {
    int rand = ... % 2;
    if (rand == 0) {
        pc->hurt(damage(atk, pc->get_Def()), race);
        pc->hurt(damage(atk, pc->get_Def()), race);
    }
}