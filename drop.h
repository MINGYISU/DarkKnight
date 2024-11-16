#ifndef DROP_H
#define DROP_H
#include "gold.h"
using namespace std;

class Drop : public Gold {
public:
  Drop(Map *p, int x, int y, int a = 0);
  void setAmount(int g);
};
#endif
