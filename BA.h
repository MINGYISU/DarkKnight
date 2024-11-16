#ifndef BA_H
#define BA_H
#include "PotDeco.h"
using namespace std;

class BA final : public PotDeco {
public:
  BA(PotEffect *p);
  int changeAtk() override;
  int changeDef() override;
};
#endif
