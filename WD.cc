#include "WD.h"
using namespace std;

WD::WD(PotEffect *p):
    PotDeco {p} {}

int WD::changeAtk() {
    return DecoratedPot->changeAtk();
}

int WD::changeDef() {
    return DecoratedPot->changeDef() - 5;
}
