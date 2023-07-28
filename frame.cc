#include "frame.h"
using namespace std;




Frame::Frame(Map* p): Decorator{p}{
    ifstream MyFile("cc3k-emptySingleFloor.txt");

    for(int i = 0; i < FLOORHEIGHT; i++){
        string line = "";
        getline(MyFile, line);
        for(int j = 0; j < FLOORWIDTH; j++){
            if( line[j] != '.'){
                coordinate[i][j] = line[j];
            }else{  //the reading point is .
                coordinate[i][j] = ' '; //blank
            }
        }
    }
}

char Frame::charAt(int xCor, int yCor){
    char out = coordinate[yCor][xCor];
    if(out == ' '){
        return nextLayer->charAt(xCor, yCor);
    }else{
        return out;
    }
}



