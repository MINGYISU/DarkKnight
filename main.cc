#include "map.h"
#include "window.h"
#include "chamber.h"
#include "frame.h"
#include "decorator.h"
#include "blank.h"
#include "stair.h"
#include "mapPotion.h"
#include "gold.h"
#include "drop.h"
#include "BA.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


#include "vampires.h"
#include "shade.h"
#include "goblin.h"
#include "troll.h"
#include "drow.h"
#include "player.h"
#include "character.h"

#include "enemy.h"
#include "coc.h"
#include "dwarf.h"
#include "elf.h"
#include "halfling.h"
#include "human.h"
#include "merchant.h"
#include "orcs.h"


#include "PotDeco.h"
#include "PotEffect.h"
#include "WA.h"
#include "WD.h"
#include "BA.h"
#include "BD.h"
#include "Water.h"



using namespace std;


int movePlayer(Window* w, int currentPlayerXCor, int currentPlayerYCor, string cmd, Player* player,
                vector<MapPotion*>* listPot, vector<Gold*>* listGold, vector<Enemy*>* listEnemy,
                bool& attackYes, int& x, int& y){
    char out = ' ';
    int intendXCor = 0;
    int intendYCor = 0;
    bool drinkPot = false;


    if(cmd[0] == 'u'){
        cmd = cmd.substr(2, 2);
        drinkPot = true;
    }


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
        return 2;
    }

    x = intendXCor;
    y = intendYCor;

    out = w->picture()->charAt(intendXCor, intendYCor);


    if (((out == '.') || (out == '+') || (out == '#')) && (!drinkPot))
    {
        player->move(intendXCor, intendYCor);
    }
    else if (out == '\\')
    {
        player->move(intendXCor, intendYCor);
        //break;
        return 0;

    }
    else if((out == 'G') && (!drinkPot)){
        for (int i = 0; i < listGold->size(); i++)
        {
            if(listGold->at(i)->charAt(intendXCor, intendYCor) == 'G'){
                if(listGold->at(i)->getAmount() == 6){
                    //dragon
                    listGold->at(i)->setPrint(false);
                    player->move(intendXCor, intendYCor);
                    cout << "this is dragon hoard!" << endl;
                    player->gain(6);
                }else{
                    listGold->at(i)->setPrint(false);
                    player->move(intendXCor, intendYCor);
                    cout << "you picked up " << listGold->at(i)->getAmount() << " gold" << endl;
                    player->gain(listGold->at(i)->getAmount());
                }
            }
        }
    }
    else if(drinkPot){
        bool didDrink = false;
        for(int i = 0; i < listPot->size(); i++){
            if(listPot->at(i)->charAt(intendXCor, intendYCor) == 'P'){
                //使用药水
                listPot->at(i)->setPrint(false);
                cout << "you drinked " << listPot->at(i)->getType() << endl;
                didDrink = true;
            }
        }
        if(!didDrink){
            cout << "你没喝药为啥摁u???" << endl;
            return 2;
        }
    } 
    else if ((out == 'H' || out == 'W' || out == 'E' || 
             out == 'O' || out == 'M' || out == 'D' || out == 'L') && (!drinkPot)) {
                attackYes = true; //able to use player attack function
    }
    else
    {
        cout << "前面的区域，以后再来探索吧" << endl;
    }
    
    
    return 1;
}



void playerAttack(Window* w, vector<Enemy*>* listEnemy, Player* player, int intendXCor,
                    int intendYCor){
    for (int i = 0; i < 20; i++) {
        Enemy *e = listEnemy->at(i);
        if (e->getX() == intendXCor &&
            e->getY() == intendYCor) {
            player->attack(e);
            cout << "You attacked " << e->getRace() << endl;
            cout << e->getHP() << endl;
            break;
        }
    }
}

void enemyAction(Window* w, vector<Enemy*>* enemyList){
    for(int i = 0; i < enemyList->size(); i++){
        if(!enemyList->at(i)->dead()){
            bool attackYes = enemyList->at(i)->attack();
            if(!attackYes){ //not attacking pc
                enemyList->at(i)->move(w->picture());
            }else{
                cout << enemyList->at(i)->getRace() << " is attacking you!" << endl;
            }
        }
    }
}


bool enemyLeftRightCompare(Enemy* e1, Enemy* e2){
    if(e1->getX() < e2->getX()){
        return true;
    }else if(e1->getX() > e2->getX()){
        return false;
    }else{
        return (e1->getY() < e2->getY());
    }
}


int main()
{
    string Filename = "cc3k-emptySingleFloor.txt";
    string FilenameModified = "cc3k-emptySingleFloor-modified.txt";

    // Player* player = nullptr;
    //store the player information
    string playerChoice = "Shade";
    cout << "你想选择什么角色？" << endl;
    cout << "Shade, Vampire, Goblin, Drow, Troll?" << endl;
    getline(cin, playerChoice);
    int playerAsset = 0;
    //string nonsence = "";
    //getline(cin, nonsence);

    for (int i = 0; i < 5; i++)
    {
        if(i > 0){
            cout << (i+1) << "'s floor!!!!!" << endl;
        }
        // FLOOR BUILDING STAGE!!!
        vector<Chamber *> listChamber; // 这些可能会有memo error
        vector<MapPotion*> listPot; 
        vector<Gold*> listGold;
        vector<Enemy*> listEnemy;

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




        // RANDOM GENERATION STAGE!
        // generate the player
        // 1. randomly choose 1 chamber,
        srand(time(0));
        int randomChamberIndex = rand() % 5;
        int playerChamberIndex = randomChamberIndex;
        int xCorPlayer = 0;
        int yCorPlayer = 0;
        listChamber.at(randomChamberIndex)->spawnCoordinate(xCorPlayer, yCorPlayer);
        Player *player = new Shade(w.picture(), xCorPlayer, yCorPlayer, playerAsset, "Shade");
        if(playerChoice == "Shade"){
            cout << "you are shade" << endl;
            player = new Shade(w.picture(), xCorPlayer, yCorPlayer, playerAsset, "Shade");
        }else if(playerChoice == "Vampire"){
            cout << "you are vampire" << endl;
            player = new Vampire(w.picture(), xCorPlayer, yCorPlayer, playerAsset, "Vampire");
        }else if(playerChoice == "Goblin"){
            cout << "you are goblin" << endl;
            player = new Goblin(w.picture(), xCorPlayer, yCorPlayer, playerAsset, "Goblin");
        }else if(playerChoice == "Drow"){
            cout << "you are drow" << endl;
            player = new Drow(w.picture(), xCorPlayer, yCorPlayer, playerAsset, "Drow");
        }else if(playerChoice == "Troll"){
            cout << "you are troll" << endl;
            player = new Troll(w.picture(), xCorPlayer, yCorPlayer, playerAsset, "Troll");
        }else{
            cout << "别瞎选了，你就当shade得了" << endl;
            //Player *player = new Shade(w.picture(), xCorPlayer, yCorPlayer);
        }
        w.picture() = player;
        //w.display();
        // call player ctor at that random place

        // generate the stairway
        int xCorStair = 0;
        int yCorStair = 0;
        //srand(time(0));
        while(true){
            randomChamberIndex = rand() % 5;
            if(randomChamberIndex != playerChamberIndex){ //ensure stair and player is not in the same
                break;
            }
        }
        listChamber.at(randomChamberIndex)->spawnCoordinate(xCorStair, yCorStair);
        Stair* stair = new Stair(w.picture(), xCorStair, yCorStair);
        w.picture() = stair;
        


        // generate the potion
        string arrPotName[6] = {"BA", "BD", "WA", "WD", "PH", "RH"};
        int lengthArrPotName = sizeof(arrPotName) / sizeof(arrPotName[0]);
        for(int i = 0; i < 5; i++){
            int xCorPot = 0;
            int yCorPot = 0;
            randomChamberIndex = rand() % 5;
            listChamber.at(randomChamberIndex)->spawnCoordinate(xCorPot, yCorPot);
            int randomPotNameIndex = rand() % lengthArrPotName;
            MapPotion *pot = new MapPotion(w.picture(), xCorPot, yCorPot, arrPotName[randomPotNameIndex]);
            listPot.push_back(pot);
            w.picture() = pot;
        }
        //generate the gold
        int arrGoldName[8] = {1, 1, 2, 2, 2, 2, 2, 6};
        int lengthArrGoldName = sizeof(arrGoldName) / sizeof(arrGoldName[0]);
        for(int i = 0; i < 10; i++){
            int xCorGold = 0;
            int yCorGold = 0;
            randomChamberIndex = rand() % 5;
            listChamber.at(randomChamberIndex)->spawnCoordinate(xCorGold, yCorGold);
            int randomGoldName = arrGoldName[rand() % lengthArrGoldName];
            Gold *gold = nullptr;
            if(randomGoldName == 6){
                //dragon hoarde
                gold = new Drop(w.picture(), xCorGold, yCorGold, randomGoldName);
            }else{
                gold = new Drop(w.picture(), xCorGold, yCorGold, randomGoldName);
            }
            listGold.push_back(gold);
            w.picture() = gold;
        }

        //generate the enemy
        int arrEnemyName[18] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
        int lengthArrEnemyName = sizeof(arrEnemyName) / sizeof(arrEnemyName[0]);
        for(int i = 0; i < 20; i++){
            int xCorEnemy = 0;
            int yCorEnemy = 0;
            randomChamberIndex = rand() % 5;
            listChamber.at(randomChamberIndex)->spawnCoordinate(xCorEnemy, yCorEnemy);
            int randomEnemyName = arrEnemyName[rand() % lengthArrEnemyName];
            Enemy* enemy = nullptr;
            if((1 <= randomEnemyName) && (randomEnemyName <= 4)){ // 4/18 = 2/9
                enemy = new Human(w.picture(), xCorEnemy, yCorEnemy, player);
            }else if((5 <= randomEnemyName) && (randomEnemyName <= 9)){ // 5/18
                enemy = new Halfling(w.picture(), xCorEnemy, yCorEnemy, player);
            }else if(((10 <= randomEnemyName) && (randomEnemyName <= 11))){ // 2/18 = 1/9
                enemy = new Elf(w.picture(), xCorEnemy, yCorEnemy, player);
            }else if(((12 <= randomEnemyName) && (randomEnemyName <= 13))){ // 2/18 = 1/9
                enemy = new Orcs(w.picture(), xCorEnemy, yCorEnemy, player);
            }else if(((14 <= randomEnemyName) && (randomEnemyName <= 15))){ // 2/18 = 1/9
                enemy = new Merchant(w.picture(), xCorEnemy, yCorEnemy, player);
            }else if(((16 <= randomEnemyName) && (randomEnemyName <= 18))){ //3/18 = 1/6
                enemy = new Dwarf(w.picture(), xCorEnemy, yCorEnemy, player);
            }
            listEnemy.push_back(enemy);
            w.picture() = enemy;
        }
        sort(listEnemy.begin(), listEnemy.end(), enemyLeftRightCompare);
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


            getline(cin, cmd);
            int currentPlayerXCor = player->getX();
            int currentPlayerYCor = player->getY();
            //cout << currentPlayerXCor << " " << currentPlayerYCor << endl;
            bool attackYes = false; //player always init attack as false
            int intendx = 0;
            int intendy = 0;
            int action = movePlayer(&w, currentPlayerXCor, currentPlayerYCor, cmd, player, 
                                    &listPot, &listGold, &listEnemy, attackYes, intendx, intendy);
            if (action == 1){
                enemyAction(&w, &listEnemy);
                cout << player->getRace() << endl;
                cout << "Player gold: " << player->getAsset() << endl;
                cout << "Player HP: " << player->getHP() << endl;
                if(attackYes){
                    playerAttack(&w, &listEnemy, player, intendx, intendy);
                }
            }else if(action == 2){
                //no move
            }else if(action == 0){ // next for loop, next layer
                playerAsset += player->getAsset();
                break;
            }



            w.display();
        }
    }
}


