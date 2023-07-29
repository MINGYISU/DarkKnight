#include "enemy.h"

Enemy::Enemy(Map *p, int x, int y,
               int atk, int def,
               int max_hp, Player *pc, std::string r): 
               Character{p, x, y, max_hp, atk, def, r}, pc{pc} {}

void Enemy::attack() {
    pc->hurt(damage(getAtk(), pc->getDef()));
}

bool Enemy::hurt(int dmg) {
    changeHP(-dmg);
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
