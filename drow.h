#ifndef DROW_H
#define DROW_H

#include "player.h"

class Drow: public Player {
    public:
        Drow();
        void drinkPot() override;
        int getAtk() override;
        int getDef() override;
}

#endif
