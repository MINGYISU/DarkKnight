#include "character.h"
using namespace std;

std::string Character::getRace() { return race; }

Character::Character(Map *p, int x, int y, 
                    int cur_hp, int atk, int def, const string race):
    Decorator{p}, xCor{x}, yCor{y},
    cur_hp{cur_hp}, atk{atk}, def{def} {}

Character::~Character() { }

int damage(int atker, int defer) {
  double damage = (100 / (100 + defer)) * atker;
  return std::ceil(damage);
}

void Character::move(int to_x, int to_y) {
  xCor = to_x;
  yCor = to_y;
}

void Character::changeHP(int amt) { // This is the changeHP() for Enemy
  cur_hp += amt;
  if (cur_hp < 0) cur_hp = 0;
}

// void Character::setPrint(bool printOrNot) { toprint = printOrNot; }

bool Character::dead() { return cur_hp <= 0; }

int Character::getX() { return xCor; }

int Character::getY() { return yCor; }

int Character::getAtk() { return atk; }

int Character::getDef() { return def; }

int Character::getHP() { return cur_hp; }

