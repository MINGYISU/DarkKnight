#include "drop.h"
using namespace std;

Drop::Drop(int x, int y, int a):
    Gold{x, y, a} {}

void Drop::setAmount(int g) {
    amount = g;
}
