#ifndef CHARACTER_H
#define CHARACTER_H

#include "decorator.h"
#include <cmath>

class Character: public Decorator {
    Character *pc;
    int xCor, yCor, cur_hp;
    const int atk, def;
    std::string race;

    public:
        ~Character();
        bool to_print();
        char set_char_at();
        virtual char char_at();
        int get_X();
        int get_Y();
        int get_Atk();
        int get_Def();
        std::string get_race();
        virtual void changeHP();
        void move(int to_x, int to_y);
        int damage(int atker, int defer);
};

#endif
