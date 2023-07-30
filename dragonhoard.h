#ifndef DRAGOBHOARD_H
#define DRAGOBHOARD_H

#include "gold.h"
#include "dragon.h"

class DragonHoard: public Gold {
        bool pickability;
        Dragon *resident;
    public:
        DragonHoard(Map *m, int x, int y); //constructor, I (shi) added the Map *m back in
        void setResidence(Dragon *d);
        bool getPickability() override; // check is Dragon dead? and change its pickability field accordingly
        //void setPickability(); // change the pickability field
        void attack();
};

#endif
