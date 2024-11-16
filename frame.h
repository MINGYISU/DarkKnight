#ifndef FRAME_H
#define FRAME_H

#include "decorator.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Frame : public Decorator {
  char coordinate[FLOORHEIGHT][FLOORWIDTH];

public:
  Frame(Map *p);
  char charAt(int xCor, int yCor) override;
  //~Frame() override;
};

#endif
