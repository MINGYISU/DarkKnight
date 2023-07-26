#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy: public Character {
    Character *pc;

    public:
    Enemy();
    virtual void print() = 0;
    virtual void attack();
    virtual bool hurt(int dmg);
};

#endif

