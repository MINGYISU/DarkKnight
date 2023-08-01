#ifndef PICKABLE_H
#define PICKABLE_H
using namespace std;
#include "decorator.h"

class Pickable : public Decorator {
    int xCor, yCor;
    bool toprint;

public:
    Pickable(Map *p, int x, int y);
    int getX();
    int getY();
    bool toPrint();
    void setPrint(bool b);
};

#endif
