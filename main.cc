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
#include "dragonhoard.h"
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
#include "dragon.h"


#include "PotDeco.h"
#include "PotEffect.h"
#include "WA.h"
#include "WD.h"
#include "BA.h"
#include "BD.h"
#include "Water.h"



using namespace std;


void render(Window *win, Player *p, string &MSG, int floor) {
        win->display();
        cout << "Race: " << p->getRace() << " Gold: " << p->getAsset() << endl;
        if (floor > 0) {
            for (int i = 0; i < 60; ++i) {
                cout << " ";
            }
            cout << "Floor " << floor << endl;
        }
        cout << "HP: " << p->getHP() << endl;
        cout << "Atk: " << p->getAtk() << endl;
        cout << "Def: " << p->getDef() << endl;
        cout << "Action: " << MSG << endl;
}

int movePlayer(Window* w, int currentPlayerXCor, int currentPlayerYCor, string cmd, Player* player,
                vector<MapPotion*>* listPot, vector<Gold*>* listGold, vector<Enemy*>* listEnemy,
                bool& attackYes, int& x, int& y, string &MSG){
    char out = ' ';
    int intendXCor = 0;
    int intendYCor = 0;
    bool at = false;
    bool drinkPot = false;
    bool trade = false;

    if (cmd[0] == 'a') {
        cmd = cmd.substr(2, 2);
        at = true;
    } else if (cmd[0] == 'u') {
        cmd = cmd.substr(2, 2);
        drinkPot = true;
    } else if (cmd[0] == 't') {
        cmd = cmd.substr(2, 2);
        trade = true;
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
        return 2;
    }

    x = intendXCor;
    y = intendYCor;

    out = w->picture()->charAt(intendXCor, intendYCor);


    if (((out == '.') || (out == '+') || (out == '#')) && (!drinkPot) && (!trade) && !at) {
        player->move(intendXCor, intendYCor);
        MSG = "PC moves " + cmd + ". ";
    } else if (out == '\\') {
        player->move(intendXCor, intendYCor);
        return 0;

    }
    else if((out == 'G') && (!drinkPot)){
        for (int i = 0; i < listGold->size(); i++)
        {
            if(listGold->at(i)->charAt(intendXCor, intendYCor) == 'G'){
                if(listGold->at(i)->getAmount() == 6){
                    if(listGold->at(i)->getPickability()){
                        listGold->at(i)->setPrint(false);
                        player->move(intendXCor, intendYCor);
                        player->gain(6);
                        MSG = "PC moves " + cmd + " picks up " + to_string(listGold->at(i)->getAmount()) + " Golds. ";
                    }
                }else{
                    listGold->at(i)->setPrint(false);
                    player->move(intendXCor, intendYCor);
                    player->gain(listGold->at(i)->getAmount());
                    MSG = "PC moves " + cmd + " and picks up " + to_string(listGold->at(i)->getAmount()) + " Golds. ";
                }
                break;
            }
        }
    }
    else if(drinkPot && (!trade)){
        bool didDrink = false;
        for(int i = 0; i < listPot->size(); i++){
            if(listPot->at(i)->charAt(intendXCor, intendYCor) == 'P'){
                listPot->at(i)->setPrint(false);
                player->drinkPot(listPot->at(i)->getType());
                MSG = "PC uses " + listPot->at(i)->getType() + ". ";
                didDrink = true;
                break;
            }
        }
        if(!didDrink){
            MSG = "No Potion Found!";
            return 2;
        }
    } 
    else if (trade && !drinkPot && !at) {
        if (out != 'M') {
            MSG = "No Merchant Found!";
            return 2;
        } else {
            Merchant *m = nullptr;
            for (int i = 0; i < listEnemy->size(); ++i) {
                if (listEnemy->at(i)->getX() == intendXCor &&
                    listEnemy->at(i)->getY() == intendYCor &&
                    listEnemy->at(i)->getRace() == "Merchant") {
                    m = static_cast<Merchant*>(listEnemy->at(i));
                    break;
                }
            }
            if (m->isHostile()) {
                MSG = "You are sanctioned by the Chamber of Commerce! Purchase Denied! ";
            } else {
                string bought = m->purchase();
                if (bought == "ESF") {
                    MSG = "Not Enough Gold! Purchase Denied! ";
                    return 2;
                } else if (bought == "QUIT") {
                    MSG = "PC leaves the Store. ";
                    return 2;
                } else {
                    MSG = "PC purchases and uses " + bought + ". ";
                }
            }
        }
    }
    else if (at && (!drinkPot) && !trade) {
        if ((out == 'H' || out == 'W' || out == 'E' || 
             out == 'O' || out == 'M' || out == 'D' || out == 'L') ) {
                attackYes = true; //able to use player attack function
        } else { MSG = "No Enemy Around. "; }
    } else {
        MSG = "Ouch! PC Hits Something Hard! ";
    }
    
    if(player->getRace() == "Troll"){
        player->changeHP(5);
    }

    return 1;
}

void randomEight(Window* w, int x, int y, int& intendX, int& intendY);

void playerAttack(Window* w, vector<Enemy*>* listEnemy, Player* player, int intendXCor,
                    int intendYCor, vector<Gold*>* listGold, string &MSG){
    for (int i = 0; i < 20; i++) {
        Enemy *e = listEnemy->at(i);
        if (e->getX() == intendXCor &&
            e->getY() == intendYCor) {
            int bf = e->getHP();
            player->attack(e);
            if (e->getHP() == 0) { MSG += "PC slains " + e->getRace() + ". "; }
            else { MSG += "PC deals " + to_string(bf - e->getHP()) + " to " + e->getRace() + " (" + to_string(e->getHP()) + " HP). "; }

            if(e->getRace() == "Human"){
                if(e->dead()){
                    //spawn 2 piles of gold
                    Drop* pile1 = new Drop{w->picture(), e->getX(), e->getY(), 2};
                    w->picture() = pile1;
                    listGold->push_back(pile1);

                    int xPile2 = 0;
                    int yPile2 = 0;
                    randomEight(w, e->getX(), e->getY(), xPile2, yPile2);
                    Drop* pile2 = new Drop{w->picture(), xPile2, yPile2, 2};
                    w->picture() = pile2;
                    listGold->push_back(pile2);
                }
            }else if(e->getRace() == "Merchant"){
                if(e->dead()){
                    //spawn merchant hoard
                    Drop* merchantHoard = new Drop{w->picture(), e->getX(), e->getY(), 4};
                    w->picture() = merchantHoard;
                    listGold->push_back(merchantHoard);
                }
            }

            break;
        }
    }
}


void enemyAction(Window* w, vector<Enemy*>* enemyList, string &MSG){
    for(int i = 0; i < enemyList->size(); i++){
        if(!enemyList->at(i)->dead()){
            bool attackYes = enemyList->at(i)->attack();
            if(!attackYes){ //not attacking pc
                enemyList->at(i)->move(w->picture());
            }else{
                MSG += enemyList->at(i)->getRace() + " deals " + to_string(enemyList->at(i)->getDamage()) + " damage to PC. ";
            }
        }
    }
}

void randomEight(Window* w, int x, int y, int& intendX, int& intendY){
    vector<int> v = {0,1,2,3,4,5,6,7};
    
    while (true)
    {
        int randomInd = rand() % v.size();
        int randomDir = v.at(randomInd);
        if (randomDir == 0)
        {
            intendX = x - 1;
            intendY = y - 1;
        }
        else if (randomDir == 1)
        {
            intendX = x - 0;
            intendY = y - 1;
        }
        else if (randomDir == 2)
        {
            intendX = x + 1;
            intendY = y - 1;
        }
        else if (randomDir == 3)
        {
            intendX = x - 1;
            intendY = y - 0;
        }
        else if (randomDir == 4)
        {
            intendX = x + 1;
            intendY = y - 0;
        }
        else if (randomDir == 5)
        {
            intendX = x - 1;
            intendY = y + 1;
        }
        else if (randomDir == 6)
        {
            intendX = x - 0;
            intendY = y + 1;
        }
        else if (randomDir == 7)
        {
            intendX = x + 1;
            intendY = y + 1;
        }
        if(w->picture()->charAt(intendX, intendY) == '.'){
            return;
        }else{ // not
            v.erase(v.begin() + randomInd);
        }
        if(v.size() == 0){
            intendX = 0;
            intendY = 0; //do not spawn, useless
            return;
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


int main() {
    string MSG;
    string Filename = "cc3k-emptySingleFloor.txt";
    string FilenameModified = "cc3k-emptySingleFloor-modified.txt";

    //store the player information
    string playerChoice = "Shade";
    cout << "Welcome to The Game of ChamberCrawler3000!" << endl;
    cout << "s: Shade    d: Drow    v: Vampire    g: Goblin    t: Troll" << endl;
    cout << "Please Choose Your Hero: ";
    getline(cin, playerChoice);
    int playerAsset = 0;
    int playerHP = 0;

    for (int j = 0; j < 5; j++) {
        // FLOOR BUILDING STAGE!!!
        vector<Chamber *> listChamber; // 这些可能会有memo error
        vector<MapPotion*> listPot; 
        vector<Gold*> listGold;
        vector<Enemy*> listEnemy;

        // This is the Chamber of Commerce, a large commerical organization
        ChamberOfCommerce *coc = new ChamberOfCommerce;

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

        // Spawn Player Character
        Player *player = nullptr;
        if (playerChoice == "v") {
            player = new Vampire(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
        } else if (playerChoice == "g") {
            player = new Goblin(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
        }else if(playerChoice == "d"){
            player = new Drow(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
        }else if(playerChoice == "t"){
            player = new Troll(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
        } else {
           player = new Shade(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
        }
        w.picture() = player;

        if (j != 0) {
            player->setHP(playerHP);
        }

        // generate the stairway
        int xCorStair = 0;
        int yCorStair = 0;
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
        int dragonNumber = 0;
        for(int i = 0; i < 10; i++){
            int xCorGold = 0;
            int yCorGold = 0;
            randomChamberIndex = rand() % 5;
            listChamber.at(randomChamberIndex)->spawnCoordinate(xCorGold, yCorGold);
            int randomGoldName = arrGoldName[rand() % lengthArrGoldName];
            if(randomGoldName == 6){
                //dragon hoard
                int dragonXCor = 0;
                int dragonYCor = 0;
                DragonHoard* gold = new DragonHoard(w.picture(), xCorGold, yCorGold);
                listGold.push_back(gold);
                w.picture() = gold;
                randomEight(&w, xCorGold, yCorGold, dragonXCor, dragonYCor);
                Dragon* dragon = new Dragon{w.picture(), dragonXCor, dragonYCor, player, xCorGold, yCorGold};
                dragonNumber++;
                listEnemy.push_back(dragon);
                gold->setResidence(dragon);
                w.picture() = dragon;
                listChamber.at(randomChamberIndex)->useSpawnCoordinate(dragonXCor, dragonYCor);
            }else{
                Drop* gold = new Drop(w.picture(), xCorGold, yCorGold, randomGoldName);
                listGold.push_back(gold);
                w.picture() = gold;
            }
        }

        //generate the enemy
        int arrEnemyName[18] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
        int lengthArrEnemyName = sizeof(arrEnemyName) / sizeof(arrEnemyName[0]);
        for(int i = 0; i < 20 - dragonNumber; i++){
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
                enemy = new Merchant(w.picture(), xCorEnemy, yCorEnemy, player, coc);
            }else if(((16 <= randomEnemyName) && (randomEnemyName <= 18))){ //3/18 = 1/6
                enemy = new Dwarf(w.picture(), xCorEnemy, yCorEnemy, player);
            }
            listEnemy.push_back(enemy);
            w.picture() = enemy;
        }
        // sort the enemy from left to right
        sort(listEnemy.begin(), listEnemy.end(), enemyLeftRightCompare);
        MSG = "Player Character has spawned. ";
        render(&w, player, MSG, -1);
        MSG = "";


        //READING CMD STAGE!!!
        //PLAYING STAGE!!!
        //bool nextFloor = false;
        while(true){
            string cmd;
            cout << "DO: ";

            getline(cin, cmd);
            int currentPlayerXCor = player->getX();
            int currentPlayerYCor = player->getY();
            //cout << currentPlayerXCor << " " << currentPlayerYCor << endl;
            bool attackYes = false; //player always init attack as false
            int intendx = 0;
            int intendy = 0;
            int action = movePlayer(&w, currentPlayerXCor, currentPlayerYCor, cmd, player, 
                                    &listPot, &listGold, &listEnemy, attackYes, intendx, intendy, MSG);
            if (action == 1){
                enemyAction(&w, &listEnemy, MSG);
                if(attackYes){
                    playerAttack(&w, &listEnemy, player, intendx, intendy, &listGold, MSG);
                }
            }else if(action == 2){
                //no move
            }else if(action == 0){ // next for loop, next layer
                playerAsset += player->getAsset();
                playerHP = player->getHP();
                break;
            }

            render(&w, player, MSG, j + 1);
            MSG = "";
        }
    }
}


