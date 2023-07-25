#include "enemy.h"

void Enemy::attack() {
    int rand = ... % 2;
    if (rand == 0) pc->hurt(damage(atk, pc->get_Def()), race);
}

void Enemy::hurt() {

}
