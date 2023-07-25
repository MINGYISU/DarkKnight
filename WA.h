#ifndef WA_H
#define WA_H
#include "PotDeco.h"
using namespace std;

class WA final: public PotDeco {
    public:
    WA (PotEffect *p);
    int changeAtk() override;
    int changeDef() override;
};
#endif
