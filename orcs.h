#ifndef ORCS_H
#define ORCS_H

#include "enemy.h"

class Orcs: public Enemy {
    public:
        Orcs(Map *p, int x, int y, Player *pc, std::string r = "Orcs");
        char charAt(int x, int y) override;
};

#endif
