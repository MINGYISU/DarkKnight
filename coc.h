#ifndef COC_H
#define COC_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class ChamberOfCommerce {
    bool manhunt;
    std::vector<std::string> store;
    std::string randPot();
    void refreshStore();
    int price(string g);

    public:
        explicit ChamberOfCommerce();
        ~ChamberOfCommerce();
        void warning();
        bool wanted();
        int getSize();
        string getAt(int which);
        void sell(int which);
        void display();
};

#endif
