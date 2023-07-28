#include "elf.h"

Elf::Elf(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 140, 30, 10, pc, r} {}

void Elf::attack() {
    if (pc->getRace() == "Drow") {
        pc->hurt(damage(getAtk(), pc->getDef()));
    } else {
        pc->hurt(damage(getAtk(), pc->getDef()));
        pc->hurt(damage(getAtk(), pc->getDef()));
    }
}

char Elf::charAt(int x, int y) {
    if (x == getX() && y == getY()) return 'E';
    else return nextLayer->charAt(x, y);
}
