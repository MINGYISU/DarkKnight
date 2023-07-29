#include "shield.h"
using namespace std;

Shield::Shield(Map *p, int x, int y):
    Equipment{p, x, y} {}

int Shield::cAtk() {
    return -10;
}

int Shield::cDef() {
    return 5;
}

const string Shield::itemName() {
    const string s = "Shield"
    return s;
}
