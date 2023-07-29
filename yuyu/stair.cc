#include "stair.h"

Stair::Stair(Map *p, int x, int y):
    Decorator{p}, xCor{x}, yCor{y}
    {}

char Stair::charAt(int x, int y){
    if((x == xCor) && (y == yCor)){
        return '\\';
    }else{
        return nextLayer->charAt(x, y);
    }
}

