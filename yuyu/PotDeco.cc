#include "PotDeco.h"
using namespace std;

PotDeco::PotDeco(PotEffect *p):
    DecoratedPot{p} {}

PotDeco::~PotDeco() {
    delete DecoratedPot;
}
