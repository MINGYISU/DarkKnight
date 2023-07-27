#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf: public Enemy {
    public:
        Elf(Map *p, int x, int y, Player *pc, std::string r = "Elf");
        void attack() override;
        char charAt(int x, int y) override;
};

#endif
