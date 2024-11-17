#ifndef DECORATORMAP_H
#define DECORATORMAP_H
#include "map.h"

class Decorator : public Map {

public:
  Map *nextLayer;
  // this is still a virtual func,
  Decorator(Map *p);
  // is not virtual, but can be used
  // as a part of ctor imple in subclasses
  virtual ~Decorator();
};

#endif
