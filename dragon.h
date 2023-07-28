#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon: public Enemy {
    int hoardXCor;
    int hoardYCor;
    public:
        Dragon(Map *p, int x, int y, Player *pc, int hx, int hy, std::string r = "Dragon");
        char charAt(int x, int y) override;
        void attack() override;
};

#endif
