#ifndef COC_H
#define COC_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

class ChamberOfCommerce {
    bool manhunt;
    std::vector<std::string> store;
    std::string randPot();
    void refreshStore();

    public:
        explicit ChamberOfCommerce();
        void warning();
        bool wanted();
        int getSize();
        std::string sell(int which);
        std::string display();
};

#endif
