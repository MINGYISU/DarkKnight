#ifndef FRAME_H
#define FRAME_H

#include <iostream>
#include <fstream>
#include <string>
#include "decorator.h"

class Frame: public Decorator{
    char coordinate[FLOORHEIGHT][FLOORWIDTH];

    public:
    Frame(Map* p);
    char charAt(int xCor, int yCor) override;
    //~Frame() override;
};

#endif

