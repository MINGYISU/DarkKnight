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

#include "equipment.h"
#include "shield.h"
#include "sword.h"
#include "fist.h"

using namespace std;

void victoryFlag() {
    cout << "\033[2J\033[1;1H";
    cout << "  __" << endl;
    cout << "/ \\--..____" << endl;
    cout << " \\ \\   V   \\-----,,,.." << endl;
    cout << "  \\ \\   I   \\         \\--,,.." << endl;
    cout << "   \\ \\   C   \\         \\  ,'" << endl;
    cout << "    \\ \\   T   \\         \\ ``.." << endl;
    cout << "     \\ \\   O   \\         \\-''" << endl;
    cout << "      \\ \\   R   \\__,,--'''" << endl;
    cout << "       \\ \\   Y   \\." << endl;
    cout << "        \\ \\   !  ,/" << endl;
    cout << "         \\ \\__..-" << endl;
    cout << "          \\ \\" << endl;
    cout << "           \\ \\" << endl;
    cout << "            \\ \\" << endl;
    cout << "             \\ \\" << endl;
    cout << "              \\ \\" << endl;
    cout << "               \\ \\" << endl;
    cout << "                \\ \\" << endl;
    cout << "                 \\ \\" << endl;
    cout << "                  \\ \\" << endl;
}

void coolLogo() {
    cout << "\033[2J\033[1;1H";
    cout << "              .-." << endl;
    cout << "              | |____________________________________________________" << endl;
    cout << " _ _ _ _ _ _ _| |                                                  .'`." << endl;
    cout << "|_|_|_|_|_|_|_| |-<Welcome-to-the-World-of-ChamberCrawler3000!>-.'****>" << endl;
    cout << "`.            | |_______________________________________________.'***.'" << endl;
    cout << "  `.        .'| |                                               `**'" << endl;
    cout << "    `-.___.'  `-'                                              .'*`." << endl;
}

string dir(string d) {
    if (d == "no") return "North";
    else if (d == "ea") return "East";
    else if (d == "so") return "South";
    else if (d == "we") return "West";
    else if (d == "ne") return "Northeast";
    else if (d == "nw") return "Northwet";
    else if (d == "sw") return "Southwest";
    else if (d == "se") return "Southeast";
    else return "";
}

string item(char t) {
    string s = ", and sees ";
    if (t == 'G') return s + "a Treasure";
    else if (t == 'P') return s + "an Unknown potion";
    else if (t == 'O') return s + "an Orcs";
    else if (t == 'm') return s + "a Friendly Merchant";
    else if (t == 'M') return s + "an Angry Merchant";
    else if (t == 'L') return s + "a Halfling";
    else if (t == 'E') return s + "an Elf";
    else if (t == 'D') return s + "a Dragon";
    else if (t == 'H') return s + "a Human";
    else if (t == 'W') return s + "a Dwarf";
    else return "";
}

void render(Window *win, Player *p, string &MSG, int floor, bool dlc) {
        if(dlc){
            win->visionDisplay();
        }else{
            win->display();
        }
        cout << "Race: " << p->getRace() << " Gold: " << p->getAsset();
        if (floor > 0) {
            for (int i = 0; i < 50; ++i) {
                cout << " ";
            }
            cout << "Floor " << floor;
        }
        cout << endl << "HP: " << p->getHP() << endl;
        cout << "Atk: " << p->getAtk() << endl;
        cout << "Def: " << p->getDef() << endl;
        if(dlc){
            cout << "Weapon: " << p->getEquip() << endl;
        }
        cout << "Action: " << MSG << endl;
        MSG = "";
}

int movePlayer(Window* w, int currentPlayerXCor, int currentPlayerYCor, string cmd, Player* player,
                vector<MapPotion*>* listPot, vector<Gold*>* listGold, vector<Enemy*>* listEnemy,
                bool& attackYes, int& x, int& y, string &MSG, bool dlc, vector<Equipment*>* listWeapon){
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
    } else if ((cmd[0] == 't') && dlc) {
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
        MSG = "PC moves " + dir(cmd);
        MSG += item(w->picture()->charAt(intendXCor, intendYCor - 1));
        MSG += item(w->picture()->charAt(intendXCor, intendYCor + 1));
        MSG += item(w->picture()->charAt(intendXCor + 1, intendYCor));
        MSG += item(w->picture()->charAt(intendXCor - 1, intendYCor));
        MSG += item(w->picture()->charAt(intendXCor + 1, intendYCor - 1));
        MSG += item(w->picture()->charAt(intendXCor - 1, intendYCor - 1));
        MSG += item(w->picture()->charAt(intendXCor + 1, intendYCor + 1)); 
        MSG += item(w->picture()->charAt(intendXCor - 1, intendYCor + 1));
        MSG += ". ";
    } else if (out == '\\') {
        player->move(intendXCor, intendYCor);
        return 0;

    }
    else if((out == 'G') && (!drinkPot)){
        int lgs = static_cast<int>(listGold->size());
        for (int i = 0; i < lgs; i++)
        {
            if(listGold->at(i)->charAt(intendXCor, intendYCor) == 'G'){
                if(listGold->at(i)->getAmount() == 6){
                    if(listGold->at(i)->getPickability()){
                        listGold->at(i)->setPrint(false);
                        player->move(intendXCor, intendYCor);
                        player->gain(6);
                        MSG = "PC moves " + dir(cmd) + " picks up " + to_string(listGold->at(i)->getAmount()) + " Golds. ";
                    }
                }else{
                    listGold->at(i)->setPrint(false);
                    player->move(intendXCor, intendYCor);
                    player->gain(listGold->at(i)->getAmount());
                    MSG = "PC moves " + dir(cmd) + " and picks up " + to_string(listGold->at(i)->getAmount()) + " Golds. ";
                }
                break;
            }
        }
    }
    else if(drinkPot && (!trade)){
        bool didDrink = false;
        int lps = static_cast<int>(listPot->size());
        for(int i = 0; i < lps; i++){
            if(listPot->at(i)->charAt(intendXCor, intendYCor) == 'P'){
                listPot->at(i)->setPrint(false);
                player->drinkPot(listPot->at(i)->getType());
                MSG = "PC uses " + listPot->at(i)->getType() + ". ";
                didDrink = true;
                break;
            }
        }

        if(dlc){
            int lws = static_cast<int>(listWeapon->size());
            for (int i = 0; i < lws; i++)
            {
                if ((listWeapon->at(i)->charAt(intendXCor, intendYCor) == '!') && 
                    (listWeapon->at(i)->toPrint()))
                {
                    //player->changeEquip(listWeapon->at(i));
                    //change equipment
                    listWeapon->at(i)->setPrint(false);//do not use it anymore
                    Equipment* oldequip = nullptr;
                    if(player->getEquip() == "Fist"){
                        oldequip = new Fist{w->picture(), intendXCor, intendYCor};
                    }else if(player->getEquip() == "Sword"){
                        oldequip = new Sword{w->picture(), intendXCor, intendYCor};
                    }else if(player->getEquip() == "Shield"){
                        oldequip = new Shield{w->picture(), intendXCor, intendYCor};
                    }
                    oldequip->setPrint(true);
                    w->picture() = oldequip; //oldequip appear on the 
                    listWeapon->push_back(oldequip);

                    Equipment* newequip = nullptr;
                    if(listWeapon->at(i)->itemName() == "Fist"){
                        newequip = new Fist{nullptr};
                    }else if(listWeapon->at(i)->itemName() == "Sword"){
                        newequip = new Sword{nullptr, 0, 0};
                    }else if(listWeapon->at(i)->itemName() == "Shield"){
                        newequip = new Shield{nullptr, 0, 0};
                    }
                    player->useEquip(newequip);
                    

                    MSG = "PC picks up " + listWeapon->at(i)->itemName() + ". ";
                    didDrink = true;
                    break;
                }
            }
        }

        if(!didDrink){
            if(dlc){
                MSG = "You have nothing to pick or use!";
            }else{
                MSG = "What Are You Looking For?! This is Not a Potion :(. ";
            }
            return 2;
        }
    } 
    else if (trade && !drinkPot && !at) {
        if (out != 'm') {
            MSG = "Only Capitalists can sell goods to you. Who are you making a deal with? :(. ";
            return 2;
        } else {
            Merchant *m = nullptr;
            int les = static_cast<int>(listEnemy->size());
            for (int i = 0; i < les; ++i) {
                if (listEnemy->at(i)->getX() == intendXCor &&
                    listEnemy->at(i)->getY() == intendYCor &&
                    listEnemy->at(i)->getRace() == "Merchant") {
                    m = static_cast<Merchant*>(listEnemy->at(i));
                    break;
                }
            }
            if (m->isHostile()) {
                MSG = "\"DON'T YOU DARE BUY A SINGLE THING FROM ME ANYMORE!!!\", said by the Angry Merchant. ";
            } else {
                string bought = m->purchase();
                if (bought == "NEF") {
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
             out == 'O' || out == 'M' || out == 'm' || out == 'D' || out == 'L') ) {
                attackYes = true; //able to use player attack function
        } else { MSG = "Pulling Out the Sword, Looking Around, Killing the Air :(. "; }
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
    int lesize = static_cast<int>(listEnemy->size());
    for (int i = 0; i < lesize; i++) {
        Enemy *e = listEnemy->at(i);
        if (e->getX() == intendXCor &&
            e->getY() == intendYCor) {
            int bf = e->getHP();
            player->attack(e);
            if (e->getHP() == 0) { MSG += "PC slains " + e->getRace() + ". "; }
            else { 
                if (e->getRace() == "Halfling" && bf == e->getHP()) {
                    MSG += "PC misses the attack to Halfling (" + to_string(e->getHP()) + " HP). ";
                } else {
                    MSG += "PC deals " + to_string(bf - e->getHP()) + " to " + e->getRace() + " (" + to_string(e->getHP()) + " HP). "; 
                }
            }

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

            if (e->dead())
            { // erase and put to back: dead enemies are all at the end
                listEnemy->erase(listEnemy->begin() + i);
                listEnemy->push_back(e); //
            }

            break;
        }
    }
}


void enemyAction(Window* w, vector<Enemy*>* enemyList, string &MSG){
    int els = static_cast<int>(enemyList->size());
    for(int i = 0; i < els; i++){
        if(!enemyList->at(i)->dead()){
            int bf = enemyList->at(i)->getPCHP();
            bool attackYes = enemyList->at(i)->attack();
            if(!attackYes){ //not attacking pc
                enemyList->at(i)->move(w->picture());
            }else{
                if (bf == enemyList->at(i)->getPCHP()) {
                    MSG += enemyList->at(i)->getRace() + " misses the attack to PC. ";
                } else {
                    MSG += enemyList->at(i)->getRace() + " deals " + to_string(bf - enemyList->at(i)->getPCHP()) + " damage to PC. ";
                }
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


int main(int argc, char* argv[]) {
    bool dlc = false;
    if(argc >= 2) {
        dlc = true;
    }

    string MSG;
    string Filename = "../map_resource/emptySingleFloor.txt";
    string FilenameModified = "../map_resource/emptySingleFloor-modified.txt";

    bool restart = false;
    bool quit = false;

    while(true) {
        // store the player information
        string playerChoice = "Shade";
        coolLogo();
        cout << "s: Shade    d: Drow    v: Vampire    g: Goblin    t: Troll" << endl;
        cout << "YOUR FATE: ";
        getline(cin, playerChoice);
        int playerAsset = 0;
        int playerHP = 0;
        string playerWeapon = "Fist";

        bool creatorMode = true;

        for (int j = 0; j < 5; j++) {

            
            // FLOOR BUILDING STAGE!!!
            vector<Chamber *> listChamber;
            vector<MapPotion *> listPot;
            vector<Gold *> listGold;
            vector<Enemy *> listEnemy;
            vector<Equipment*> listWeapon;

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
            if (playerChoice == "v")
            {
                player = new Vampire(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
            }
            else if (playerChoice == "g")
            {
                player = new Goblin(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
            }
            else if (playerChoice == "d")
            {
                player = new Drow(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
            }
            else if (playerChoice == "t")
            {
                player = new Troll(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
            }
            else
            {
                player = new Shade(w.picture(), xCorPlayer, yCorPlayer, playerAsset);
            }
            w.picture() = player;

            if (j != 0)
            {
                player->setHP(playerHP);
                Equipment* weapon = nullptr;
                if(playerWeapon == "Fist"){
                    weapon = new Fist{nullptr};
                }else if(playerWeapon == "Sword"){
                    weapon = new Sword{nullptr, 0, 0};
                }else if(playerWeapon == "Shield"){
                    weapon = new Shield{nullptr, 0, 0};
                }
                player->useEquip(weapon);
            }

            w.windowInit(player);
            // generate the stairway
            int xCorStair = 0;
            int yCorStair = 0;
            while (true)
            {
                randomChamberIndex = rand() % 5;
                if (randomChamberIndex != playerChamberIndex)
                { // ensure stair and player is not in the same
                    break;
                }
            }
            listChamber.at(randomChamberIndex)->spawnCoordinate(xCorStair, yCorStair);
            Stair *stair = new Stair(w.picture(), xCorStair, yCorStair);
            w.picture() = stair;

            // generate the potion
            string arrPotName[6] = {"BA", "BD", "WA", "WD", "PH", "RH"};
            int lengthArrPotName = sizeof(arrPotName) / sizeof(arrPotName[0]);
            for (int i = 0; i < 5; i++)
            {
                int xCorPot = 0;
                int yCorPot = 0;
                randomChamberIndex = rand() % 5;
                listChamber.at(randomChamberIndex)->spawnCoordinate(xCorPot, yCorPot);
                int randomPotNameIndex = rand() % lengthArrPotName;
                MapPotion *pot = new MapPotion(w.picture(), xCorPot, yCorPot, arrPotName[randomPotNameIndex]);
                listPot.push_back(pot);
                w.picture() = pot;
            }

            // generate the gold
            int arrGoldName[8] = {1, 1, 2, 2, 2, 2, 2, 6};
            int lengthArrGoldName = sizeof(arrGoldName) / sizeof(arrGoldName[0]);
            int dragonNumber = 0;
            for (int i = 0; i < 10; i++)
            {
                int xCorGold = 0;
                int yCorGold = 0;
                randomChamberIndex = rand() % 5;
                listChamber.at(randomChamberIndex)->spawnCoordinate(xCorGold, yCorGold);
                int randomGoldName = arrGoldName[rand() % lengthArrGoldName];
                if (randomGoldName == 6)
                {
                    // dragon hoard
                    int dragonXCor = 0;
                    int dragonYCor = 0;
                    DragonHoard *gold = new DragonHoard(w.picture(), xCorGold, yCorGold);
                    listGold.push_back(gold);
                    w.picture() = gold;
                    randomEight(&w, xCorGold, yCorGold, dragonXCor, dragonYCor);
                    Dragon *dragon = new Dragon{w.picture(), dragonXCor, dragonYCor, player, xCorGold, yCorGold};
                    dragonNumber++;
                    listEnemy.push_back(dragon);
                    gold->setResidence(dragon);
                    w.picture() = dragon;
                    listChamber.at(randomChamberIndex)->useSpawnCoordinate(dragonXCor, dragonYCor);
                }
                else
                {
                    Drop *gold = new Drop(w.picture(), xCorGold, yCorGold, randomGoldName);
                    listGold.push_back(gold);
                    w.picture() = gold;
                }
            }

            // generate the enemy
            int arrEnemyName[18] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
            int lengthArrEnemyName = sizeof(arrEnemyName) / sizeof(arrEnemyName[0]);
            for (int i = 0; i < 20 - dragonNumber; i++)
            {
                int xCorEnemy = 0;
                int yCorEnemy = 0;
                randomChamberIndex = rand() % 5;
                listChamber.at(randomChamberIndex)->spawnCoordinate(xCorEnemy, yCorEnemy);
                int randomEnemyName = arrEnemyName[rand() % lengthArrEnemyName];
                Enemy *enemy = nullptr;
                if ((1 <= randomEnemyName) && (randomEnemyName <= 4))
                { // 4/18 = 2/9
                    enemy = new Human(w.picture(), xCorEnemy, yCorEnemy, player);
                }
                else if ((5 <= randomEnemyName) && (randomEnemyName <= 9))
                { // 5/18
                    enemy = new Halfling(w.picture(), xCorEnemy, yCorEnemy, player);
                }
                else if (((10 <= randomEnemyName) && (randomEnemyName <= 11)))
                { // 2/18 = 1/9
                    enemy = new Elf(w.picture(), xCorEnemy, yCorEnemy, player);
                }
                else if (((12 <= randomEnemyName) && (randomEnemyName <= 13)))
                { // 2/18 = 1/9
                    enemy = new Orcs(w.picture(), xCorEnemy, yCorEnemy, player);
                }
                else if (((14 <= randomEnemyName) && (randomEnemyName <= 15)))
                { // 2/18 = 1/9
                    enemy = new Merchant(w.picture(), xCorEnemy, yCorEnemy, player, coc);
                }
                else if (((16 <= randomEnemyName) && (randomEnemyName <= 18)))
                { // 3/18 = 1/6
                    enemy = new Dwarf(w.picture(), xCorEnemy, yCorEnemy, player);
                }
                listEnemy.push_back(enemy);
                w.picture() = enemy;
            }


            if(dlc){
                //generate weapons
                int arrNameWeapon[2] = {0, 1};
                int lengthArrWeapon = sizeof(arrNameWeapon) / sizeof(arrNameWeapon[0]);
                for(int i = 0; i < 1; i++){
                    int xCorWea = 0;
                    int yCorWea = 0;
                    randomChamberIndex = rand() % 5;
                    listChamber.at(randomChamberIndex)->spawnCoordinate(xCorWea, yCorWea);
                    int randomWeapon = arrNameWeapon[rand() % lengthArrWeapon];
                    Equipment *equip = nullptr;
                    if(randomWeapon == 0){
                        equip = new Sword(w.picture(), xCorWea, yCorWea);
                    }else if(randomWeapon == 1){
                        equip = new Shield(w.picture(), xCorWea, yCorWea);
                    }
                    listWeapon.push_back(equip);
                    w.picture() = equip;
                }
            }


            // sort the enemy from left to right
            sort(listEnemy.begin(), listEnemy.end(), enemyLeftRightCompare);
            MSG = "Player Character has spawned. ";
            render(&w, player, MSG, 0, dlc);
            MSG = "";

            // READING CMD STAGE!!!
            // PLAYING STAGE!!!
            // bool nextFloor = false;
            while (true) {
                string cmd;
                cout << "-|===>: ";

                getline(cin, cmd);

                if (cmd == "q")
                {
                    quit = true;
                    break;
                }
                else if (cmd == "r")
                {
                    restart = true;
                    break;
                }
                else if (cmd == "f")
                {
                    creatorMode = !creatorMode;
                    if (!creatorMode) MSG = "TIME PAUSE!";
                    else MSG = "TIME CONTINUE!";
                }

                int currentPlayerXCor = player->getX();
                int currentPlayerYCor = player->getY();
                bool attackYes = false; // player always init attack as false
                int intendx = 0;
                int intendy = 0;
                int action = movePlayer(&w, currentPlayerXCor, currentPlayerYCor, cmd, player,
                                        &listPot, &listGold, &listEnemy, attackYes, intendx, intendy, MSG, dlc, &listWeapon);
                if (player->dead()) {
                    quit = true;
                    break;
                }

                if (action == 1)
                {
                    if (creatorMode)
                    {
                        enemyAction(&w, &listEnemy, MSG);
                        if (player->dead()) {
                            quit = true;
                            break;
                        }
                    }
                    if (attackYes)
                    {
                        playerAttack(&w, &listEnemy, player, intendx, intendy, &listGold, MSG);
                    }
                    if (dlc)
                    {
                        w.updateVision(player);
                    }
                }
                else if (action == 2)
                {
                    // no move
                }
                else if (action == 0)
                { // next for loop, next layer
                    playerAsset += player->getAsset();
                    playerHP = player->getHP();
                    playerWeapon = player->getEquip();
                    w.destroy();
                    delete coc;
                    break;
                }
                render(&w, player, MSG, j + 1, dlc);
            }
            if (quit)
            {
                MSG = "MISSION FAILED";
                render(&w, player, MSG, j+1, dlc);
                cout << "RECORDS: Golds: " << player->getAsset() << endl;
                cout << "FLOOR ACHIEVED: " << j + 1 << endl;
                delete coc;
                w.destroy();
                break;
            }
            if (restart)
            {
                delete coc;
                w.destroy();
                break;
            }

            if (j == 4) { 
                victoryFlag();
                cout << "GOLDS GAINED: " << playerAsset << endl;
                cout << "CONGRATULATIONS! YOU ARE THE HERO OF CHAMBER!" << endl;
                cout << "THANK YOU FOR PLAYING OUR GAME!" << endl;
                quit = true;
                break;
            }
        }

        if (quit) {
            break;
        } else if (restart) {
            continue;
        }


    }

    return 0;
}


