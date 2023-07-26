#ifndef PICKABLE_H
#define PICKABLE_H
using namespace std;

class Pickable {
    bool toPrint;
    int xCor, yCor;
    public:
    Pickable(int x, int y, bool t = true);
    virtual char charAt();
    int getX();
    int getY();
    bool toPrint(); //this function is empty
    void setPrint(); //this function is empty
};

#endif
