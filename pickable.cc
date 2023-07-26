#include "pickable.h"
using namespace std;

Pickable::Pickable(int x, int y, bool t):
    xCor{x}, yCor{y} {}

int Pickable::getX() {
    return xCor;
}

int Pickable::getY() {
    return yCor;
}

bool Pickable::toPrint() {}

void Pickable::setPrint() {}
