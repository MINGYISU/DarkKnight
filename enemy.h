#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy: public Character {
    Character *pc;

    public:
    Enemy(Map *p, int x, int y, int atk, int def, int max_hp, Character *pc);
    virtual void print() = 0;
    virtual void attack();
    virtual bool hurt(int dmg);
};

#endif

