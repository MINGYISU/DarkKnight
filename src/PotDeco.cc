#include "PotDeco.h"

PotDeco::PotDeco(PotEffect *p):
    DecoratedPot{p} {}

PotDeco::~PotDeco() {
    delete DecoratedPot;
}
