#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

using namespace std;

class Enemy: public Character {
    char getCharAt(Map *m, int x, int y);
    string randDir(Map *m, int gox, int goy);
    protected:
    public:
        Enemy(Map *p, int x, int y, int atk, int def, int max_hp, std::string r);
        virtual void move(Map *m);
};

#endif

