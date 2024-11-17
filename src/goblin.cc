#include "goblin.h"

Goblin::Goblin(Map *p, int x, int y, int a, std::string r):
    Player{p, x, y, 110, 15, 20, r, a} {}

void Goblin::attack(Character *e) {
    if (e->hurt(damage(getAtk(), e->getDef()))) {
        if (e->dead()) gain(5);
    }
}

