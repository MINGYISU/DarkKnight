#include "gold.h"
using namespace std;

Gold::Gold(int x, int y, int a):
    Pickable{x, y}, amount{a} {}

int Gold::getAmount() {
    return amount;
}
