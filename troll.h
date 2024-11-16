#ifndef TROLL_H
#define TROLL_H

#include "player.h"

class Troll : public Player {
public:
  Troll(Map *p, int x, int y, int a, std::string r = "Troll");
};
#endif
