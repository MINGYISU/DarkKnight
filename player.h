#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "Water.h"
#include "BA.h"
#include "WA.h"
#include "BD.h"
#include "WD.h"
#include <string>

class Player: public Character {
    const int max_hp;

    protected:
    int asset;
    PotEffect *CurEffect;
    
    public:
        Player(Map *p, int x, int y, 
                int cur_hp, int atk, int def,
                int max_hp, std::string r);
        char charAt(int x, int y) override;
        virtual void attack(Character *e);
        void changeHP(int amt) override;
        void drinkPot(std::string PotType);
        void gain(int amt);
        virtual void hurt(int dmg, std::string et);
        virtual int getAtk();
        virtual int getDef();
};

#endif

