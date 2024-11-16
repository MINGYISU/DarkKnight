#ifndef CHARACTER_H
#define CHARACTER_H

#include "decorator.h"
#include <cmath>
#include <string>
using namespace std;

class Character : public Decorator {
  const std::string race;
  // bool toprint;

protected:
  int xCor, yCor, cur_hp;
  const int atk, def;

public:
  Character(Map *p, int x, int y, int cur_hp, int atk, int def, const string r);
  ~Character();
  bool toPrint();
  // void setPrint(bool printOrNot);
  int getX();
  int getY();
  virtual int getAtk();
  virtual int getDef();
  int getHP();
  bool dead();
  std::string getRace();
  virtual void changeHP(int amt);
  void move(int to_x, int to_y);
  int damage(int atker, int defer);
  virtual bool hurt(int dmg) = 0;
};

#endif
