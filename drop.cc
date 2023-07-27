#include "drop.h"
using namespace std;

Drop::Drop(Map* p, int x, int y, int a) : Gold{p, x, y, a} {}

void Drop::setAmount(int g)
{
    amount = g;
}

