#ifndef WINDOW_H
#define WINDOW_H
#include <iostream>
#include <vector>
#include "map.h"

class Window {
  std::ostream &out = std::cout;

  Map* win;
  //enemy vector

 public:
  //vector<Chamber*> chamberList;
  explicit Window(Map* layer): win{layer} {}

  Map *&picture() { return win; } //getter
  void display();
};

#endif




