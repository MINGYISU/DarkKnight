#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"

class Goblin: public Player {
    public:
        void attack(Character *e) override;
        void hurt(int dmg, std::string e) override;
};

#endif
