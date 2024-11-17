#include "pickable.h"

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

