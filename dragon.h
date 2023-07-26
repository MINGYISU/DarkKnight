#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon: public Enemy {
    public:
        Dragon(Map *p, int x, int y, Character *pc);
        char charAt(int x, int y) override;
        void move() override;
}

#endif
