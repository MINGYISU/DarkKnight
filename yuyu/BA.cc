#include "BA.h"
using namespace std;

BA::BA(PotEffect *p):
    PotDeco {p} {}

int BA::changeAtk() {
    return DecoratedPot->changeAtk() + 5;
}

int BA::changeDef() {
    return DecoratedPot->changeDef();
}

