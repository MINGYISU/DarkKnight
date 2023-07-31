#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "Water.h"
#include "BA.h"
#include "WA.h"
#include "BD.h"
#include "WD.h"
//new (Jeannie)
#include "sword.h"
#include "shield.h"
//new (Jeannie)
#include <string>

class Player: public Character {
    const int max_hp;

    protected:
    int asset;
    PotEffect *CurEffect;
    //new (Jeannie)
    Equipment *CurEquip;
    //new (Jeannie)
    
    public:
        Player(Map *p, int x, int y, int max_hp, 
                int atk, int def, std::string r, int a = 0);
        char charAt(int x, int y) override;
        virtual void attack(Character *e);
        void changeHP(int amt) override;
        virtual void drinkPot(std::string PotType);
        void gain(int amt);
        bool hurt(int dmg) override;
        virtual int getAtk();
        virtual int getDef();
        int getAsset();
        //new
        void changeEquip(Equipment* onGround);
        //new above
};

#endif

