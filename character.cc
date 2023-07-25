#include "character.h"

Character::~Character() { }

int damage(int atker, int defer) {
    double damage = (100 / (100 + defer)) * atker;
    return std::ceil(damage);
}

void Character::move(int to_x, int to_y) {
    xCor = to_x;
    yCor = to_y;
}

void Character::changeHP(int amt) { 
    cur_hp += amt;
    if (cur_hp < 0) cur_hp = 0;
} 

std::string Character::get_race() { return race; }

