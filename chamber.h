#ifndef CHAMBER_H
#define CHAMBER_H
#include "decorator.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
//#include "character.h"
//#include "pickable.h"

class Chamber: public Decorator{//abstract class, have 5 subclass
    char coordinate[FLOORHEIGHT][FLOORWIDTH];
    int usedSpawnPlace[FLOORHEIGHT][FLOORWIDTH];
    int yMax; 
    int yMin; 
    int xMin; 
    int xMax;
    public:
    Chamber(Map* p, int yMax, int yMin, int xMin, int xMax, string Filename);
    char charAt(int xCor, int yCor) override;
    void spawnCoordinate(int& x, int& y);
    //only return a random coordinate
    //the real ctor is run in main func
    void printUsedSpawningPlace();
    ~Chamber(); //abstract class
};

#endif


