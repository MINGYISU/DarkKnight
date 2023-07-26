#include "enemy.h"


void Enemy::attack() {
    srand(time(0));
    int rand = rand() % 2;
    if (rand == 0) pc->hurt(damage(getAtk(), pc->get_Def()), race);
}

bool Enemy::hurt(int dmg) {
    changeHP(-dmg);
    return true;
}
