#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"

class Halfling: public Enemy {
    public:
        Halfling(Map *p, int x, int y, Character *pc);
        char charAt() override;
        bool hurt(int dmg) override;
        char charAt(int x, int y) override;
};

#endif
