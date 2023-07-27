#include "shade.h"

Shade::Shade(Map *p, int x, int y):
    player{p, x, y, 125, 25, 25} {
        race = "Shade";
    }

