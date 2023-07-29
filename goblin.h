#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"

class Goblin: public Player {
    public:
        Goblin(Map *p, int x, int y, int a, std::string r = "Goblin");
        void attack(Character *e) override;
        //bool hurt(int dmg) override;
};

#endif
