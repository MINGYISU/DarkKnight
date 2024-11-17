#ifndef SHIELD_H
#define SHIELD_H
#include "equipment.h"

class Shield : public Equipment {
public:
  Shield(Map *p, int x, int y);
  int cAtk() override;
  int cDef() override;
  const string itemName() override;
};
#endif
