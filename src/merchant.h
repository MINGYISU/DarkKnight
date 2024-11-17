#ifndef MERCHANT_H
#define MERCHANT_H

#include "coc.h"
#include "enemy.h"

class Merchant : public Enemy {
  ChamberOfCommerce *home;

public:
  Merchant(Map *p, int x, int y, Player *pc, ChamberOfCommerce *coc = nullptr,
           const string r = "Merchant");
  bool attack() override;
  bool hurt(int dmg) override;
  void call();
  bool isHostile();
  char charAt(int x, int y) override;
  string purchase();
};

#endif
