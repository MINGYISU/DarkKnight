#include "map.h"
#include "window.h"
#include "chamber.h"
#include "frame.h"
#include "decorator.h"
#include "blank.h"

#include "enemy.h"
#include "human.h"

int main() {
    string Filename = "cc3k-emptySingleFloor.txt";

    Map *Layer1 = new Blank;
    Window w{Layer1};
    
    w.picture() = new Frame{w.picture()};
    
    Chamber *newptr1 = new Chamber{w.picture(), 7, 2, 3, 29, Filename};

    w.picture() = newptr1;

    Enemy *enemy = new Human(w.picture(), 3, 3);

    w.picture() = enemy;

    Enemy *e2 = new Human(w.picture(), 3, 4);

    w.picture() = e2;

    Enemy *e3 = new Human(w.picture(), 4, 3);

    w.picture() = e3;

    Enemy *e4 = new Human(w.picture(), 4, 4);

    w.picture() = e4;


    w.display();

    e2->move(w.picture());
    enemy->move(w.picture());

    w.display();

}