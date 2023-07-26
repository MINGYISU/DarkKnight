#include "elf.h"

Elf::Elf(Map *p, int x, int y, Character *pc):
    Enemy{p, x, y, 140, 30, 10, pc} {
        race = "Elf";
    }


void Elf::attack() {
    if (pc->getRace() == "Drow") {
        pc->hurt(damage(getAtk(), pc->getDef()), race);
    } else {
        pc->hurt(damage(getAtk(), pc->getDef()), race);
        pc->hurt(damage(getAtk(), pc->getDef()), race);
    }
}

char Elf::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'E';
    else return nextLayer->charAt(x, y);
}
