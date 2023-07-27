#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
//#include "potion.h"

class Player: public Character {
    const int max_hp;
    int gold = 0;
    
    public:
        Player(Map *p, int x, int y, 
                int cur_hp, int atk, int def,
                int max_hp);
        char charAt(int x, int y) override;
        // virtual void attack(Character *e);
        // virtual void hurt();
        void changeHP(int amt) override;
};

#endif

