#ifndef VAMPIRES_H
#define VAMPIRES_H

#include "player.h"

class Vampire: public Player {
    public:
        void changeHP(int amt) override;
        void attack(Character *e) override;
        void hurt(int dmg, std::string enemy) override;
};

#endif
