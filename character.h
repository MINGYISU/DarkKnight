#ifndef CHARACTER_H
#define CHARACTER_H

#include "decorator.h"
#include <cmath>
#include <string>
using namespace std;

class Character: public Decorator {
    Character *pc;
    const int atk, def;
    std::string race;
    bool toprint;
    
    protected:
        int xCor, yCor, cur_hp;

    public:
        Character(Map *p, int x, int y, int cur_hp,
                  int atk, int def);
        ~Character();
        bool toPrint();
        void setPrint(bool printOrNot);
        int getX();
        int getY();
        virtual int getAtk();
        virtual int getDef();
        std::string getRace() = 0;
        virtual void changeHP(int amt);
        void move(int to_x, int to_y);
        int damage(int atker, int defer);
};

#endif
