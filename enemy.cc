#include "enemy.h"

Enemy::Enemy(Map *p, int x, int y,
               int max_hp, int atk,
               int def, Player *pc, std::string r): 
               Character{p, x, y, max_hp, atk, def, r}, pc{pc} {}

bool Enemy::attack() {
    if (dead()) return false;
    int px = pc->getX();
    int py = pc->getY();
    int x = getX();
    int y = getY();
    if ((x - 1) <= px && px <= (x + 1) && (y - 1) <= py && py <= (y + 1)) {
        pc->hurt(damage(getAtk(), pc->getDef()));
        return true;
    }
    return false;
}

bool Enemy::hurt(int dmg) {
    changeHP(-1 * dmg);
    return true;
}

char Enemy::getCharAt(Map *m, int x, int y) { return m->charAt(x, y); }

string Enemy::randDir(Map *m, int gox, int goy) {
    vector<string> lst;
    if (getCharAt(m, gox, goy - 1) == '.') lst.push_back("no");
    if (getCharAt(m, gox, goy + 1) == '.') lst.push_back("so");
    if (getCharAt(m, gox + 1, goy) == '.') lst.push_back("ea");
    if (getCharAt(m, gox - 1, goy) == '.') lst.push_back("we");
    if (getCharAt(m, gox + 1, goy - 1) == '.') lst.push_back("ne");
    if (getCharAt(m, gox - 1, goy - 1) == '.') lst.push_back("nw");
    if (getCharAt(m, gox + 1, goy + 1) == '.') lst.push_back("se");
    if (getCharAt(m, gox - 1, goy + 1) == '.') lst.push_back("sw");

    if (lst.empty()) return "noway";
    else {
        srand(time(0));
        return lst.at(rand() % lst.size());
    }
}

void Enemy::move(Map *m) {
    int px{pc->getX()}, py{pc->getY()};
    if (px >= getX() - 1 && py >= getY() - 1 && 
        px <= getX() + 1 && py <= getY() + 1) { return ; }
    string dir = randDir(m, xCor, yCor);
    if (dir == "no") yCor -= 1;
    else if (dir == "so") yCor += 1;
    else if (dir == "ea") xCor += 1;
    else if (dir == "we") xCor -= 1;
    else if (dir == "ne") {
        xCor += 1;
        yCor -= 1;
    } else if (dir == "nw") {
        xCor -= 1;
        yCor -= 1;
    } else if (dir == "se") {
        xCor += 1;
        yCor += 1;
    } else if (dir == "sw") {
        xCor -= 1;
        yCor += 1;
    } 
}

int Enemy::getDamage() {
    return damage(getAtk(), pc->getDef());
}
