#ifndef PONG
#define PONG

#include <vector>
#include "Window.h"
#include "Mobile.h"
#include "Mur.h"

class Pong{
 private:
  int WIDTH;
  int HEIGHT;
  std::vector<Mobile*> _mobiles;
  std::vector<Mur*>     _walls;
  bool isRunning;
  Window win;
  void drawAll(sf::RenderWindow *win) const;
 
 public:
 Pong(int width, int height):WIDTH(width),HEIGHT(height),isRunning(false),win(Window("Pong",WIDTH,HEIGHT)){}
  void init();
  void execute();
  void collision();
};

#endif
