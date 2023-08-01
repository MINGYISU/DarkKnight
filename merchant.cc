#include "merchant.h"

Merchant::Merchant(Map *p, int x, int y, Player *pc, ChamberOfCommerce *coc, const string r):
    Enemy{p, x, y, 30, 70, 5, pc, r}, home{coc} {}

void Merchant::call() { home->warning(); } // notify the chamber of commerce

bool Merchant::isHostile() { return home->wanted(); }

bool Merchant::attack() {
    if (dead() || !isHostile()) return false;
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

bool Merchant::hurt(int dmg) {
    changeHP(-dmg);
    if (!isHostile()) call();
    return true;
}

char Merchant::charAt(int x, int y) {
    if (!dead() && x == getX() && y == getY()) {
        if (isHostile()) return 'M';
        else return 'm';
    }
    else return nextLayer->charAt(x, y);
}

string Merchant::purchase() {
    if (isHostile()) return "QUIT";
    cout << "\033[2J\033[1;1H";
    cout << "Welcome to the Chamber Store!" << endl;
    cout << home->display() << endl;
    cout << "Choose: ";
    int input;
    string pot;
    cin >> input;
    pot = home->getAt(input);
    if (pot == "INVALID") { 
        return "QUIT";
    }
    if (pot == "RH") {
        if (pc->getAsset() < 1) { 
            return "NEF";
        } else {
            pc->gain(-1);
            home->sell(input);
        }
    } else if (pot == "BD") 
        if (pc->getAsset() < 3) { 
            return "NEF";
        }
        else {
            pc->gain(-3);
            home->sell(input);
        }
    else {
        if (pc->getAsset() < 5) { 
            return "NEF";
        } else {
            pc->gain(-5);
            home->sell(input);
        }
    }
    pc->drinkPot(pot);
    return pot;
}

