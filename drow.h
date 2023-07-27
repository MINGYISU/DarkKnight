#ifndef DROW_H
#define DROW_H

#include "player.h"

class Drow: public Player {
    public:
        Drow(Map *p, int x, int y, std::string r = "Drow");
        void drinkPot() override;
        int getAtk() override;
        int getDef() override;
};

#endif
