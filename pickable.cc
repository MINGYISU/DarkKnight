#include "pickable.h"
//temporate
#include <iostream>
//temporate
using namespace std;

Pickable::Pickable(Map *p, int x, int y) : Decorator{p}, xCor{x}, yCor{y}, toprint{true} {}

int Pickable::getX()
{
    return xCor;
}

int Pickable::getY()
{
    return yCor;
}

bool Pickable::toPrint()
{
    return toprint;
}

void Pickable::setPrint(bool b)
{
    toprint = b;
}

char Pickable::charAt(int x, int y) {}

//new below (Jeannie)
void Pickable::swap(Pickable *onGround) {
    this->xCor = onGround->xCor;
    this->yCor = onGround->yCor;
    this->toprint = true;
    onGround->toprint = false;
}
//new above (Jeannie)
