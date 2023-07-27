#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class Dragon: public Enemy {
    public:
        Dragon(Map *p, int x, int y, Player *pc, std::string r = "Dragon");
        char charAt(int x, int y) override;
}

#endif
