#ifndef DROW_H
#define DROW_H

#include "player.h"

class Drow: public Player {
    public:
        Drow(Map *p, int x, int y, int a, std::string r = "Drow");
        void drinkPot(string PotType) override;
        int getAtk() override;
        int getDef() override;
};

#endif
