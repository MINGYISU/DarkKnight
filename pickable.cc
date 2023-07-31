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
void Pickable::changeX(int x) {
    xCor = x;
}
void Pickable::changeY(int y) {
    yCor = y;
}
//new above (Jeannie)
