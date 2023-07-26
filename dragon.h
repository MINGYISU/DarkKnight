#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon: public Enemy {
    public:
        Dragon();
        void move() override;
}

#endif
