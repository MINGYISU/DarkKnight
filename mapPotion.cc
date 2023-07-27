#include "mapPotion.h"
using namespace std;

MapPotion::MapPotion(Map *p, int x, int y, string t):
    Pickable{p, x, y}, type{t} {}

string MapPotion::getType(){
    return type;
}

char MapPotion::charAt(int x, int y){
    if((x == getX()) && (y == getY())){
        return 'P';
    }else{
        return nextLayer->charAt(x, y);
    }
}



