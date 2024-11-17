#ifndef COC_H
#define COC_H

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class ChamberOfCommerce {
  bool manhunt;
  std::vector<std::string> store;
  std::string randPot();
  void refreshStore();

public:
  explicit ChamberOfCommerce();
  ~ChamberOfCommerce();
  void warning();
  bool wanted();
  int getSize();
  string getAt(int which);
  void sell(int which);
  void display();
  int price(string g);
};

#endif
