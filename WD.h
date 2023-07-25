#ifndef WD_H
#define WD_H
#include "PotDeco.h"
using namespace std;

class WD final: public PotDeco {
    public:
    WD (PotEffect *p);
    int changeAtk() override;
    int changeDef() override;
};
#endif
