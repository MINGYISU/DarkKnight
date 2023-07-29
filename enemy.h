#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"
#include <vector>

class Enemy: public Character {
    char getCharAt(Map *m, int x, int y);
    string randDir(Map *m, int gox, int goy);
    protected:
        Player *pc;
    public:
        Enemy(Map *p, int x, int y, int atk, int def, int max_hp, Player *pc, std::string r);
        virtual void attack();
        virtual bool hurt(int dmg);
        virtual void move(Map *m);
};

#endif

