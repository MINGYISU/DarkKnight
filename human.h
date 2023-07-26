#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"

class Human: public Enemy {
    public:
        Human(Map *p, int x, int y, Character *pc);
        char charAt(int x, int y) override;
};

#endif
