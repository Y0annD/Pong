#ifndef PONG
#define PONG

#include <vector>
#include "Window.h"
#include "Mobile.h"
#include "Mur.h"
#include "Triangle.h"
#include "Circle.h"

class Pong{
 private:
  int WIDTH;
  int HEIGHT;
  sf::Clock clock;
  std::vector<Mobile*> _mobiles;
  std::vector<Mur*>     _walls;
  bool isRunning;
  bool pause;
  Window win;

  int collision(Mobile*);
  void drawAll(sf::RenderWindow *win) const;
  void manageEvent();
    void moveAll(void);
 
 public:
 Pong(int width, int height):WIDTH(width),HEIGHT(height),isRunning(false),pause(false),win(Window("Pong",WIDTH,HEIGHT+40)){}
  ~Pong(void);
  void init();
  void execute();
};

#endif
