#ifndef WATER_H
#define WATER_H
#include "PotEffect.h"

class Water : public PotEffect {
public:
  int changeAtk() override;
  int changeDef() override;
  ~Water();
};

#endif
