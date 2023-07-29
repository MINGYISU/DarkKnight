#ifndef GOLD_H
#define GOLD_H

#include "pickable.h"
using namespace std;

class Gold : public Pickable
{
protected:
    int amount;

public:
    Gold(Map *p, int x, int y, int a = 0);
    char charAt(int x, int y) override;
    int getAmount();
};
#endif
