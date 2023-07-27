#include "pickable.h"
using namespace std;

Pickable::Pickable(int x, int y):
    xCor{x}, yCor{y}, toPrint{true} {}

int Pickable::getX() {
    return xCor;
}

int Pickable::getY() {
    return yCor;
}

bool Pickable::toPrint() {}

void Pickable::setPrint() {}
