#ifndef MAPPOTION_H
#define MAPPOTION_H
#include "pickable.h"
#include <string>
using namespace std;

class MapPotion : public Pickable {
  string type;

public:
  MapPotion(Map *p, int x, int y, string t);
  string getType();
  char charAt(int x, int y) override;
};

#endif
