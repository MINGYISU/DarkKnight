#ifndef BD_H
#define BD_H
#include "PotDeco.h"

class BD final : public PotDeco {
public:
  BD(PotEffect *p);
  int changeAtk() override;
  int changeDef() override;
};
#endif
