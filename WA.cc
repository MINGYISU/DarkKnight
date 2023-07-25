#include "WA.h"
using namespace std;

WA::WA(PotEffect *p):
    PotDeco {p} {}

int WA::changeAtk() {
    return DecoratedPot->changeAtk() - 5;
}

int WA::changeDef() {
    return DecoratedPot->changeDef();
}
