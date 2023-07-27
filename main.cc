#include "map.h"
#include "character.h"
#include "player.h"
#include "shade.h"
#include "enemy.h"
#include "halfling.h"

using namespace std;

int main() {
 //   Map *m = new Map;
    Player *me = new Shade{nullptr,1,1};
    Enemy *they = new Halfling{nullptr, 2, 2, me};
    delete they;
    delete me;
 //   delete m;
}