#ifndef BLANK_H
#define BLANK_H

#include "map.h"

class Blank : public Map {

public:
  char charAt(int xCor, int yCor) override;
};

#endif
