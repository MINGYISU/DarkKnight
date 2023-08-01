#include "fist.h"
using namespace std;

Fist::Fist(Map *p, int x, int y):
    Equipment{p, x, y} {
        setPrint(false);
    }

int Fist::cAtk() {
    return 0;
}

int Fist::cDef() {
    return 0;
}

const string Fist::itemName() {
    const string s = "Fist";
    return s;
}
