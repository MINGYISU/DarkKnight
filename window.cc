#include "window.h"
#include "map.h"
using namespace std;

#define ESC "\033["
#define BACKGROUND "1"
#define YELLOW_TXT "33"
#define BLUE_TXT "34"
#define GREEN_TXT "32"
#define RED_TXT "31"
#define RESET "\033[m"

void Window::display() {
  for (int i = 0; i < Map::FLOORHEIGHT; ++i) {
    for (int j = 0; j < Map::FLOORWIDTH; ++j) {
      char output = picture()->charAt(j, i);
      if(output == 'G'){
        out << ESC << BACKGROUND << ";" << YELLOW_TXT << "m" << output << RESET;
      }else if((output == '@') || (output == '\\')){
        out << ESC << BACKGROUND << ";" << BLUE_TXT << "m" << output << RESET;
      }else if(output == 'P'){
        out << ESC << BACKGROUND << ";" << GREEN_TXT << "m" << output << RESET;
      }else if((output == 'H') || (output == 'W') || (output == 'E') || (output == 'O') || (output == 'M')
                || (output == 'D') || (output == 'L')){
        out << ESC << BACKGROUND << ";" << RED_TXT << "m" << output << RESET;
      }
      else{
        out << output;
      }
    }
    cout << "" << endl;
  }

}


Window::~Window() {
  //cout << "s dtor" << endl;
  delete win; 
}








