#include "goblin.h"

void Goblin::attack(Character *e) {
    if (e->hurt(damage(getAtk(), e->getDef()))) {
        if (e->dead()) gain(5);
    }
}

void Goblin::hurt(int dmg, std::string enemy) {
    if (enemy == "Orcs") dmg * 3 / 2;
    changeHP(-dmg);
}
