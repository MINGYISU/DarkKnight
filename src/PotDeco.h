#ifndef POTDECO_H
#define POTDECO_H

#include "PotEffect.h"
class PotDeco : public PotEffect {
protected:
  PotEffect *DecoratedPot;

public:
  PotDeco(PotEffect *p);
  virtual ~PotDeco();
};

#endif
