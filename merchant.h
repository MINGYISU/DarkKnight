#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
#include "coc.h"
using namespace std;

class Merchant: public Enemy {
    ChamberOfCommerce *home;
    public:
        Merchant(Map *p, int x, int y, Player *pc, const string r = "Merchant");
        bool attack() override;
        bool hurt(int dmg) override;
        void call();
        bool isHostile();
        char charAt(int x, int y) override;
};
#endif
