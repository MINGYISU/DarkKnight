#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy: public Character {
    public:
    virtual void print() = 0;
    void attack() override;
    virtual void hurt();
};

#endif

