#include "chamber.h"
using namespace std;

Chamber::Chamber(Map* p, int yMax, int yMin, 
                int xMin, int xMax, string Filename): 
Decorator{p}, yMax{yMax}, yMin{yMin}, xMin{xMin}, xMax{xMax}  {
    ifstream MyFile(Filename);

    for(int i = 0; i < FLOORHEIGHT; i++){
        for(int j = 0; j < FLOORWIDTH; j++){
            usedSpawnPlace[i][j] = 0; //init
            coordinate[i][j] = ' '; 
        }
    }

    for(int i = 0; i < FLOORHEIGHT; i++){
        string line = "";
        getline(MyFile, line);
        if((yMin <= i) && (i <= yMax)){
            for(int j = 0; j < FLOORWIDTH; j++){
                if((xMin <= j) && (j <= xMax)){
                    if( line[j] == '.'){
                        coordinate[i][j] = '.';
                        usedSpawnPlace[i][j] = 1; //change 0 to 1
                    }else{  //the reading point is .
                        //coordinate[i][j] = ' '; //blank
                    }
                }
            }
        }
    }
}

char Chamber::charAt(int xCor, int yCor){
    char out = coordinate[yCor][xCor];
    if(out == ' '){
        return nextLayer->charAt(xCor, yCor);
    }else{
        return out;
    }
}

void Chamber::spawnCoordinate(int& x, int& y){
    int xRange = xMax - xMin;
    int yRange = yMax - yMin;
    srand(time(0));
    while(true){
        x = rand() % xRange + xMin;
        y = rand() % yRange + yMin;
        if(usedSpawnPlace[y][x] == 1){
            usedSpawnPlace[y][x] = 0; //modify it to 0
            return; //the y and x has been randomly assigned to 
            //a place without previous spawning obj
        }
    }
}

void Chamber::useSpawnCoordinate(int x, int y){
    usedSpawnPlace[y][x] = 0;
}

Chamber::~Chamber(){}






