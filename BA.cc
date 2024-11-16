#include "BA.h"

BA::BA(PotEffect *p):
    PotDeco {p} {}

int BA::changeAtk() {
    return DecoratedPot->changeAtk() + 5;
}

int BA::changeDef() {
    return DecoratedPot->changeDef();
}

