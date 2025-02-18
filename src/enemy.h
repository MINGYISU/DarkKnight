#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"
#include <vector>

class Enemy : public Character {
  char getCharAt(Map *m, int x, int y);
  string randDir(Map *m, int gox, int goy);

protected:
  Player *pc;

public:
  Enemy(Map *p, int x, int y, int max_hp, int atk, int def, Player *pc,
        std::string r);
  int getPCHP();
  virtual bool attack();
  virtual bool hurt(int dmg);
  virtual void move(Map *m);
};

#endif
