#include "elf.h"

Elf::Elf(Map *p, int x, int y, Player *pc, std::string r):
    Enemy{p, x, y, 140, 30, 10, pc, r} {}

void Elf::attack() {
    int px = pc->getX();
    int py = pc->getY();
    int x = getX();
    int y = getY();
    if ((x - 1) <= px && px <= (x + 1) && (y - 1) <= py && py <= (y + 1)) {
        if (pc->getRace() == "Drow") {
            pc->hurt(damage(getAtk(), pc->getDef()));
        } else {
            pc->hurt(damage(getAtk(), pc->getDef()));
            pc->hurt(damage(getAtk(), pc->getDef()));
        }
    }
}

char Elf::charAt(int x, int y) {
    if (!dead() && x == getX() && y == getY()) return 'E';
    else return nextLayer->charAt(x, y);
}
