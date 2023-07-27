#include "dragonhoard.h"

DragonHoard::DragonHoard(int x, int y):
    Gold{x, y, 6}, guardian{nullptr} {}

/*
bool DragonHoard::getPickability() {
    return pickability;
}

void DragonHoard::setPickability() { pickability = guardian->dead(); }
*/

void DragonHoard::attack() { guardian->attack(); }
