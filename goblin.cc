#include "goblin.h"

Goblin::Goblin(Map *p, int x, int y, std::string r):
    Player{p, x, y, 110, 15, 20, r} {}

void Goblin::attack(Character *e) {
    if (e->hurt(damage(getAtk(), e->getDef()))) {
        if (e->dead()) gain(5);
    }
}

//void Goblin::hurt(int dmg, std::string e) {
//    if (enemy == "Orcs") dmg * 3 / 2;
//    changeHP(-dmg);
//    return true;
//}
