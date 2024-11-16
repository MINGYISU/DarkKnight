#include "window.h"
#include "map.h"
using namespace std;

#define ESC "\033["
#define BACKGROUND "1"
#define BACKGROUND_VISION "100"
#define YELLOW_TXT "33"
#define BLUE_TXT "34"
#define GREEN_TXT "32"
#define RED_TXT "31"
#define RED_BACK "101"
#define RESET "\033[m"
#define CLS "\033[2J\033[1;1H"


void Window::windowInit(Player* pc){
  for (int row = 0; row < Map::FLOORHEIGHT; row++)
  {
    for (int column = 0; column < Map::FLOORWIDTH; column++)
    {
      if ((pc->getX() <= column + 5) && (pc->getX() >= column - 5) && (pc->getY() <= row + 5) && (pc->getY() >= row - 5))
      {
        pcVision[row][column] = 1;
      }
      else
      {
        pcVision[row][column] = 0;
      }
    }
  }
}


void Window::display() {
  cout << CLS;
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
      }else if (output == 'X') {
        out << ESC << BACKGROUND << ";" << RED_BACK << "m" << output << RESET;
      }
      else if (output == '!')
      {
        out << ESC << BACKGROUND << ";" << YELLOW_TXT << "m" << output << RESET;
      }
      else if (output == 'm') {
        out << ESC << BACKGROUND << ";" << BLUE_TXT << "m" << 'M' << RESET;
      }
      else{
        out << output;
      }
    }
    cout << "" << endl;
  }

}

void Window::visionDisplay(){
  out << CLS;
  for (int i = 0; i < Map::FLOORHEIGHT; ++i) {
    for (int j = 0; j < Map::FLOORWIDTH; ++j) {
      if (pcVision[i][j] == 1) { //have the vision
        char output = picture()->charAt(j, i);
        if (output == 'G') {
          out << ESC << BACKGROUND << ";" << YELLOW_TXT << "m" << output << RESET;
        } else if ((output == '@') || (output == '\\')) {
          out << ESC << BACKGROUND << ";" << BLUE_TXT << "m" << output << RESET;
        } else if (output == 'P') {
          out << ESC << BACKGROUND << ";" << GREEN_TXT << "m" << output << RESET;
        }
        else if ((output == 'H') || (output == 'W') || (output == 'E') || (output == 'O') || (output == 'M') || (output == 'D') || (output == 'L')) {
          out << ESC << BACKGROUND << ";" << RED_TXT << "m" << output << RESET;
        } else if (output == 'm'){
          out << ESC << BACKGROUND << ";" << BLUE_TXT << "m" << 'M' << RESET;
        } else if (output == 'X') {
          out << ESC << BACKGROUND << ";" << RED_BACK << "m" << output << RESET;
        } else if (output == '!') {
          out << ESC << BACKGROUND << ";" << YELLOW_TXT << "m" << output << RESET;
        } else {
          out << output;
        }
      } else { //does not have the vision
        out << ESC << BACKGROUND_VISION << ";" << RED_TXT << "m" << ':' << RESET;
      }
    }
    cout << "" << endl;
  }
}

void Window::updateVision(Player* pc){
  int x = pc->getX();
  int y = pc->getY();
  for (int row = y-5; row <= y+5; row++)
  {
    for (int column = x-5; column <= x+5; column++)
    {
      if ((0 <= row) && (row < Map::FLOORHEIGHT) && (0 <= column) && (column < Map::FLOORWIDTH))
      {
        pcVision[row][column] = 1;
      }
    }
  }
}

Window::~Window() {
  //cout << "s dtor" << endl;
  delete win; 
  //delete[] pcVision;
}

void Window::destroy() {
  delete win;
  win = nullptr;
}






