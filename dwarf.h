#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"

class Dwarf: public Enemy {
    public:
       Dwarf(Map *p, int x, int y, Character *pc);
       char charAt(int x, int y)
};

#endif
