#ifndef CHARACTER_H
#define CHARACTER_H

#include "decorator.h"

class Character: public Decorator {
    int x, y, hp, atk, def;

    public:
        ~Character();
        bool to_print();
        char set_char_at();
        virtual char char_at();
        int get_X();
        int get_Y();
        virtual int get_Atk();
        virtual void move();
        virtual void attack();
        virtual void hurt();
};

