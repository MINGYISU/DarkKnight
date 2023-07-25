#ifndef VAMPIRES_H
#define VAMPIRES_H

#include "player.h"

class Vampire : public Player{
    string race;
    public:
        Vampire(Map *p, int x, int y,
                int cur_hp, int atk, int def,
                int max_hp, string r);
        string getRace() override;
        void changeHP(int amt) override;
        // void attack(Character *e) override;
        // void hurt(int dmg, std::string enemy) override;
};

#endif
