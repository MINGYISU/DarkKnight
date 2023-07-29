#ifndef SWORD_H
#define SWORD_H
#include "equipment.h"
using namespace std;

class Sword: public Equipment {
    public:
    Sword(Map *p, int x, int y);
    int cAtk() override;
    int cDef() override;
    const string itemName() override;
}