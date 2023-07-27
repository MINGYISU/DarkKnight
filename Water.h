#ifndef WATER_H
#define WATER_H
#include "PotEffect.h"
using namespace std;

class Water: public PotEffect {
    public:
    int changeAtk() override;
    int changeDef() override;
    ~Water();
};

#endif
