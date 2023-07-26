#include "dragonhoard.h"
using namespace std;

DragonHoard::DragonHoard(int x, int y, int a, bool p = false):
    Gold{x, y, a} {}

bool DragonHoard::getPickability() {
    return pickability;
}

void DragonHoard::setAmount(int a) {
    amount = a;
}

void DragonHoard::setPickability(bool p) {
    pickability = p;
}
