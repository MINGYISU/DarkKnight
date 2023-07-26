#ifndef CHARACTER_H
#define CHARACTER_H

#include "decorator.h"
#include <cmath>
#include <string>
using namespace std;

class Character : public Decorator
{
    Character *pc;
    const int atk, def;
    //string race;
    bool toprint;
    
    protected:
        int xCor, yCor, cur_hp;

    public:
        Character(Map *p, int x, int y, int cur_hp,
                  int atk, int def);
        bool toPrint();
        void setPrint(bool printOrNot);
        // char set_char_at();
        // char charAt(int x, int y) override;
        int getX();
        int getY();
        int getAtk();
        int getDef();
        virtual string getRace() = 0;
        virtual void changeHP(int amt);
        void move(int to_x, int to_y);
        int damage(int atker, int defer);
        ~Character();
};

#endif

