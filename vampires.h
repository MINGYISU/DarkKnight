#ifndef VAMPIRES_H
#define VAMPIRES_H

#include "player.h"

class Vampire : public Player{
    string race;
    public:
        Vampire(Map *p, int x, int y);
        void changeHP(int amt) override;
        void attack(Character *e) override;
};

#endif
