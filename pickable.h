#ifndef PICKABLE_H
#define PICKABLE_H
using namespace std;
#include "decorator.h"

class Pickable : public Decorator
{
    bool toprint;
    int xCor, yCor;

public:
    Pickable(Map *p, int x, int y);
    virtual char charAt(int x, int y) = 0;
    int getX();
    int getY();
    bool toPrint();
    void setPrint(bool b);
};

#endif
