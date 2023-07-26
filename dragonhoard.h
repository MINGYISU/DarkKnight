#ifndef DRAGOBHOARD_H
#define DRAGOBHOARD_H

#include "gold.h"
using namespace std;
class DragonHoard: public Gold {
    bool pickability;
    public:
    DragonHoard(int x, int y, int a = 0, bool p = false); //constructor
    bool getPickability(); // return the pickability
    void setAmount(int a); // change the amount of gold
    void setPickability(bool p); // change the pickability field
};

#endif
