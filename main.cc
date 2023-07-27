#include "map.h"
#include "window.h"
#include "chamber.h"
#include "frame.h"
#include "decorator.h"
#include "blank.h"
#include "stair.h"
#include "mapPotion.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


#include "vampire.h"
#include "player.h"
#include "character.h"


using namespace std;




bool movePlayer(Window* w, int currentPlayerXCor, int currentPlayerYCor, string cmd, Player* player){
    char out = ' ';
    int intendXCor = 0;
    int intendYCor = 0;


    if(cmd == "no"){
        intendXCor = currentPlayerXCor;
        intendYCor = currentPlayerYCor - 1;
    }else if(cmd == "so"){
        intendXCor = currentPlayerXCor;
        intendYCor = currentPlayerYCor + 1;
    }else if(cmd == "ea"){
        intendXCor = currentPlayerXCor + 1;
        intendYCor = currentPlayerYCor;
    }else if(cmd == "we"){
        intendXCor = currentPlayerXCor - 1;
        intendYCor = currentPlayerYCor;
    }else if(cmd == "ne"){
        intendXCor = currentPlayerXCor + 1;
        intendYCor = currentPlayerYCor - 1;
    }else if(cmd == "nw"){
        intendXCor = currentPlayerXCor - 1;
        intendYCor = currentPlayerYCor - 1;
    }else if(cmd == "se"){
        intendXCor = currentPlayerXCor + 1;
        intendYCor = currentPlayerYCor + 1;
    }else if(cmd == "sw"){
        intendXCor = currentPlayerXCor - 1;
        intendYCor = currentPlayerYCor + 1;
    }
    //else if(cmd == "q"){
        //return false;
    //}
    else{
        cout << "请输入正确指令" << endl;
        return true;
    }


    out = w->picture()->charAt(intendXCor, intendYCor);


    if ((out == '.') || (out == '+') || (out == '#'))
    {
        player->move(intendXCor, intendYCor);
    }
    else if (out == '\\')
    {
        player->move(intendXCor, intendYCor);
        //break;
        return false;

    }
    else
    {
        cout << "前面的区域，以后再来探索吧" << endl;
    }
    
    
    return true;
}




int main()
{

    string Filename = "cc3k-emptySingleFloor.txt";
    string FilenameModified = "cc3k-emptySingleFloor-modified.txt";

    for (int i = 0; i < 5; i++)
    {
        if(i > 0){
            cout << (i+1) << "'s floor!!!!!" << endl;
        }
        // FLOOR BUILDING STAGE!!!
        vector<Chamber *> listChamber; // 这些可能会有memo error
        // vector<Enemy*> listEnemy;

        // init the map
        Map *Layer1 = new Blank;
        Window w{Layer1};
        // 1. start with frame
        w.picture() = new Frame{w.picture()};
        // 2. then fill the chamber
        Chamber *newptr1 = new Chamber{w.picture(), 7, 2, 3, 29, Filename};
        listChamber.push_back(newptr1);
        w.picture() = newptr1;
        Chamber *newptr2 = new Chamber{w.picture(), 22, 15, 4, 29, Filename};
        listChamber.push_back(newptr2);
        w.picture() = newptr2;
        Chamber *newptr3 = new Chamber{w.picture(), 23, 16, 37, 79, Filename};
        listChamber.push_back(newptr3);
        w.picture() = newptr3;
        Chamber *newptr4 = new Chamber{w.picture(), 13, 10, 38, 51, Filename};
        listChamber.push_back(newptr4);
        w.picture() = newptr4;
        Chamber *newptr5 = new Chamber{w.picture(), 13, 3, 39, 78, FilenameModified};
        listChamber.push_back(newptr5);
        w.picture() = newptr5;

        //w.display();

        // for (int i = 0; i < 5; i++)
        //{ // spawning
        //     int x = 0;
        //     int y = 0;
        //     listChamber.at(i)->spawnCoordinate(x, y);
        //     cout << x << " " << y << endl;
        //  listChamber.at(i)->printUsedSpawningPlace();
        //}




        // RANDOM GENERATION STAGE!
        // generate the player
        // 1. randomly choose 1 chamber,
        srand(time(0)); 
        int randomChamberIndex = rand() % 5;
        int xCorPlayer = 0;
        int yCorPlayer = 0;
        listChamber.at(randomChamberIndex)->spawnCoordinate(xCorPlayer, yCorPlayer);
        Player* player = new Vampire(w.picture(), xCorPlayer, yCorPlayer,
                                     50, 25, 25, 50000, "vampire");
        w.picture() = player;
        //w.display();
        // call player ctor at that random place

        // generate the stairway
        int xCorStair = 0;
        int yCorStair = 0;
        //srand(time(0));
        randomChamberIndex = rand() % 5;
        listChamber.at(randomChamberIndex)->spawnCoordinate(xCorStair, yCorStair);
        Stair* stair = new Stair(w.picture(), xCorStair, yCorStair);
        w.picture() = stair;
        


        // generate the potion
        for(int i = 0; i < 5; i++){
            int xCorPot = 0;
            int yCorPot = 0;
            randomChamberIndex = rand() % 5;
            listChamber.at(randomChamberIndex)->spawnCoordinate(xCorPot, yCorPot);
            string arrPotName[6] = {"BA", "BD", "WA", "WD", "PH", "RH"};
            int randomPotName = rand() % 6;
            MapPotion *pot = new MapPotion(w.picture(), xCorPot, yCorPot, arrPotName[randomPotName]);
            w.picture() = pot;
        }
        //generate the gold

        //generate the enemy


        w.display();


        //READING CMD STAGE!!!
        //PLAYING STAGE!!!
        //bool nextFloor = false;
        while(true){
            string cmd;
            cout << "pls move" << endl;
            cout << "no for north, so for south, ea for east, we for west" << endl;
            cout << "ne for northeast, nw for northwest, se for southeast, sw for southwest" << endl;
            //cout << "u direction to drink potion, there is a blank between!" << endl;

            cin >> cmd;
            int currentPlayerXCor = player->getX();
            int currentPlayerYCor = player->getY();
            //cout << currentPlayerXCor << " " << currentPlayerYCor << endl;

            if (movePlayer(&w, currentPlayerXCor, currentPlayerYCor, cmd, player)){

            }else{ // next for loop
                break;
            }

            w.display();
        }
    }
}


