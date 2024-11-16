#include "BD.h"

BD::BD(PotEffect *p):
    PotDeco {p} {}

int BD::changeAtk() {
    return DecoratedPot->changeAtk();
}

int BD::changeDef() {
    return DecoratedPot->changeDef() + 5;
}

