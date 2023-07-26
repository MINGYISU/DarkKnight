#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf: public Enemy {
    public:
        Elf();
        void attack() override;
};

#endif
