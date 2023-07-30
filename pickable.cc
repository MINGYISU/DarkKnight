#include "pickable.h"
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

void Pickable::swap(Pickable* inHands, Pickable* onGround) {
    inHands->xCor = onGround->xCor;
    inHands->yCor = onGround->yCor;
    inHands->toprint = true;
    onGround->toprint = false;
}
