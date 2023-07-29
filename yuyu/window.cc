#include "window.h"
#include "map.h"
using namespace std;



void Window::display() {
  for (int i = 0; i < Map::FLOORHEIGHT; ++i) {
    for (int j = 0; j < Map::FLOORWIDTH; ++j) {
      out << picture()->charAt(j, i);
    }
    cout << "" << endl;
  }

}


Window::~Window() {
  //cout << "s dtor" << endl;
  delete win; 
}








