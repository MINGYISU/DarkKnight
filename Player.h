#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "potion.h"

class Player: public Character {
    const int max_hp;
    int gold = 0;
    
    public:
    char char_at();
    virtual void attack(Character *e);
    virtual void hurt();
    void changeHP() override;
};

#endif
