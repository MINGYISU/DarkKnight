#include "gold.h"
using namespace std;

Gold::Gold(Map* p, int x, int y, int a) : Pickable{p, x, y}, amount{a} {}

int Gold::getAmount()
{
    return amount;
}

char Gold::charAt(int x, int y){
    if((x == getX()) && (y == getY()) && toPrint()){
        return 'G';
    }else{
        return nextLayer->charAt(x, y);
    }
}

