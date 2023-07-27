#include "enemy.h"
using namespace std;

Enemy::Enemy(Map *p, int x, int y,
               int atk, int def,
               int max_hp, Player *pc, const string race): 
               Character{p, x, y, max_hp, atk, def}, pc{pc} {}

void Enemy::attack() {
    pc->hurt(damage(getAtk(), pc->getDef()), pc->getRace());
}

bool Enemy::hurt(int dmg) {
    changeHP(-dmg);
    return true;
}
