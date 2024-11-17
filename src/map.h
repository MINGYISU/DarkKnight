#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Map {
public:
  static const int FLOORWIDTH = 79;  // x
  static const int FLOORHEIGHT = 25; // y
  virtual ~Map();
  virtual char charAt(int xCor, int yCor) = 0;
};

#endif
