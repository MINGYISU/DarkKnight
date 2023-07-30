#include "coc.h"

ChamberOfCommerce::ChamberOfCommerce():
    manhunt{false} {
        refreshStore();
    }

void ChamberOfCommerce::warning() { manhunt = true; } // A merchant was attacked, become hostile

bool ChamberOfCommerce::wanted() { return manhunt; }

std::string ChamberOfCommerce::randPot() {
    int ran = rand() % 6;
    if (ran == 0) return "BA";
    else if (1 == ran || ran == 2) return "BD";
    else return "RH";
}

void ChamberOfCommerce::refreshStore() {
    srand(time(0));
    for (int i = store.size(); i < 5; ++i) {
        string pt = randPot();
        cout << pt << endl;
        store.push_back(pt);
    }
}

std::string ChamberOfCommerce::sell(int which) {
    if (which < 0 || which > store.size()) return "INVALID";
    std::string pot = store.at(which);
    store.erase(store.begin() + which);
    return pot;
}

std::string ChamberOfCommerce::display() {
    std::string s{"PRICE: RH-3 BD-5 BA-10\nTODAY'S NEW: "};
    for (int i = 0; i < store.size(); ++i) {
        std::ostringstream oss;
        oss << i;
        s += oss.str() + ": " + store.at(i) + " ";
    }
    return s;
}

int ChamberOfCommerce::getSize() {
    int s{0};
    s = store.size();
    return s;
}
