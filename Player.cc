#include "player.h"

char Player::char_at() { return '@'; }

void Player::attack(Character *e) {
    int rand = ... % 2;
    if (e->get_race() == "Halfling") {
        if (rand == 0) e->hurt(damage(atk, pc->get_Def));
    } else e->hurt(damage(atk, pc->get_Def));
}

void Player::changeHP(int amt) {
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
    else if (cur_hp > max_hp) cur_hp = max_hp;
}

