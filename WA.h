#ifndef WA_H
#define WA_H
#include "PotDeco.h"

class WA final : public PotDeco {
public:
  WA(PotEffect *p);
  int changeAtk() override;
  int changeDef() override;
};
#endif
