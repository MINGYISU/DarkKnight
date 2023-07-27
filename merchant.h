#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
#include "coc.h"

class Merchant: public Enemy {
    ChamberOfCommerce *home;
    public:
        Merchant(Map *p, int x, int y, Player *pc, ChamberOfCommerce *home);
        void attack() override;
        void hurt(int dmg) override;
        void call();
        bool isHostile();
        char charAt(int x, int y) override;
};

#endif
