#ifndef DRAGOBHOARD_H
#define DRAGOBHOARD_H

#include "gold.h"
#include "dragon.h"

class DragonHoard: public Gold {
    protected:
        // bool pickability;
        Map *guardian;

    public:
        DragonHoard(int x, int y); //constructor
        /*
        bool getPickability(); // return the pickability
        void setPickability(); // change the pickability field
        */
        void attack();
};

#endif
