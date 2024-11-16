#ifndef STAIR_H
#define STAIR_H
#include "decorator.h"

class Stair : public Decorator {
  int xCor, yCor;

public:
  Stair(Map *p, int x, int y);
  char charAt(int x, int y) override;
};

#endif
