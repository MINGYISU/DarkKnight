#include "dragonhoard.h"

DragonHoard::DragonHoard(Map *m, int x, int y):
    Gold{m, x, y, 6}, resident{nullptr} {}

void DragonHoard::setResidence(Dragon *d) {
    resident = d;
}

bool DragonHoard::getPickability() {
    pickability = resident->dead();
    return pickability;
}

//void DragonHoard::setPickability() { pickability = guardian->dead(); }


//void DragonHoard::attack() { guardian->attack(); }
