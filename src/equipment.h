#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "pickable.h"
#include <string>

using namespace std;

class Equipment : public Pickable {
public:
  Equipment(Map *p, int x, int y);
  virtual int cAtk() = 0;
  virtual int cDef() = 0;
  virtual const string itemName() = 0;
  char charAt(int x, int y) override;
};
#endif
