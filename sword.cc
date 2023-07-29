#include "sword.h"
using namespace std;

Sword::Sword(Map *p, int x, int y):
    Equipment{p, x, y} {}

int Sword::cAtk() {
    return 5;
}

int Sword::cDef() {
    return -10;
}

const string Sword::itemName() {
    const string s = "Sword"
    return s;
}
