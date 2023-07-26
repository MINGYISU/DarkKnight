#ifndef GOLD_H
#define GOLD_H

#include "pickable.h"
using namespace std;

class Gold: public Pickable {
    protected:
    int amount;
    public:
    Gold(int x, int y, int a = 0);
    char charAt() override;
    int getAmount();
};
#endif
