#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"

class Goblin: public Player {
    public:
        Goblin(Map *p, int x, int y, std::string r = "Goblin");
        void attack(Character *e) override;
        void hurt(int dmg, std::string e) override;
};

#endif
