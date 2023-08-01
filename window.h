#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <vector>
#include "map.h"
#include "player.h"

class Window {
  std::ostream &out = std::cout;

  Map* win;
  int pcVision[Map::FLOORHEIGHT][Map::FLOORWIDTH];

 public:
  //vector<Chamber*> chamberList;
  explicit Window(Map* layer): win{layer} {}

  Map *&picture() { return win; } //getter
  void display();
  void visionDisplay();
  void updateVision(Player* pc);
  void windowInit(Player* pc);
  void destroy();
  ~Window();
};

#endif




