#include "equipment.h"
using namespace std;

Equipment::Equipment(Map *p, int x, int y):
    Pickable{p, x, y} {}

char Equipment::charAt(int x, int y) {
    if((x == getX()) && (y == getY()) && toPrint()){
        return '!';
    }else{
        return nextLayer->charAt(x, y);
    }
}
