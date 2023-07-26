#ifndef ORCS_H
#define ORCS_H

#include "enemy.h"

class Orcs: public Enemy {
    public:
        Orcs(Map *p, int x, int y, Character *pc);
        char charAt(int x, int y) override;
};

#endif
