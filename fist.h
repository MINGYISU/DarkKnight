#ifndef FIST_H
#define FIST_H
#include "equipment.h"
using namespace std;

class Fist: public Equipment {
    public:
    Fist(Map *p, int x = 0, int y = 0);
    int cAtk() override;
    int cDef() override;
    const string itemName() override;
};
#endif