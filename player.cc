#include "player.h"

Player::Player(Map *p, int x, int y,
               int cur_hp, int atk, int def,
               int max_hp) : 
               Character{p, x, y, cur_hp, atk, def},
               max_hp{max_hp} 
               {}

char Player::charAt(int x, int y) {
    if((x == getX()) && (y == getY())) return '@';
    else return nextLayer->charAt(x, y);
}

void Player::attack(Character *e) { e->hurt(damage(atk, e->getDef)); }


void Player::changeHP(int amt) {
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
    else if (cur_hp > max_hp) cur_hp = max_hp;
}



