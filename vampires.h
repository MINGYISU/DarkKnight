#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "player.h"

class Vampire: public Player{
    public:
        Vampire(Map *p, int x, int y, int a, std::string r = "Vampire");
        void changeHP(int amt) override;
        void attack(Character *e) override;
};

#endif
